typedef long long LL;

class BookMyShow {
public:
    static const int maxg = 230;
    int n,m;
    vector<int> rem;
    LL groupRemSum[maxg];
    multiset<int> groupRems[maxg];
    set<int> nonempty;
    BookMyShow(int n, int m) {
        this->n = n;
        this->m = m;
        memset(groupRemSum,0,sizeof(groupRemSum));
        for( int i = 0 ; i < n ; i++ ) {
            groupRemSum[i/maxg] += m;
            rem.push_back(m);
            nonempty.insert(i);
            groupRems[i/maxg].insert(m);
        }
    }
    int getMax(int g) {
        if(groupRems[g].empty())
            return 0;
        multiset<int>::iterator it = groupRems[g].end();
        it--;
        return (*it);
    }
    void eraseRem(int g , int num , int k) {
        multiset<int>::iterator it = groupRems[g].find(num);
        groupRems[g].erase(it);
        groupRems[g].insert(num-k);
    }
    vector<int> gather(int k, int maxRow) {
        vector<int> ans;
        int gid = -1 , rid = -1;
        int lastGroup = maxRow/maxg;
        for( int i = 0 ; i < lastGroup ; i++ )
            if(getMax(i) >= k) {
                for( int j = maxg*i ; ; j++ )
                    if(rem[j] >= k) {
                        rid = j;
                        break;
                    }
                gid = i;
                break;
            }
        if(gid == -1) {
            for( int i = maxg*lastGroup ; i <= maxRow ; i++ )
                if(rem[i] >= k) {
                    gid = lastGroup;
                    rid = i;
                    break;
                }
        }
        if(gid != -1) {
            ans.push_back(rid);
            ans.push_back(m-rem[rid]);
            eraseRem(gid,rem[rid],k);
            rem[rid] -= k;
            groupRemSum[gid] -= k;
            if(rem[rid] == 0)
                nonempty.erase(rid);
        }
        return ans;
    }
    bool scatter(int k, int maxRow) {
        LL totalRem = 0;
        int lastGroup = maxRow/maxg;
        for( int i = 0 ; i < lastGroup ; i++ )
            totalRem += groupRemSum[i];
        for( int i = maxg*lastGroup ; i <= maxRow ; i++ )
            totalRem += rem[i];
        bool ans = false;
        if(totalRem >= (LL) k) {
            ans = true;
            set<int>::iterator it = nonempty.begin();
            while(k != 0) {
                int rid = (*it);
                int gid = rid/maxg;
                int tobeused = min(rem[rid],k);
                k -= tobeused;
                eraseRem(gid,rem[rid],tobeused);
                rem[rid] -= tobeused;
                groupRemSum[gid] -= tobeused;
                if(rem[rid] == 0)
                    nonempty.erase(rid);
                it++;
            }
        }
        return ans;
    }
};
