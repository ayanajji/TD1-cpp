#include "TimeSeriesGenerator.h"
#include <iostream>

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

TimeSeriesGenerator::TimeSeriesGenerator(int s) : seed(s) {}

void TimeSeriesGenerator::printTimeSeries(const vector<double>& series) {
    for (double value : series) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
