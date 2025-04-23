class Solution {
public:
    int Calc(int x){
        int s = 0;
        while(x>0){
            s += x%10;
            x/=10;
        }
        return s;
    }
    int countLargestGroup(int n) {
        int sum;
        map<int,int> M;
        int maxi = 0;
        for(int i=1; i<=n; i++){
            sum = Calc(i);
            M[sum]++;
            maxi = max(maxi,M[sum]);
        }
        int cnt =0;
        for(auto ele: M){
            if(ele.second == maxi) cnt++;
        }
        return cnt;
    }
};