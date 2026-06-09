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
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int totalLength = mountainArr.length();
        int low = 0, high = totalLength - 1;
        int peakIndex = 0;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        peakIndex = low;

        low = 0, high = peakIndex;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            } else if (value > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low = peakIndex, high = totalLength - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            } else if (value < target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};