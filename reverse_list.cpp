#include <iostream>
#include <vector>

/**
 * @brief Развернуть связный список
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        ListNode *rev = nullptr, *temp_next, *curr = head;

        while (curr) {
            temp_next = curr->next;
            curr->next = rev;
            rev = curr;
            curr = temp_next;
        }

        return rev;
    }
};

ListNode* createList(const std::vector<int> &values) {
    if (values.empty()) return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode *head) {
    ListNode *current = head;

    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    std::cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    std::cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}
