class Solution {
public:
    int last[26];
    int nxt[100][26];
    int cycle[100][100][2];
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length();
        int len2 = s2.length();
        memset(nxt,-1,sizeof(nxt));
        memset(last,-1,sizeof(last));
        memset(cycle,-1,sizeof(cycle));
        for( int i = 2*len1-1 ; i >= 0 ; i-- ) {
            last[s1[i%len1]-'a'] = i;
            if(i < len1)
                for( int j = 0 ; j < 26 ; j++ )
                    nxt[i][j] = last[j];
        }
        int k1 = 0 , k2 = 0;
        int idx1 = 0 , idx2 = 0;
        bool check_cycle = true;
        while(k1 < n1) {
            int c = s2[idx2]-'a';
            int nxt_idx = nxt[idx1][c];
            if(nxt_idx == -1)
                return 0;
            if(nxt_idx >= len1 && k1+1 >= n1)
                break;
            if(check_cycle) {
                if(cycle[idx1][idx2][0] != -1) {
                    int diff1 = k1 - cycle[idx1][idx2][0];
                    int diff2 = k2 - cycle[idx1][idx2][1];
                    int max_diff1 = (n1-1) - cycle[idx1][idx2][0];
                    int q = max_diff1 / diff1;
                    k1 = cycle[idx1][idx2][0] + q*diff1;
                    k2 = cycle[idx1][idx2][1] + q*diff2;
                    check_cycle = false;
                    continue;
                }
                cycle[idx1][idx2][0] = k1;
                cycle[idx1][idx2][1] = k2;
            }
            idx1 = nxt_idx+1;
            if(idx1 >= len1)
                idx1 -= len1 , k1++;
            idx2++;
            if(idx2 >= len2)
                idx2 -= len2 , k2++;
        }
        return k2/n2;
    }
};
