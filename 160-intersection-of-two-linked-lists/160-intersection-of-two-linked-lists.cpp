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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1=0,c2=0,diff=0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1!=NULL){
            c1++;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            c2++;
            temp2 = temp2->next;
        }
        

        diff  = abs(c1-c2);

        if(c1>c2){
            while(diff--){
                headA = headA->next;
            }
        }
        else{
            while(diff--){
                headB = headB->next;
            }
        }
        

        while(headA!=NULL and headB!=NULL){
            if(headA == headB){
                return headA;
            }
             headA = headA->next;
             headB = headB->next;
        }
        return NULL;
     
    }
};