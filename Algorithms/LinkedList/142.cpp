// O(N)
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
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return nullptr;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (!fast->next || !fast->next->next)
            return nullptr;
        
        ListNode *start = fast;
        while (head != start)
        {
            start = start->next;
            head = head->next;
        }
        
        return head;
    }
};