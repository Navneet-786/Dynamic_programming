class Solution {
public:

    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        if(n>m)return false;

        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<n+1;i++){
            dp[i][0] = 0;
        }
        for(int j = 1;j<m+1;j++){
            dp[0][j] =0;
        }

        for(int i=1;i<n+1;i++){
            for(int j = 1;j<m+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        if(dp[n][m]==min(n,m)){
            return true;
        }
        return false;
    }
};