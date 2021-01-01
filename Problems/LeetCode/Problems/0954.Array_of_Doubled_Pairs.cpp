class Solution {
public:
    bool canReorderDoubled(vector<int>& ar) {
        int n = ar.size();
        int cp=0,cn=0,c0=0;
        multiset<int> ps,ns;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] > 0)
                ps.insert(ar[i]),cp++;
            else if(ar[i] < 0)
                ns.insert(-ar[i]),cn++;
            else
                c0++;
        if(cp%2 or cn%2 or c0%2)
            return false;
        multiset<int>::iterator it;
        for( int i = 0 ; i < cp/2 ; i++ ) {
            it = ps.begin();
            int val = (*it);
            ps.erase(it);
            it = ps.find(2*val);
            if(it == ps.end())
                return false;
            ps.erase(it);
        }
        for( int i = 0 ; i < cn/2 ; i++ ) {
            it = ns.begin();
            int val = (*it);
            ns.erase(it);
            it = ns.find(2*val);
            if(it == ns.end())
                return false;
            ns.erase(it);
        }
        return true;
    }
};