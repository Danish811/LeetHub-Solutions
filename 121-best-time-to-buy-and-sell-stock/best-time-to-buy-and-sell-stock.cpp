class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int suffmax[n];
        suffmax[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--){
            suffmax[i] = max(suffmax[i+1],prices[i]);
        }
        int maxi =0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, suffmax[i]-prices[i]);
        }
        return maxi;
    }
};