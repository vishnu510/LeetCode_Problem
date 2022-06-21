class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest =0;
        for(auto & num:st){
            if(st.count(num-1)) continue;
            int j =1;
            while(st.count(num+j)){
                j++;
            }
            longest = max(longest,j);
        }
        return longest;
    }
};