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
        if(!head) return NULL;
        Node* headCp = NULL,*curr = head,* currCp = NULL;
        while(curr){
            currCp = new Node(curr->val,curr->next,NULL);
            curr->next = currCp;
            curr = currCp->next;
        }
        curr = head;
        while(curr){
            currCp = curr->next;
            if(curr->random){
                currCp->random = curr->random->next;
            }
            curr = currCp->next;
        }
        curr = head;
        headCp = head->next;
        while(curr){
            currCp = curr->next;
            curr->next = currCp->next;
            curr = curr->next;
            if(curr){
                currCp->next = curr->next;
            }
        }
        return headCp;
    }
};