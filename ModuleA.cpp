#include "ModuleA.h"
#include "Public.h"
#include <iostream>
void RunModuleA() {
  std::cout << pub_var;
  pub_var = 10;
  std::cout << pub_var;
}

void AddSa() {
  gg::s_var = 10;
}

int getGlobal() {
  return gg::s_var;
}