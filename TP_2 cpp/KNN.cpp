#ifndef KNN_H
#define KNN_H

#include "TimeSeriesDataset.h"
#include <vector>
#include <string>

class KNN {
public:
    KNN(int k, const std::string& similarityMeasure);
    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const std::vector<int>& groundTruth);

private:
    int k;
    std::string similarityMeasure;
    int predict(const std::vector<double>& series, const TimeSeriesDataset& trainData);
    double calculateSimilarity(const std::vector<double>& x, const std::vector<double>& y);
};

#endif 
