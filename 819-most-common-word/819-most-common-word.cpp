class Solution {
public:
    string mostCommonWord(string p, vector<string>& b) {
        string result;
        int count = 0;
        unordered_map<string, int> umap;
        int i = 0;
        while(i < p.size()){
            string result = "";
            while(i < p.size() && isalpha(p[i])){
                result += tolower(p[i]);
                i++;
            }
            if(result != "")
                umap[result]++;
            i++;
        }
        for(auto& s: b){
            umap.erase(s);
        }
        for(auto& [key,value] : umap){
            if(count < value){
                result = key;
                count = value;
            }
        }
        return result;
    }
};