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
    void check(TreeNode* root,vector<int> &vec){
        if(!root) return;
        if(!(root->left || root->right)){
            vec.push_back(root->val);
        }
        check(root->left,vec);
        check(root->right,vec);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> rootA{};
        vector<int> rootB{};
        check(root1,rootA);
        check(root2,rootB);
        return rootA==rootB;
    }
};