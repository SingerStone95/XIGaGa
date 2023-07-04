#include "ParentB.h"
#include <iostream>
#include "globalv.h"
using namespace std;
namespace pb {

void ParentB::parent() {
  cout << "write  g_int = " << &g_int << "\n";
  g_int = 18;
  cout << "ParentB parent\n";
}
void ParentB::parentB() {
  parent();
  cout << "ParentB parentB\n";
}

ParentB::ParentB() {
  cout << "ParentB()";
}

}  // namespace pb