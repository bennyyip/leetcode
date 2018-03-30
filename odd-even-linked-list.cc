/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (head) {
            ListNode *p = head, *q = head->next, *evenhead = q;
            while (q && q->next) {
                p->next = q->next;
                p = p->next;
                q->next = p->next;
                q = q->next;
            }
            p->next = evenhead;
        }
        return head;
    }
};
