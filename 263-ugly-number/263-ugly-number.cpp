class Solution {
public:
    bool isUgly(int n) {
        vector<int> primes = {2,3,5};
   if(n<1) return false;
   for(auto i:primes) while(n%i==0) n/=i;
   return n==1;
    }
};