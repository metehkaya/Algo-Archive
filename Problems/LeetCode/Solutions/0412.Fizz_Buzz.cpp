class Solution {
public:
    string int2str(int n) {
        string res = "";
        while(n) {
            res.push_back('0'+(n%10));
            n /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for( int i = 1 ; i <= n ; i++ ) {
            string res;
            if(i%15 == 0)
                res = "FizzBuzz";
            else if(i%3 == 0)
                res = "Fizz";
            else if(i%5 == 0)
                res = "Buzz";
            else
                res = int2str(i);
            ans.push_back(res);
        }
        return ans;
    }
};