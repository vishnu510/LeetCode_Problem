class Solution {
public:
    int titleToNumber(string columnTitle) {
      int result = 0;
        for(auto c:columnTitle){
            int diff = c-'A'+1;
            result = result*26 + diff;
        }
        return result;  
    }
};