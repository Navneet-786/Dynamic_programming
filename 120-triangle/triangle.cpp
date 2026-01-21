class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0] = triangle[0][0];
        for(int i = 1;i<n;i++){
            dp[i][0] = dp[i-1][0] + triangle[i][0];
        }
        for(int i = 1;i<n;i++){
            for(int j =1;j<=i;j++){
                int top = INT_MAX;
                int diag = dp[i-1][j-1];
                if(i!=j) top = dp[i-1][j];                
                dp[i][j] = triangle[i][j] + min(top, diag);
            }
        }
        int ans = INT_MAX;
        for(auto it: dp[n-1]){
            ans = min(ans,it);
        }
        return ans;
    }
};