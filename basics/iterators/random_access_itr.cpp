#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

std::mutex vecMutex;

void add_to_vector(vector<int> &numbers, int values) {
  lock_guard<mutex> guard(vecMutex);
  numbers.push_back(values);
}

void print_vector(const vector<int> &numbers) {
  lock_guard<mutex> guard(vecMutex);
  for (int num : numbers) {
    cout << num << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> numbers;
  thread t1(add_to_vector, ref(numbers), 1);
  thread t2(add_to_vector, ref(numbers), 2);
  thread t3(add_to_vector, ref(numbers), 3);
  thread t4(add_to_vector, ref(numbers), 4);
  thread t5(add_to_vector, ref(numbers), 5);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();

  t5.swap(t3);

  thread t6(print_vector, ref(numbers));
  t6.join();

  return 0;
}