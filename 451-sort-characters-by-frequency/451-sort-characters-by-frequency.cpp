class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        priority_queue<pair<int,char>> Maxheap;
        for(auto i:s){
            map[i]++;
        }
        string res;
        for(auto j:map){
            Maxheap.push({j.second,j.first});
        }
        while(!Maxheap.empty()){
            res+=string(Maxheap.top().first,Maxheap.top().second);
            Maxheap.pop();
        }
        return res;
    }
};