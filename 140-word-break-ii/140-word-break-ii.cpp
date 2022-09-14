class Solution {
public:
    vector<string> ans;
    
    class Trie{
        public:
        Trie* child[26];
        bool isEnd = false;
    };
    
    void insert(string & str,Trie* root){
        
        Trie* node = root;
        for(auto c:str){
            if(node->child[c-'a'] == nullptr){
                node->child[c-'a'] = new Trie();
            }
            node = node->child[c-'a'];
        }
        node->isEnd = true;
    }
    bool search(string & str,Trie* root){
        
        Trie* node = root;
        for(auto c:str){
            if(node->child[c-'a'] == nullptr){
                return false;
            }
            node = node->child[c-'a'];
        }
        return node->isEnd;
    }
    void helper(string & s,int currIdx,Trie* root,string currStr){
        if(currIdx == s.size()){
            ans.push_back(currStr.substr(0,0+currStr.size()-1));
            return;
        }
        string res = "";
        for(int i=currIdx;i<s.size();i++){
            res.push_back(s[i]);
            if(search(res,root)){
                helper(s,i+1,root,currStr+res+" ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie* root = new Trie();
        
        for(auto str:wordDict){
            insert(str,root);
        }
        helper(s,0,root,"");
        return ans;
    }
};