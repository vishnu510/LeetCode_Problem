class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m1,m2;
        
        for(auto c:ransomNote){
            m1[c]++;
        }
        
        for(auto c:magazine){
            m2[c]++;
        }
        for(auto i:m1){
            
            if(m2[i.first] < i.second){
                return false;
            }
        }
        return true;
    }
};