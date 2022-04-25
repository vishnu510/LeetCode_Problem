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
        if(head == NULL || head->next == NULL){
            return head;
        }
   
        ListNode * temp = head;
        int len =0;
        while(temp!= NULL){
            temp = temp->next;
            len++;
        }
        if ( k%len == 0){
            return head;
        }
        int n ;
        n = k%len;
        
        
        
        ListNode* slow = head;
        ListNode * fast = head;
        
        
        
        for(int i = 1 ; i < (len-n) ; i++){
            slow = slow->next;
            fast = fast->next;
        }
        while(slow->next != NULL){
            slow = slow->next;
            
        }
        slow->next = head;
        head = fast->next;
        fast->next = NULL;
        
        return head;
    }
};