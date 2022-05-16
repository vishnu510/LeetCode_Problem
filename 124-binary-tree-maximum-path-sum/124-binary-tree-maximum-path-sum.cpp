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
       int getMaxSum(TreeNode* root, int& sum) {
   
    if(root == NULL){
        return 0;
    }
   
    int left_sum = root->val + getMaxSum( root->left , sum );
    int right_sum = root->val + getMaxSum( root->right , sum );
    
    sum = max({
                sum,           
                root->val,      
                left_sum,        
                right_sum,        
                left_sum + right_sum - root->val   
            });
    
   
    return max({ left_sum , right_sum , root->val });
}

int maxPathSum(TreeNode* root) {
    int sum INT_MIN;
    getMaxSum(root, sum);
    return sum;
    }
};