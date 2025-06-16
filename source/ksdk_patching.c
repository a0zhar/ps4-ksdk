#include "../include/ksdk_patching.h"


void init_505_ksdk(uint8_t *kbase) {

    Xfast_syscall = (void *)(kbase + 0x1C0);
    copyin = (void *)(kbase + 0x1EA710);
    copyout = (void *)(kbase + 0x1EA630);
    printf = (void *)(kbase + 0x436040);
    vprintf = (void *)(kbase + 0x4360B0);
    malloc = (void *)(kbase + 0x10E250);
    free = (void *)(kbase + 0x10E460);
    memcpy = (void *)(kbase + 0x1EA530);
    memset = (void *)(kbase + 0x3205C0);
    memcmp = (void *)(kbase + 0x50AC0);
    kmem_alloc = (void *)(kbase + 0xFCC80);
    strlen = (void *)(kbase + 0x3B71A0);
    pause = (void *)(kbase + 0x3FB920);
    kthread_add = (void *)(kbase + 0x138360);
    kthread_exit = (void *)(kbase + 0x138640);
    sched_prio = (void *)(kbase + 0x31EE00);
    sched_add = (void *)(kbase + 0x31F150);
    kern_yield = (void *)(kbase + 0x3FBC40);
    fill_regs = (void *)(kbase + 0x234BA0);
    set_regs = (void *)(kbase + 0x234CD0);
    create_thread = (void *)(kbase + 0x1BE1F0);
    kproc_create = (void *)(kbase + 0x137DF0);
    kthread_set_affinity = (void *)(kbase + 0x138CC0);
    kthread_suspend_check = (void *)(kbase + 0x138A60);
    kproc_kthread_add = (void *)(kbase + 0x138B70);
    sx_init_flags = (void *)(kbase + 0xF5BB0);
    sx_xlock = (void *)(kbase + 0xF5E10);
    sx_xunlock = (void *)(kbase + 0xF5FD0);
    mtx_init = (void *)(kbase + 0x402780);
    mtx_lock_spin_flags = (void *)(kbase + 0x402100);
    mtx_unlock_spin_flags = (void *)(kbase + 0x4022C0);
    mtx_lock_sleep = (void *)(kbase + 0x401CD0);
    mtx_unlock_sleep = (void *)(kbase + 0x401FA0);
    kern_reboot = (void *)(kbase + 0x10D390);
    vm_map_lock_read = (void *)(kbase + 0x19F140);
    vm_map_lookup_entry = (void *)(kbase + 0x19F760);
    vm_map_unlock_read = (void *)(kbase + 0x19F190);
    vmspace_acquire_ref = (void *)(kbase + 0x19EF90);
    vmspace_free = (void *)(kbase + 0x19EDC0);
    vm_map_delete = (void *)(kbase + 0x1A19D0);
    vm_map_protect = (void *)(kbase + 0x1A3A50);
    vm_map_findspace = (void *)(kbase + 0x1A1F60);
    vm_map_insert = (void *)(kbase + 0x1A0280);
    vm_map_lock = (void *)(kbase + 0x19EFF0);
    vm_map_unlock = (void *)(kbase + 0x19F060);
    proc_rwmem = (void *)(kbase + 0x30D150);

    disable_console_output = (void *)(kbase + 0x19ECEB0);
    M_TEMP = (void *)(kbase + 0x14B4110);
    kernel_map = (void *)(kbase + 0x1AC60E0);
    prison0 = (void *)(kbase + 0x10986a0);
    rootvnode = (void *)(kbase + 0x22C1A70);
    allproc = (void *)(kbase + 0x2382FF8);
    sysents = (void *)(kbase + 0x107C610);
}

void init_672_ksdk(uint8_t *kbase) {

    // Functions
    Xfast_syscall = (void *)(kbase + 0x000001C0);
    copyin = (void *)(kbase + 0x003C17A0);
    copyout = (void *)(kbase + 0x003C16B0);
    printf = (void *)(kbase + 0x00123280);
    vprintf = (void *)(kbase + 0x001232F0);
    malloc = (void *)(kbase + 0x0000D7A0);
    free = (void *)(kbase + 0x0000D9A0);
    memcpy = (void *)(kbase + 0x003C15B0);
    memset = (void *)(kbase + 0x001687D0);
    memcmp = (void *)(kbase + 0x00207E40);
    kmem_alloc = (void *)(kbase + 0x00250730);
    strlen = (void *)(kbase + 0x002433E0);
    pause = (void *)(kbase + 0x0022A080);
    kthread_add = (void *)(kbase + 0x0008A600);
    kthread_exit = (void *)(kbase + 0x0008A8F0);
    sched_prio = (void *)(kbase + 0x004453C0);
    sched_add = (void *)(kbase + 0x00445F20);
    kern_yield = (void *)(kbase + 0x0022A3A0);
    fill_regs = (void *)(kbase + 0x000A36D0);
    set_regs = (void *)(kbase + 0x000A3800);
    create_thread = (void *)(kbase + 0x004A6FB0);
    kproc_create = (void *)(kbase + 0x0008A0A0);
    kthread_set_affinity = (void *)(kbase + 0x0008AF70);
    kthread_suspend_check = (void *)(kbase + 0x0008AD10);
    kproc_kthread_add = (void *)(kbase + 0x0008AE20);
    sx_init_flags = (void *)(kbase + 0x00042450);
    sx_xlock = (void *)(kbase + 0x000426C0);
    sx_xunlock = (void *)(kbase + 0x00042880);
    mtx_init = (void *)(kbase + 0x00496FE0);
    mtx_lock_spin_flags = (void *)(kbase + 0x00496970);
    mtx_unlock_spin_flags = (void *)(kbase + 0x00496B30);
    mtx_lock_sleep = (void *)(kbase + 0x00496540);
    mtx_unlock_sleep = (void *)(kbase + 0x00496810);
    kern_reboot = (void *)(kbase + 0x00206D50);
    vm_map_lock_read = (void *)(kbase + 0x0044CD40);
    vm_map_lookup_entry = (void *)(kbase + 0x0044D330);
    vm_map_unlock_read = (void *)(kbase + 0x0044CD90);
    vmspace_acquire_ref = (void *)(kbase + 0x0044CB90);
    vmspace_free = (void *)(kbase + 0x0044C9C0);
    vm_map_delete = (void *)(kbase + 0x0044F8A0);
    vm_map_protect = (void *)(kbase + 0x00451BF0);
    vm_map_findspace = (void *)(kbase + 0x0044FE60);
    vm_map_insert = (void *)(kbase + 0x0044DEF0);
    vm_map_lock = (void *)(kbase + 0x0044CBF0);
    vm_map_unlock = (void *)(kbase + 0x0044CC60);
    proc_rwmem = (void *)(kbase + 0x0010EE10);

        // Data
    disable_console_output = (void *)(kbase + 0x01A6EB18);
    M_TEMP = (void *)(kbase + 0x01540EB0);
    kernel_map = (void *)(kbase + 0x0220DFC0);
    prison0 = (void *)(kbase + 0x0113E518);
    rootvnode = (void *)(kbase + 0x02300320);
    allproc = (void *)(kbase + 0x022BBE80);
    sysents = (void *)(kbase + 0x0111E000);
}


