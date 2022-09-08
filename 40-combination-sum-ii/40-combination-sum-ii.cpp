class Solution {
public:
    
    void helper(int idx,int target,vector<vector<int>>& ans,vector<int>& cand,vector<int>& temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<cand.size();i++){
            if(i > idx && cand[i] == cand[i-1]) continue;
            if(cand[i] > target) break;
            temp.push_back(cand[i]);
            helper(i+1,target-cand[i],ans,cand,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,target,ans,candidates,temp);
        return ans;
    }
};