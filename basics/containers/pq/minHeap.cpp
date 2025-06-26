#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

template<typename T>
class MinHeap{
    private:
    std::vector<T> heapArray;

    // helper function for index calculations
    int getParentIndex(int i) {
        return (i-1)/2;
    }

    int getLeftChildIndex(int i){
        return 2*i + 1;
    }

    int getRightChildIndex(int i){
        return  2*i + 1;
    }

    //helper function to check child.parent existance
    bool hasParent(int i) { return getParentIndex(i) >= 0;}
    bool hasLeftChild(int i) {return getLeftChildIndex(i) < heapArray.size();}
    bool hasRightChild(int i) {return getRightChildIndex(i) < heapArray.size();}

    // helper functions to get child/parent values
    T leftChild(int i) { return heapArray[getLeftChildIndex(i)]; }
    T rightChild(int i) { return heapArray[getRightChildIndex(i)]; }
    T parent(int i) { return heapArray[getParentIndex(i)]; }

    void heapifyUp() {
        int currentIndex = heapArray.size() -1 ;
        while (hasParent(currentIndex) && parent(currentIndex) > heapArray[currentIndex]){
            std::swap(heapArray[currentIndex], heapArray[getParentIndex(currentIndex)]);
            currentIndex = getParentIndex(currentIndex);
        }
    }

    // restore heap property by moving element down
    void heapifyDown() {
        int currentIndex = 0;
        while (hasLeftChild(currentIndex)) {
            int smallerChildIndex = getLeftChildIndex(currentIndex);
            if(hasRightChild(currentIndex) && rightChild(currentIndex) < leftChild(currentIndex)){
                smallerChildIndex = getRightChildIndex(currentIndex);
            }

            if (heapArray[currentIndex] <= heapArray[smallerChildIndex]){
                break;
            } else {
            std::swap(heapArray[currentIndex], heapArray[smallerChildIndex]);
            currentIndex = smallerChildIndex;
            }
        
        }
    }

    public:
    MinHeap() {}

    bool isEmpty() const {
        return heapArray.empty();
    }
    T peekMin() const {
        if(isEmpty()){
            throw std::runtime_error("Heap is empty!");
        }
        return heapArray[0];
    }

    void insert(T item){
        heapArray.push_back(item);
        heapifyUp();
    }

    T extractMin() {
        if(isEmpty()){
            throw std::runtime_error("Heap is empty!");
        }
        T minItem = heapArray[0];
        heapArray[0] = heapArray.back();
        heapArray.pop_back();
        heapifyDown();
        return minItem;
    }

    size_t size() const {
        return heapArray.size();
    }

    // printing heap array
    void printHeapArray() const {
        std::cout << "Heap Array: [";
        for(size_t i =0; i< heapArray.size(); ++i){
            std::cout << heapArray[i] << (i == heapArray.size() -1 ?"": ", ");
        }
        std::cout << "]\n";
    }
    
};

int main() {
    MinHeap<int> min_heap;

    std::cout << "Is heap empty? " << (min_heap.isEmpty() ? "Yes" : "No") << std::endl;

    min_heap.insert(10);
    min_heap.insert(4);
    min_heap.insert(15);
    min_heap.insert(1);
    min_heap.insert(9);
    min_heap.insert(20);

    min_heap.printHeapArray(); // Should show something like [1, 4, 15, 10, 9, 20] (order depends on swaps)

    std::cout << "Min element: " << min_heap.peekMin() << std::endl; // Should be 1

    std::cout << "Extracted min: " << min_heap.extractMin() << std::endl; // Extracts 1
    min_heap.printHeapArray(); // Should show [4, 9, 15, 10, 20] (or similar)

    std::cout << "Min element after extraction: " << min_heap.peekMin() << std::endl; // Should be 4

    min_heap.insert(2);
    min_heap.printHeapArray(); // Should insert 2 and bubble up

    std::cout << "Min element after inserting 2: " << min_heap.peekMin() << std::endl; // Should be 2

    while (!min_heap.isEmpty()) {
        std::cout << "Extracting: " << min_heap.extractMin() << std::endl;
        min_heap.printHeapArray();
    }

    try {
        min_heap.peekMin(); // This will throw an exception
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}