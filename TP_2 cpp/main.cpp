#include "SinWaveGenerator.h"
#include "StepGenerator.h"
#include "GaussianGenerator.h"
#include "TimeSeriesGenerator.h"
#include "KNN.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    TimeSeriesDataset trainData(false, true), testData(false, false);
    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;

    vector<double> gaussian1 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian1);

    vector<double> gaussian2 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian2);

    vector<double> sin1 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin1);

    vector<double> sin2 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin2);

    vector<double> step1 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step1);

    vector<double> step2 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step2);

    vector<int> ground_truth;
    testData.addTimeSeries(gsg.generateTimeSeries(11));
    ground_truth.push_back(0);

    testData.addTimeSeries(swg.generateTimeSeries(11));
    ground_truth.push_back(1);

    testData.addTimeSeries(stg.generateTimeSeries(11));
    ground_truth.push_back(2);

    KNN knn_1(1, "dtw");
    cout << knn_1.evaluate(trainData, testData, ground_truth) << endl;

    KNN knn_2(2, "euclidean_distance");
    cout << knn_2.evaluate(trainData, testData, ground_truth) << endl;
    KNN knn_3(3, "euclidean_distance");
    cout << knn_3.evaluate(trainData, testData, ground_truth) << endl;

    return 0;
}