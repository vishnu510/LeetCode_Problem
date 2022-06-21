class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        int min_sum = INT_MAX;
        unordered_map<string,int> ump;
        for(int i=0;i<list1.size();i++){
            ump[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++){
            if(ump.find(list2[i])!=ump.end()){
                if(ump[list2[i]]+i<min_sum){
                    res.clear();
                    res.push_back(list2[i]);
                    min_sum = ump[list2[i]]+i;
                }
                else if(ump[list2[i]]+i==min_sum){
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};