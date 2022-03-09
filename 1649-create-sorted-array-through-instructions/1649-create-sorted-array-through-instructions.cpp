#define mod 1000000007
class Solution {
public:
    int bit[100002];
    long long sum(int i){
        long long ans = 0;
        for(int j=i;j>0;j-=(j&-j))ans+=bit[j];
        return ans;
    }
    void update(int i){
        for(int j=i;j<=100001;j+=(j&-j))bit[j]+=1;
    }
    long long createSortedArray(vector<int>& v) {
        long long n = v.size();
        long long ans =0;
        for(int i=0;i<n;i++){
            ans+=min(sum(v[i]-1),i-sum(v[i]));
           ans%=mod;
            update(v[i]);
        }
        return ans;
    }
};