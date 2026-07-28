/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr ptr) {}
 *     ListNode(int x) : val(x), next(nullptr ptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* odd_start = head;
        ListNode* even_start = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* tmp = head->next->next;

        while (tmp && tmp->next) {
            odd->next = tmp;
            odd = odd->next;
            even->next = tmp->next;
            even = even->next;
            tmp = tmp->next->next;
        }
        if (tmp) {
            odd->next = tmp;
            odd = odd->next;
        }
        even->next = nullptr;
        odd->next = even_start;
        return odd_start;
    }
};