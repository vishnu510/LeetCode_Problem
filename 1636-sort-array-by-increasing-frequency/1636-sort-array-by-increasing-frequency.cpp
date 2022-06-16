class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> m;
        vector<pair<int,int>> ms;
        vector<int> ans;
        for(auto i:nums) m[i]++;
        for(auto it : m){
            ms.push_back({it.second,-it.first});
        }
        sort(ms.begin(),ms.end());
        for(auto j:ms){
            for(int k=0;k<j.first;k++){
                ans.push_back(-j.second);
            }
        }
        return ans;
    }
};