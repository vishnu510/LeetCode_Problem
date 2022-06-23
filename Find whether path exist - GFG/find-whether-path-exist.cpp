// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool ans = false;
    
    void bfs(vector<vector<int>>& grid,int i,int j,int di,int dj){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        if(i==di && j==dj){
            ans = true;
            return;
        }
        int start = grid[i][j];
        grid[i][j] =0;
        bfs(grid,i-1,j,di,dj);
        bfs(grid,i+1,j,di,dj);
        bfs(grid,i,j-1,di,dj);
        bfs(grid,i,j+1,di,dj);
        grid[i][j] = start;
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int s=0,e=0,di=0,dj=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    s = i;
                    e =j;
                }
                if(grid[i][j]==2){
                    di = i;
                    dj =j;
                }
            }
        }
        bfs(grid,s,e,di,dj);
        return ans;
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends