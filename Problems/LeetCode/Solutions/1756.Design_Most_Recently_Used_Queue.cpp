#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class MRUQueue {
public:
    int idx;
    ordered_set mru;
    MRUQueue(int n) {
        for( int i = 1 ; i <= n ; i++ )
            mru.insert({i,i});
        idx = n;
    }
    int fetch(int k) {
        idx++;
        auto it = mru.find_by_order(k-1);
        int ans = it->second;
        mru.erase(it);
        mru.insert({idx,ans});
        return ans;
    }
};
