class SmallestInfiniteSet {
public:
    set<int> s;
    SmallestInfiniteSet() {
        for( int i = 1 ; i <= 1000 ; i++ )
            s.insert(i);
    }
    int popSmallest() {
        set<int>::iterator sit = s.begin();
        int val = (*sit);
        s.erase(sit);
        return val;
    }
    void addBack(int num) {
        s.insert(num);
    }
};
