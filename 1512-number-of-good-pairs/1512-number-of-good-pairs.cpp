class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count= 0,j;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
             if(m.find(nums[i])==m.end()){
                 m[nums[i]] =1;
             }
            else{
                m[nums[i]]++;
            }
        }
        for(auto &it:m){
            int n = it.second;
            count+= (n*(n-1)/2);
            
        }
        return count;
    }
};