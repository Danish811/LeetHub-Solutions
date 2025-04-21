class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> sum(n+1,0);
        vector<long long> res(n+1,0);
        for(int i=0; i<n; i++) {
            sum[i+1] = differences[i];
            sum[i+1] += sum[i];
        }
        int mini = 0;
        for(int i=0; i<n+1; i++){
            if(sum[mini] > sum[i]){
                mini= i;
            }
        }
        res[mini] = lower;
        for(int i=mini; i>0; i--){
            res[i-1] = res[i] - differences[i-1]; 
        
        }
        for(int i=mini; i<n; i++){
            res[i+1] = res[i] + differences[i];
        }
        int maxi = 0;
        for(int i=0; i<res.size(); i++){
            if(res[i] > res[maxi]) maxi = i;
        }
        if(res[maxi] > upper) return 0;
        return upper-res[maxi]+1;
    }
};