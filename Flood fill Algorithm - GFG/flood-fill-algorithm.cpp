// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    void colorFill(vector<vector<int>>& image,int sr,int sc,int oc,int nc){
        int r = image.size(),c = image[0].size();
        if(image[sr][sc]==oc){
            image[sr][sc] =nc;
        }
        if(sr+1<r && image[sr+1][sc]==oc){
            colorFill(image,sr+1,sc,oc,nc);
        }
        if(sr-1>=0 && image[sr-1][sc]==oc){
            colorFill(image,sr-1,sc,oc,nc);
        }
        if(sc+1<c && image[sr][sc+1]==oc){
            colorFill(image,sr,sc+1,oc,nc);
        }
        if(sc-1>=0 && image[sr][sc-1]==oc){
            colorFill(image,sr,sc-1,oc,nc);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        if(image[sr][sc]==newColor){
            return image;
        }
        colorFill(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends