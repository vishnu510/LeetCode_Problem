class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            p.pop();
        }
        return p.top();
    }
};