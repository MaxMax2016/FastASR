
#ifndef SIMD_AVX_H
#define SIMD_AVX_H

extern float mean512(float *din);

extern float var512(float *din, float mean);
extern void norm512(float *din, float *weight, float *bias, float mean,
                     float std);

#endif
