#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H
#include <vector>

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double moyenne;
    double ecart_type;

public:
    GaussianGenerator();
    GaussianGenerator(double moyenne, double ecart_type, int seed);

    std::vector<double> generateTimeSeries(int size) override;
};

#endif
