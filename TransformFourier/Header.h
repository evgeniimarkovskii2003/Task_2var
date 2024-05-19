#pragma once
#include <complex> 
#include <vector> 
#include <cmath> 
#include <iostream> 
#include <cstdlib>
#include <ctime> 
#ifndef PI 
#define PI 3.14159265358979323846 
#endif

typedef std::complex<double> Complex;
typedef std::vector<Complex> ComplexVector;

class FFT {
public:
    FFT(int n);

    ComplexVector fft(const ComplexVector& x);

    ComplexVector ifft(const ComplexVector& x);

private:
    int N;
    ComplexVector w;
};
