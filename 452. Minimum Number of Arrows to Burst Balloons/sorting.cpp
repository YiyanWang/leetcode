#include <vector>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);

        int shot = 1;
        int reachable = points[0][1];
        for (int i = 1; i < n; i++) {
            if (points[i][0] > reachable) {
                shot++;
                reachable = points[i][1];
            }
        }

        return shot;
    }
};