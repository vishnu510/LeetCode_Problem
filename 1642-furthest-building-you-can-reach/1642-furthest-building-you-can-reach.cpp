class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(); 
		priority_queue<int>pq;
		for(int i = 1; i < n; i++) {
			int diff = heights[i] - heights[i-1];
			if(diff > 0) {
				pq.push(diff);
				bricks -= diff;
				if(bricks < 0) {
					bricks += pq.top();
					pq.pop();
					ladders--;
					if(ladders < 0) {
						return i - 1;
					}
				}
			}
		}
		return n - 1;
    }
};