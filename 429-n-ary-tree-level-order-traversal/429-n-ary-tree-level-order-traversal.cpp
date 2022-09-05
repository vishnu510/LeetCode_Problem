/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            
            vector<int> res;
            
            int n = q.size();
            
            for(int i=0;i<n;i++){
                res.push_back(q.front()->val);
                Node* temp = q.front();
                q.pop();
                for(Node* t:temp->children){
                    q.push(t);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};