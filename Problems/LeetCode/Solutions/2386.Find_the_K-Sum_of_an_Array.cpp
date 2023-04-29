#define fi first
#define se second
typedef long long LL;
typedef pair<LL,int> pi;

class Solution {
public:
    long long kSum(vector<int>& ar, int k) {
        int n = ar.size();
        LL sum = 0;
        vector<int> v;
        for( int i = 0 ; i < n ; i++ ) {
            sum += max(ar[i],0);
            v.push_back(abs(ar[i]));
        }
        sort(v.begin(),v.end());
        priority_queue<pi,vector<pi>,greater<pi>> heap;
        heap.push(pi(v[0],0));
        LL rem = 0;
        while(--k) {
            pi temp = heap.top();
            heap.pop();
            rem = temp.fi;
            int idx = temp.se;
            if(idx+1 < n) {
                heap.push(pi(rem+v[idx+1],idx+1));
                heap.push(pi(rem-v[idx]+v[idx+1],idx+1));
            }
        }
        return sum-rem;
    }
};
