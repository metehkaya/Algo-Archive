typedef long long LL;

class Solution {
public:
    int init(int cx , int cy , int id , vector<int>& tree , vector<int>& nums1) {
        if(cx == cy)
            return tree[id] = nums1[cx];
        int mid = (cx+cy) >> 1;
        int l = init(cx,mid,2*id+1,tree,nums1);
        int r = init(mid+1,cy,2*id+2,tree,nums1);
        return tree[id] = l+r;
    }
    int update(int cx , int cy , int qx , int qy , int id , vector<int>& tree , vector<bool>& lazy) {
        int len = cy-cx+1;
        if(lazy[id]) {
            lazy[id] = false;
            tree[id] = len-tree[id];
            if(len > 1)
                lazy[2*id+1] = !lazy[2*id+1] , lazy[2*id+2] = !lazy[2*id+2];
        }
        if(qy < cx or cy < qx)
            return tree[id];
        if(qx <= cx and cy <= qy) {
            tree[id] = len-tree[id];
            if(len > 1)
                lazy[2*id+1] = !lazy[2*id+1] , lazy[2*id+2] = !lazy[2*id+2];
            return tree[id];
        }
        int mid = (cx+cy) >> 1;
        int l = update(cx,mid,qx,qy,2*id+1,tree,lazy);
        int r = update(mid+1,cy,qx,qy,2*id+2,tree,lazy);
        return tree[id] = l+r;
    }
    vector<LL> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        vector<int> tree(4*n,0);
        vector<bool> lazy(4*n,false);
        init(0,n-1,0,tree,nums1);
        LL sum = 0;
        for(int num : nums2)
            sum += num;
        vector<LL> ans;
        for(auto q : queries) {
            if(q[0] == 1)
                update(0,n-1,q[1],q[2],0,tree,lazy);
            else if(q[0] == 2)
                sum += (LL)q[1]*tree[0];
            else
                ans.push_back(sum);
        }
        return ans;
    }
};
