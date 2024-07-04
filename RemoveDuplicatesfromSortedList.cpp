#include <iostream>

/**
 * @brief https://leetcode.com/problems/remove-duplicates-from-sorted-list
 * 
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode *temp1 = head, *temp2 = temp1->next;

        while (temp2) {
            if (temp1->val == temp2->val) {
                temp1->next = temp2->next;
                temp2 = temp1->next;
            } else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};