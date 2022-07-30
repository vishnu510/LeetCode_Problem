class Solution {
public:
    
    vector<int> countF(string word){
        
        vector<int> freq(26);
        
        for(auto c:word){
            freq[c-'a']++;
        }
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2){
        
        vector<int> maxF(26);
        vector<string> ans;
        
        for(auto word:words2){
            
            vector<int> freq = countF(word);
            
            for(int i=0;i<26;i++){
                maxF[i] = max(maxF[i],freq[i]);
            }
        }
        for(auto word:words1){
            
            vector<int> freq = countF(word);
            
            int i=0;
            for(;i<26;i++){
                if(freq[i]<maxF[i]) break;
            }
            if(i==26) ans.push_back(word);
        }
        
        return ans;
    }
};