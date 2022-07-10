class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        int prev =0,curr=0;
        for(int i=2;i<=n;i++){
            int oneStepCost = prev+cost[i-1];
            int towStepCost = curr + cost[i-2];
            curr = prev;
            prev = min(oneStepCost,towStepCost);
        }
        return prev;
    }
};