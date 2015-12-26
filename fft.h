//
//  fft.h
//  FFT
//
//  Created by Daniel Norman on 12/25/15.
//  Copyright © 2015 Daniel Norman. All rights reserved.
//

#ifndef fft_h
#define fft_h

#include <complex.h>
#include <math.h>
#include <stdlib.h>

typedef struct _fft_helper {
    double complex* twiddles;
    int npoint;
} fft_helper;

void setup_fft_helper(fft_helper*, int npoint);
void fft(fft_helper*, double complex* input, double complex* output);

#endif /* fft_h */
