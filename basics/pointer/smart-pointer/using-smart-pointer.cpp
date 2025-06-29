#include <iostream>
#include <memory> // For std::unique_ptr and std::shared_ptr
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

void demonstrateUniquePointers() {
  std::cout << "\n--- Demonstrating std::unique_ptr ---" << std::endl;

  // 1. Create a unique_ptr
  //    Use std::make_unique (preferred way in C++14+) for safety and
  //    efficiency. It automatically allocates MyResource(100) and owns it.
  std::cout << "Creating uniquePtr1..." << std::endl;
  std::unique_ptr<MyResource> uniquePtr1 = std::make_unique<MyResource>(100);

  // Access the object (just like raw pointers)
  uniquePtr1->doSomething();
  std::cout << "Value pointed to by uniquePtr1: " << uniquePtr1->value
            << std::endl;

  // 2. No manual delete needed!
  //    When uniquePtr1 goes out of scope (at the end of this function),
  //    its destructor will automatically call delete on the MyResource(100)
  //    object.
  std::cout << "uniquePtr1 will automatically delete its resource when it goes "
               "out of scope."
            << std::endl;

  // 3. Unique ownership: Cannot copy
  // std::unique_ptr<MyResource> uniquePtr2 = uniquePtr1; // ERROR: Call to
  // implicitly-deleted copy constructor
  std::cout << "\nAttempting to copy uniquePtr1 (will fail/not compile)."
            << std::endl;

  // 4. Unique ownership: Can move
  //    Ownership of MyResource(100) is transferred from uniquePtr1 to
  //    uniquePtr3. uniquePtr1 becomes nullptr after the move.
  std::cout << "Moving ownership from uniquePtr1 to uniquePtr3..." << std::endl;
  std::unique_ptr<MyResource> uniquePtr3 = std::move(uniquePtr1);

  if (uniquePtr1 == nullptr) {
    std::cout << "uniquePtr1 is now nullptr after move." << std::endl;
  }
  uniquePtr3->doSomething(); // uniquePtr3 now owns and can use the resource.

  // When uniquePtr3 goes out of scope, it will delete MyResource(100).
} // MyResource(100) destroyed here when uniquePtr3 goes out of scope.

void demonstrateSharedPointers() {
  std::cout << "\n--- Demonstrating std::shared_ptr ---" << std::endl;

  // 1. Create a shared_ptr
  //    Use std::make_shared (preferred) for safety and efficiency.
  //    It allocates MyResource(200) and its internal reference counter.
  std::cout << "Creating sharedPtr1..." << std::endl;
  std::shared_ptr<MyResource> sharedPtr1 = std::make_shared<MyResource>(200);
  std::cout << "Reference count for sharedPtr1: " << sharedPtr1.use_count()
            << std::endl; // Output: 1

  // Access the object
  sharedPtr1->doSomething();

  // 2. Shared ownership: Can copy
  //    sharedPtr2 now also points to the *same* MyResource(200) object.
  //    The reference count increments.
  std::cout << "\nCreating sharedPtr2 (copy of sharedPtr1)..." << std::endl;
  std::shared_ptr<MyResource> sharedPtr2 = sharedPtr1;
  std::cout << "Reference count for sharedPtr1: " << sharedPtr1.use_count()
            << std::endl; // Output: 2
  std::cout << "Reference count for sharedPtr2: " << sharedPtr2.use_count()
            << std::endl; // Output: 2

  // 3. When a shared_ptr goes out of scope or is reset, the reference count
  // decrements.
  //    The resource is only deleted when the reference count drops to 0.
  { // Create a nested scope for sharedPtr3
    std::cout
        << "\nCreating sharedPtr3 in a nested scope (copy of sharedPtr1)..."
        << std::endl;
    std::shared_ptr<MyResource> sharedPtr3 = sharedPtr1;
    std::cout << "Reference count: " << sharedPtr1.use_count()
              << std::endl; // Output: 3
  } // sharedPtr3 goes out of scope here. Reference count decrements.
  std::cout << "sharedPtr3 went out of scope. Reference count: "
            << sharedPtr1.use_count() << std::endl; // Output: 2

  // Resetting a shared_ptr also decrements the count.
  std::cout << "\nResetting sharedPtr2..." << std::endl;
  sharedPtr2.reset(); // sharedPtr2 no longer owns the resource.
  if (sharedPtr2 == nullptr) {
    std::cout << "sharedPtr2 is now nullptr." << std::endl;
  }
  std::cout << "Reference count: " << sharedPtr1.use_count()
            << std::endl; // Output: 1

  // When sharedPtr1 goes out of scope, the count will become 0, and
  // MyResource(200) will be destroyed.
  std::cout << "sharedPtr1 will delete its resource when it goes out of scope "
               "(final owner)."
            << std::endl;

} // MyResource(200) destroyed here when sharedPtr1 goes out of scope.

int main() {
  std::cout << "\n=======================================================\n";
  demonstrateUniquePointers();
  std::cout << "\n=======================================================\n";
  demonstrateSharedPointers();
  std::cout << "\n=======================================================\n";

  std::cout << "\nProgram finished." << std::endl;
  // Observe: Any 'MyResource created' messages that don't have a corresponding
  // 'MyResource destroyed' message were likely memory leaks (from raw pointer
  // section).

  return 0;
}