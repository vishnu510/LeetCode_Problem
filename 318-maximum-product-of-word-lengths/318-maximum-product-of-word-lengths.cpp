class Solution {
public:

int maxProduct(vector<string>& words) {
    vector<int> bit;
    for(string &str:words){
        int mask = 0;
        for(char &ch:str){
            mask |=(1<<(ch-'a'));
        }
        bit.push_back(mask);
    }
    int result = 0;
    for(int i=0;i<bit.size();i++){
        for(int j=i+1;j<bit.size();j++){
            if((bit[i] & bit[j])==0){
                result= max(result, (int)(words[i].size()*words[j].size()));
            }
        }
    }
    return result;
  }
};