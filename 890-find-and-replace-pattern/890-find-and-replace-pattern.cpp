class Solution {
public:
    vector<int> check(string pattern){
        
        
        if(pattern.size()==0) return {};
        vector<int> temp;
        
        unordered_map<char,int> mp;
        int idx =0;
        for(int i=0;i<pattern.size();i++){
            if(mp.find(pattern[i])==mp.end()){
                mp.insert({pattern[i],idx++});
                temp.push_back(mp[pattern[i]]);
            }
            else{
                temp.push_back(mp[pattern[i]]);
            }
        }
        return temp;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<int> temp = check(pattern);
        
        vector<string> ans;
        
        for(int i=0;i<words.size();i++){
            vector<int> patternWord = check(words[i]);
            if(temp==patternWord){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};