#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// extended euclidean algorithm
ll extGCD(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
        return x = 1, y = 0, a;
    ll d = extGCD(b, (a % b), y, x);
    y -= a / b * x;
    return d;
}

// chinese remainder theorem
bool crt(long long a1, long long m1, long long a2, long long m2, long long &x, long long &mod)
{
    long long p, q;
    long long d = extGCD(m1, m2, p, q);
    if ((a2 - a1) % d != 0)
        return false;
    mod = m1 / d * m2;
    x = ((a1 + (a2 - a1) / d * p % (m2 / d) * m1) % mod + mod) % mod;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x, y, vx, vy;
        cin >> n >> x >> y >> vx >> vy;

        if (vx == 0 && (x != 0 && x != n))
        {
            cout << -1 << '\n';
            continue;
        }
        if (vy == 0 && (y != 0 && y != n))
        {
            cout << -1 << '\n';
            continue;
        }

        long long rx = (vx > 0) ? (n - x) : x;
        long long ry = (vy > 0) ? (n - y) : y;
        long long modx = n / gcd(n, abs(vx));
        long long mody = n / gcd(n, abs(vy));

        long long t0, lcm;
        if (!crt(rx, modx, ry, mody, t0, lcm))
        {
            cout << -1 << '\n';
            continue;
        }

        // Where do we land after t0 time?
        long long xf = x + vx * t0;
        long long yf = y + vy * t0;

        if ((xf == 0 || xf == n) && (yf == 0 || yf == n))
        {
            cout << (xf / n + yf / n) << '\n'; // # reflections = times crossed x/n or y/n
        }
        else
        {
            cout << -1 << '\n'; // never lands on a vertex
        }
    }
    return 0;
}