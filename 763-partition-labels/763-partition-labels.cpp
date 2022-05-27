class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.size();
        if(len==0) return {};
        vector<int> LastIdx(26,0);
        for(int i=0;i<len;i++){
            LastIdx[s[i]-'a'] = i;
        }
        vector<int> res;
        int start=0,end=0;
        for(int i=0;i<len;i++){
            end = max(end,LastIdx[s[i]-'a']);
            if(i==end){
                res.push_back(i-start+1);
                start = i+1;
            }
        
        }
        return res;
    }
};