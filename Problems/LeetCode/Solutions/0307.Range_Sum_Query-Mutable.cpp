class NumArray {
public:
    int n;
    vector<int> ar;
    vector<int> tree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        ar = nums;
        tree.resize(n+1,0);
        for( int i = 0 ; i < n ; i++ )
            updateTree(i+1, ar[i]);
    }
    void update(int i, int val) {
        int diff = val - ar[i];
        ar[i] = val;
        updateTree(i+1, diff);
    }
    int sumRange(int i, int j) {
        return queryTree(j+1) - queryTree(i);
    }
    void updateTree(int i, int add) {
        while(i <= n) {
            tree[i] += add;
            i += (i & (-i));
        }
    }
    int queryTree(int i) {
        int sum = 0;
        while(i) {
            sum += tree[i];
            i -= (i & (-i));
        }
        return sum;
    }
};