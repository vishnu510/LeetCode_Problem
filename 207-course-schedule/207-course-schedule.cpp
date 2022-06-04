class Solution {
public:
    int w=0,g=1,b=2;//w=unvisited g=not explored b=visited
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&visited){
        visited[node]= g;
        for(int i=0;i<graph[node].size();i++){
            if(visited[graph[node][i]]==g){
                return false;
            }
            if(visited[graph[node][i]]==w){
                if(!dfs(graph[node][i],graph,visited)){
                    return false;
                }
            }
        }
        visited[node] = b;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses,w);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,graph,visited)){
                return false;
            }
        }
        return true;
    }
};