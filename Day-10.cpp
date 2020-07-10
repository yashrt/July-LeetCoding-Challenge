/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        stack<Node*> S;
        Node* curr = head;
        Node* tail = head;
        while(curr)
        {
            if(curr->child)
            {
                Node* child = curr->child;
                if(curr->next)
                {
                    S.push(curr->next);
                    curr->next->prev = NULL;
                }
                curr->next = child; 
                child->prev = curr;
                curr->child = NULL;
            }
            tail = curr;
            curr = curr->next;
        }
        while(!S.empty())
        {
            curr = S.top();
            S.pop();
            tail->next = curr;
            curr->prev = tail;
            while(curr)
            {
                tail = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};
