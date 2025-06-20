class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> Dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    Dp[i][j] = Dp[i-1][j-1] + 1;
                }
                else{
                    Dp[i][j] = max(Dp[i-1][j], Dp[i][j-1]);
                }
            }
        }
        return Dp[n][m];
    }
};