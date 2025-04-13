class Solution {
public:
    int fourC1 = 4;
    int fiveC1 = 5;
    int mod = 1e9 + 7;
    long long binPow(long long x, long long n){
        long long res = 1;
        while(n>0){
            if(n&1){
                res = (x*res)%mod;
                n--;
            }
            else{
                x=(x*x)%mod;
                n/=2;
            }
        }
        return res%mod;
    }
    int countGoodNumbers(long long n) {
      //  primes are 2 3 5 7 
       // evens are 0 2 4 6 8
        long long places = n;//floor(log10(n)) + 1;
        long long ans = binPow(20,n/2);
      //  if(places>1) ans--;

        if(n&1) ans *= 5;
        return ans%mod;
    }
};