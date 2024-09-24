class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        small.push(num);

        if (small.size()>0 && large.size()>0 && small.top() > large.top()){
            large.push(small.top());
            small.pop();
        }

        if (small.size() > large.size() + 1){
            large.push(small.top());
            small.pop(); 
        }

        if (small.size() + 1 < large.size()){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) return small.top();
        if (small.size() < large.size()) return large.top();
        return  (small.top() + large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */