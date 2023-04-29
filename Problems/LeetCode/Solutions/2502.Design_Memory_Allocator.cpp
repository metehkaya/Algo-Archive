class Allocator {
public:
    int n;
    vector<int> v;
    Allocator(int n) {
        this->n = n;
        v.resize(n,0);
    }
    int allocate(int sz, int id) {
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && v[i] == v[j])
                j++;
            if(v[i] == 0 && j-i >= sz) {
                for( int k = 0 ; k < sz ; k++ )
                    v[i+k] = id;
                return i;
            }
        }
        return -1;
    }
    int free(int id) {
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            if(v[i] == id)
                v[i] = 0 , cnt++;
        return cnt;
    }
};
