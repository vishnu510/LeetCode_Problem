class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len  = s.size();
        string word = s;
        reverse(s.begin(),s.end());
        int dpMat[len+1][len+1];
        for(int i = 0;i<len+1;i++){
           dpMat[i][0] =0;
        }
         for(int i = 0;i<len+1;i++){
           dpMat[0][i] =0;
        }
        for(int i =1;i<=len;i++){
           for(int j=1;j<=len;j++){
               if(s[i-1]==word[j-1]){
                 dpMat[i][j] = 1 + dpMat[i-1][j-1];
               }
               else{
                   dpMat[i][j] = max(dpMat[i][j-1],dpMat[i-1][j]);
               }
           }
        }
        return dpMat[len][len];
    }
};