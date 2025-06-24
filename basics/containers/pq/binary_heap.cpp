#include <bits/stdc++.h>
using namespace std;

template <typename Comparable>
class BinaryHeap
{
public:
    explicit BinaryHeap(int capacity = 100);
    explicit BinaryHeap(const vector<Comparable> &items);

    bool isEmpty() const;
    const Comparable &findMin() const;

    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void deleteMin();
    void deleteMIn(Comparable &minItem);
    void makeEmpty();

private:
    int currentSize;          // Number of element in heap
    vector<Comparable> array; // The heap array

    void buildHeap();
    void percolateDown(int hole);
}

int
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}