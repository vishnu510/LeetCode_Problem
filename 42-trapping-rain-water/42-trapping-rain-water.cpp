class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n,0),suffics(n,0);
        int mx = height[0];
        for(int i =0;i<n;i++){
            mx = max(mx,height[i]);
            prefix[i] = mx;
        }
        int mx2 = height[height.size()-1];
        for(int i = n-1;i>=0;i--){
            mx2 = max(mx2,height[i]);
            suffics[i] = mx2;
        }
        
        int ans =0;
        for(int i=0;i<height.size();i++){
            ans += min(prefix[i],suffics[i])-height[i];
        }
        return ans;
    }
};