class Solution {
public:
//     lōng  long countSubarrys(long long n)
//     {
//         return n * (n + 1) / 2;
//     }

//     // function to count the number of sub-arrays with
//     // maximum greater then L and less than R.
//     long long countSubarrays(vector<int> a, int n, int L, int R)
//     {
//         long long res = 0;

//         // exc is going to store count of elements
//         // smaller than L in current valid subarray.
//         // inc is going to store count of elements
//         // smaller than or equal to R.
//         long long exc = 0, inc = 0;

//         // traverse through all elements of the array
//         for (int i = 0; i < n; i++) {

//             // If the element is greater than R,
//             // add current value to result and reset
//             // values of exc and inc.
//             if (a[i] > R || a[i] < L) {
//                 res += (countSubarrys(inc) - countSubarrys(exc));
//                 inc = 0;
//                 exc = 0;
//             }

//             // if it is less than L, then it is included
//             // in the sub-arrays
//             else if (a[i]> L) {
//                 exc++;
//                 inc++;
//             }

//             // if >= L and <= R, then count of
//             // subarrays formed by previous chunk
//             // of elements formed by only smaller
//             // elements is reduced from result.
//             else {
//                 res -= countSubarrys(exc);
//                 exc = 0;
//                 inc++;
//             }
//         }

//         // Update result.
//         res += (countSubarrys(inc) - countSubarrys(exc));

//         // returns the count of sub-arrays
//         return res;
//     }


    long long countSubarrays(vector<int>& arr, int minK, int maxK) {
        long res = 0, j = 0, jmin = -1, jmax = -1, n = arr.size();
        for (int i = 0; i < n; ++i) {
            if  (arr[i] < minK || arr[i] > maxK) {
                jmin = jmax = -1;
                j = i + 1;
            }
            if (arr[i] == minK) jmin = i;
            if (arr[i] == maxK) jmax = i;
            res += max(0L, min(jmin, jmax) - j + 1);
        }
        return res;     
    }
};