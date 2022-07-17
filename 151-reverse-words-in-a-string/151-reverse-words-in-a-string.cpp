class Solution {
public:
    string reverseWords(string s) {
       
        stringstream str(s);
        vector<string> ans;
        string res ="";
        string word;
        while(str>>word){
            ans.push_back(word);
        }
        
        reverse(ans.begin(),ans.end());
        
        for(auto i:ans){
            if(res.size()) res+=' ';
            res+=i;
        }
        return res;
    }
};