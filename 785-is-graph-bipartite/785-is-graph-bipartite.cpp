class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,0);
        queue<int> list;
        for(int i=0;i<n;i++){
            if(colors[i]){
                continue;
            }
            colors[i] = 1;
            list.push(i);
            while(!list.empty()){
                int temp = list.front();
                for(auto neighbor:graph[temp]){
                    if(!colors[neighbor]){
                        colors[neighbor] = -colors[temp];
                        list.push(neighbor);
                    }
                    else if(colors[neighbor]==colors[temp]){
                        return false;
                    }
                }
                list.pop();
            }
        }
        return true;
    }
};