void init_702_ksdk(uint8_t *kbase) {

    Xfast_syscall = (void *)(kbase + 0x000001C0);
    copyin = (void *)(kbase + 0x0002F230);
    copyout = (void *)(kbase + 0x0002F140);
    printf = (void *)(kbase + 0x000BC730);
    vprintf = (void *)(kbase + 0x000BC7a0);
    malloc = (void *)(kbase + 0x00301840);
    free = (void *)(kbase + 0x00301A40);
    memcpy = (void *)(kbase + 0x0002F040);
    memset = (void *)(kbase + 0x002DFC20);
    memcmp = (void *)(kbase + 0x00207500);
    kmem_alloc = (void *)(kbase + 0x001170F0);
    strlen = (void *)(kbase + 0x00093FF0);
    pause = (void *)(kbase + 0x0016EEE0);
    kthread_add = (void *)(kbase + 0x000C46D0);
    kthread_exit = (void *)(kbase + 0x000C49C0);
    sched_prio = (void *)(kbase + 0x003281F0);
    sched_add = (void *)(kbase + 0x00328D50);
    kern_yield = (void *)(kbase + 0x0016F210);
    fill_regs = (void *)(kbase + 0x004940A0);
    set_regs = (void *)(kbase + 0x004941D0);
    create_thread = (void *)(kbase + 0x000842E0);
    kproc_create = (void *)(kbase + 0x000C4170);
    kthread_set_affinity = (void *)(kbase + 0x000C5030);
    kthread_suspend_check = (void *)(kbase + 0x000C4DD0);
    kproc_kthread_add = (void *)(kbase + 0x000C4EE0);
    sx_init_flags = (void *)(kbase + 0x001ADDB0);
    sx_xlock = (void *)(kbase + 0x001AE030);
    sx_xunlock = (void *)(kbase + 0x001AE1F0);
    mtx_init = (void *)(kbase + 0x000BBB10);
    mtx_lock_spin_flags = (void *)(kbase + 0x000BB490);
    mtx_unlock_spin_flags = (void *)(kbase + 0x000BB650);
    mtx_lock_sleep = (void *)(kbase + 0x000BB060);
    mtx_unlock_sleep = (void *)(kbase + 0x000BB330);
    kern_reboot = (void *)(kbase + 0x002CD780);
    vm_map_lock_read = (void *)(kbase + 0x0025FB90);
    vm_map_lookup_entry = (void *)(kbase + 0x00260190);
    vm_map_unlock_read = (void *)(kbase + 0x0025FBE0);
    vmspace_acquire_ref = (void *)(kbase + 0x0025F9F0);
    vmspace_free = (void *)(kbase + 0x0025F820);
    vm_map_delete = (void *)(kbase + 0x00262700);
    vm_map_protect = (void *)(kbase + 0x00264A50);
    vm_map_findspace = (void *)(kbase + 0x00262CC0);
    vm_map_insert = (void *)(kbase + 0x00260D60);
    vm_map_lock = (void *)(kbase + 0x0025FA50);
    vm_map_unlock = (void *)(kbase + 0x0025FAB0);
    proc_rwmem = (void *)(kbase + 0x00043E80);

    disable_console_output = (void *)(kbase + 0x01A6EAA0);
    M_TEMP = (void *)(kbase + 0x01A7AE50);
    kernel_map = (void *)(kbase + 0x021C8EE0);
    prison0 = (void *)(kbase + 0x0113E398);
    rootvnode = (void *)(kbase + 0x022C5750);
    allproc = (void *)(kbase + 0x01B48318);
    sysents = (void *)(kbase + 0x01125660);
}
void init_755_ksdk(uint8_t *kbase) {

    Xfast_syscall = (void *)(kbase + 0x000001C0);
    copyin = (void *)(kbase + 0x0028F9F0);
    copyout = (void *)(kbase + 0x0028F900);
    printf = (void *)(kbase + 0x0026F740);
    vprintf = (void *)(kbase + 0x0026F7B0);
    malloc = (void *)(kbase + 0x001D6680);
    free = (void *)(kbase + 0x001D6870);
    memcpy = (void *)(kbase + 0x0028F800);
    memset = (void *)(kbase + 0x0008D6F0);
    memcmp = (void *)(kbase + 0x0031D250);
    kmem_alloc = (void *)(kbase + 0x001753E0);
    strlen = (void *)(kbase + 0x002E8BC0);
    pause = (void *)(kbase + 0x00086E80);
    kthread_add = (void *)(kbase + 0x0000DE50);
    kthread_exit = (void *)(kbase + 0x0000E140);
    sched_prio = (void *)(kbase + 0x0018FDF0);
    sched_add = (void *)(kbase + 0x00190930);
    kern_yield = (void *)(kbase + 0x000871B0);
    fill_regs = (void *)(kbase + 0x003DB0D0);
    set_regs = (void *)(kbase + 0x003DB200);
    create_thread = (void *)(kbase + 0x0047AB60);
    kproc_create = (void *)(kbase + 0x0000D8F0);
    kthread_set_affinity = (void *)(kbase + 0x0000E7C0);
    kthread_suspend_check = (void *)(kbase + 0x0000E550);
    kproc_kthread_add = (void *)(kbase + 0x0000DE50);
    sx_init_flags = (void *)(kbase + 0x000D1380);
    sx_xlock = (void *)(kbase + 0x000D1600);
    sx_xunlock = (void *)(kbase + 0x000D17C0);
    mtx_init = (void *)(kbase + 0x003105B0);
    mtx_lock_spin_flags = (void *)(kbase + 0x0030FF30);
    mtx_unlock_spin_flags = (void *)(kbase + 0x003100F0);
    mtx_lock_sleep = (void *)(kbase + 0x0030FBB0);
    mtx_unlock_sleep = (void *)(kbase + 0x0030FED0);
    kern_reboot = (void *)(kbase + 0x000D28E0);
    vm_map_lock_read = (void *)(kbase + 0x002FC430);
    vm_map_lookup_entry = (void *)(kbase + 0x002FCA70);
    vm_map_unlock_read = (void *)(kbase + 0x002FC480);
    vmspace_acquire_ref = (void *)(kbase + 0x002FC290);
    vmspace_free = (void *)(kbase + 0x002FC0C0);
    vm_map_delete = (void *)(kbase + 0x002FEFA0);
    vm_map_protect = (void *)(kbase + 0x003012F0);
    vm_map_findspace = (void *)(kbase + 0x002FF560);
    vm_map_insert = (void *)(kbase + 0x002FD640);
    vm_map_lock = (void *)(kbase + 0x002FC2E0);
    vm_map_unlock = (void *)(kbase + 0x002FC350);
    proc_rwmem = (void *)(kbase + 0x00361310);

    disable_console_output = (void *)(kbase + 0x01564910);
    M_TEMP = (void *)(kbase + 0x01556DA0);
    kernel_map = (void *)(kbase + 0x021405B8);
    prison0 = (void *)(kbase + 0x0113B728);
    rootvnode = (void *)(kbase + 0x01B463E0);
    allproc = (void *)(kbase + 0x0213C828);
    sysents = (void *)(kbase + 0x01122340);
}