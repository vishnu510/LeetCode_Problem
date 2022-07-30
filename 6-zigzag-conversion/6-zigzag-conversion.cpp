class Solution {
public:
    string convert(string s, int numRows) {
        
        string ans;
        vector<string> res(numRows);
        
        int i=0, n = s.size();
        
        while(i<n){
            
            for(int j=0;j<numRows&&i<n;i++,j++){
                res[j]+=s[i];
            }
            
            for(int j = numRows-2;j>0 && i<n;j--,i++){
                res[j]+=s[i];
            }
        }
        
        for(int i=0;i<res.size();i++){
            ans+=res[i];
        }
        return ans;
    }
};