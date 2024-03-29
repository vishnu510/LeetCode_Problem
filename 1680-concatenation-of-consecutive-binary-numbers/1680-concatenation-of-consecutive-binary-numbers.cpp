class Solution {
public:
    int concatenatedBinary(int n) {
      int M = 1e9 + 7, l = 0;
        // use long here as it potentially could overflow for int
        long ans = 0;
        for (int i = 1; i <= n; i++) {
           
            if ((i & (i - 1)) == 0) l += 1;
            
            ans = ((ans << l) | i) % M;
        }
        return ans;
    }
};