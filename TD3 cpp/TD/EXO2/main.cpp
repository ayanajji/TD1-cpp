#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                vector<int> indices;
                indices.insert(indices.end(), i); 
                indices.insert(indices.end(), j); 
                return indices;
            }
        }
    }
}

vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap; 
    vector<int> indices;
    
    for (size_t i = 0; i < nums.size(); ++i) {
        int rest = target - nums[i];
        if (numMap.find(rest) != numMap.end()) {
          indices.insert(indices.end(), numMap[rest]); 
          indices.insert(indices.end(), i); 
            return indices;  
        }
        numMap[nums[i]] = i; 
    }
    return indices;  
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution: ["
         << indicesBruteForce[0] << ", "
         << indicesBruteForce[1] << "]" << endl;
    
    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: ["
         << indicesOptimal[0] << ", "
         << indicesOptimal[1] << "]" << endl;
    
    return 0;
}
