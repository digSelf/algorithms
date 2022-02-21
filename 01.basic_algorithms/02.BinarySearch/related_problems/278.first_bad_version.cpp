// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version); // 预先定义的

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};