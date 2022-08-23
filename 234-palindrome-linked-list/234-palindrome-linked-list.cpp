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
        vector<int> num;
        
        ListNode* curr = head;
        
        while(curr){
            num.push_back(curr->val);
            curr = curr->next;
        }
        
        vector<int> copy = num;
        
        reverse(copy.begin(),copy.end());
        
        return num == copy;
    }
};