class MovingAverage {
public:
    MovingAverage(int size) : m_size(size), m_sum(0) {}
    
    double next(int val) {
        // Queue is full (Reached sliding window's size)
        if (m_q.size() == m_size) {
            m_sum -= m_q.front();
            m_q.pop();
        }
        
        m_q.push(val);
        m_sum += val;
        
        return m_sum / (double)m_q.size();
    }
    
private:
    queue<int> m_q; // store the numbers (up to sliding window size)
    int m_size;     // size of sliding window
    int m_sum;      // current sum of the numbers
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
