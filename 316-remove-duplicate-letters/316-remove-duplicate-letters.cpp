class Solution {
public:
    string removeDuplicateLetters(string s) {
    vector<int> v1(26,0);
        for(int i=0;i<s.size();i++){
            v1[s[i]-'a']++;
        }
        stack<char> stk;
        vector<bool> visited(26,false);
        for(int i=0;i<s.size();i++){
            v1[s[i]-'a']--;
            if(visited[s[i]-'a']) continue;
            while(stk.size()>0 and stk.top()>s[i] and v1[stk.top()-'a']>0 ){
                visited[stk.top()-'a'] = false;
                stk.pop();
            }
            stk.push(s[i]);
            visited[s[i]-'a'] =true;
        }
        string res = "";
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};