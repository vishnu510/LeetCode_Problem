/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      if(!head)
            return NULL;
        Node* head_cp = NULL;
        Node* curr = head;
        Node* curr_cp = NULL;

        while(curr!=NULL){
            curr_cp = new Node(curr->val,curr->next,NULL);
            curr->next = curr_cp;
            curr = curr_cp->next;
        }

        curr = head;
        while(curr!=NULL){
            curr_cp = curr->next;
            if(curr->random)
                curr_cp->random = curr->random->next;
            curr = curr_cp->next;
        }

        curr = head;
        head_cp = head->next;
        while(curr!=NULL){
            curr_cp = curr->next;
            curr->next = curr_cp->next; 
            curr = curr->next;
            if(curr)
                curr_cp->next = curr->next;
        }
        return head_cp;
    }
};