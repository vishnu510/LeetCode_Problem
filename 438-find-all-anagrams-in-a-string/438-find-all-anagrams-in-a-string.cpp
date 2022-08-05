class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         
        int m = s.size() , n = p.size();
        
        vector<int> m1(26,0),m2(26,0);
        
        for(int i=0;i<n;i++){
            m1[p[i]-'a']++;
        }
        int i=0,j=0;
        vector<int> ans;
        while(j<m){
            
            m2[s[j]-'a']++;
            if((j-i+1)< n){
                j++;
            }
            else if((j-i+1)==n){
                if(m1==m2){
                    ans.push_back(i);
                }
                m2[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};