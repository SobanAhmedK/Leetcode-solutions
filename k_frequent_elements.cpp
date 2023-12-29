// //Given an integer array nums and an integer k, return the k most frequent elements. 
//You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }

        vector<pair<int, int>> freqPairs;
        for (auto it = m.begin(); it != m.end(); it++) {
            freqPairs.push_back({it->first, it->second});
        }

        sort(freqPairs.begin(), freqPairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; 
        });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqPairs[i].first);
        }

        return result;
    }
};
