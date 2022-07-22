class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        if(nums.empty() || nums[0].empty() ) return {};
        
        vector<int> ans;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            
            auto[x,y] = q.front();
            ans.push_back(nums[x][y]);
            if(x+1<nums.size() && y==0){
                
                q.push({x+1,y});
            }
            if(y+1< nums[x].size()){
                q.push({x,y+1});
            }
            q.pop();
        }
        return ans;
    }
};