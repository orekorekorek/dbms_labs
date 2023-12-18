#include <vector>
#include <memory>

template <typename T>
class Heap
{
private:
  std::vector<std::shared_ptr<T> > data;

  void heapifyUp();
  void heapifyDown();
public:
  Heap();

  void insert(const T &value);
  void remove();
  const T &getTop() const;
  bool isEmpty() const;
  friend std::ostream &operator<<(std::ostream &os, const Heap<T> &heap);
  friend std::istream &operator>>(std::istream &is, Heap<T> &heap);
  typename std::vector<std::shared_ptr<T> >::iterator begin();
  typename std::vector<std::shared_ptr<T> >::iterator end();
};
