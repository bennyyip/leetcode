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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        struct Cmp {
            bool operator()(const ListNode *x, const ListNode *y) {
                return x->val > y->val;
            };
        };
        priority_queue<ListNode *, vector<ListNode *>, Cmp> pq;
        for (auto x : lists) {
            if (x)
                pq.push(x);
        }
        ListNode *head = NULL, **cur = &head;
        while (!pq.empty()) {
            *cur = pq.top();
            pq.pop();
            ListNode *x = (*cur)->next;
            if (x)
                pq.push(x);
            cur = &((*cur)->next);
        }
        return head;
    }
};
