class Solution {
public:
vector<vector<int>>dp;
int solve(string &s,string &t, int n1, int n2){
    if(n2==0)return 1;
    if(n1==0)return 0;
    if(dp[n1][n2]!=-1)return dp[n1][n2];
    if(s[n1-1]==t[n2-1]){
        return  dp[n1][n2] = solve(s, t, n1-1, n2-1) + solve(s, t, n1-1, n2);
    }
    else{
        return  dp[n1][n2] = solve(s, t, n1-1, n2);
    }
}

int numDistinct(string s, string t) {
    int n1 = s.size();
    int n2 = t.size();
    if(n2 > n1)return 0;
    dp.assign(n1+1,vector<int>(n2+1,-1));
    return solve(s, t, n1, n2);
    }
};