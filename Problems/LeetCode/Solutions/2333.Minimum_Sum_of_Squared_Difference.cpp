#define fi first
#define se second
#define pb push_back
typedef long long LL;
typedef pair<int,int> pi;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int k = k1+k2;
        map<int,int> hashh;
        hashh[0] = 0;
        vector<int> diff;
        for( int i = 0 ; i < n ; i++ )
            diff.pb(abs(nums1[i]-nums2[i]));
        for( int i = 0 ; i < n ; i++ )
            hashh[diff[i]]++;
        while(k > 0) {
            map<int,int>::iterator mit = hashh.end();
            mit--;
            pi p = (*mit);
            int d = p.fi;
            int c = p.se;
            if(d == 0)
                return 0;
            mit--;
            pi p2 = (*mit);
            int d_less = p2.fi;
            int d_diff = d-d_less;
            LL rem = (LL) d_diff*c;
            if(rem <= k) {
                hashh.erase(d);
                hashh[d_less] += c;
                k -= rem;
            }
            else {
                hashh.erase(d);
                hashh[d-k/c] += c-(k%c);
                hashh[d-k/c-1] += k%c;
                break;
            }
        }
        LL ans = 0;
        map<int,int>::iterator mit = hashh.begin();
        while(mit != hashh.end()) {
            pi p = (*mit);
            int d = p.fi;
            int c = p.se;
            ans += (LL)d*d*c;
            mit++;
        }
        return ans;
    }
};
