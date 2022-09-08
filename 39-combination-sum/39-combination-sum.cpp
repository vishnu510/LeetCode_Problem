class Solution {
public:
    
    void helper(int idx,int target,vector<int>& cand,vector<vector<int>>& ans,vector<int> & temp){
        
        if(idx == cand.size()){
            
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(cand[idx] <= target){
            temp.push_back(cand[idx]);
            helper(idx,target-cand[idx],cand,ans,temp);
            temp.pop_back();
        }
        helper(idx+1,target,cand,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,target,candidates,ans,temp);
        return ans;
    }
};