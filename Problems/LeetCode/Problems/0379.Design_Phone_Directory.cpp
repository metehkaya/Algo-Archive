class PhoneDirectory {
public:
    unordered_set<int> myset;
    PhoneDirectory(int maxNumbers) {
        for( int i = 0 ; i < maxNumbers ; i++ )
            myset.insert(i);
    }
    int get() {
        if(myset.empty())
            return -1;
        unordered_set<int>::iterator iter = myset.begin();
        int val = (*iter);
        myset.erase(iter);
        return val;
    }
    bool check(int number) {
        return myset.find(number) != myset.end();
    }
    void release(int number) {
        myset.insert(number);
    }
};