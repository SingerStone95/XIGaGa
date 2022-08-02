#pragma once

namespace pa {
class ParentA {
 public:
  void parent();
  void parentA();
  ParentA(int value);
  typedef int (*callback)(int, int);
  int add_2(int a, int b, callback p);

 static int add_1(int a, int b);

 private:
  int p_value = 0;
};

}  // namespace pa
