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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergeNode,*temp;
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    if(list1->val<=list2->val){
        mergeNode = list1;
        list1 = list1->next;
    }
    else{
        mergeNode = list2;
        list2 = list2->next;
    }
     temp =mergeNode;
     while (list1 and list2)
     {
         if(list1->val<=list2->val){
             temp->next = list1;
             temp = temp->next;
             list1 = list1->next;
         }
         else{
            temp->next = list2;
             temp = temp->next;
             list2 = list2->next;
         }
     }
     temp->next = (!list1)?list2:list1;
     return mergeNode;
    }
};