class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      
        unordered_map<string,vector<string>> map;
        vector<vector<string>> result;
        int i=0,len = strs.size();
        while(i<len){
            string str = strs[i];
            sort(str.begin(),str.end());
            map[str].push_back(strs[i]);
            i++;
        }
       for(auto i=map.begin();i!=map.end();i++){
           result.push_back(i->second);
       }
       
       return result;  
    }
};