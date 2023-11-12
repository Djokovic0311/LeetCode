class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int res1 = 0, res2 = 1;
        bool valid1 = true, valid2 = true;
        if(nums1[n-1] > nums2[n-1]) {
            for(int i = 0; i < n-1; i++) {
                if(min(nums1[i], nums2[i]) > nums2[n-1]) {
                    res1 = -1;
                    break;
                } else if(nums2[i] > nums2[n-1]) {
                    res1++;
                }
            }

        } else {
            for(int i = 0; i < n-1; i++) {
                if(min(nums1[i], nums2[i]) > nums1[n-1] || max(nums1[i], nums2[i]) > nums2[n-1]) {
                    res1 = -1;
                    break;
                } else if(nums1[i] > nums1[n-1]) {
                    res1++;
                }
            }
        
        }
        // cout << res1 << endl;
        swap(nums1[n-1], nums2[n-1]);
        if(nums1[n-1] > nums2[n-1]) {
            for(int i = 0; i < n-1; i++) {
                if(min(nums1[i], nums2[i]) > nums2[n-1]) {
                    res2 = -1;
                    break;
                } else if(nums2[i] > nums2[n-1]) {
                    res2++;
                }
            }

        } else {
            // cout << "here" << endl;
            for(int i = 0; i < n-1; i++) {
                if(min(nums1[i], nums2[i]) > nums1[n-1] || max(nums1[i], nums2[i]) > nums2[n-1]) {
                    
                    res2 = -1;
                    break;
                } else if(nums1[i] > nums1[n-1]) {
                    // cout << i << endl;
                    res2++;
                }
            }
     
        }
        // cout << res2 << endl;
        if(res1 == -1 && res2 == -1)
            return -1;
        else if(res1 == -1) 
            return res2;
        else if(res2 == -1)
            return res1;
        else return min(res1, res2);
    }
};
