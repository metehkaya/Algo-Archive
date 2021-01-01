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
    int getSum(const vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for( int i = 0 ; i < nestedList.size() ; i++ ) {
            if( nestedList[i].isInteger() )
                sum += depth * nestedList[i].getInteger();
            else
                sum += getSum( nestedList[i].getList() , depth+1 );
        }
        return sum;
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        if(nestedList.size() == 0)
            return 0;
        return getSum(nestedList,1);
    }
};