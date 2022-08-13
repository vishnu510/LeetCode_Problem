class Solution {
public:
    bool checkString(unordered_map<string,int> mp,string s,int wordCount){
        
        for(int i=0;i<s.size();i+=wordCount){
            string w = s.substr(i,wordCount);
            
            if(mp.find(w)!=mp.end()){
                if(--mp[w] == -1){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int sSize = s.size();
        int wind = words[0].size();
        int windowSize = wind*words.size();
        
        unordered_map<string,int> mp;
        
        for(auto i:words){
            mp[i]++;
        }
        vector<int> res;
        int i=0;
        while(i+windowSize <= sSize){
            if(checkString(mp,s.substr(i,windowSize),wind)){
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};