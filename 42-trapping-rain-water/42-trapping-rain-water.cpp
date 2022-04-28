class Solution {
public:
    int trap(vector<int>& height) {
     int size = height.size();
    vector<int> left(size,0);
    vector<int> right(size,0);
    int answer=0,l=height[0],m=height[size-1];
    for (int i = 0; i < size; i++)
    {
        left[i] = max(l,height[i]);
        l = max(l,height[i]);
    }
    for (int i = size-1; i >=0 ; i--)
    {
        right[i] = max(m,height[i]);
        m = max(m,height[i]);
    }
    for (int i = 0; i < size; i++)
    {
        answer+= min(left[i],right[i])-height[i];
    }
        return answer;
    }
};