class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0,minimum=prices[0];
        for(int i=0;i<prices.size();i++){
            minimum = min(minimum,prices[i]);
            max_profit = max(max_profit,prices[i]-minimum);
        }
        return max_profit;
    }
};