class Solution {
public:
    vector<string> ans;
    class Trie{
        public:
        Trie* child[26];
        bool isEnd = false;
        
    };
    
    void insert(string & word,Trie* root){
        Trie* curr = root;
        for(char c:word){
            if(curr->child[c-'a']==nullptr){
                curr->child[c-'a'] = new Trie();
            }
            curr = curr->child[c-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string & word,Trie* root){
        Trie* curr = root;
        
        for(char c:word){
            
            if(curr->child[c-'a']==nullptr) return false;
            curr = curr->child[c-'a'];
        }
        return curr->isEnd;
    }
    
    void dfs(string &s,int currIdx, Trie* root,string currStr){
        if(currIdx==s.size()){
            ans.push_back(currStr.substr(0,0+currStr.size()-1));
            return;
        }
        string res ="";
        for(int i=currIdx;i<s.size();++i){
            res.push_back(s[i]);
            if(search(res,root)){
                dfs(s,i+1,root,currStr+res+" ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        Trie* root = new Trie();
        
        for(auto word:wordDict){
            insert(word,root);
        }
        dfs(s,0,root,"");
        return ans;
    }
};