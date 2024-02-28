#pragma once
#include <memory>
#include <iostream>

class CObj {
 public:
  CObj(int v);
  CObj();
  virtual ~CObj();

  CObj(CObj& other);

  CObj(CObj&& other);

  CObj& operator=(CObj rhs);

  int GetValue() { return value_; }

  std::shared_ptr<CObj> GetNextObj() { return next_; }
  void SetNextObj(std::shared_ptr<CObj> next) { next_ = next; }

  int SetValue(int value) {
    value_ = value;
    return value_;
  }
  void handle_weak_ptr() {
    if (!next_weak_.expired()) {
      auto next = next_weak_.lock();
      std::cout << "expired false" << next->GetValue() << "\n";
    } else {
      std::cout << "expired true"<< "\n";
    }
  }

 public:
  std::weak_ptr<CObj> next_weak_;

 private:
  int value_ = -1;
  std::shared_ptr<CObj> next_;
  std::unique_ptr<CObj> next_unique_;
};
