#ifndef FCT_H
#define FCT_H

#include "FFT.h"
#include <math.h>

using namespace std;


void fillArray(Complex *in, Complex *out,int size);
double f_sin(double x);
void fct(Complex *in,int size,double *out);

#endif