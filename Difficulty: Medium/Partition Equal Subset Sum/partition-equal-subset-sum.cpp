class Solution {
  public:
  
  

    bool equalPartition(vector<int>& arr) {
       
        int sum = 0;
        for(auto it: arr)
            sum+=it;
        
        if(sum&1)return false;
        
        int target = sum/2;
        //we are going to implement tabulation method 
        int n = arr.size();
        
        vector<vector<int>>dp(n+1,vector<int>(target+1, 0));
        
        dp[0][0] = 1;
        for(int j = 1;j<target+1;j++){
            dp[0][j] = 0;
        }
        for(int i= 1;i<n+1;i++){
            dp[i][0] = 1;
        }
        
        for(int i =1;i< n+1;i++){
            for(int j = 1;j<target+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][target];
        
        
        
    }
};