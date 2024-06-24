/**
 * @brief https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
 */

#include <iostream>
#include <string>

using std::string;
using std::cout;

class Solution {
public:
    int strStr(string haystack, string needle) {
      int size_haystack = haystack.length();
      int size_needle = needle.length();

      if (size_needle == 0) {
        return 0;
      }

      for (int i = 0; i <= size_haystack - size_needle; ++i) {
        int j = 0;
        for ( ; j < size_needle; ++j) {
          if (haystack[i + j] != needle[j]) {
            break;
          }
        }
        if (j == size_needle) {
          return i;
        }
      }
      return -1;
    }
};

int main() {
 string test1 = "leetcode";
 string test2 = "c";

 Solution *test = new Solution();
 cout << test->strStr(test1, test2);
}
