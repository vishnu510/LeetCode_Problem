class Solution {
public:
    
    bool ispalindrome(string s,int start,int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    
    void helper(int idx, string s,vector<vector<string>>& ans,vector<string>& temp){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx;i<s.size();i++){
            if(ispalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(0,s,ans,temp);
        return ans;
    }
};