class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(auto it:stones){
            sum += it;
        }

        vector<vector<int>>dp(n+1, vector<int>(sum+1,0));
        for(int i = 0;i<n+1;i++){
            dp[i][0] = 1;
        }
       for(int i = 1;i<n+1;i++){
        for(int j = 1;j<sum+1;j++){
            if(stones[i-1]<=j){
                dp[i][j] =  dp[i-1][j] || dp[i-1][j-stones[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
       }

       int ans = INT_MAX;
       for(int i = 0;i<=sum/2;i++){
            if(dp[n][i]){
                ans = min(ans, sum - (2* i));
            }
       }

       return ans;
        
    }
};