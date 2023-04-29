class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    int id,n;
    vector<int> nums;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for( int i = 0 ; i < nestedList.size() ; i++ )
            dfs(nestedList[i]);
        id = 0;
        n = nums.size();
    }
    void dfs(NestedInteger ni) {
        if(ni.isInteger())
            nums.push_back(ni.getInteger());
        else {
            vector<NestedInteger> v = ni.getList();
            for( int i = 0 ; i < v.size() ; i++ )
                dfs(v[i]);
        }
    }
    int next() {
        return nums[id++];
    }
    bool hasNext() {
        return id < n;
    }
};