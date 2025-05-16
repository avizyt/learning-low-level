#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator<(const Point &other) const
    {
        return x < other.x || (x == other.x && other.y);
    }
};
// cross product of vector (pq x pr)
int cross(const Point &p, const Point &q, const Point &r)
{
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

// check if r lies to the left of the line from p to q
bool isLeft(const Point &p, const Point &q, const Point &r)
{
    return cross(p, q, r) > 0;
}

// slow convex hull algorithm
vector<Point> slowConvexHull(const vector<Point> &P)
{
    set<pair<Point, Point>> E;

    for (auto &p : P)
    {
        for (auto q : P)
        {
            if (p == q)
                continue;
            bool valid = true;
            for (auto &r : P)
            {
                if (r == p || r == q)
                    continue;
                if (isLeft(p, q, r))
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                E.insert({p, q});
            }
        }
    }

    // reconstruct convex hull from edges
    // build adj map to walk edges in order
    map<Point, Point> edgeMap;
    for (auto &e : E)
    {
        edgeMap[e.first] = e.second;
    }

    // start from the leftmost (lowest x) point
    Point start = *min_element(P.begin(), P.end());
    vector<Point> L;
    L.push_back(start);
    Point curr = start;

    // walk through edges to get clockwise list
    while (true)
    {
        auto it = edgeMap.find(curr);
        if (it == edgeMap.end())
            break;
        curr = it->second;
        if (curr == start)
            break;
        L.push_back(curr);
    }
    return L;
}

// Test driver
int main()
{
    vector<Point> P = {
        {0, 0}, {1, 2}, {2, 1}, {3, 3}, {4, 0}, {2, -2}};

    vector<Point> hull = slowConvexHull(P);

    cout << "Convex Hull in clockwise order:\n";
    for (auto &pt : hull)
    {
        cout << "(" << pt.x << ", " << pt.y << ")\n";
    }

    return 0;
}