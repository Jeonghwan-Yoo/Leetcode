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
    ListNode *GetMid(ListNode *head)
    {
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            head = head->next;
            fast = fast->next->next;
        }
        ListNode *mid = head->next;
        head->next = nullptr;
        
        return mid;
    }
    ListNode *Merge(ListNode *list1, ListNode *list2)
    {
        ListNode tmpHead(0);
        ListNode *cur = &tmpHead;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if (list1)
            cur->next = list1;
        else
            cur->next = list2;
        
        return tmpHead.next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *mid = GetMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        return Merge(left, right);
    }
};