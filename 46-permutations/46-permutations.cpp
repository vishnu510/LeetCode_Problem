class Solution {
public:
    void permutation(vector<int>& nums,vector<vector<int>>& res,int l){
    if(l>=nums.size()){
        res.push_back(nums);
        return;
    }
    else{
        for(int i=l;i<nums.size();i++){
            swap(nums[l],nums[i]);
            permutation(nums,res,l+1);
            swap(nums[l],nums[i]);
        }
    }

}

vector<vector<int>> permute(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> res;
    permutation(nums,res,0);
    return res;
}
};