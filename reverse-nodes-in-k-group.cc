/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define REP(i, n) for (size_t i = 0; i < n; ++i)
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode **p = &head;

        for (;;) {
            ListNode *q = *p;
            REP(i, k) {
                if (!q)
                    return head;
                q = q->next;
            }
            q = *p;
            ListNode *l = q;
            ListNode *r = q;
            ListNode *t;
            REP(i, k) {
                t = q->next;
                q->next = l;
                l = q;
                q = t;
            }
            *p = l;
            r->next = q;

            REP(i, k) { p = &(*p)->next; }
        }
        return head;
    }
};

