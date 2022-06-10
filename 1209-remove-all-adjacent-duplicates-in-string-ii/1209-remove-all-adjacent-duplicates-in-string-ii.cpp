class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty() || st.top().first != s[i]) st.push({s[i],1});
            else if(st.top().first == s[i]){
                if(st.top().second + 1 == k){
                    while(!st.empty() && st.top().first == s[i]) st.pop();
                }else{
                    st.push({s[i],st.top().second + 1});
                }
            }
        }
        
        string res = "";
        while(!st.empty()){
            res+=st.top().first;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};