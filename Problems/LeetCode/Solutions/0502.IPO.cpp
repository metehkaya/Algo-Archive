#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pi> v;
        int n = profits.size() , idx = 0;
        for( int i = 0 ; i < n ; i++ )
            v.pb(pi(capital[i],profits[i]));
        sort(v.begin(),v.end());
        priority_queue<int> heap;
        while(k--) {
            while(idx < n && v[idx].fi <= w)
                heap.push(v[idx++].se);
            if(heap.empty())
                break;
            w += heap.top();
            heap.pop();
        }
        return w;
    }
};
