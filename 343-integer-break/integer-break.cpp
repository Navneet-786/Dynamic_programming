class Solution {
public:

int solve(int n, vector<int>&dp){
    if(n==1 || n==2)return 1;

    if(dp[n]!=-1)return dp[n];
    int result = INT_MIN;
    for(int i  = 1;i<n;i++){
        int prod = i*max(n-i, solve(n-i, dp));
        result = max(result, prod);
    }

    return dp[n] = result;
}
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return solve(n, dp);
    }
};