
// #include <immintrin.h>
// #include <stdio.h>

// float mean512(float *din)
// {
//     __m256 *a1 = (__m256 *)din;
//     __m256 a2[32];
//     __m256 a3[16];
//     __m256 a4[8];
//     __m256 a5[4];
//     __m256 a6[2];
//     __m256 a7;
//     int i;
//     for (i = 0; i < 32; i++) {
//         a2[i] = _mm256_add_ps(a1[i], a1[i + 32]);
//     }
//     for (i = 0; i < 16; i++) {
//         a3[i] = _mm256_add_ps(a2[i], a2[i + 16]);
//     }
//     for (i = 0; i < 8; i++) {
//         a4[i] = _mm256_add_ps(a3[i], a3[i + 8]);
//     }
//     for (i = 0; i < 4; i++) {
//         a5[i] = _mm256_add_ps(a4[i], a4[i + 4]);
//     }

//     a6[0] = _mm256_add_ps(a5[0], a5[2]);
//     a6[1] = _mm256_add_ps(a5[1], a5[3]);
//     a7 = _mm256_add_ps(a6[0], a6[1]);
//     float *b = (float *)&a7;
//     float result = b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6] + b[7];
//     return result / 512;
// }

// float var512(float *din, float mean)
// {
//     __m256 m256mean = {mean, mean, mean, mean, mean, mean, mean, mean};
//     __m256 *a0 = (__m256 *)din;
//     __m256 a1[64];
//     __m256 a2[32];
//     __m256 a3[16];
//     __m256 a4[8];
//     __m256 a5[4];
//     __m256 a6[2];
//     __m256 a7;
//     int i;
//     for (i = 0; i < 64; i++) {
//         __m256 tmp = _mm256_sub_ps(a0[i], m256mean);
//         a1[i] = _mm256_mul_ps(tmp, tmp);
//     }
//     for (i = 0; i < 32; i++) {
//         a2[i] = _mm256_add_ps(a1[i], a1[i + 32]);
//     }
//     for (i = 0; i < 16; i++) {
//         a3[i] = _mm256_add_ps(a2[i], a2[i + 16]);
//     }
//     for (i = 0; i < 8; i++) {
//         a4[i] = _mm256_add_ps(a3[i], a3[i + 8]);
//     }
//     for (i = 0; i < 4; i++) {
//         a5[i] = _mm256_add_ps(a4[i], a4[i + 4]);
//     }

//     a6[0] = _mm256_add_ps(a5[0], a5[2]);
//     a6[1] = _mm256_add_ps(a5[1], a5[3]);
//     a7 = _mm256_add_ps(a6[0], a6[1]);
//     float *b = (float *)&a7;
//     float result = b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6] + b[7];
//     return result / 512;
// }

// void norm512(float *din, float *weight, float *bias, float mean, float std)
// {

//     __m256 m_mean = {mean, mean, mean, mean, mean, mean, mean, mean};
//     __m256 m_std = {std, std, std, std, std, std, std, std};
//     __m256 *m_din = (__m256 *)din;
//     __m256 *m_weight = (__m256 *)weight;
//     __m256 *m_bias = (__m256 *)bias;

//     int i;
//     for (i = 0; i < 64; i++) {
//         m_din[i] = _mm256_sub_ps(m_din[i], m_mean);
//         m_din[i] = _mm256_div_ps(m_din[i], m_std);
//         m_din[i] = _mm256_mul_ps(m_din[i], m_weight[i]);
//         m_din[i] = _mm256_add_ps(m_din[i], m_bias[i]);
//     }
// }
