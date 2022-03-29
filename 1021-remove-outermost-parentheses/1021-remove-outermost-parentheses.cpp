class Solution {
public:
    string removeOuterParentheses(string s) { 
        int count=0;
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(count++){
                    str+='(';
                }
            }
            else{
                if(--count){
                    str+=')';
                }
            }
        }
        return str;
    }
};