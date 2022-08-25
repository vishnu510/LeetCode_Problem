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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        int count =0;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
       
        ListNode* prev = dummy,*curr = dummy,*nextNode=dummy;
         while(curr->next){
            count++;
            curr = curr->next;
        }
        while(count >= k){
            curr = prev->next;
            nextNode = curr->next;
            for(int i=1;i<k;i++){
                curr->next = nextNode->next;
                nextNode->next = prev->next;
                prev->next = nextNode;
                nextNode = curr->next;
            }
            prev = curr;
            count -= k;
        }
        return dummy->next;
    }
};