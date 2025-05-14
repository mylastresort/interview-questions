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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode();
        ListNode* head = ret;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        while (head1 || head2) {
            if (head1) {
                head->val += head1->val;
                head1 = head1->next;
            }
            if (head2) {
                head->val += head2->val;
                head2 = head2->next;
            }
            if (head1 || head2 || head->val / 10) {
                head->next = new ListNode();
                if (head->val >= 10) {
                    head->next->val = head->val / 10;
                    head->val = head->val % 10;
                }
                head = head->next;
            }
        }
        return ret;
    }
};