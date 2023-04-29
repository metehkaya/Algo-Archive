class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k <= numOnes+numZeros)
            return min(k,numOnes);
        else
            return numOnes-(k-(numOnes+numZeros));
    }
};
