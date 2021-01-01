class MyHashMap {
public:
    static const int maxs = 10007;
    int key[maxs];
    int val[maxs];
    MyHashMap() {
        memset(key,-1,sizeof(key));
        memset(val,-1,sizeof(val));
    }
    int func(int key) {
        return key / maxs;
    }
    void put(int k, int v) {
        int idx = -1;
        int id = func(k);
        while(key[id] != -1 and key[id] != k) {
            if(idx == -1 and key[id] == -2)
                idx = id;
            id = (id+1) % maxs;
        }
        if(idx == -1)
            idx = id;
        key[idx] = k;
        val[idx] = v;
    }
    int get(int k) {
        int id = func(k);
        while(key[id] != -1 and key[id] != k)
            id = (id+1) % maxs;
        return val[id];
    }
    void remove(int k) {
        int id = func(k);
        while(key[id] != -1 and key[id] != k)
            id = (id+1) % maxs;
        if(key[id] == k)
            key[id] = -2 , val[id] = -1;
    }
};