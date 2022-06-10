class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int temp[256]={0},l =0,r=0,ans=0;
        while(r<s.size()){
            temp[s[r]]++;
            while(temp[s[r]]>1){
                temp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};