class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(),m=arr2.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr1[i]]++;
        }
        vector<int> ans,res;
        for(int i=0;i<m;i++){
            while(mp[arr2[i]]>0){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
                if(mp[arr2[i]]==0){
                    mp.erase(arr2[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(mp[arr1[i]]>0){
                res.push_back(arr1[i]);
            }
        }
        sort(res.begin(),res.end());
        ans.insert(ans.end(),res.begin(),res.end());
        return ans;
    }
};