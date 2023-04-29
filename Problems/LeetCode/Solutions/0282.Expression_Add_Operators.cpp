typedef long long LL;

class Solution {
public:
    vector<string> ans;
    void f(string &num , int target , int idx , LL res , LL prev , string path) {
        if(idx == num.size()) {
            if(res == target)
                ans.push_back(path);
            return;
        }
        LL val = 0;
        string sub = "";
        for( int i = idx ; i < num.size() ; i++ ) {
            sub += num[i];
            val = 10*val + num[i] - '0';
            if(sub.size() > 1 && sub[0] == '0')
                break;
            if(idx == 0)
                f(num , target , i+1 , val , val , sub);
            else {
                f(num , target , i+1 , res+val , val , path+"+"+sub);
                f(num , target , i+1 , res-val , -val , path+"-"+sub);
                f(num , target , i+1 , (res-prev)+(prev*val) , prev*val , path+"*"+sub);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        f(num,target,0,0,0,"");
        return ans;
    }
};