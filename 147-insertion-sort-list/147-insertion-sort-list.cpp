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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* p1=head,*p2=head;
        vector<int> ans;
        while(p1!=NULL){
            ans.push_back(p1->val);
            p1 = p1->next;
        }
        int i,j,key;
        for(int i=1;i<ans.size();i++){
            key = ans[i];
            j = i-1;
            while(j>=0 && ans[j]>key){
                ans[j+1] = ans[j];
                j = j-1;
            }
            ans[j+1] = key;
        }
        for(int i=0;i<ans.size();i++){
            p2->val = ans[i];
            p2  =p2->next;
        }
        return head;
    }
};