#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

class Solution {
public:
    vector<int> mapping;
    void getDigits(int num , vector<int>& digs) {
        if(num == 0)
            digs.pb(0);
        else
            while(num) {
                digs.pb(num%10);
                num /= 10;
            }
        reverse(digs.begin(),digs.end());
    }
    int getNewNum(vector<int>& digs) {
        int num = 0;
        for( int i = 0 ; i < digs.size() ; i++ )
            num = 10*num + mapping[digs[i]];
        return num;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        this->mapping = mapping;
        vector<pii> ar;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ ) {
            int num = nums[i];
            vector<int> digs;
            getDigits(num,digs);
            int newNum = getNewNum(digs);
            ar.pb(pii(pi(newNum,i),num));
        }
        sort(ar.begin(),ar.end());
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ )
            ans.pb(ar[i].se);
        return ans;
    }
};
