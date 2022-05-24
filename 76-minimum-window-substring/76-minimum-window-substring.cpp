class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        for(auto c:t){
            map[c]++;
        }
        int count =0,minlen = INT_MAX,low=0,start=0;
        for(int high=0;high<s.length();high++){
            if(map[s[high]]>0) count++;
            map[s[high]]--;
            if(count==t.length()){
                while(low<high and map[s[low]]<0) {
                    map[s[low]]++;
                    low++;
                }
                if(minlen > high-low){
                    minlen = high-(start=low)+1;
                }
                map[s[low++]]++;
                count--;
            }
        }
        return minlen==INT_MAX?"":s.substr(start,minlen);
    }
};