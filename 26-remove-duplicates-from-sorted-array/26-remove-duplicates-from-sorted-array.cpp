class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        
        for(auto i:nums){
            st.insert(i);
        }
        
        nums.clear();
        for(auto i:st){
            nums.push_back(i);
        }
        return nums.size();
    }
};