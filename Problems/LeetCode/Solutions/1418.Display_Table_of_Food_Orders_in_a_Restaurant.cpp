typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

bool CustomCompare(const string& a, const string& b) {
    int valA = 0 , valB = 0;
    for( int i = 0 ; i < a.length() ; i++ ) {
        valA *= 10;
        valA += a[i]-'0';
    }
    for( int i = 0 ; i < b.length() ; i++ ) {
        valB *= 10;
        valB += b[i]-'0';
    }
    return valA < valB;
};

class Solution {
public:
    string int2Str(int val) {
        if(val == 0)
            return "0";
        string s = "";
        while(val) {
            char c = '0' + (val%10);
            s.push_back(c);
            val /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    vvs displayTable(vvs & orders) {
        int n = orders.size();
        set<string> foods;
        set<string, decltype(&CustomCompare)> tables(&CustomCompare);
        for( int i = 0 ; i < n ; i++ )
            tables.insert(orders[i][1]);
        for( int i = 0 ; i < n ; i++ )
            foods.insert(orders[i][2]);
        map<string,int> hashFood;
        map<string,int> hashTable;
        int cntFood = 0;
        int cntTable = 0;
        for( auto it : foods )
            hashFood[it] = cntFood++;
        for( auto it : tables )
            hashTable[it] = cntTable++;
        vvi ar(cntTable,vi(cntFood,0));
        for( int i = 0 ; i < n ; i++ ) {
            int tableID = hashTable[orders[i][1]];
            int foodID = hashFood[orders[i][2]];
            ar[tableID][foodID]++;
        }
        vvs ans;
        vs firstRow;
        firstRow.push_back("Table");
        for( auto it : foods )
            firstRow.push_back(it);
        ans.push_back(firstRow);
        cntTable = 0;
        for( auto it : tables ) {
            vs row;
            row.push_back(it);
            for( int i = 0 ; i < cntFood ; i++ )
                row.push_back(int2Str(ar[cntTable][i]));
            ans.push_back(row);
            cntTable++;
        }
        return ans;
    }
};