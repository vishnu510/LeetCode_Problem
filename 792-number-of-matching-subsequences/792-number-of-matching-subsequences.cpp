bool greaterString(string a, string b){
    // helper method to sort the list of 
    // words in decreasing order of length
    return a.size() > b.size();
}

struct TrieNode{
    // Stuct to represnet trie node
    char c;
    unordered_map<char, TrieNode*> children;
    
    TrieNode(char x){
        c = x;
    }
};

class Solution {
public:
    bool isMatchingSubseq(string s, string w, int N){
        // util funciton to find if w is a valid
        // subseq of s. O(n) time compl.
        
        if(s.size() < w.size())
            return false;
        
        if(s.size() == w.size())
            return s == w;
        
        
        int i = 0, j = 0;
        
        while(i < N){
            if(s[i] == w[j])
                j++;
            if(j == w.size())
                return true;
            i++;
        }
        
        return w.size() == j;        
        
    }
    
    void addToTrie(TrieNode* root, string s){
        // helper method to add to trie
        int i = 0;
        while(i < s.size()){
            if(root->children.find(s[i]) != root->children.end())
                root = root->children[s[i]];
            else
                root->children[s[i]] = new TrieNode(s[i]);
            i++;
        }
        return;
    }
    
    bool isSubstr(TrieNode* root, string s){
        // check if string substring of already 
        // indexed strings via trie DFS
        int i = 0;
        while(i < s.size()){
            
            if(root->children.find(s[i]) == root->children.end())
                return false;
            
            root = root->children[s[i]];
            i++;
        }
        return true;
    }
        
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        sort(words.begin(), words.end(), greaterString);
        
        /*
        Algo 
         iterate through all strings in list
         if string substring of an already valid subseq then count++
         check if valid subseq, increment count if valid
         if not valid store in look up table
        */
        
        // init trie
        TrieNode* root_valid = new TrieNode('/');
        unordered_set<string> invalid_list;
        
        for(int i = 0 ; i < words.size() ; i++){
            if(invalid_list.find(words[i]) != invalid_list.end())
                continue;
            
            if(isSubstr(root_valid, words[i]))
               count++;
            else if(isMatchingSubseq(s, words[i], s.size())){
                count++;
                addToTrie(root_valid, words[i]);
            }
            else{
                invalid_list.insert(words[i]);
            }   
        }
        return count;
    }
};