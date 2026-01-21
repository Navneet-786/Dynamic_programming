class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(),0);
        int target = (sum + diff);
        
        if(target&1)return 0;
        
        target = target/2;
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        
        dp[0][0] = 1;
        
        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<target+1;j++){
                int notInclude = dp[i-1][j];
                int include = 0;
                if(arr[i-1]<=j){
                    include = dp[i-1][j-arr[i-1]];
                }
                
                dp[i][j] = notInclude + include;
            }
        }
        
        return dp[n][target];
    }
};