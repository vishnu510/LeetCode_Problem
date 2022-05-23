class Solution {
public:
    string reverseWords(string s) {
       stringstream str(s);
    string ans = "";
    string word;
    vector<string> vec;
    while(str>>word){
         vec.push_back(word);
    }
     reverse(vec.begin(),vec.end());
     for(auto i:vec){
         if(ans.size()) ans+= ' ';
         ans+=i;
     }
     return ans; 
    }
};