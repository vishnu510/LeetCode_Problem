class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=31;i>=0;--i){
            res |=(n&1)<<i;
            n=n>>1;
        }
        return res;
    }
};