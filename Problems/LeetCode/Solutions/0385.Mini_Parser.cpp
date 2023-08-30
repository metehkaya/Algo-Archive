class NestedInteger {
public:
    NestedInteger();
    NestedInteger(int value);
    bool isInteger() const;
    int getInteger() const;
    void setInteger(int value);
    void add(const NestedInteger &ni);
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(istringstream &in) {
        int num;
        if(in >> num)
            return NestedInteger(num);
        in.clear();
        in.get();
        NestedInteger res;
        while(in.peek() != ']') {
            res.add(deserialize(in));
            if(in.peek() == ',')
                in.get();
        }
        in.get();
        return res;
    }
    NestedInteger deserialize(string s) {
        istringstream in(s);
        return deserialize(in);
    }
};
