class Solution {
public:
    int getNext(int n){
    int total = 0,digit;
    while (n>0)
    {
        digit = n%10;
        n/=10;
        total+=(digit*digit);
    }
    return total;
}

    bool isHappy(int n) {
    int slow_ptr = n;
    int fast_ptr = getNext(n);
    while (fast_ptr!=1 and fast_ptr!=slow_ptr)
    {
        slow_ptr = getNext(slow_ptr);
        fast_ptr = getNext(getNext(fast_ptr));
    }
    
    return fast_ptr==1;
    }
};