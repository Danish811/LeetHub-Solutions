class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> Dp(n+1, vector<int>(n+1, 0));
        string t = s;
        reverse(t.begin(),t.end());
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    Dp[i][j] = Dp[i-1][j-1] + 1;
                }
                else{
                    Dp[i][j] = max(Dp[i-1][j], Dp[i][j-1]);
                }
            }
        }
        return Dp[n][n];
    }
};