class Solution {
public:
    string reorganizeString(string s) {
     unordered_map<char,int> mp;
        priority_queue<pair<int,char>> MaxHeap;
        for(auto& i:s){
            mp[i]++;
        }
        for(auto j:mp){
            MaxHeap.push(make_pair(j.second,j.first));
        }
        string ans;
        while(MaxHeap.size()>1){
            auto top1 = MaxHeap.top();
            MaxHeap.pop();
            auto top2 = MaxHeap.top();
            MaxHeap.pop();
            ans+=top1.second;
            ans+=top2.second;
             top1.first-=1;
            top2.first-=1;
            if(top1.first>0){
                MaxHeap.push(top1);
            }
            if(top2.first>0){
                MaxHeap.push(top2);
            }
        }
        if(!MaxHeap.empty()){
            if(MaxHeap.top().first>1){
                return "";
            }
            else{
                ans+=MaxHeap.top().second;
            }
        }
        return ans;   
    }
};