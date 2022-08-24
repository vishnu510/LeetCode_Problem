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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *middle = head,*temp = head;
        int n =0;
        while(temp){
            n++;
            temp = temp->next;
        }
        temp = head;
        if(n%2==0){
            n = n/2 +1;
            while(--n){
                temp = temp->next;
            }
            middle = temp;
        }
        else{
            temp = head;
            n = n/2;
            while(n--){
                temp = temp->next;
            }
            middle = temp;
        }
        return middle;
    }
};