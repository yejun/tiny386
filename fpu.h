#ifndef FPU_H
#define FPU_H

#include <stdbool.h>
#include <stdint.h>

typedef struct FPU FPU;

FPU *fpu_new();
void fpu_delete(FPU *fpu);
bool fpu_exec1(FPU *fpu, void *cpu, int op, int group, unsigned int i);
bool fpu_exec2(FPU *fpu, void *cpu, bool opsz16, int op, int group, int seg, uword addr);

#if defined(__wasm__) && defined(FAST_PD) && !defined(USE_FLOAT80)
void fpu_move_real64(FPU *fpu, int group, void *p);
#endif

#endif /* FPU_H */
