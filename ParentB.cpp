#include "ParentB.h"
#include <iostream>
using namespace std;
namespace pb {
void ParentB::parent() {
  cout << "ParentB parent\n";
}
void ParentB::parentB() {
  parent();
  cout << "ParentB parentB\n";
}
}  // namespace pb