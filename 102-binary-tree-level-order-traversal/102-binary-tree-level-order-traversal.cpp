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
    vector<vector<int>> levelOrder(TreeNode* root) {
       if(root==NULL){
           return {};
       }
       vector<vector<int>> ans;
       queue<TreeNode*> q;
       q.push(root);
       TreeNode* curr; 
        while(!q.empty()){
            
            int len = q.size();
            vector<int> res;
            for(int i=0;i<len;i++){
                
                curr = q.front();
                q.pop();
                res.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(res);
        }
        return ans;
    }
};