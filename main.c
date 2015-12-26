//
//  main.c
//  FFT
//
//  Created by Daniel Norman on 12/16/15.
//  Copyright © 2015 Daniel Norman. All rights reserved.
//

#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include "fft.h"

#define FFT_SIZE (1 << 2)

int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    
    fft_helper ffth;
    setup_fft_helper(&ffth, FFT_SIZE);
    
    double complex buffer[FFT_SIZE];
    buffer[0] = 1;
    buffer[1] = 0;
    buffer[2] = 1;
    buffer[3] = 1;

    double complex output[FFT_SIZE];

    fft(&ffth, buffer, output);
    for (i = 0; i < FFT_SIZE; ++i) {
        printf("%.3f + %.3fj\n", creal(output[i]), cimag(output[i]));
    }
    
    buffer[0] = 0;
    buffer[1] = 0;
    buffer[2] = 1;
    buffer[3] = 1;
    
    printf("\n");
    fft(&ffth, buffer, output);
    for (i = 0; i < FFT_SIZE; ++i) {
        printf("%.3f + %.3fj\n", creal(output[i]), cimag(output[i]));
    }
    
    return 0;
}
