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
    bool isPalindrome(ListNode* head) {
         stack<int> st;
   bool flag = true;
    ListNode *temp1 = head;
   while (temp1!=NULL)
   {   
      
       st.push(temp1->val);
        temp1 = temp1->next;
   }
   while (head!=NULL)
   {   
       
       if(st.top()!=head->val){
           flag = false;
       }
       head = head->next;
       st.pop();
   }
 
   return flag;
        
    }
};