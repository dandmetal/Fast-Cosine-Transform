#include "FCT.h"


void fillArray(Complex *in, Complex *out,int size){
	const int size2= size*2;
	for (int i=0; i < size2 ; i++){
		if ( i < size)
			out[i]=in[i];
		else
			out[i]=0;
	}
}

double f_sin(double x){
	return - sqrt(1 - x*x);
}

void fct(Complex *in,int size,double *out){
	Complex shift;
	const int size2= size*2;
	const Complex two(2,0);
	const Complex cmp(0,1);
	double s,norm,calc,trig;
	Complex temp[size2];
	fillArray(in,temp,size);
	fft(temp,size2);
	for (int i=0; i < size ; i++){
		s = (i == 0) ? sqrt(.5) : 1.;
		norm=s * 0.5 * sqrt(2./size);
		Complex ii(i,0);
		calc= (- PI * i / (2 * size));
		trig=cos(calc);
		shift=two * ( trig + cmp*f_sin(trig));
		out[i]=norm *real(temp[i] * shift); 
	}
}

