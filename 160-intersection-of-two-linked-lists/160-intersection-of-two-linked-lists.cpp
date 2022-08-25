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
        int c1=0,c2=0;
        ListNode* t1 = headA,*t2 = headB;
        
        while(t1){
            c1++;
            t1 = t1->next;
        }
        while(t2){
            c2++;
            t2 = t2->next;
        }
        int diff = abs(c1-c2);
        if(c1>c2){
            while(diff--){
                headA = headA->next;
            }
        }
        else if(c1 < c2){
            while(diff--){
                headB  = headB->next;
            }
        }
        while(headA && headB){
            if(headA==headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};