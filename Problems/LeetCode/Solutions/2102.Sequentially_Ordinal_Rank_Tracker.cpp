#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, string>, null_type, less<pair<int, string>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class SORTracker {
public:
    int k;
    pbds tree;
    SORTracker() {
        k = 0;
    }
    void add(string name, int score) {
        pair<int, string> p = make_pair(-score, name);
        tree.insert(p);
    }
    string get() {
        string ans = tree.find_by_order(k)->second;
        k++;
        return ans;
    }
};
