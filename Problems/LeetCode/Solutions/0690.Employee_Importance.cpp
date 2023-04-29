class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    map<int,Employee*> mp;
    int dfs(Employee* u) {
        int res = u->importance;
        int deg = u->subordinates.size();
        for( int i = 0 ; i < deg ; i++ )
            res += dfs(mp[u->subordinates[i]]);
        return res;
    }
    int getImportance(vector<Employee*> ar, int id) {
        int n = ar.size() , ans;
        for( int i = 0 ; i < n ; i++ )
            mp[ar[i]->id] = ar[i];
        ans = dfs(mp[id]);
        return ans;
    }
};