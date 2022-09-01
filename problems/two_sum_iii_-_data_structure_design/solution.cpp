class TwoSum {
public:
    map<long long,long long>mpp;
    TwoSum() {
    }
    
    void add(int number) {
        mpp[number]++;
    }
    
    bool find(int value) {
        for(auto x : mpp)
        {
            if(mpp.find(value-x.first)!=mpp.end())
            {
                if(value-x.first==x.first && mpp[x.first]>=2)
                return true;
                if(value-x.first!=x.first)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */