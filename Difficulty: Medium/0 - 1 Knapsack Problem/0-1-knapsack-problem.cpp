class Solution {
  public:
 vector<vector<int>>dp;
  int solve(int n,vector<int> &val, vector<int> &wt, int W ){
      if(n==0 || W==0)return 0;
      
      if(dp[n][W]!=-1)return dp[n][W];
      if(wt[n-1]<=W){
          //either we select it or not
          int selected = val[n-1] + solve(n-1, val, wt, W-wt[n-1]);
          int notSelected = solve(n-1, val, wt, W);
          return dp[n][W] =  max(selected, notSelected); 
      }
      else{
          return dp[n][W] =  solve(n-1, val, wt, W);
      }
  }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
       
       int n = val.size();
       dp.assign(n+1, vector<int>(W+1,-1));
       return solve(n, val, wt, W);
        
    }
};