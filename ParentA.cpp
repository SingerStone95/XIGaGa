#include "ParentA.h"
#include <iostream>
using namespace std;

namespace pa {

void ParentA::parent() {
  cout << "ParentA parent\n";
}
void ParentA::parentA() {
  cout << "ParentA parentA " << ParentA::p_value << "\n";
}

int ParentA::add_2(int a, int b, callback p) {
  return (*p)(a, b);
}
 int  ParentA::add_1(int a, int b) {
  return a + b;
}

ParentA::ParentA(int value) {
  ParentA::p_value = value;
}

}  // namespace pa
