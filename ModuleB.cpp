#include "ModuleB.h"
#include <iostream>
int pub_var = 5;
void RunModuleB() {
  pub_var = 20;
}
void PrintSa() {
  std::cout << gg::s_var;
}