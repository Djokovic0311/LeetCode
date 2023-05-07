class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0);
        vector<int> answer;
        int count = 0;
        for (const vector<int>& query : queries) {
            int index = query[0];
            int color = query[1];
            
            // cout << count << endl;
            // Check if the current index has the same color as its left neighbor
            if (index > 0 && nums[index - 1] == nums[index] && nums[index] != 0) {
                // cout << "the current index has the same color as its left neighbor" << endl;
                count--;
            }
            
            // Check if the current index has the same color as its right neighbor
            if (index < n - 1 && nums[index + 1] ==  nums[index] && nums[index] != 0) {
                // cout << "the current index has the same color as its right neighbor" << endl;
                count--;
            }
            
            nums[index] = color;
            
            // Check if the current index has the same color as its left neighbor after coloring
            if (index > 0 && nums[index - 1] == color) {
                // cout << "the current index has the same color as its left neighbor after coloring" << endl;
                count++;
            }
            
            // Check if the current index has the same color as its right neighbor after coloring
            if (index < n - 1 && nums[index + 1] == color) {
                // cout << "the current index has the same color as its right neighbor after coloring" << endl;
                count++;
            }
            // cout << endl;
            answer.push_back(count);
        }
        
        return answer;        
    }
};
