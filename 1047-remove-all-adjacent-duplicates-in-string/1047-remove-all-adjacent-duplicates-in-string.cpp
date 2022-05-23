class Solution {
public:
    string removeDuplicates(string s) {
        int slow=0;
        for(int fast=1;fast<s.length();fast++){
            if(slow<0 || s[slow]!=s[fast]){
                s[++slow] = s[fast];
            }
            else{
                --slow;
            }
        }
        return s.substr(0,slow+1);
    }
};