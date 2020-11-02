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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *ret = new ListNode();
        ListNode *cur = head;
        ListNode *prev, *next;
        while (cur)
        {
            prev = ret;
            next = ret->next;
            while (next)
            {
                if (next->val > cur->val)
                    break;
                prev = next;
                next = next->next;
            }
            
            ListNode *nextIter = cur->next;
            prev->next = cur;
            cur->next = next;
            cur = nextIter;
        }
        
        return ret->next;
    }
};