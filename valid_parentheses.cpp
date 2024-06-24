/**
 * @brief https://leetcode.com/problems/valid-parentheses
 */

#include <iostream>
#include <string>
#include <stack>
#include <map>

using std::map;
using std::stack;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    bool isValid(string s)
    {
        stack <char> bracket_stack;

        map<char, char> bracket_map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (auto symbol : s)
        {
            if (symbol == '(' || symbol == '[' || symbol == '{') {
                bracket_stack.push(symbol);
            }
            else {
                // закрывающий тип скобки -> должен совпасть с последней открытой скобкой
                if (!bracket_stack.empty() && bracket_map[symbol] == bracket_stack.top()) {
                    // типы совпадают -> удаляем скобку
                    bracket_stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        // после всех проходов стек должен быть пустой (true)
        return bracket_stack.empty();
    }
};

/*
    Input: s = "()"
    Output: true

    Input: s = "()[]{}"
    Output: true

    Input: s = "(]"
    Output: false
*/

int main()
{
    auto* result = new Solution();

    string test1 = "()";
    cout << "Res: " << result->isValid(test1) << endl;

    string test2 = "()[]{}";
    cout << "Res: " << result->isValid(test2) << endl;

    string test3 = "(]";
    cout << "Res: " << result->isValid(test3) << endl;

    string test4 = "){";
    cout << "Res: " << result->isValid(test4) << endl;
}
