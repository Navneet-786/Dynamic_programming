class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int maxProfit = 0;
        int minBuyStock = prices[0];
        for(int i =1;i<n;i++){
           int tempProfit = prices[i] - minBuyStock;
           maxProfit = max(maxProfit, tempProfit);
           if(minBuyStock > prices[i]){
               minBuyStock = prices[i];
           }
        }
        
        return maxProfit;
    }
};
