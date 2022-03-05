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
    ListNode* sortList(ListNode* head) {
       ListNode* ptr1=head,*ptr2=head;
        vector<int>ans;
        while(ptr1!=NULL){
            ans.push_back(ptr1->val);
                ptr1 = ptr1->next;
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            ptr2->val = ans[i];
            ptr2 = ptr2->next;
        }
        return head;
    }
};