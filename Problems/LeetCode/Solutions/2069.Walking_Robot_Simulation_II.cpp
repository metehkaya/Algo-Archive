class Robot {
public:
    int n,total,w,h;
    vector<vector<int>> ar;
    Robot(int w, int h) {
        total = 0;
        this->w = w;
        this->h = h;
        for( int i = 0 ; i < w-1 ; i++ )
            ar.push_back({i,0});
        for( int i = 0 ; i < h-1 ; i++ )
            ar.push_back({w-1,i});
        for( int i = w-1 ; i > 0 ; i-- )
            ar.push_back({i,h-1});
        for( int i = h-1 ; i > 0 ; i-- )
            ar.push_back({0,i});
        n = ar.size();
    }
    void step(int num) {
        total += num;
    }
    vector<int> getPos() {
        return ar[total%n];
    }
    string getDir() {
        if(total == 0)
            return "East";
        int k = total % n;
        if(k > 0 && k <= w-1)
            return "East";
        else if(k > w-1 && k <= (w-1)+(h-1))
            return "North";
        else if(k > (w-1)+(h-1) && k <= (w-1)+(h-1)+(w-1))
            return "West";
        else
            return "South";
    }
};
