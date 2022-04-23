class Solution {
public:
    int nextGreaterElement(int n) {
        int temp = n;
        vector<int> res;
        while(temp){
            res.push_back(temp%10);
            temp/=10;
        }
        reverse(res.begin(),res.end());
        int l,m;
        temp = res.size();
        for(l=temp-2;l>=0;l--){
            if(res[l]<res[l+1]){
                break;
            }
        }
        if(l<0){
            return -1;
        }
        else{
            for(m = temp-1;m>l;m--){
                if(res[m]>res[l]) break;
            }
                swap(res[m],res[l]);
                reverse(res.begin()+l+1,res.end());
            
        }
        long long result =0;
        for(int i=0;i<temp;i++){
            result = result*10 + res[i];
        }
        if(result>INT_MAX) return -1;
        return result;
    }
};