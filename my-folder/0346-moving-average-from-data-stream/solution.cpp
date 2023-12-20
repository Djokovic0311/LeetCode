class MovingAverage {
public:
    int windowSum = 0;
    int windowSize = 0;
    queue<int> q;
    MovingAverage(int size) {
        windowSize = size;
    }
    
    double next(int val) {
        if(q.size() < windowSize) {
            q.push(val);
            windowSum += val;
            return (double) windowSum / (double) q.size();
        } else {
            int tmp = q.front();
            q.pop();
            q.push(val);
            windowSum -= tmp;
            windowSum += val;
            return (double) windowSum / (double) windowSize;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
