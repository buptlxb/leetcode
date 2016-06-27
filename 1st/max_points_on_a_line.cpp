#include <vector>
#include <iostream>
#include <unordered_map>
#include <limits>

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

using namespace std;

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int len = points.size();
        if (len == 0)
            return 0;
        int res = 1;
        unordered_map<double, int> umap;
        for (int i = 0; i < len; i++) {
            umap.clear();
            int samePointsNum = 0;
            int max = 1;
            for (int j = i + 1; j < len; j++) {
                double slope = numeric_limits<double>::infinity();
                if (points[i].x != points[j].x)
                    slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
                else if (points[i].y == points[j].y) {
                    samePointsNum++;
                    continue;
                }
                int tmp;
                if (umap.find(slope) != umap.end())
                    tmp = ++umap[slope];
                else {
                    umap.insert(unordered_map<double, int>::value_type(slope, 2));
                    tmp = 2;
                }
                if (max < tmp)
                    max = tmp;
            }
            if (res < max + samePointsNum)
                res = max + samePointsNum;
        }
        return res;
    }
};

int main(void)
{
    Point p1(1, 2);
    Point p2(2, 3);
    Point p3(2, 4);
    Point p4(2, 5);
    Point p5(4, 6);
    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p5);
    Solution s = Solution();
    cout << s.maxPoints(points) << endl;
}
