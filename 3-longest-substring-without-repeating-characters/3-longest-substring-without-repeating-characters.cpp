class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> mp(256,-1);
        int i = 0, j =0;
        int n = s.size();
        int count =0;
        while( j< n){
            if(mp[s[j]]!=-1){
                i = max(mp[s[j]]+1,i);
            }
            mp[s[j]] = j;
            count = max(count,j-i+1);
            j++;
        }
        return count++;
        
    }
};