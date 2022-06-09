class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> str1Map;
        for(auto &i:s1){
            str1Map[i]++;
        }
        int windowSize = s1.size();
        int windowEnd =0,matched =0;
        for(int windowStart =0;windowStart<s2.size();windowStart++){
            auto it = str1Map.find(s2[windowStart]);
            if(it!=str1Map.end()){
                str1Map[it->first]--;
                if(str1Map[it->first]==0){
                    matched++;
                }
            }
            if(matched == str1Map.size())
            {return true;}

            if(s1.size()<=windowStart+1-windowEnd){
                auto iter = str1Map.find(s2[windowEnd]);
                if(iter!=str1Map.end()){
                    if(str1Map[iter->first]==0){
                        matched--;
                    }
                    str1Map[iter->first]++;
                }
                windowEnd++;
            }
        }
        return false;
    }
};