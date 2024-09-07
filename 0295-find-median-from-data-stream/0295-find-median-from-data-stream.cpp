class MedianFinder {
public:
    int size;
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    MedianFinder() {      
    }
    
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        if (minh.size() > maxh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }

        
    }
    
    double findMedian() {
        if(minh.size()-maxh.size()!=0)
        {
            return maxh.size()-minh.size()==1?maxh.top():minh.top();
        }
        else
        {
            return (maxh.top()+minh.top())/2.0;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */