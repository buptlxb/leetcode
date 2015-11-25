#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    typedef vector<Point>::size_type sz_t;
    int maxPoints(vector<Point>& points) {
        if (points.empty())
            return 0;
        const sz_t len = points.size();
        int ret = 1;
        unordered_map<double, int> um;
        for (sz_t i = 0; i < len; ++i) {
            um.clear();
            int same = 0;
            int max = 1;
            for (int j = i+1; j < len; ++j) {
                double slope = numeric_limits<double>::infinity();
                if (points[i].x != points[j].x)
                    slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
                else if (points[i].y == points[j].y) {
                    ++same;
                    continue;
                }
                int tmp;
                if (um.find(slope) != um.end())
                    tmp = ++um[slope];
                else {
                    tmp = um[slope] = 2;
                }
                if (max < tmp)
                    max = tmp;
            }
            if (ret < max + same)
                ret = max + same;
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
