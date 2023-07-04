#include "CObj.h"
#include <iostream>

CObj::CObj(int v) : value_(v) {
  std::cout << "CObj(int v)"
            << "\n";
}
CObj::CObj() {
  std::cout << "CObj()"
            << "\n";
}
CObj::~CObj() {}

CObj::CObj(const CObj& other) {
  std::cout << "CObj(CObj& other) "
            << "\n";
  value_ = other.value_;
}
CObj::CObj(CObj&& other) {
  std::cout << "CObj(CObj&& other) "
            << "\n";
  value_ = other.value_;
  other.value_ = -1;
}

CObj& CObj::operator=(CObj other) {
  std::cout << "operator=(CObj other)) "
            << "\n";
  value_ = other.value_;
  return *this;
}