class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int countZero =0;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%k==0) countZero++;
            else{
                ans.push_back(((arr[i]%k)+k)%k);
            }
        }
        if(countZero%2==1) return false;
        else{
            sort(ans.begin(),ans.end());
            int i=0,j=ans.size()-1;
            while(i<j){
                if((ans[i]+ans[j])%k!=0) return false;
                else{
                    i++;
                    j--;
                }
            }
        }
        return true;
    }
};