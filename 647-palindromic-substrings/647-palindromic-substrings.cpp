class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        vector<vector<int>> dynamic(len+1,vector<int>(len+1,0));
        int ans=0;
        for(int i=1;i<=len;i++){
            for(int j=0;j<(len-i+1);j++){
              if(i==1) dynamic[j][j] =1;
              else if(i==2){
                  if(s[j]==s[j+1]) dynamic[j][j+1]=1;
                  else 
                    dynamic[j][j+1] =0;
              }
              else if(s[j]==s[j+i-1] and dynamic[j+1][j+i-2]>0) dynamic[j][j+i-1] = 1;
              else
                dynamic[j][j+i-1] = 0;
              ans+=dynamic[j][j+i-1];  
            }
        }
        return ans;
    }
};