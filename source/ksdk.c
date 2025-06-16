#include "../include/ksdk.h"
#include "../include/ksdk_firmware.h"
#include "../include/ksdk_patching.h"

uint64_t cached_kernel_base;

/* Function pointer declarations */
void (*Xfast_syscall)(void);
int (*copyin)(const void *uaddr, void *kaddr, uint64_t len);
int (*copyout)(const void *kaddr, void *uaddr, uint64_t len);
int (*printf)(const char *fmt, ...);
int (*vprintf)(const char *fmt, va_list arg);
void *(*malloc)(uint64_t size, void *type, int flags);
void (*free)(void *addr, void *type);
void *(*memcpy)(void *dest, const void *src, uint64_t num);
void *(*memset)(void *ptr, int value, uint64_t num);
int (*memcmp)(const void *ptr1, const void *ptr2, uint64_t num);
void *(*kmem_alloc)(struct vm_map *map, uint64_t size);
uint64_t(*strlen)(const char *str);
void (*pause)(const char *wmesg, int timo);
int (*kthread_add)(void (*func)(void *), void *arg, struct proc *procp, struct thread **newtdpp, int flags, int pages, const char *fmt, ...);
void (*kthread_exit)(void);
void (*sched_prio)(struct thread *td, uint16_t prio);
void (*sched_add)(struct thread *td, uint64_t cpuset);
void (*kern_yield)(uint64_t p);
int (*fill_regs)(struct thread *td, struct reg *rg);
int (*set_regs)(struct thread *td, struct reg *rg);
int (*create_thread)(struct thread *td, uint64_t ctx, void (*start_func)(void *), void *arg, char *stack_base, uint64_t stack_size, char *tls_base, long *child_tid, long *parent_tid, uint64_t flags, uint64_t rtp);
int (*kproc_create)(void (*func)(void *), void *arg, struct proc **newpp, int flags, int pages, const char *fmt, ...);
void (*kthread_set_affinity)(const char *tdname, uint64_t prio, uint64_t cpuset, uint64_t unknown); /* custom name */
void (*kthread_suspend_check)(void);
int (*kproc_kthread_add)(void (*func)(void *), void *arg, struct proc **procptr, struct thread **tdptr, int flags, int pages, char *procname, const char *fmt, ...);
void (*sx_init_flags)(struct sx *sx, const char *description, int opts);
void (*sx_xlock)(struct sx *sx);
void (*sx_xunlock)(struct sx *sx);
void (*mtx_init)(struct mtx *mutex, const char *name, const char *type, int opts);
void (*mtx_lock_spin_flags)(struct mtx *mutex, int flags);
void (*mtx_unlock_spin_flags)(struct mtx *mutex, int flags);
void (*mtx_lock_sleep)(struct mtx *mutex, int flags);
void (*mtx_unlock_sleep)(struct mtx *mutex, int flags);
int (*kern_reboot)(int magic);
void (*vm_map_lock_read)(struct vm_map *map);
int (*vm_map_lookup_entry)(struct vm_map *map, uint64_t address, struct vm_map_entry **entries);
void (*vm_map_unlock_read)(struct vm_map *map);
struct vmspace *(*vmspace_acquire_ref)(struct proc *p);
void (*vmspace_free)(struct vmspace *vm);
int (*vm_map_delete)(struct vm_map *map, uint64_t start, uint64_t end);
int (*vm_map_protect)(struct vm_map *map, uint64_t start, uint64_t end, int new_prot, uint64_t set_max);
int (*vm_map_findspace)(struct vm_map *map, uint64_t start, uint64_t length, uint64_t *addr);
int (*vm_map_insert)(struct vm_map *map, uint64_t object, uint64_t offset, uint64_t start, uint64_t end, int prot, int max, int cow);
void (*vm_map_lock)(struct vm_map *map);
void (*vm_map_unlock)(struct vm_map *map);
int (*proc_rwmem)(struct proc *p, struct uio *uio);

/* Data pointer declarations */
uint8_t *disable_console_output;
void *M_TEMP;
void **kernel_map;
void **prison0;
void **rootvnode;
struct proc **allproc;
struct sysent *sysents;


uint64_t get_kbase() {
    uint32_t edx;
    uint32_t eax;
    __asm__("rdmsr" : "=d"(edx), "=a"(eax) : "c"(0xC0000082));
    return ((((uint64_t)edx) << 32) | (uint64_t)eax) - __Xfast_syscall;
}

uint64_t ksdk_read_msr(uint32_t reg) {
    uint32_t edx;
    uint32_t eax;
    __asm__("rdmsr" : "=d"(edx), "=a"(eax) : "c"(reg));
    return (((uint64_t)edx) << 32) | (uint64_t)eax;
}

uint64_t ksdk_read_cr0(void) {
    uint64_t cr0;
    __asm__("movq %0, %%cr0" : "=r" (cr0) : : "memory");
    return cr0;
}

void ksdk_write_cr0(uint64_t cr0) {
    __asm__("movq %%cr0, %0" : : "r" (cr0) : "memory");
}

void ksdk_cpu_enable_wp(void) {
    uint64_t cr0 = ksdk_read_cr0();
    ksdk_write_cr0(cr0 | X86_CR0_WP);
}

void ksdk_cpu_disable_wp(void) {
    uint64_t cr0 = ksdk_read_cr0();
    ksdk_write_cr0(cr0 & ~X86_CR0_WP);
}

void *ksdk_curthread(void) {
    uint64_t td;
    __asm__("movq %0, %%gs:0" : "=r" (td) : : "memory");
    return (void *)td;
}

void init_ksdk(void) {
    cached_kernel_base = get_kbase();
    unsigned short firmwareVersion = kget_firmware_from_base(cached_kernel_base);
    switch (firmwareVersion) {
        case 505: init_505_ksdk((uint8_t *)cached_kernel_base); break;
        case 672: init_672_ksdk((uint8_t *)cached_kernel_base); break;
        case 702: init_702_ksdk((uint8_t *)cached_kernel_base); break;
        case 755: init_755_ksdk((uint8_t *)cached_kernel_base); break;
        case 900:  /* TODO */ break;
        case 1100: /* TODO */ break;
        default:
            break;
    }
}