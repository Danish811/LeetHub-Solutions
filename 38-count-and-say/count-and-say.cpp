class Solution {
public:

    string countAndSay(int n) {
         string ans = "1";
         n--;
         while(n--){
            int start=0;
            char key = ans[0];
            int i=0;
            string temp = "";
            while(start<ans.size() && i<ans.size()){
                while(i<ans.size() && ans[i] == key) i++;
               
                temp += to_string( i - start );
                temp += key;
                key = ans[i];
                start = i;
                
            }
            cout << temp << endl;
            ans = temp;
         }
         return ans;
    }
};