class Solution {
public:
    class Trie{
        public:
        unordered_map<char,Trie*> children;
        bool isEnd = false;
        void insert(string str){
        Trie* node = this;
        
        for(auto c:str){
            if(node->children.find(c) == node->children.end()){
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    bool search(string str){
        Trie* node = this;
        
        for(auto c:str){
            if(node->children.find(c) == node->children.end()){
                return false;
            }
            node = node->children[c];
        }
        return node->isEnd;
    }
    };
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(auto str:wordDict){
            trie.insert(str);
        }
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        
        for(int i=1;i<=s.size();i++){
            for(int j =0;j<i;j++){
                if(dp[j] && trie.search(s.substr(j,i-j))){
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};