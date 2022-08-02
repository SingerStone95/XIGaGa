#pragma once
template <class T>
class Node {
 public:
  Node<T>* pre;
  Node<T>* next;
  Node(T defaultValue) {
    value = defaultValue;
    pre = nullptr;
    next = nullptr;
  }

  T getValue() { return value; }

  private:
  T value;
};