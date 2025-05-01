#include <bits/stdc++.h>
using namespace std;

/*
Let (x, y) be the integer coordinates of a student’s house on a 2D plane. There
are 2N students and we want to pair them into N groups. Let di be the distance
between the houses of 2 students in group i. Form N groups such that cost = PN i=1 di
is minimized. Output the minimum cost as a floating point number with 2 digits
precision in one line. Constraints: 1  N  8 and 0  x, y  1000.

Sample input (with explanation):
N = 2; Coordinates of the 2N = 4 houses are {1, 1}, {8, 6}, {6, 8}, and {1, 3}.
Sample output (with explanation):
cost = 4.83.
*/

// max number of students
const int MAX_N = 16;
const double INF = 1e18;

double dist[MAX_N][MAX_N];

// dp[mask] = min cost to pair by mask
double dp[1 << MAX_N];

int n;
vector<pair<int, int>> students;

// recursive DP function
double solve(int mask)
{

    // if all students are paired
    if (mask == (1 << (2 * n)) - 1)
        return 0.0;

    if (dp[mask] >= 0.0)
        return dp[mask]; // already computed

    double ans = INF;

    // first unpaired student
    int first_unpaired = -1;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (!(mask & (1 << i)))
        {
            first_unpaired = i;
            break;
        }
    }

    // now try pairing 'first_unpaired' with every other unpaired student
    for (int j = first_unpaired + 1; j < 2 * n; ++j)
    {
        if (!(mask & (1 << j)))
        {
            int new_mask = mask | (1 << first_unpaired) | (1 << j);
            double cost = dist[first_unpaired][j];
            ans = min(ans, cost + solve(new_mask));
        }
    }
    return dp[mask] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    students.resize(2 * n);

    // reading coordinates
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> students[i].first >> students[i].second;
    }

    // precomputing distances
    for (int i = 0; i < 2 * n; ++i)
    {
        for (int j = 0; j < 2 * n; ++j)
        {
            int dx = students[i].first - students[j].first;
            int dy = students[i].second - students[j].second;
            dist[i][j] = sqrt(dx * dx + dy * dy);
        }
    }

    // initialize dp with -1 (uncomputed)
    fill(dp, dp + (1 << (2 * n)), -1.0);

    double answer = solve(0);

    cout << fixed << setprecision(2) << answer << '\n';

    return 0;
}