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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow;
        ListNode* cur;

        cur = head;
        slow = head;

        bool odd = false;
        while (cur) {
            if (odd) {
                slow = slow->next;
            }
            odd = !odd;
            cur = cur->next;
        }
        return slow;
    }
};