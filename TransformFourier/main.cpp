#include "Header.h"
int main() {
    srand(time(0));
    int N = 16;
    FFT fft(N);

    ComplexVector input(N);
    for (int i = 0; i < N; ++i) {
        input[i] = Complex(rand() % 10, rand() % 10);
    }

    ComplexVector transformation = fft.fft(input);
    ComplexVector transformationReverse = fft.ifft(transformation);

    double error = 0.0;
    for (int i = 0; i < N; ++i) {
        error += std::abs(transformation[i] - transformationReverse[i]);
    }

    std::cout << "Average error: " << error / N << std::endl;

    return 0;
}