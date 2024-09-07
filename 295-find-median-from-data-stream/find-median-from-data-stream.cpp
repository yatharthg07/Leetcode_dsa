class MedianFinder {
public:
    int size;
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    MedianFinder() {      
    }
    
    void addNum(int num) {
        maxh.push(num);
        if(!maxh.empty() && !minh.empty())
        {
            int x=maxh.top();
            int y=minh.top();
            if(x>y)
            {
                maxh.pop();
                minh.push(x);   
            }
        }
    if (maxh.size() > minh.size() + 1) {
        int temp = maxh.top();
        maxh.pop();
        minh.push(temp);
    }

   if (minh.size() > maxh.size() + 1) {
        int temp = minh.top();
        minh.pop();
        maxh.push(temp);
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