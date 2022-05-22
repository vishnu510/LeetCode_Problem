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
  vector<int> nums;
vector<int> kthMax(TreeNode* root){
   if(!root) return {};
   nums.push_back(root->val);
   kthMax(root->left);
   kthMax(root->right);
   return nums;
}
int kthSmallest(TreeNode* root, int k) {
        vector<int> ans = kthMax(root);
        int largest = -1;
        int n = ans.size();
    for(int i =0;i<n;i++){
        largest = max(largest,ans[i]);
    }
    
    vector<int> freq(largest+1,0);
    
    for(int x =0;x<n;x++){
        freq[ans[x]]++;
    }
    int j=0;
    for(int i=0;i<=largest;i++){
       while(freq[i]>0){
           ans[j]=i;
           freq[i]--;
           j++;
       }
    }
        return ans[k-1];
    }
};