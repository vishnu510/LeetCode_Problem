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
         if(!head and !head->next){
        return head;
    }
    ListNode* temp = head;
    ListNode* middle = head;
    int count =0;
    while(temp){
        count++;
        temp = temp->next;
    }
    temp = head;
    if(count%2==0){
        count = count/2 +1;
        while(--count){
            temp = temp->next;
        }
        middle = temp;
    }
    
    else{
        temp = head;
        count = count/2;
        while(count--){
            temp = temp->next;
        }
        middle = temp;
    }
    return middle;
        
    }
};