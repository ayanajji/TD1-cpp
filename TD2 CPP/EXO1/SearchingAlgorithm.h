#ifndef SEARCHING_ALGORITHM_H
#define SEARCHING_ALGORITHM_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SearchingAlgorithm {
public:
    int numberComparisons;
    static int totalComparisons;
    static int totalSearches;
    static double averageComparisons;

    SearchingAlgorithm();
    virtual int search(const vector<int>& arr, int target) = 0;
    void calculateAverage();
    void displaySearchResults(ostream& os, int result, int target);
};

class LinearSearch : public SearchingAlgorithm {
public:
    int search(const vector<int>& arr, int target) override;
};

class JumpSearch : public SearchingAlgorithm {
public:
    int search(const vector<int>& arr, int target) override;
};

class BinarySearch : public SearchingAlgorithm {
public:
    int search(const vector<int>& arr, int target) override;
};

#endif // SEARCHING_ALGORITHM_H
