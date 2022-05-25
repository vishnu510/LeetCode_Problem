class Solution {
public:
    int findMinLen(vector<string>& strs){
    int min = strs[0].size();
    for(int i=1;i<strs.size();i++){
        if(min>strs[i].size()){
            min = strs[i].size();
        }
    }
    return min;
}

string longestCommonPrefix(vector<string>& strs) {
      if(strs.size()==0) return "";
      int minlen = findMinLen(strs);
      string res = "";
      for(int i=0;i<minlen;i++){
          char curr = strs[0][i];
          for(int j=0;j<strs.size();j++){
              if(strs[j][i]!=curr){
                   return res;
              }
          }
          res+=curr;
      }
     return res;
    }
        
  
};