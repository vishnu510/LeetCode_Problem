class Solution {
public:
    string getSpace(int n){
        string space ="";
        for(int i=0;i<n;i++){
            space+=" ";
        }
        return space;
    }
    
    string justify(vector<string>& words, int maxWidth){
        int len = 0;
        for(auto &word:words){
            len+=word.size();
        }
        int total = maxWidth - len;
        if(words.size()==1){
            return words[0] + getSpace(total);
        }
        int space = total/(words.size()-1);
        int rem = total%(words.size()-1);
        string line = words[0];
        for(int i=1;i<words.size();i++){
            if(i<=rem){
                line+=getSpace(space+1)+words[i];
            }
            else{
                line+=getSpace(space)+words[i];
            }
        }
        return line;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curr = 0;
        vector<string> temp;
        vector<string> ans;
        for(auto &word:words){
            if(curr + word.size()<=maxWidth){
                temp.push_back(word);
                curr+=word.size()+1;
            }
            else{
                curr =0;
                string line = justify(temp,maxWidth);
                ans.push_back(line);
                temp.clear();
                temp.push_back(word);
                curr+=word.size()+1;
            }
        }
        string line =temp[0];
        for(int i=1;i<temp.size();i++){
            line+=" "+temp[i];
        }
        line+=getSpace(maxWidth-line.size());
        ans.push_back(line);
        return ans;
    }
};