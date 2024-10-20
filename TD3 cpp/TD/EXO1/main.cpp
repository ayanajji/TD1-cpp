#include <iostream>
#include <vector>
#include <map>

using namespace std;
void countFrequencyBruteForce(const vector<int>& numbers) {
    int size = numbers.size();  
    for (int i = 0; i < size; i++) {
        bool duplique = false;

        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                duplique = true;
                break;
            }
        }

        if (duplique) {
            continue;
        }

        int cpt = 1;
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] == numbers[j]) {
                cpt++;
            }
        }

        cout << numbers[i] << " : " << cpt << " times" << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequencyMap;
    
    for (size_t i = 0; i < numbers.size(); i++) {  
        if (frequencyMap.find(numbers[i]) == frequencyMap.end()) {
            frequencyMap[numbers[i]] = 1;  
        } else {
            frequencyMap[numbers[i]]++;  
        }
    }
    
    return frequencyMap;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    // Test countFrequencyBruteForce
    cout << "Frequency (Brute Force): " << endl;
    countFrequencyBruteForce(numbers);

    // Test countFrequencyOptimal
    cout << "\nFrequency (Optimal): " << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << " : " << entry.second << " times" << endl;
    }

    return 0;
}