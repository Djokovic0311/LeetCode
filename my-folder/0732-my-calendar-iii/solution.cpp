class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        lines[start]++;
        lines[end]--;
        int mx = 0, cnt = 0;
        for (auto x : lines) {
            // here we calculate the prefix sum
            cnt += x.second;
            // and record the maximum overlapping intervals
            mx = max(mx, cnt);
        }
        return mx;        
    }
private:
    map<int, int> lines;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
