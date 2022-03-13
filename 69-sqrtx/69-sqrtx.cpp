class Solution {
public:
    int mySqrt(int x) {
        long long ans,i=1;
        while(i*i<=x){
            i++;
        }
        ans = i-1;
        
        return ans;
    }
};