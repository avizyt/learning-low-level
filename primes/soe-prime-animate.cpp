#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
#include <vector>


using namespace std;

// Function to clear the CLI screen based on OS
void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void printGrid(const vector<int> &status, int n) {
  clearScreen();
  cout << "--- Sieve of Eratosthenes Animation ---" << endl;
  cout << "P = Prime, X = Marking Composite, . = Composite" << endl << endl;

  for (int i = 2; i <= n; i++) {
    if (status[i] == 0)
      cout << setw(3) << i << " "; // Unprocessed
    else if (status[i] == 1)
      cout << "  P "; // Confirmed Prime
    else if (status[i] == 2)
      cout << "  X "; // Currently marking
    else if (status[i] == 3)
      cout << "  . "; // Already marked

    if ((i - 1) % 10 == 0)
      cout << endl;
  }
  cout << endl;
}

void animateSieve(int n) {
  // status: 0=potential, 1=prime, 3=composite
  vector<int> status(n + 1, 0);

  for (int p = 2; p <= n; p++) {
    if (status[p] == 0) {
      status[p] = 1; // Mark as Prime
      printGrid(status, n);
      this_thread::sleep_for(chrono::milliseconds(500));

      for (int i = p * p; i <= n; i += p) {
        int oldStatus = status[i];
        status[i] = 2; // Show marking process
        printGrid(status, n);

        this_thread::sleep_for(chrono::milliseconds(100));
        status[i] = 3; // Permanent composite
      }
    }
  }
  printGrid(status, n);
  cout << "Algorithm Complete!" << endl;
}

int main() {
  int limit = 50; // Keep it small for CLI visibility
  animateSieve(limit);
  return 0;
}