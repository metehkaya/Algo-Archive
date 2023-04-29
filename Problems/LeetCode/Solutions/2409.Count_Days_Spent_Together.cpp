class Solution {
public:
    int p[2][2];
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    void f(string& s , int id1 , int id2) {
        int m = stoi(s.substr(0,2)) - 1;
        int d = stoi(s.substr(3,2)) - 1;
        int total = d;
        for( int i = 0 ; i < m ; i++ )
            total += months[i];
        p[id1][id2] = total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        f(arriveAlice,0,0);
        f(leaveAlice,0,1);
        f(arriveBob,1,0);
        f(leaveBob,1,1);
        int l = max(p[0][0],p[1][0]);
        int r = min(p[0][1],p[1][1]);
        return max(r-l+1,0);
    }
};
