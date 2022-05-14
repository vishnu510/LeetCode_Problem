/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode * left_search = 0;
     TreeNode * right_search = 0;
     if(root==NULL){
         return 0;
     }
     if(root==p or root==q){
         return root;
     }
     left_search = lowestCommonAncestor(root->left,p,q);
     right_search = lowestCommonAncestor(root->right,p,q);
     if(left_search==NULL){
         return right_search;
     }
    if(right_search==NULL){
         return left_search;
     }
    return root;   
  }
};