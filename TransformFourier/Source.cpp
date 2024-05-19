#include "Header.h"

FFT::FFT(int n) : N(n) {
    if ((N % 2 != 0) && (N % 3 != 0) && (N % 5 != 0)) {
        throw std::invalid_argument("Length of FFT must be a multiple of 2, 3, or 5");
    }
    w.resize(N / 2);
    for (int i = 0; i < N / 2; ++i) {
        w[i] = std::polar(1.0, -2 * PI * i / N);
    }
}

ComplexVector FFT::fft(const ComplexVector& x) {
    ComplexVector FFT(N);
    for (int i = 0; i < N; ++i) {
        FFT[i] = 0;
        for (int j = 0; j < N; ++j) {
            FFT[i] += x[j] * w[(j * i) % (N / 2)];
        }
    }
    return FFT;
}

ComplexVector FFT::ifft(const ComplexVector& x) {
    ComplexVector IFFT(N);
    for (int i = 0; i < N; ++i) {
        IFFT[i] = 0;
        for (int j = 0; j < N; ++j) {
            IFFT[i] += x[j] * std::conj(w[(i * j) % (N / 2)]) / Complex(N, 0);
        }
    }
    return IFFT;
}