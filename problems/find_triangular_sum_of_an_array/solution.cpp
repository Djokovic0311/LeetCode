class Solution {
public:
    vector<long long> getRow(int rowIndex) {
        vector<long long> row = {1};
        vector<long long> newRow;
        while(row.size() <= rowIndex){
            newRow = {};
            newRow.push_back(1);
            for(int i=0; i<row.size()-1; i++){
                newRow.push_back((row[i]+row[i+1])%10);
            }
            newRow.push_back(1);//添加每行的末尾元素
            row = newRow;
        }
        return row;
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<long long> weight = getRow(n-1);
        for(int i = 0; i < n; i++) {
            // cout << weight[i] << ' ';
            res += (nums[i] * (weight[i] % 10));
            res %= 10;
        }
        return res;
    }
};