class Excel {
public:
    map<string,pair<int,vector<string>>> mp;
    Excel(int height, char width) {}
    string get_cell_key(int row , char c) {
        string s = "";
        s.push_back(c);
        s += to_string(row);
        return s;
    }
    int get_sum(string key) {
        int sum = 0;
        auto v = std::get<1>(mp[key]);
        for( string& entry : v ) {
            int idx = entry.find(':');
            if(idx != -1) {
                int tlr = stoi(entry.substr(1,idx-1));
                int brr = stoi(entry.substr(idx+2));
                char tlc = entry[0];
                char brc = entry[idx+1];
                for( int r = tlr ; r <= brr ; r++ )
                    for( char c = tlc ; c <= brc ; c++ )
                        sum += get_cell_value(get_cell_key(r,c));
            }
            else
                sum += get_cell_value(entry);
        }
        return sum;
    }
    int get_cell_value(string key) {
        if(mp.find(key) == mp.end())
            return 0;
        auto cell_value = mp[key];
        if(std::get<1>(cell_value).empty())
            return std::get<0>(cell_value);
        else
            return get_sum(key);
    }
    void set(int row, char column, int val) {
        string key = get_cell_key(row, column);
        mp[key] = make_pair(val, vector<string>());
    }
    int get(int row, char column) {
        string key = get_cell_key(row, column);
        return get_cell_value(key);
    }
    int sum(int row, char column, vector<string> numbers) {
        string key = get_cell_key(row, column);
        auto p = make_pair(0, numbers);
        mp[key] = p;
        return get_sum(key);
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */
