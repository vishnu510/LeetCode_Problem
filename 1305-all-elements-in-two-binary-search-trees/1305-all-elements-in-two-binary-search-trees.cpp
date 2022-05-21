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
   
    void inorder(TreeNode* root,vector<int>&vec){
        if(root)
        {
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
        }
    }
    void mergetrees(vector<int> v1,vector<int>v2,vector<int>&mergedtree){
        int i=0,j=0,k=0;
        while(i<v1.size() and j<v2.size()){
            if(v1[i]<v2[j]){
                mergedtree[k++] = v1[i++];
            }
            else{
                mergedtree[k++] = v2[j++];
            }
        }
        while(i<v1.size()){
            mergedtree[k++] = v1[i++];
        }
        while(j<v2.size()){
            mergedtree[k++] = v2[j++];
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1,tree2;
        inorder(root1,tree1);
        inorder(root2,tree2);
        vector<int> mergedtree(tree1.size()+tree2.size());
        mergetrees(tree1,tree2,mergedtree);
        return mergedtree;
    }
};