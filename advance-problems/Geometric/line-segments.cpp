#include <bits/stdc++.h>
using namespace std;

/*
There are two line segments : the first goes through the points(x_1, y_1) and (x_2, y_2), and the second goes through the points(x_3, y_3) and (x_4, y_4).Your task is to determine if the line segments intersect, i.e., they have at least one common point.

Input

The first input line has an integer t : the number of tests.After this, there are t lines that describe the tests.Each line has eight integers
x_1, y_1, x_2, y_2, x_3, y_3, x_4 and y_4.

Output
For each test, print "YES" if the line segments intersect and "NO" otherwise.

Input:

5
1 1 5 3 1 2 4 3
1 1 5 3 1 1 4 3
1 1 5 3 2 3 4 1
1 1 5 3 2 4 4 1
1 1 5 3 3 2 7 4

Output:

NO
YES
YES
YES
YES
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

int sign(ll num)
{
    if (num < 0)
    {
        return -1;
    }
    else if (num == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

ll trigonometric_sense(Point p, Point p1, Point p2)
{
    return sign(
        1LL * (p1.x - p.x) * (p2.y - p.y) - 1LL * (p2.x - p.x) * (p1.y - p.y));
}

// Check if the rectangles with [P1, P2] and [P3, P4] as diagonals intersect
bool quick_check(Point p1, Point p2, Point p3, Point p4)
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    x1 = min(p1.x, p2.x), x2 = max(p1.x, p2.x);
    y1 = min(p1.y, p2.y), y2 = max(p1.y, p2.y);
    x3 = min(p3.x, p4.x), x4 = max(p3.x, p4.x);
    y3 = min(p3.y, p4.y), y4 = max(p3.y, p4.y);
    return x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1;
}

bool check(Point p1, Point p2, Point p3, Point p4)
{
    if (trigonometric_sense(p1, p2, p3) * trigonometric_sense(p1, p2, p4) > 0)
    {
        return false;
    }
    if (trigonometric_sense(p3, p4, p1) * trigonometric_sense(p3, p4, p2) > 0)
    {
        return false;
    }
    return true;
}

int main()
{
    int test_num;
    cin >> test_num;
    for (int t = 0; t < test_num; t++)
    {
        Point p1, p2, p3, p4;
        cin >> p1 >> p2 >> p3 >> p4;

        if (quick_check(p1, p2, p3, p4))
        {
            puts("NO");
        }
        else if (check(p1, p2, p3, p4))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
}