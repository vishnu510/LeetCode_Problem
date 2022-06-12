// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        int freshOrange =0;
        vector<int> direction = {-1,0,1,0,-1};
        queue<pair<int,int>> que;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
                if(grid[i][j]==1){
                    freshOrange++;
                }
            }
        }
        int timeTaken = -1;
        while(!que.empty()){
            int qSize = que.size();
            while(qSize--){
                pair<int,int> p = que.front();
                que.pop();
                for(int i=0;i<4;i++){
                    int r = p.first + direction[i];
                    int c = p.second + direction[i+1];
                    if(r>=0 && r<row && c>=0 && c<col and grid[r][c]==1){
                        grid[r][c]=2;
                        que.push({r,c});
                        freshOrange--;
                    }
                }
            }
            timeTaken++;
        }
        if(freshOrange>0) return -1;
        if(timeTaken==-1) return 0;
        return timeTaken;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends