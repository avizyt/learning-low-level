#include <vector>    // For std::vector
#include <iostream>  // For std::cout, std::endl
#include <algorithm> // For std::move, std::swap
#include <stdexcept> // For std::out_of_range

// Forward declaration (not strictly needed for methods within the class, but good practice)
template <typename Comparable>
class BinaryHeap;

// -----------------------------------------------------------------------------
// Step 1: Basic Class Structure and Headers
// -----------------------------------------------------------------------------
template <typename Comparable>
class BinaryHeap
{
public:
    // Constructors
    explicit BinaryHeap(int capacity = 100);
    explicit BinaryHeap(const std::vector<Comparable> &items);

    // Public API methods
    bool isEmpty() const;
    const Comparable &findMin() const;
    void insert(const Comparable &x); // Lvalue insert
    void insert(Comparable &&x);      // Rvalue insert (move semantics)
    void deleteMin();
    void deleteMin(Comparable &minItem);
    void makeEmpty();

private:
    int currentSize;               // Number of elements currently in the heap
    std::vector<Comparable> array; // The underlying array to store heap elements

    // Private helper methods
    void buildHeap();             // Builds heap from existing elements in 'array'
    void percolateDown(int hole); // Restores heap property by moving element down
};

// -----------------------------------------------------------------------------
// Step 2: Default Constructor `explicit BinaryHeap(int capacity = 100)`
// -----------------------------------------------------------------------------
template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity)
    : currentSize(0), array(capacity + 1) // Initialize size to 0, array with capacity+1 (for sentinel at index 0)
{
    // No specific elements to add, just initialized capacity
}

// -----------------------------------------------------------------------------
// Step 3: Constructor from Vector `explicit BinaryHeap(const std::vector<Comparable> &items)`
// -----------------------------------------------------------------------------
template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const std::vector<Comparable> &items)
    // Initialize array with enough capacity (items.size() + a buffer like 10),
    // and set currentSize to the number of items.
    : array(items.size() + 10), currentSize{static_cast<int>(items.size())}
{
    // 1. Copy elements from the input vector to the heap's array.
    //    Elements are copied starting from array[1] because array[0] is typically a sentinel.
    for (int i = 0; i < items.size(); ++i)
    {
        array[i + 1] = items[i];
    }

    // 2. Build the heap property from the copied elements.
    //    This is done by calling percolateDown for all non-leaf nodes, starting from the last one.
    //    The last non-leaf node is at index currentSize / 2 (for a 1-indexed heap).
    for (int i = currentSize / 2; i > 0; --i)
    {
        percolateDown(i);
    }
}

// -----------------------------------------------------------------------------
// Step 4: `isEmpty() const`
// -----------------------------------------------------------------------------
template <typename Comparable>
bool BinaryHeap<Comparable>::isEmpty() const
{
    return currentSize == 0;
}

// -----------------------------------------------------------------------------
// Step 5: `findMin() const`
// -----------------------------------------------------------------------------
template <typename Comparable>
const Comparable &BinaryHeap<Comparable>::findMin() const
{
    if (isEmpty())
    {
        throw std::out_of_range("Heap is empty: Cannot find minimum.");
    }
    // In a min-heap, the minimum element is always at the root (array[1]).
    return array[1];
}

// -----------------------------------------------------------------------------
// Step 6: `insert(const Comparable &x)` (Lvalue reference)
// -----------------------------------------------------------------------------
template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &x)
{
    // Check if the array needs to be resized (currentSize reaches capacity - 1 because array[0] is sentinel).
    if (currentSize == array.size() - 1)
    {
        array.resize(array.size() * 2); // Double the array capacity
    }

    // Start percolate up process:
    // 1. Create a 'hole' at the new end of the heap.
    // 2. Temporarily place the element 'x' (or its copy) at array[0] as a sentinel.
    // 3. Move larger parent elements down into the hole until correct position is found.
    // 4. Place 'x' into the final hole.

    int hole = ++currentSize; // Increment size, 'hole' is the new last position
    // Use array[0] as a sentinel to simplify loop condition:
    // 'x' is placed here temporarily. When 'hole' reaches 1, hole/2 is 0.
    // The comparison `x < array[hole/2]` will become `x < array[0]` which is `x < x` (false),
    // correctly stopping the loop.
    array[0] = x; // Assign x to sentinel (a copy is made here)

    // Percolate up: move elements down as long as 'x' is smaller than its parent
    for (; x < array[hole / 2]; hole /= 2)
    {
        array[hole] = std::move(array[hole / 2]); // Move parent down to the current hole
    }
    array[hole] = std::move(array[0]); // Place x from sentinel into its final hole
}

// -----------------------------------------------------------------------------
// Step 7: `insert(Comparable &&x)` (Rvalue reference - Move Semantics)
// -----------------------------------------------------------------------------
template <typename Comparable>
void BinaryHeap<Comparable>::insert(Comparable &&x)
{
    // Same capacity check as Lvalue insert
    if (currentSize == array.size() - 1)
    {
        array.resize(array.size() * 2);
    }

    int hole = ++currentSize;
    // Use array[0] as a sentinel. Crucially, use std::move(x) to transfer ownership
    // of x's resources directly to array[0], avoiding a copy.
    array[0] = std::move(x);

    // Percolate up: The comparison uses the value now in array[0] implicitly
    // (or if x was moved, its content is now in array[0]).
    // The original x object is now in a valid but unspecified state.
    // This loop compares the value that was originally 'x' (now in array[0])
    // with parents.
    for (; array[0] < array[hole / 2]; hole /= 2)
    { // Note: now comparing array[0] itself
        array[hole] = std::move(array[hole / 2]);
    }
    array[hole] = std::move(array[0]); // Move the element from sentinel to its final hole
}

// -----------------------------------------------------------------------------
// Step 8: `deleteMin()` (No return value)
// -----------------------------------------------------------------------------
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
    if (isEmpty())
    {
        throw std::out_of_range("Heap is empty: Cannot delete minimum.");
    }
    // 1. Replace the root (minimum) with the last element in the heap.
    array[1] = std::move(array[currentSize--]); // Move last element to root, then decrement size.

    // 2. Restore heap property by percolating down the new root.
    percolateDown(1);
}

// -----------------------------------------------------------------------------
// Step 9: `deleteMin(Comparable &minItem)` (Return value by reference)
// -----------------------------------------------------------------------------
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable &minItem)
{
    if (isEmpty())
    {
        throw std::out_of_range("Heap is empty: Cannot delete minimum.");
    }
    // 1. Get the minimum item (from the root).
    minItem = std::move(array[1]); // Move the minimum out.

    // 2. Replace the root with the last element and decrement size.
    array[1] = std::move(array[currentSize--]);

    // 3. Restore heap property by percolating down the new root.
    percolateDown(1);
}

// -----------------------------------------------------------------------------
// Step 10: `makeEmpty()`
// -----------------------------------------------------------------------------
template <typename Comparable>
void BinaryHeap<Comparable>::makeEmpty()
{
    currentSize = 0; // Simply reset the size. The vector retains its capacity.
}

// -----------------------------------------------------------------------------
// Step 11: `percolateDown(int hole)` (Private Helper)
// -----------------------------------------------------------------------------
template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    int child;
    // Temporarily store the element that is at 'hole' position.
    // This element will "travel" down the heap.
    Comparable tmp = std::move(array[hole]);

    // Loop continues as long as 'hole' has at least one child (left child is at hole * 2)
    for (; hole * 2 <= currentSize; hole = child)
    {
        child = hole * 2; // Assume left child is the potential candidate for promotion

        // Check if a right child exists AND if the right child is smaller than the left child.
        if (child != currentSize && array[child + 1] < array[child])
        {
            child++; // If so, the right child is the smaller one.
        }

        // Compare 'tmp' (the element being percolated down) with the smaller child.
        if (array[child] < tmp)
        {
            // If the child is smaller than 'tmp', move the child up to the current 'hole'.
            // This effectively moves the 'hole' down to the child's position.
            array[hole] = std::move(array[child]);
        }
        else
        {
            // If the child is not smaller than 'tmp', 'tmp' has found its correct position.
            break;
        }
    }
    // Place 'tmp' into its final position (the last 'hole').
    array[hole] = std::move(tmp);
}

// -----------------------------------------------------------------------------
// Step 13: Main function for testing
// -----------------------------------------------------------------------------
int main()
{
    std::cout << "--- Testing Default Constructor & Insert ---" << std::endl;
    BinaryHeap<int> heap1; // Default capacity 100
    heap1.insert(10);
    heap1.insert(5);
    heap1.insert(20);
    heap1.insert(3);
    heap1.insert(15);

    std::cout << "Min element (heap1): " << heap1.findMin() << std::endl; // Expected: 3

    std::cout << "\n--- Testing Constructor from Vector ---" << std::endl;
    std::vector<int> data = {15, 80, 20, 5, 40, 10, 70, 30, 2};
    BinaryHeap<int> heap2(data);
    std::cout << "Min element (heap2, after buildHeap): " << heap2.findMin() << std::endl; // Expected: 2

    std::cout << "\n--- Testing deleteMin ---" << std::endl;
    int minVal;
    heap2.deleteMin(minVal);
    std::cout << "Deleted min: " << minVal << ". New min: " << heap2.findMin() << std::endl; // Expected deleted: 2, New min: 5
    heap2.deleteMin();
    std::cout << "Deleted another min. New min: " << heap2.findMin() << std::endl; // Expected new min: 10

    std::cout << "\n--- Testing Rvalue Insert ---" << std::endl;
    BinaryHeap<std::string> stringHeap;
    std::string s1 = "banana";
    stringHeap.insert(s1);                                            // Lvalue
    stringHeap.insert(std::string("apple"));                          // Rvalue
    stringHeap.insert("grape");                                       // C-string literal promotes to Rvalue temporary
    std::cout << "Min string: " << stringHeap.findMin() << std::endl; // Expected: apple
    stringHeap.deleteMin(s1);
    std::cout << "Deleted min: " << s1 << ". New min: " << stringHeap.findMin() << std::endl; // Expected deleted: apple, New min: banana

    std::cout << "\n--- Testing makeEmpty ---" << std::endl;
    std::cout << "Is heap2 empty before makeEmpty? " << (heap2.isEmpty() ? "Yes" : "No") << std::endl;
    heap2.makeEmpty();
    std::cout << "Is heap2 empty after makeEmpty? " << (heap2.isEmpty() ? "Yes" : "No") << std::endl;

    try
    {
        heap2.findMin();
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl; // Expected
    }

    return 0;
}