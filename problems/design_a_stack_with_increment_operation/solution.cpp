class CustomStack {
public:
    int max;
    vector<int> v;
    CustomStack(int maxSize) {
        max=maxSize;
    }
    
    void push(int x) {
        if(v.size()<max)
            v.push_back(x);
    }
    
    int pop() {
        if(v.size()==0)
            return -1;
        int x=v.back();
        v.pop_back();
        return x;
    }
    void increment(int k, int val) {
        int x=k;
        if(v.size()<k)
            x=v.size();
        for(int i=0;i<x;i++)
        {
            v[i]+=val;
        }
    }
};
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */