/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:


int findPeak(MountainArray &mountainArr) {
    int left = 0;
    int right = mountainArr.length() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int binarySearch(MountainArray &mountainArr, int target, int left, int right, bool isAscending) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isAscending) {
            if (mountainArr.get(mid) < target) {
                left = mid + 1;
            } else if (mountainArr.get(mid) > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        } else {
            if (mountainArr.get(mid) > target) {
                left = mid + 1;
            } else if (mountainArr.get(mid) < target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
    }
    return -1;
}

int findInMountainArray(int target, MountainArray &mountainArr) {
    int peakIndex = findPeak(mountainArr);
    int leftSearch = binarySearch(mountainArr, target, 0, peakIndex, true);
    if (leftSearch != -1) {
        return leftSearch;
    }
    return binarySearch(mountainArr, target, peakIndex + 1, mountainArr.length() - 1, false);
}
};
