#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);

        for (const auto& rd : bookings) {
            int start = rd[0], end = rd[1], seats = rd[2];

            ans[start - 1] += seats;
            
            if (end < n)
                ans[end] -= seats;
        }

        for (int i = 1; i < n; ++i) {
            ans[i] += ans[i - 1];
        }

        return ans;
    }
};