class Solution {
public:
using ll = long long;
int numDistinct(string s, string t) {
    int n1 = s.size();
    int n2 = t.size();
    if(n2 > n1)return 0;
    vector<ll>prevRow(n1+1,1);
    vector<ll>currRow(n1+1);
    currRow[0] = 0;
    for(int i = 1;i<n2+1;i++){
        for(int j = 1;j<n1+1;j++){
            if(t[i-1]== s[j-1]){
                currRow[j] = prevRow[j-1] + currRow[j-1];
            }
            else{
                currRow[j] = currRow[j-1];
            }
            if (currRow[j] > INT_MAX) {
                currRow[j] = INT_MAX;
            }
        }
        prevRow = currRow;
    }
    return prevRow[n1];
    }
};