class Solution {
public:
    
    
    int minimumDifference(vector<int>& nums) 
    {
        int totalSum = 0;
      
        for(int num : nums) {
          totalSum += num;
        }
        
        int n = nums.size();
        vector <vector<int>> left_part(n / 2 + 1), right_part(n / 2 + 1);
      
        left_part[0].push_back(0);
        right_part[0].push_back(0);
      
        int part_len = n / 2;
        for(int i = 0; i < (1 << part_len); i++) {
          int part_sum = 0, len = 0;
          
          for(int j = 0; j < n / 2; j++) {
            if(i & (1 << j)) {
              part_sum += nums[j];
              len++;
            }
          }
          
          left_part[len].push_back(part_sum);
        }
      
      
        for(int i = 0; i < (1 << part_len); i++) {
          int part_sum = 0, len = 0;
          
          for(int j = 0; j < n / 2; j++) {
            if(i & (1 << j)) {
              part_sum += nums[j + n / 2];
              len++;
            }
          }
          
          right_part[len].push_back(part_sum);
        }
      
        for(int l = 0; l <= n / 2; l++) {
            sort(left_part[l].begin(), left_part[l].end());
            sort(right_part[l].begin(), right_part[l].end());
        }
      
        int minDiff = INT_MAX;
        for(int l = 0; l <= n / 2; l++) {
            int left_len = l, right_len = n / 2 - l;
          
            int half = totalSum / 2;
            for(int i = 0; i < left_part[left_len].size(); i++) {
                int req = half - left_part[left_len][i];
                auto it = lower_bound(right_part[right_len].begin(), right_part[right_len].end(), req);
              
                if(it == right_part[right_len].end()) {
                  it--;
                }
                int p1 = left_part[left_len][i] + (*it);
                int p2 = totalSum - p1;
              
                minDiff = min(abs(p1 - p2), minDiff);
            }
        }
        
        return minDiff;
    }
};