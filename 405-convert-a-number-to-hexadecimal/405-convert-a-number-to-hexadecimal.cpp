class Solution {
public:
    string toHex(int num) {
        string res = "";
        unsigned int n = num;
        if(n==0){
            return "0";
        }
        int remainder =0;
        while(n>0){
            remainder = n%16;
            if(remainder<10){
                res+=(remainder+'0');
            }
            else{
                res+=(87+remainder);
            }
            n/=16;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};