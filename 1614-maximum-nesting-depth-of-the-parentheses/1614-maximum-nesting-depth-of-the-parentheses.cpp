class Solution {
public:
    int maxDepth(string s) {
        
        stack<char> st;
        int maximum = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                int curr = st.size();
                maximum = max(maximum,curr);
                    st.pop();
            }
        }
        return maximum;
    }
};