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
    void dfs(TreeNode* root,int currDepth,int &maxDepth,int &ans){
        if(root==NULL) return;
        dfs(root->left,currDepth+1,maxDepth,ans);
        if(currDepth>maxDepth){
            ans = root->val;
            maxDepth = currDepth;
        }
        dfs(root->right,currDepth+1,maxDepth,ans);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth =0;
        int ans = root->val;
        dfs(root,0,maxDepth,ans);
        return ans;
        
    }
};