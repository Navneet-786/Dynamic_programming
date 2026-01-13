class Solution {
  public:
  vector<vector<int>>dp;
   bool solve(vector<int>&vec, int n,int sum){
       //base case
       if(n==0 && sum==0)return 1;
       if(sum==0)return 1;
       if(n==0) return 0;
       
      if(dp[n][sum]!=-1)return dp[n][sum];
      if(vec[n-1] <= sum){
          bool include = solve(vec, n-1, sum-vec[n-1]);
          bool exclude = solve(vec, n-1, sum);
          return dp[n][sum] = ( include || exclude);
      }
      else{
          return dp[n][sum] = solve(vec, n-1 , sum);
      }
   }

    bool isSubsetSum(vector<int>& arr, int sum) {
       
        int n = arr.size();
        dp.assign(n+1,vector<int>(sum+1,-1));
        return solve(arr,n, sum);
        
    }
};