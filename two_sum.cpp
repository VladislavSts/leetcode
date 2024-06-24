/**
 * @brief https://leetcode.com/problems/two-sum
 */

#include <iostream>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto* dummy = new ListNode();
        auto* current = dummy;
        int razr = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            int sum_1 = (l1 != nullptr) ? l1->val : 0;
            int sum_2 = (l2 != nullptr) ? l2->val : 0;
            int cur_sum = sum_1 + sum_2 + razr;
            razr = cur_sum / 10;

            current->next = new ListNode(cur_sum % 10);
            current = current->next;

            if (l1 != nullptr)l1 = l1->next;

            if (l2 != nullptr) l2 = l2->next;

            if (razr > 0) current->next = new ListNode(razr);
        }
        return dummy->next;
    }
};

int main() {
    // Создание тестовых списков
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;

    ListNode* result = solution.addTwoNumbers(l1, l2);

    std::cout << "Result: ";

    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    
    std::cout << std::endl;

    return 0;
}
