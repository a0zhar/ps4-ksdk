#pragma once
#ifndef UTIL_H
#define UTIL_H

#define MIN(X, Y)  (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y)  (((X) > (Y)) ? (X) : (Y))

#define ROTL16(v, n) ((uint16_t)((v) << (n)) | ((v) >> (16 - (n))))
#define ROTL32(v, n) ((uint32_t)((v) << (n)) | ((v) >> (32 - (n))))

#define ALIGN(size, alignment)  (((size) + ((alignment) - 1)) & ~((alignment) - 1))
#define ALIGN_PAGE(size)  ALIGN(size, 0x4000)

/* bitfields */
#define GET_HI(hi, lo) (hi)
#define GET_LO(hi, lo) (lo)
#define GET_MASK(hi, lo)  (((1 << ((hi) - (lo) + 1)) - 1) << (lo))
#define EXTRACT(value, field)  (((value) & field(GET_MASK)) >> field(GET_LO))

/* helpers */
#define X86_CR0_WP (1 << 16)

#define NULL 0

#define offsetof(st, m) ((uint64_t)((char *)&((st *)(0))->m - (char *)0))

#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((uint64_t)(!(sizeof(x) % sizeof(0[x])))))


#endif /* UTIL_H */
