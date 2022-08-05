class Solution {
public:
    
    int solver(string &s, int &k, int &totalUnique) {
        int start=0, end=0, currunique=0, numk=0;
        int cnt = 0;
        vector <int> chMap(26, 0);
        while(end < s.size()) {
            if (!chMap[s[end] - 'a']) currunique++;
            chMap[s[end]-'a']++;
            if (chMap[s[end] - 'a'] == k) numk++;
            end++;
            while(currunique > totalUnique) {
                if (chMap[s[start] - 'a'] == k) numk--;
                chMap[s[start]-'a']--;
                if (!chMap[s[start] - 'a']) currunique--;
                start++;
            }
            // number of unique elements are equal to the number of elements which have count of at least k
            if (currunique == numk) {
                cnt = max(cnt, end-start);
            }
        }
        return cnt;
    }
    int longestSubstring(string s, int k) {
        
        int n = s.size();
        int cnt = 0;
        for(int i =1; i<=26; i++) {
            cnt = max(cnt, solver(s, k, i));
        }
        return cnt;
    }
};