/*
You are given an array nums of size N. A minority element is defined as the element that has a frequency closest to the median frequency of all elements in the array. If there are multiple elements that satisfy this condition, follow these rules:
Return the index the element with the smallest value among them.
If there is a tie, return the index of the first occurrence of the chosen minority element.
The array may contain negative numbers, and the size of the array N is always at least 3.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int find_minority_element_index(int N, std::vector<int>& nums) {

    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    vector<int> freqValues;
    for (auto& entry : freqMap) {
        freqValues.push_back(entry.second);
    }
    sort(freqValues.begin(), freqValues.end());

    int n = freqValues.size();
    int medianFreq = (n % 2 == 1) ? freqValues[n / 2] : (freqValues[n/2] + freqValues[(n / 2) - 1])/2;

    // Step 4: Find the closest frequency to the median
    int closestFreq = INT_MAX;
    vector<int> candidates;

    for (auto& entry : freqMap) {
        int num = entry.first;
        int freq = entry.second;
        int diff = abs(freq - medianFreq);

        if (diff < closestFreq) {
            closestFreq = diff;
            candidates = {num};  // Reset the candidates
        } else if (diff == closestFreq) {
            candidates.push_back(num);
        }
    }

    int chosenElement = *min_element(candidates.begin(), candidates.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == chosenElement) {
            return i+1;
        }
    }

    return -1;  // This should never be reached as N >= 3
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    int result = find_minority_element_index(N, nums);
    std::cout << result << std::endl;

    return 0;
}