class Solution {
public:
    string reverseWords(string s) {
        int start = 0,end=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                end = i;
                reverse(s.begin()+start,s.begin()+end);
                start = i+1;
            }
        }
        reverse(s.begin()+start,s.end());
        return s;
    }
};