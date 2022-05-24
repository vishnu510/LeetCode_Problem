class Solution {
public:
    int numDecodings(string s) {
       int len = s.length();
        if(s[0]=='0') return 0;
        if(len==1) return 1;
        vector<int> res(len+1,0);
        res[0] = 1;
        res[1] = 1;
        for(int i=2;i<=len;i++){
            int oneDigit = (s[i-1]-'0');
            int twoDigit = (s[i-2]-'0')*10 + (s[i-1]-'0');
            if(oneDigit>=1) res[i]+=res[i-1];
            if(twoDigit>=10 and twoDigit<=26) res[i]+=res[i-2];
        }
        return res[len];
    }
};