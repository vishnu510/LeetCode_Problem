class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()){
            return 0;
        }
        set<string> st;
        for(auto it:wordList){
            st.insert(it);
        }
        queue<string> q;
        q.push(beginWord);
        int ans =0;
        while(!q.empty()){
            ans++;
            int n=q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.size();i++){
                    
                    string temp = curr;
                    for(char c='a';c<='z';c++){
                        temp[i] = c;
                        if(curr == temp){
                            continue;
                        }
                        if(temp == endWord){
                            return ans+1;
                        }
                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};