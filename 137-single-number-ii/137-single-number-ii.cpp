class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
    }
    for(auto i=map.begin();i!=map.end();i++){
        if(i->second==1){
            return i->first;
        }
    }
    return 0;
    }
};