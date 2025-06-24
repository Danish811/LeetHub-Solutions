class Solution {
public:
    bool Prime (int x){
        if(x==1) return false;
        for(int i=2; i*i<=x; i++){
            if(x%i==0)return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int,int> Cnt;
        for(auto ele: nums){
            Cnt[ele]++;
        }
        for(auto ele: Cnt){
            cout << ele.first << " " << ele.second << endl;
            if(Prime(ele.second)) return true;
        }
        return false;
    }
};