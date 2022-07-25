class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> ans;
        
        for(int i=0;i<trips.size();i++){
            ans.push_back({trips[i][1],trips[i][0]});
            ans.push_back({trips[i][2],-trips[i][0]});
        }
        sort(ans.begin(),ans.end());
        int res =0;
        
        for(int i=0;i<ans.size();i++){
            res+=ans[i].second;
            if(res > capacity){
                return false;
            }
        }
        return true;
    }
};