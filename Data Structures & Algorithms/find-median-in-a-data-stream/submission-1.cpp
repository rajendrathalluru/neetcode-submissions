class MedianFinder {
    priority_queue<int> maxHeap; // smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // larger half

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Add to smaller half first
        maxHeap.push(num);

        // Make sure every element in maxHeap <= every element in minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Keep maxHeap the same size or one larger
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};