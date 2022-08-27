class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left =0, right = n-1;
        int ans =0;
        int mxleft =0, mxright =0;
        while(left <= right){
            
            if(height[left] <= height[right]){
                if(height[left] >= mxleft) mxleft = height[left];
                else{
                    ans += mxleft - height[left];
                }
                left++;
            }
            else{
                if(height[right] >= mxright) mxright = height[right];
                else{
                    ans += mxright-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};