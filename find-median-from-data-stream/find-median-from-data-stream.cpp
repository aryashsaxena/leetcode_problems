class MedianFinder {
public:
    priority_queue<int> mxq;
    priority_queue<int,vector<int>,greater<int>> mnq;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mxq.push(num);
        mnq.push(mxq.top());
        mxq.pop();

        if(mnq.size()>mxq.size()){
            mxq.push(mnq.top());
            mnq.pop();
        }
    }
    
    double findMedian() {
        if(mxq.size()==mnq.size()){
            return (double)(mxq.top()+mnq.top())/2.0;
        }
        return mxq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */