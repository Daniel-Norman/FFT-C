//
//  fft.c
//  FFT
//
//  Created by Daniel Norman on 12/25/15.
//  Copyright © 2015 Daniel Norman. All rights reserved.
//

#include "fft.h"

void set_twiddles(fft_helper* ffth) {
    int i = 0;
    double k = 0;
    double NN = ffth->npoint;
    
    for (; i < ffth->npoint; ++i && ++k) {
        ffth->twiddles[i] = cos(2 * M_PI * k / NN) - I*sin(2 * M_PI * k / NN);
    }
}

void setup_fft_helper(fft_helper* ffth, int npoint) {
    ffth->npoint = npoint;
    ffth->twiddles = (double complex *) malloc(npoint * sizeof(double complex));
    set_twiddles(ffth);
}

void perform_fft(fft_helper* ffth, double complex* input, double complex* output, int size, int stride) {
    if (size == 2) {
        output[0] = input[0] + input[stride];
        output[1] = input[0] - input[stride];
    }
    else {
        perform_fft(ffth, input, output, size / 2, stride * 2);
        perform_fft(ffth, input + stride, output + size / 2, size / 2, stride * 2);
        
        int k;
        double complex twop; //Twiddle factor times output
        for (k = 0; k < size / 2; k+=1) {
            twop = ffth->twiddles[k * (ffth->npoint / size)] * output[k + size / 2];
            output[k] += twop;
            output[k + size / 2] = output[k] - 2 * twop;
        }
    }
}

void fft(fft_helper* ffth, double complex* input, double complex* output) {
    perform_fft(ffth, input, output, ffth->npoint, 1);
}