class SnapshotArray {
public:
    int n;
    int nSnap;
    vector<vector<pair<int,int>>>v;
    SnapshotArray(int length) {
        nSnap=0;
        v.clear();
        v.resize(n=length);
        for( int i = 0 ; i < n ; i++ )
            v[i].push_back(make_pair(0,0));
    }
    void set(int index, int val) {
        int sz = v[index].size();
        if(v[index][sz-1].second == nSnap)
            v[index][sz-1].first = val;
        else
            v[index].push_back(make_pair(val,nSnap));
    }
    int snap() {
        nSnap++;
        return nSnap-1;
    }
    int get(int index, int snap_id) {
        int sz = v[index].size();
        int l=0,r=sz-1,last=sz-1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(v[index][mid].second <= snap_id)
                last=mid,l=mid+1;
            else
                r=mid-1;
        }
        return v[index][last].first;
    }
};