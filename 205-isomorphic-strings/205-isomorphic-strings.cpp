class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int len = s.size();
        char seen[128] = {};
        for (int i = 0; i < len; i++) {
            // checking s, char by char
            char c = s[i];
            if (!seen[c]) {
                // if we never saw this, we check it does not match any other seen
                for (char s: seen) if (s == t[i]) return false;
          
                seen[c] = t[i];
            }
            
            else if (seen[c] != t[i]) return false;
        }
        return true;
    }
};