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
    vector<vector<int>> ans;
    vector<int> route;
    void dfs(TreeNode* root,int curr,int target){
        if(root==NULL) return;
        
        curr += root->val;
        route.push_back(root->val);
        if(curr == target && !root->left && !root->right){
            ans.push_back(route);
        }
        dfs(root->left,curr,target);
        dfs(root->right,curr,target);
        route.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,0,targetSum);
        return ans;
    }
};