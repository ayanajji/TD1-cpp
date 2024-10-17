#include "SearchingAlgorithm.h"

// Static member initialization
int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearches = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

void SearchingAlgorithm::calculateAverage() {
    if (totalSearches > 0) {
        averageComparisons = static_cast<double>(totalComparisons) / totalSearches;
    }
}

void SearchingAlgorithm::displaySearchResults(ostream& os, int result, int target) {
    os << "Searching for " << target << ": ";
    totalComparisons += numberComparisons;
    totalSearches++;
    calculateAverage();
    
    if (result != -1) {
        os << "Item found at index: " << result << endl;
    } else {
        os << "Item not found." << endl;
    }
    os << "Total comparisons: " << totalComparisons << endl;
    os << "Average comparisons: " << averageComparisons << endl;
}

int LinearSearch::search(const vector<int>& arr, int target) {
    numberComparisons = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        numberComparisons++;
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int JumpSearch::search(const vector<int>& arr, int target) {
    numberComparisons = 0;
    size_t n = arr.size();
    size_t step = static_cast<size_t>(sqrt(n));  
    size_t prev = 0;

    while (arr[min(step, n) - 1] < target) {
        numberComparisons++;
        prev = step;
        step += static_cast<size_t>(sqrt(n));
        if (prev >= n) return -1;
    }

    for (size_t i = prev; i < min(step, n); i++) {
        numberComparisons++;
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int BinarySearch::search(const vector<int>& arr, int target) {
    numberComparisons = 0;
    size_t left = 0, right = arr.size() - 1;

    while (left <= right) {
        numberComparisons++;
        size_t mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}
