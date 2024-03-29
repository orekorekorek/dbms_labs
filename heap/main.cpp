#include <iostream>
#include <vector>
#include <memory>
#include "src/heap.h"

class MyData
{
private:
  int value;

public:
  MyData(int val) : value(val) {}

  int getValue() const
  {
    return value;
  }

  bool operator>(const MyData &other) const
  {
    return value > other.value;
  }
};

int main()
{
  Heap<MyData> myHeap;

  myHeap.insert(MyData(5));
  myHeap.insert(MyData(10));
  myHeap.insert(MyData(3));

  std::cout << "Heap: " << myHeap << std::endl;

  myHeap.remove();

  std::cout << "Heap after removal: " << myHeap << std::endl;

  std::cout << "Heap elements using iterator: ";
  for (const auto &item : myHeap)
  {
    std::cout << *item << " ";
  }
  std::cout << std::endl;

  return 0;
}
