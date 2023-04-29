#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int nthSuperUglyNumber(int m, vector<int>& ar) {
        int n = ar.size() , ans;
        set<pi> myset;
        myset.insert(pi(1,0));
        while(true) {
            set<pi>::iterator it = myset.begin();
            pi p = (*it);
            myset.erase(it);
            int num = p.fi;
            int k = p.se;
            if(--m == 0) {
                ans = num;
                break;
            }
            if(num <= INT_MAX / ar[k])
                myset.insert(pi(num*ar[k],k));
            if(num != 1 && k+1 < n && num / ar[k] <= INT_MAX / ar[k+1])
                myset.insert(pi(num/ar[k]*ar[k+1],k+1));
        }
        return ans;
    }
};