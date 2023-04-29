class MyHashSet {
public:
    static const int maxs = 10007;
    int val[maxs];
    MyHashSet() {
        memset(val,-1,sizeof(val));
    }
    int func(int key) {
        return key / maxs;
    }
    void add(int key) {
        int idx = -1;
        int id = func(key);
        while(val[id] != -1 and val[id] != key) {
            if(idx == -1 and val[id] == -2)
                idx = id;
            id = (id+1) % maxs;
        }
        if(val[id] == key)
            return;
        if(idx == -1)
            idx = id;
        val[idx] = key;
    }
    void remove(int key) {
        int id = func(key);
        while(val[id] != -1 and val[id] != key)
            id = (id+1) % maxs;
        if(val[id] == key)
            val[id] = -2;
    }
    bool contains(int key) {
        int id = func(key);
        while(val[id] != -1 and val[id] != key)
            id = (id+1) % maxs;
        return val[id] == key;
    }
};