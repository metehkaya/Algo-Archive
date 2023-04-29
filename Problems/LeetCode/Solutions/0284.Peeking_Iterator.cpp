class PeekingIterator : public Iterator {
public:
    int n,idx;
    vector<int> ar;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        idx = 0;
	    ar = nums;
        n = ar.size();
	}
	int peek() {
        return ar[idx];
	}
	int next() {
	    return ar[idx++];
	}
	bool hasNext() const {
	    return idx < n;
	}
};