class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]) return a[1]<b[1];
        else{
            return a[0]>b[0];
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> ans;
        for(auto man:people){
            ans.insert(ans.begin()+man[1],man);
        }
        return ans;
    }
};