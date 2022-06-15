class Solution {
public:
    bool static cmp(string &word1,string &word2){
        return word1.size() < word2.size();
    }
    int longestStrChain(vector<string>& words) {
       sort(words.begin(),words.end(),cmp);
       unordered_map<string,int> mp;
        int maxLength =0;
        for(auto word : words){
            int currLength =1;
            for(int i=0;i<word.size();i++){
                string predecessor = word.substr(0,i)+word.substr(i+1);
                if(mp.find(predecessor)!=mp.end()){
                    int prevLength = mp[predecessor];
                    currLength = max(currLength,prevLength+1);
                }
            }
            mp[word] = currLength;
            maxLength = max(maxLength,currLength);
        }
        return maxLength;
    }
};