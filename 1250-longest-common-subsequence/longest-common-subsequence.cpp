class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        vector<vector<int>> Dp(n+1, vector<int>(text2.size()+1, 0));
        string t = text2;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=t.size(); j++){
                if(text1[i-1] == t[j-1]){
                    Dp[i][j] = Dp[i-1][j-1] + 1;
                }
                else{
                    Dp[i][j] = max(Dp[i-1][j], Dp[i][j-1]);
                }
            }
        }
        return Dp[n][text2.size()];
    }
};