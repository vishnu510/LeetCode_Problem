class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenofs = s.length(),lenofp = p.length();
        if(lenofp>lenofs) return {};
        vector<int> vecs(26,0),vecp(26,0),res;
        for(int i=0;i<lenofp;i++){
            vecp[p[i]-'a']++;
        }
        int i=0,j=0;
        while(j<lenofs){
            vecs[s[j]-'a']++;
            if((j-i+1)<lenofp){
                j++;
            }
            else if((j-i+1)==lenofp){
                if(vecs==vecp){
                    res.push_back(i);
                }
                vecs[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return res;
    }
};