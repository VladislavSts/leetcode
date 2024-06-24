/**
 * @brief https://leetcode.com/problems/search-insert-position
 */

#include <iostream>
#include <vector>

using std::vector;

/* Линейный поиск */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
          if (nums[i] == target) {
            return i;
          }
          if (target < nums[i]) {
            return i;
          }
          idx++;
        }
        return nums.size();
    }
};

/* Бинарный поиск */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int l = 0;
      int r = nums.size() - 1;
      int mid;

      while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == target) {
          return mid;
        }
        if (nums[mid] > target) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      return l;
    }
};
