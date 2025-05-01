#include <bits/stdc++.h>
using namespace std;

/*
There is a line that goes through the points p_1=(x_1,y_1) and p_2=(x_2,y_2)There is also a point p_3=(x_3,y_3).Your task is to determine whether p_3 is located on the left or right side of the line or if it touches the line when
we are looking from p_1 to p_2.

Input
The first input line has an integer t: the number of tests.
After this, there are t lines that describe the tests. Each line has six integers: x_1, y_1, x_2, y_2, x_3 and y_3.
Output
For each test, print "LEFT", "RIGHT" or "TOUCH".
Example
Input:

3
1 1 5 3 2 3
1 1 5 3 4 1
1 1 5 3 3 2

Output:

LEFT
RIGHT
TOUCH

*/

typedef long long ll;

struct Point
{
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}

    friend istream &operator>>(istream &in, Point &p)
    {
        int x, y;
        cin >> p.x >> p.y;
        return in;
    }
};

ll collinear(Point p, Point p1, Point p2)
{
    return 1LL * (p.y - p1.y) * (p2.x - p1.x) - 1LL * (p.x - p1.x) * (p2.y - p1.y);
}

int main()
{
    int test_num;
    cin >> test_num;
    for (int t = 0; t < test_num; t++)
    {
        Point p1, p2, p3;
        cin >> p1 >> p2 >> p3;

        if (collinear(p1, p2, p3) == 0)
        {
            std::cout << "TOUCH" << std::endl;
        }
        else if (collinear(p1, p2, p3) < 0)
        {
            std::cout << "RIGHT" << std::endl;
        }
        else
        {
            std::cout << "LEFT" << std::endl;
        }
    }
}