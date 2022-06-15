class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		vector<int> pre(n,0);
		vector<int> curr(n);

		for(int i = 0; i < m; i++){

			for(int j = 0; j < n; j++){

					if(obstacleGrid[i][j] == 1) curr[j] = 0;
					else if(i == 0 and j == 0) curr[j] = 1;
					else {  
						int up = 0, left = 0;

						if(i > 0) up = pre[j];
						if(j > 0) left = curr[j-1];

						curr[j] = up + left;
					}
				}

				pre = curr;
			}

		return pre[n-1];
    }
};