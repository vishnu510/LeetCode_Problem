class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mxProfit = 0 , minPrice = INT_MAX;
        
        for(int i=0;i<prices.size();i++){
            
            minPrice = min(minPrice,prices[i]);
            
            mxProfit = max(mxProfit, prices[i]-minPrice);
        }
        
        return mxProfit;
    }
};