#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * @brief https://leetcode.com/problems/contains-duplicate-ii
 * 
 */

using std::vector;
using std::unordered_map;

/**
 * unordered_map:
 * 
 */

class Solution {
public:
    bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
        unordered_map<int, int> index_map;

        for (int i = 0; i < nums.size(); ++i) {
            if (index_map.find(nums[i]) != index_map.end()) {
                if (i - index_map[nums[i]] <= k) {
                    return true;
                }
            }
            index_map[nums[i]] = i;
        }

        return false;
    }
};
