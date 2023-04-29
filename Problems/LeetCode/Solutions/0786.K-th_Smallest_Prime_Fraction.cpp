#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;
typedef pair<double,pi> pdi;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& ar, int k) {
        int n = ar.size();
        priority_queue<pdi,vector<pdi>,greater<pdi>> heap;
        for( int i = 1 ; i < n ; i++ )
            heap.push(pdi((double)ar[0]/ar[i],pi(0,i)));
        vector<int> ans(2);
        while(k--) {
            pdi temp = heap.top();
            heap.pop();
            int i = temp.se.fi;
            int j = temp.se.se;
            ans[0] = ar[i] , ans[1] = ar[j];
            if(++i < j)
                heap.push(pdi((double)ar[i]/ar[j],pi(i,j)));
        }
        return ans;
    }
};
