#pragma once
class CObj {
 public:
  CObj(int v);
  CObj();
  virtual ~CObj();

  CObj(const CObj& other);
  CObj(CObj&& other);
  CObj& operator=(CObj rhs);

 private:
  int value_ = -1;
};
