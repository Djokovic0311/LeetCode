class Solution {
public:
    bool jump(vector<int>& arr, vector<bool>& visited, int i){
        if(i < 0 || i >= arr.size() || visited[i] != 0) return false;
        if(arr[i] == 0) return true;
        visited[i] = true;
        return jump(arr, visited, i+arr[i]) || jump(arr, visited, i-arr[i]);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return jump(arr, visited, start);
    }
};