class Solution {
public:
     bool isPalin(string& s)
    {
        int i = 0, j = s.size()-1;
        while(j>=i)
            {if(s[i]!=s[j]) return false;
            ++i,--j;}
        return true;
    }
    int removePalindromeSub(string s) {
        return 2-isPalin(s);
    }
};