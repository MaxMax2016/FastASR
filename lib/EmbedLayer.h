
#ifndef EMBEDLAYER_H
#define EMBEDLAYER_H

#include <stdint.h>

#include "Tensor.h"
#include "WenetParams.h"

class EmbedLayer {
  private:
    EncEmbedParams *params;

    int in_row;
    int in_column;

    int conv0_row;
    int conv0_column;
    int *conv0_idxs;

    int conv1_row;
    int conv1_column;
    int *conv1_idxs;

    void conv_idxs_calc(int row, int column);

    void get_conv_ind(int trans, int in_row, int in_column, int kernel,
                      int stride, int &out_row, int &out_column,
                      int *&out_idxs);
    void conv0_forward(Tensor<float> *&din);
    void conv1_forward(Tensor<float> *&din);
    void linear_out_forward(Tensor<float> *&din);

  public:
    EmbedLayer(EncEmbedParams *params);
    ~EmbedLayer();
    void forward(Tensor<float> *&din);
};

#endif
