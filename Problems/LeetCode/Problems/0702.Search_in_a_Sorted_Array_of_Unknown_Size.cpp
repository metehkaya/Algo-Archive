class ArrayReader {
public:
    int get(int index);
};

class Solution {
public:
    const int MAXS = 10000;
    int search(const ArrayReader& reader, int target) {
        int l = 1 , r = MAXS , n = 0;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(reader.get(mid-1) == INT_MAX)
                r = mid-1;
            else
                l = mid+1 , n = mid;
        }
        l = 0 , r = n-1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            int val = reader.get(mid);
            if(val < target)
                l = mid+1;
            else if(val > target)
                r = mid-1;
            else
                return mid;
        }
        return -1;
    }
};