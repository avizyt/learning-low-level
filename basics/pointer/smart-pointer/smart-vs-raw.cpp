#include <iostream>
// #include <vector> // We'll use this later for smart pointers

// A simple class to demonstrate memory management
class MyResource {
public:
  int value;

  MyResource(int val) : value(val) {
    std::cout << "MyResource created with value: " << value << std::endl;
  }

  ~MyResource() {
    std::cout << "MyResource destroyed with value: " << value << std::endl;
  }

  void doSomething() {
    std::cout << "MyResource " << value << " is doing something." << std::endl;
  }
};

void demonstrateRawPointers() {
  std::cout << "--- Demonstrating Raw Pointers ---" << std::endl;

  // 1. Declare a raw pointer (initially points to nothing specific)
  MyResource *ptr1 =
      nullptr; // It's good practice to initialize pointers to nullptr

  // 2. Allocate memory for a MyResource object on the heap (dynamic memory)
  //    'new MyResource(10)' creates an object and returns its memory address.
  //    ptr1 now "points to" this object.
  std::cout << "\nAllocating ptr1..." << std::endl;
  ptr1 = new MyResource(10); // Allocated on the heap

  // 3. Access the object using the pointer (dereferencing)
  //    Use '*' to get the value the pointer points to.
  //    Use '->' to access members of the object the pointer points to.
  std::cout << "Value pointed to by ptr1: " << (*ptr1).value << std::endl;
  ptr1->doSomething();

  // 4. Deallocate memory (VERY IMPORTANT!)
  //    This tells the system to free up the locker that ptr1 points to.
  //    After delete, ptr1 still holds the old address, but that memory is no
  //    longer guaranteed to belong to your program.
  std::cout << "\nDeallocating ptr1..." << std::endl;
  delete ptr1;
  ptr1 = nullptr; // Set to nullptr to avoid "dangling pointer" issues
                  // (explained below)

  std::cout << "ptr1 is now nullptr." << std::endl;

  // --- Common Problems with Raw Pointers ---

  // Problem A: Memory Leak
  // You allocate memory with 'new', but forget to call 'delete'.
  // The locker is never returned to the warehouse, even if you lose its number.
  // This memory remains occupied until the program ends, wasting resources.
  std::cout << "\n--- Demonstrating Memory Leak ---" << std::endl;
  MyResource *leakedPtr = new MyResource(99);
  // Oops! Forgot to delete leakedPtr. The memory for MyResource(99) is lost.
  // The destructor for MyResource(99) will NOT be called here.
  std::cout << "Oops! Forgot to delete 'leakedPtr'. This is a memory leak."
            << std::endl;
  // When 'demonstrateRawPointers' function ends, 'leakedPtr' goes out of scope,
  // but the memory it pointed to is still allocated.

  // Problem B: Dangling Pointer
  // You delete the memory, but the pointer still holds the address.
  // If you try to use it, you're accessing deallocated memory (undefined
  // behavior).
  std::cout << "\n--- Demonstrating Dangling Pointer ---" << std::endl;
  MyResource *danglingPtr = new MyResource(20);
  std::cout << "danglingPtr points to object with value: " << danglingPtr->value
            << std::endl;
  delete danglingPtr; // Memory is freed, destructor called.

  // NOW danglingPtr is a "dangling pointer"
  // It still holds the address of the freed memory.
  std::cout << "Memory for danglingPtr's object has been deleted." << std::endl;
  // Trying to use it now is DANGEROUS! It might work, it might crash, it might
  // corrupt data. std::cout << "Attempting to use danglingPtr (DANGEROUS!): "
  // << danglingPtr->value << std::endl; Best practice: danglingPtr = nullptr;
  // immediately after delete.
  danglingPtr = nullptr; // Prevents further accidental use of dangling pointer.

  // Problem C: Double Free
  // You delete the same memory twice.
  // This is also undefined behavior and can crash your program or corrupt
  // memory.
  std::cout << "\n--- Demonstrating Double Free ---" << std::endl;
  MyResource *doubleFreePtr = new MyResource(30);
  delete doubleFreePtr;
  std::cout << "First delete successful." << std::endl;
  // delete doubleFreePtr; // DANGEROUS! Trying to delete already freed memory.
  std::cout << "Attempting second delete (DANGEROUS! commented out)."
            << std::endl;
  doubleFreePtr = nullptr; // Always nullify after delete.
}