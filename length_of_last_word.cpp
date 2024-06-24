/**
 * @brief https://leetcode.com/problems/length-of-last-word
 */

#include <iostream>

using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int curr_length = 0; // текущая длина слова
        int last_length = 0; // последняя длина слова
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ' ') {
                curr_length++;
            } else {
                /* текущий символ - пробел */
                if (curr_length) {
                    last_length = curr_length; /* запомнили длину последнего слова */
                }
                curr_length = 0;
            }
        }
        if (curr_length != 0) {
            last_length = curr_length;
        }
        return last_length;
    }
};

int main() {
    string str = "luffy is still joyboy";
    Solution test;
    test.lengthOfLastWord(str);
}
