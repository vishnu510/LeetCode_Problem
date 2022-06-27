// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isSafe(int grid[N][N],int a,int b,int c){
        for(int i=0;i<9;i++){
            if(grid[a][i]==c)return false;
            if(grid[i][b]==c)return false;
        }
        int key=3*(a/3)+b/3;
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int tempkey=3*(i/3)+j/3;
                if(key==tempkey){
                    if(grid[i][j]==c)return false;
                }
            }
        }
        return true;
    }
    
    bool solve(int grid[N][N],int i,int j){
       if(i==8&&j==9)return true;
       if(j==9)i++,j=0;
       if(grid[i][j])return solve(grid,i,j+1); 
       for(int k=1;k<=9;k++){
           if(isSafe(grid,i,j,k)){
               grid[i][j]=k;
               if(solve(grid,i,j+1))return true;
               grid[i][j]=0;
           }
       }
        return false;
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return solve(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)cout<<grid[i][j]<<" ";
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends