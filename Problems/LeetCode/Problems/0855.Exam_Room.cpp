typedef pair<int,int> pi;
typedef pair<pi,bool> pib;

class ExamRoom {
public:
    struct set_compare {
        pi getSeatDist(const pib& p) const {
            if(p.first.first == -1)
                return make_pair(0,p.first.second);
            if(p.second == 1)
                return make_pair(p.first.second-1,p.first.second-1-p.first.first);
            int seat = (p.first.first + p.first.second) / 2;
            return make_pair(seat, seat-p.first.first);
        }
        bool operator() (const pib& a, const pib& b) const {
            pi pa = getSeatDist(a);
            int seatA = pa.first;
            int distA = pa.second;
            pi pb = getSeatDist(b);
            int seatB = pb.first;
            int distB = pb.second;
            if(distA != distB)
                return distA > distB;
            return seatA < seatB;
        }
    };
    int n;
    int cnt;
    set<int> seats;
    set<pib,set_compare> myset;
    ExamRoom(int N) {
        n = N;
        cnt = 0;
        seats.insert(-1);
        seats.insert(N);
        myset.insert(pib(pi(-1,n),1));
    }
    int seat() {
        if(cnt == 0) {
            seats.insert(0);
            myset.clear();
            myset.insert(pib(pi(-1,0),0));
            myset.insert(pib(pi(0,n),1));
            cnt = 1;
            return 0;
        }
        cnt++;
        pib p = *(myset.begin());
        int seat;
        if(p.first.first == -1)
            seat = 0;
        else if(p.first.second == n)
            seat = n-1;
        else
            seat = (p.first.first + p.first.second) / 2;
        seats.insert(seat);
        myset.erase(p);
        myset.insert(pib(pi(p.first.first,seat),0));
        myset.insert(pib(pi(seat,p.first.second),p.first.second==n));
        return seat;
    }
    void leave(int p) {
        cnt--;
        set<int>::iterator sit;
        sit = seats.upper_bound(p);
        int r = (*sit);
        sit = seats.lower_bound(p);
        sit--;
        int l = (*sit);
        seats.erase(p);
        myset.erase(pib(pi(l,p),0));
        myset.erase(pib(pi(p,r),r==n));
        myset.insert(pib(pi(l,r),r==n));
    }
};