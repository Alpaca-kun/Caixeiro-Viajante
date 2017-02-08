#include <iostream>
#include <vector>

using namespace std;

int main () {
  vector<int> myvector(10);

  int vSize = myvector.size();

  for (int i = 0; i < vSize; i++) {
    myvector[i] = i;
    cout << "i"<< myvector[i] << endl;
  }
}
