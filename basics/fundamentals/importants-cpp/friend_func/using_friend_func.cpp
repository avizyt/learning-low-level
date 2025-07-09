#include <iostream>

using namespace std;

void friend_function();
void non_friend_function();

class PrivateHolder {
public:
  PrivateHolder(int val) : private_value(val) {}

private:
  int private_value;
  friend void friend_function();
};

void non_friend_function() {
  PrivateHolder ph(10);
  //   std::cout << ph.private_value << std::endl;
}

class PrivateHolderDerived : public PrivateHolder {
public:
  PrivateHolderDerived(int val) : PrivateHolder(val) {}

private:
  int derived_private_value = 0;
};

void friend_function() {
  PrivateHolderDerived pd(20);
  std::cout << pd.private_value << std::endl;
  //   std::cout << pd.derived_private_value << std::endl;
}

class Accesser {
public:
  void private_accesser();
};

class PrivateHolder {
public:
  PrivateHolder(int val) : private_value(val) {}
  friend void Accesser::private_accesser();

private:
  int private_value;
};

void Accesser::private_accesser() {
  PrivateHolder ph(10);
  std::cout << ph.private_value << std::endl;
}

int main() {
  non_friend_function();
  friend_function();
}