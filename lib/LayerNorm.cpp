#include <math.h>
#include <stdio.h>

#include "LayerNorm.h"
#include "simd_avx.h"

LayerNorm::LayerNorm(NormParams *params, float error)
    : params(params), error(error)
{
}

LayerNorm::~LayerNorm()
{
}

void LayerNorm::mean_var(float *din, float &mean, float &var)
{
    int i;
    // mean = 0;
    // for (i = 0; i < 512; i++) {
    //     mean += din[i];
    // }
    // mean = mean / 512;
    mean = mean512(din);
    // printf("addr %ld mean is %f,simd_mean is %f\n", (long)din, mean,
    // simd_mean);

    // var = 0;
    // for (i = 0; i < 512; i++) {
    //     float tmp = din[i] - mean;
    //     var += tmp * tmp;
    // }
    // var = var / 512;
    var = var512(din, mean);
    // printf("var is %f, t_var is %f\n", var, t_var);
}

// void LayerNorm::mean_var(float *din, float &mean, float &var)
// {
//     int i;
//     mean = 0;
//     for (i = 0; i < 512; i++) {
//         mean += din[i];
//     }
//     mean = mean / 512;

//     var = 0;
//     for (i = 0; i < 512; i++) {
//         float tmp = din[i] - mean;
//         var += tmp * tmp;
//     }
//     var = var / 512;
// }

void LayerNorm::norm(float *din, float mean, float var)
{
    int i;
    float dd = sqrt(var + error);

    // float tmp[512];
    // memcpy(tmp, din, 512 * sizeof(float));

    // for (i = 0; i < 512; i++) {
    //     din[i] = (din[i] - mean) / dd;
    //     din[i] = din[i] * params->weight[i] + params->bias[i];
    // }

    norm512(din, params->weight, params->bias, mean, dd);
    // printf("%f %f mean is %f dd is %f\n", tmp[0], din[0], mean, dd);
}

void LayerNorm::forward(Tensor<float> *din)
{
    int mm = din->buff_size / 512;
    int i;
// #pragma omp parallel for
    for (i = 0; i < mm; i++) {
        int offset = i * 512;
        float mean, var;
        float *buff = din->buff + offset;
        mean_var(buff, mean, var);
        norm(buff, mean, var);
    }
}
