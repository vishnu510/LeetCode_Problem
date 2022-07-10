class Solution {
public:
    bool good(vector<int>&w,int days,int mid){
        int day =1;
        int wcount =0;
        for(int i=0;i<w.size();i++){
            
            wcount+=w[i];
            if(wcount>mid){
                day++;
                wcount =w[i];
            }
            
        }
        if(day<=days){
                return true;
            }
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int s =*max_element(weights.begin(),weights.end()),sum=0;
        for(auto i:weights){
            sum+=i;
        }
        int e = sum;
        int ans =0;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(good(weights,days,mid)){
                ans =mid;
                e =mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};