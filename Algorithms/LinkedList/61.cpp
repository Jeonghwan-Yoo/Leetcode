// O(N)
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;
        
        ListNode *cur = head;
        int sz = 1;
        while (cur->next)
        {
            cur = cur->next;
            ++sz;
        }

        cur->next = head;
        k %= sz;
        
        for (int i = 0; i < sz - k; ++i)
            cur = cur->next;
        head = cur->next;
        cur->next = nullptr;
        
        return head;
    }
};