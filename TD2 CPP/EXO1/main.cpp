#include "SearchingAlgorithm.h"

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;

    LinearSearch linearSearch;
    int linearResult = linearSearch.search(arr, target);
    linearSearch.displaySearchResults(cout, linearResult, target);

    JumpSearch jumpSearch;
    int jumpResult = jumpSearch.search(arr, target);
    jumpSearch.displaySearchResults(cout, jumpResult, target);

    BinarySearch binarySearch;
    int binaryResult = binarySearch.search(arr, target);
    binarySearch.displaySearchResults(cout, binaryResult, target);

    return 0;
}
