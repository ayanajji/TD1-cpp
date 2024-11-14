#include "GaussianGenerator.h"
#include "TimeSeriesGenerator.h"
#include <cmath>
#include <cstdlib>

GaussianGenerator::GaussianGenerator(double moyenne, double ecart_type, int seed)
    : TimeSeriesGenerator(seed), moyenne(moyenne), ecart_type(ecart_type) {}

std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    srand(seed);

    for (int i = 0; i < size; ++i) {
        double u1 = ((double) rand() / RAND_MAX);
        double u2 = ((double) rand() / RAND_MAX);
        double z0 = sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2);
        double value = moyenne + z0 * ecart_type; 
        series.push_back(value);
    }

    return series;
}
