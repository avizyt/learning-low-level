
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;
using ull = unsigned long long;
using ll = long long;
using Clock = chrono::high_resolution_clock;

// -------------------- Master analyzer --------------------
// We analyze recurrences T(n) = a T(n/b) + f(n).
// f_type: 0 => f(n)=n^c
//         1 => f(n)=n^c * log^k(n)
//         2 => special: n / log n  (demonstration of "Master not applicable")
void analyze_master(long long a, long long b, int f_type, double c = 0.0,
                    int k = 0) {
  double p = log((double)a) / log((double)b); // p = log_b a
  cout << "Recurrence: T(n) = " << a << " T(n/" << b << ") + f(n)\n";
  cout << "Critical exponent p = log_b(a) = " << p << "\n";

  if (f_type == 0) {
    cout << "f(n) = n^" << c << "\n";
    if (c < p - 1e-12) {
      cout << "Case 1: f(n) = O(n^{p-eps}) -> T(n) = Theta(n^" << p << ")\n";
    } else if (fabs(c - p) < 1e-12) {
      cout << "Case 2 (k=0): f(n)=Theta(n^p) -> T(n) = Theta(n^p log n)\n";
    } else {
      cout << "Case 3: f(n) = Omega(n^{p+eps}) and regularity must hold -> "
              "T(n)=Theta(f(n))\n";
    }
  } else if (f_type == 1) {
    cout << "f(n) = n^" << c << " * (log n)^" << k << "\n";
    if (c < p - 1e-12) {
      cout << "Case 1 -> T(n) = Theta(n^" << p << ")\n";
    } else if (fabs(c - p) < 1e-12) {
      cout << "Case 2: T(n) = Theta(n^p (log n)^{" << (k + 1) << "})\n";
    } else {
      cout << "Case 3 -> T(n) = Theta(n^" << c << " (log n)^" << k
           << "), if regularity holds\n";
    }
  } else {
    cout << "Special f(n) = n / log n. Master theorem does NOT apply "
            "directly.\n";
    cout << "Use recursion-tree or more general tools (Akra–Bazzi) -> result "
            "Theta(n log log n).\n";
  }
  cout << "--------------------------------------------------------\n";
}

// -------------------- Example algorithms --------------------

// Binary search: T(n) = T(n/2) + O(1) -> Theta(log n)
int binary_search_vec(const vector<int> &v, int target) {
  int l = 0, r = (int)v.size() - 1;
  while (l <= r) {
    int m = l + ((r - l) >> 1);
    if (v[m] == target)
      return m;
    if (v[m] < target)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}

// Merge sort: T(n) = 2T(n/2) + Theta(n) -> Theta(n log n)
void merge(vector<int> &a, int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; ++i)
    L[i] = a[l + i];
  for (int j = 0; j < n2; ++j)
    R[j] = a[m + 1 + j];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      a[k++] = L[i++];
    else
      a[k++] = R[j++];
  }
  while (i < n1)
    a[k++] = L[i++];
  while (j < n2)
    a[k++] = R[j++];
}
void merge_sort_rec(vector<int> &a, int l, int r) {
  if (l >= r)
    return;
  int m = l + (r - l) / 2;
  merge_sort_rec(a, l, m);
  merge_sort_rec(a, m + 1, r);
  merge(a, l, m, r);
}
void merge_sort(vector<int> &a) { merge_sort_rec(a, 0, (int)a.size() - 1); }

// Custom recursion to simulate T(n) = 2 T(n/2) + n / log n
// We'll allocate O(n / log n) work by performing a loop of that size.
void custom_rec_work(size_t units) {
  // do trivial work units times
  volatile size_t s = 0;
  for (size_t i = 0; i < units; ++i)
    s += i & 1;
  (void)s;
}
void custom_rec(size_t n) {
  if (n <= 1)
    return;
  size_t half = n / 2;
  custom_rec(half);
  custom_rec(n - half);
  // simulate n / log n work (avoid zero)
  double lg = log(max<size_t>(2, n));
  size_t units = max<size_t>(1, (size_t)((double)n / lg));
  custom_rec_work(units);
}

// -------------------- Timing harness --------------------
template <class F> double time_call(F f) {
  auto t0 = Clock::now();
  f();
  auto t1 = Clock::now();
  chrono::duration<double> dur = t1 - t0;
  return dur.count();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << "\n=== Master theorem analyzer examples ===\n\n";

  // Example 1: Binary search
  analyze_master(1, 2, 0, 0.0, 0); // a=1,b=2, f(n)=n^0 -> Case2 -> Theta(log n)

  // Example 2: Merge sort
  analyze_master(2, 2, 1, 1.0,
                 0); // f(n) = n^1 log^0 => Case2 -> Theta(n log n)

  // Example 3: Strassen-like: 7T(n/2) + n^2
  analyze_master(7, 2, 0, 2.0,
                 0); // p = log_2 7 ~ 2.807 => Case1 -> Theta(n^log_2 7)

  // Example 4: 2T(n/2) + n/log n (Master doesn't apply)
  analyze_master(2, 2, 2);

  cout << "\nNow run empirical timings for algorithms to see scaling:\n";
  cout << "(times in seconds, run with -O2 for meaningful results)\n\n";

  // Binary search timing (should grow like log n)
  {
    cout << "Binary search timings:\n";
    for (int exp = 16; exp <= 26; exp += 5) { // n from ~65k to ~67M
      int n = 1 << exp;
      vector<int> v(n);
      iota(v.begin(), v.end(), 0);
      int target = n - 1;
      int reps = 1000000 / max(1, exp); // vary reps to get non-trivial time
      double t = time_call([&]() {
        for (int i = 0; i < reps; ++i)
          binary_search_vec(v, target);
      });
      cout << "n=" << n << " reps=" << reps << " time=" << t << "\n";
    }
    cout << "--------------------------------------------------------\n";
  }

  // Merge sort timing (should grow ~ n log n)
  {
    cout << "Merge sort timings:\n";
    for (int n : {1 << 10, 1 << 12, 1 << 14, 1 << 16}) {
      vector<int> a(n);
      mt19937 rng(123456);
      for (int i = 0; i < n; ++i)
        a[i] = rng();
      double t = time_call([&]() { merge_sort(a); });
      cout << "n=" << n << " time=" << t << "\n";
    }
    cout << "--------------------------------------------------------\n";
  }

  // Custom recursion simulating n/log n extra work -> T(n) ~ n log log n
  {
    cout << "Custom recursion (T(n)=2T(n/2)+n/log n) timings:\n";
    for (int n : {1 << 12, 1 << 14, 1 << 16}) {
      double t = time_call([&]() { custom_rec((size_t)n); });
      cout << "n=" << n << " time=" << t << "\n";
    }
    cout << "Note: Master theorem does not apply; recursion-tree predicts "
            "Theta(n log log n).\n";
    cout << "--------------------------------------------------------\n";
  }

  cout << "\nDone. Interpret timings vs. theoretical predictions.\n";
  cout << "If you'd like, I can:\n";
  cout << " - add counters to count recursion nodes and per-level costs\n - "
          "plot results (Python) for clearer visuals\n - implement Akra-Bazzi "
          "solver for more general recurrences\n";
  cout << "\n";

  return 0;
}
