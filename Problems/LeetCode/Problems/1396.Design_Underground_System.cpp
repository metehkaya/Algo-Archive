#define fi first
#define se second
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<string,string> pss;

class UndergroundSystem {
public:
    map<pss,pii> avg;
    map<int,pis> checkin;
    UndergroundSystem() {}
    void checkIn(int id, string name, int t) {
        checkin[id] = pis(t,name);
    }
    void checkOut(int id, string name, int t) {
        pis temp = checkin[id];
        int stime = temp.fi;
        string sname = temp.se;
        pss p = pss(sname,name);
        avg[p].fi += t-stime;
        avg[p].se++;
    }
    double getAverageTime(string s, string t) {
        pss p = pss(s,t);
        auto it = avg.find(p);
        if(it == avg.end())
            return 0;
        return (double) (it->se.fi) / (it->se.se);
    }
};