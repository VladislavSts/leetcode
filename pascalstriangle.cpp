#include <iostream>
#include <vector>

/**
 * @brief https://leetcode.com/problems/pascals-triangle
 * 
 */

using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        for (size_t i = 0; i < numRows; ++i) {
            res[i].resize(i + 1, 1);
        }

        for (size_t i = 2; i < numRows; ++i) {
            for (size_t j = 1; j < res[i].size() - 1; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        
        return res;
    }
};




