// User function template for C++
class Solution {
  public:
//   int solve(vector<int>&vec, int index){
//       if(index == 0)return vec[index];
//       if(index == 1)return max(vec[index], vec[0]);
      
      
//       int takeNumber = vec[index] + solve(vec, index-2);
//       int notTakeNumber = solve(vec, index-1);
      
//       return max(takeNumber, notTakeNumber);
//   }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
       int n = arr.size();
       vector<int>dp(n,0);
       
       
       dp[0] = arr[0];
       dp[1] = max(arr[0], arr[1]);
       
       for(int i =2;i<dp.size();i++){
           int takeNumber = arr[i] + dp[i-2];
           int notTakeNumber = dp[i-1];
           
           dp[i] = max(takeNumber, notTakeNumber);
       }
       
       
       return dp[n-1];
    }
};