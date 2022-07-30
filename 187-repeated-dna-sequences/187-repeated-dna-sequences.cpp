class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string> ans;
        
        if(s.size()<10) return ans;
        
        for(int i=0;i<s.size()-9;i++){
            
            mp[s.substr(i,10)]++;
        }
        
        for(auto c:mp){
            if(c.second>1){
                ans.push_back(c.first);
            }
        }
        return ans;
    }
};