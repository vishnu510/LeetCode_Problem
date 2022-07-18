class Solution {
public:

    bool isMatch(string s, string p) {
        int n = s.length(),m=p.length();
        int t[n+1][m+1];
        t[0][0]=true; 
        // if both of are 0 length
        
        if(m) t[0][1]=false;
        // if string length is 0 and pattern length is 1 it will always be 0
        
        // if length of string is greater than 1 ans pattern length is 0
        for(int i=1;i<=n;i++)
        {
            t[i][0]=false;
        }
        
        // A base case where string length is 0 but pattern length is not 0
        for(int j=2;j<=m;j++)
        {
            if(p[j-1]=='*') // consider example p = "a*b*c*" but s=""
                t[0][j] = t[0][j-2];
            else t[0][j] = false;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
        
                if(p[j-1]=='.'|| p[j-1]==s[i-1]) t[i][j] = t[i-1][j-1];
                // if two character matches or one of them is "."
                
                else if(p[j-1]=='*' && j>1){ // if there is * in pattern we have to check for character behind * 
                    if(p[j-2]==s[i-1] || p[j-2]=='.'){
                        t[i][j] = t[i][j-2] || t[i-1][j];
                    }
                    else{
                        t[i][j] = t[i][j-2];
                    }
                }
                else t[i][j]=false;
            }
        }
        return t[n][m];
    }
};