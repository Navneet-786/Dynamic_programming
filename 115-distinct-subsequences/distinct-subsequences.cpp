class Solution {
public:
using ll = long long;
vector<vector<ll>>dp;
int numDistinct(string s, string t) {
    int n1 = s.size();
    int n2 = t.size();
    if(n2 > n1)return 0;
    dp.assign(n2+1,vector<ll>(n1+1,0));

    for(int i = 0;i<n1+1;i++){
        dp[0][i] = 1;
    }

    for(int i = 1;i<n2+1;i++){
        for(int j = 1;j<n1+1;j++){
            if(t[i-1]== s[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
            if (dp[i][j] > INT_MAX) {
                dp[i][j] = INT_MAX;
            }
        }
    }
    return (int)dp[n2][n1];
    }
};