class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans;
        if(k>n){
            ans.push_back(*max_element(nums.begin(),nums.end()));
            return ans;
        }
        
        int i =0,j=0;
        deque<int> q;
        
        while(j<n){
            
            while(!q.empty() && q.back()<nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else{
                ans.push_back(q.front());
                if(q.front()==nums[i]){
                    q.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};