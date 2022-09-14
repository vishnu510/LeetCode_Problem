/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans =0;
    void rec(TreeNode* root,int count){
        if(root==NULL) return;
        count ^= (1<<root->val);
        if(!root->right && !root->left){
            
            ans += (count & (count-1)) == 0;
        }
        rec(root->left,count);
        rec(root->right,count);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        rec(root,0);
        return ans;
    }
};