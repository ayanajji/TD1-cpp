#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>

class TimeSeriesDataset {
public:
    TimeSeriesDataset(bool znormalize, bool isTrain);
    void addTimeSeries(const std::vector<double>& series);
    void zNormalizeSeries(std::vector<double>& series);

private:
    bool znormalize;
    bool isTrain;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    int maxLength;
    int numberOfSamples;
};
#endif