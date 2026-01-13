class Solution {
  public:
  vector<vector<int>>dp;
  int solve(vector<vector<int>>& arr, int day, int task){
      //base case
      if(day==0){
          int maxi = 0;
          for(int i = 0;i<=2 ;i++){
              if(i!=task){
                maxi = max(maxi, arr[0][i]);
              }
          }
          return maxi;
      }
      
      if(dp[day][task]!=-1)return dp[day][task];
      int maxi = 0;
      for(int i = 0;i< 3;i++){
          if(i!=task){
              maxi = max(maxi, arr[day][i] + solve(arr, day-1, i));
          }
      }
      return dp[day][task]=  maxi;
  }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int task = 3; //assume no task is perform
        int day = arr.size()-1;
        
        dp.assign(arr.size(),vector<int>(4,-1));
        return solve(arr,day, task);
        
    }
};