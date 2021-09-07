class NumArray {
public:
    NumArray(vector<int>& nums)
    {        
        m_sums.resize(nums.size()+1, 0);
        int acc=0;
        transform(nums.cbegin(), nums.cend(), m_sums.begin()+1, [&acc](int a){return acc+=a;});
    }
    
    int sumRange(int left, int right) 
    {     
        return m_sums[right+1] - m_sums[left];
    }
private:        
    std::vector<int> m_sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */