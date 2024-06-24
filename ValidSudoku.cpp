/**
 * @brief https://leetcode.com/problems/valid-sudoku
 */

#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        vector<set<char>> boxes(9);

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char num = board[row][col];
                if (num == '.') {
                    continue; // Пропускаем пустые ячейки
                }

                // Индекс подбокса
                int boxIndex = (row / 3) * 3 + (col / 3);

                // Проверка строки
                if (rows[row].find(num) != rows[row].end()) {
                    return false;
                }
                rows[row].insert(num);

                // Проверка столбца
                if (cols[col].find(num) != cols[col].end()) {
                    return false;
                }
                cols[col].insert(num);

                // Проверка подбокса
                if (boxes[boxIndex].find(num) != boxes[boxIndex].end()) {
                    return false;
                }
                boxes[boxIndex].insert(num);
            }
        }
        return true;
    }
};

