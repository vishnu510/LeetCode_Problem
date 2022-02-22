class Solution {
public:
    int missingNumber(vector<int>& nums) {
       unordered_set<int> s;
        for (auto x : nums) {
            s.insert(x);
        }

        int i = 0;
        while (i < nums.size()) {
            if (s.find(i) != s.end()) {
                i++;
            } else {
                break;
            }
        }

        return i; 
    }
};