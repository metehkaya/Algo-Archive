class MedianFinder {
public:
    int n = 0;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    MedianFinder() {}
    void addNum(int num) {
        if(n == 0)
            minHeap.push(num);
        else if(n & 1) {
            if(num <= minHeap.top())
                maxHeap.push(num);
            else {
                int temp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
            }
        }
        else {
            if(num >= maxHeap.top())
                minHeap.push(num);
            else {
                int temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(temp);
            }
        }
        n++;
    }
    double findMedian() {
        double ans;
        if(n&1)
            ans = minHeap.top();
        else
            ans = (minHeap.top() + maxHeap.top()) / 2.0;
        return ans;
    }
};
