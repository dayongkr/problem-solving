/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* result;
    void rec(ListNode* prev, ListNode* cur) {
        if (!cur) {
            result = prev;
            return;
        }
        rec(cur, cur->next);
        cur->next = prev;
        prev->next = nullptr;
    }
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        rec(head, head->next);
        return result;
    }
};