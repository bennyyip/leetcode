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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto slow = &head;
        auto fast = head;
        while (n--)
            fast = fast->next;
        while (fast) {
            slow = &(*slow)->next;
            fast = fast->next;
        }
        fast = (*slow)->next;
        delete *slow;
        *slow = fast;
        return head;
    }
};
