class BinaryMatrix {
public:
	int get(int x, int y);
	vector<int> dimensions();
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &mat) {
        vector<int> dims = mat.dimensions();
        int n = dims[0];
        int m = dims[1];
        int minCol = m;
        for( int i = 0 ; i < n ; i++ ) {
            int l=0,r=m-1;
            while(l <= r) {
                int mid = (l+r) >> 1;
                int val = mat.get(i,mid);
                if(val == 0)
                    l = mid+1;
                else {
                    r = mid-1;
                    minCol = min(minCol, mid);
                }
            }
        }
        if(minCol == m)
            minCol = -1;
        return minCol;
    }
};