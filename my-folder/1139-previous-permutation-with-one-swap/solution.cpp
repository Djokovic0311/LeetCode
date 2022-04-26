class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr;
        int j = n-2;
        while(j >= 0 && arr[j] <= arr[j+1]) {
            j--;
        }
        if(j < 0) return arr;
        int i=n-1;
        while(i>0 && arr[i]>=arr[j])
        {
            i--;
        }
        while(i>0 && arr[i]==arr[i-1])
        {
            i--;
        }
        swap(arr[j],arr[i]);
        return arr;
    }
};
