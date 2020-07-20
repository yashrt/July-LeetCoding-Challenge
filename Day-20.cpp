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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        
        while(head->val==val)
        {
            if(head->next)
                head = head->next;
            else
                return NULL;
        }

        ListNode* pre = head;
        ListNode* curr = head->next;
        
        while(curr)
        {
            if(curr->val==val)
                pre->next = curr->next;
            else
                pre = curr;

            curr = curr->next;
        }
        return head;
    }
};
