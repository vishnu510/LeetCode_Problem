class Solution {
public:
    string frequencySort(string s) {
      priority_queue<pair<int,char>> MaxHeap;
        unordered_map<char,int> map;
        for(int i=0;i<s.size();i++)
            map[s[i]]++;
        for(auto i:map)
            MaxHeap.push(make_pair(i.second,i.first));
        string result="";
        while(!MaxHeap.empty())
        {
            int freq=MaxHeap.top().first;
            char str= MaxHeap.top().second;
            for(int i=0;i<freq;i++)
            {
                result+=str;
            }
            MaxHeap.pop();
        }
        return result;
    }
};