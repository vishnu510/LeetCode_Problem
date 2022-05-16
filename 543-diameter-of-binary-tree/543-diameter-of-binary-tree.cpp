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
    int max_height(TreeNode* root,int* diameter){
    if(!root) return 0;
    int left = max_height(root->left,diameter);
    int right = max_height(root->right,diameter);
    *diameter = max(*diameter,left+right);
    return 1 + max(left,right);
}
int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int diameter = INT_MIN;
        int height_of_Tree = max_height(root,&diameter);
        return diameter;
    }
};