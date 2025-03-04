class Solution {
public:
    string dternary(int n){
        string ternary = "";
        
        while(n > 0){
            ternary = char(n % 3 + '0') + ternary;
            n /= 3;
        }
        
        return ternary;
    }
    bool checkPowersOfThree(int n) {
        string tern = dternary(n);
        for(auto c: tern){
            if(c == '2') return false;
        }
        return true;
    }
};