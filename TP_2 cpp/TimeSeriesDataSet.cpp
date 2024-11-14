#include "TimeSeriesDataset.h"
#include <numeric>
#include <cmath>

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series) {
    std::vector<double> series_copy = series;
    if (znormalize) {
        zNormalizeSeries(series_copy);
    }
    data.push_back(series_copy);
    ++numberOfSamples;
    if (series.size() > maxLength) {
        maxLength = series.size();
    }
}

void TimeSeriesDataset::zNormalizeSeries(std::vector<double>& series) {
    double mean = std::accumulate(series.begin(), series.end(), 0.0) / series.size();
    double sq_sum = std::inner_product(series.begin(), series.end(), series.begin(), 0.0);
    double stdev = std::sqrt(sq_sum / series.size() - mean * mean);
    for (double& val : series) {
        val = (val - mean) / stdev;
    }
}
