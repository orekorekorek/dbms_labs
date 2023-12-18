#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class Heap
{
private:
  std::vector<std::shared_ptr<T>> data;

  void heapifyUp()
  {
    int index = data.size() - 1;
    while (index > 0)
    {
      int parentIndex = (index - 1) / 2;
      if (*data[index] > *data[parentIndex])
      {
        std::swap(data[index], data[parentIndex]);
        index = parentIndex;
      }
      else
      {
        break;
      }
    }
  }

  void heapifyDown()
  {
    int index = 0;
    while (true)
    {
      int leftChildIndex = 2 * index + 1;
      int rightChildIndex = 2 * index + 2;
      int largestIndex = index;

      if (leftChildIndex < data.size() && *data[leftChildIndex] > *data[largestIndex])
      {
        largestIndex = leftChildIndex;
      }

      if (rightChildIndex < data.size() && *data[rightChildIndex] > *data[largestIndex])
      {
        largestIndex = rightChildIndex;
      }

      if (largestIndex != index)
      {
        std::swap(data[index], data[largestIndex]);
        index = largestIndex;
      }
      else
      {
        break;
      }
    }
  }

public:
  void insert(const T &value)
  {
    data.push_back(std::make_shared<T>(value));
    heapifyUp();
  }

  void remove()
  {
    if (data.empty())
    {
      throw std::out_of_range("Heap is empty");
    }

    std::swap(data[0], data.back());
    data.pop_back();
    heapifyDown();
  }

  const T &getTop() const
  {
    if (data.empty())
    {
      throw std::out_of_range("Heap is empty");
    }
    return *data[0];
  }

  bool isEmpty() const
  {
    return data.empty();
  }

  // Операторы сдвига влево и вправо для чтения и записи из любого потока
  friend std::ostream &operator<<(std::ostream &os, const Heap<T> &heap)
  {
    for (const auto &item : heap.data)
    {
      os << *item << " ";
    }
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Heap<T> &heap)
  {
    T value;
    is >> value;
    heap.insert(value);
    return is;
  }

  // Итератор для работы с коллекцией
  typename std::vector<std::shared_ptr<T>>::iterator begin()
  {
    return data.begin();
  }

  typename std::vector<std::shared_ptr<T>>::iterator end()
  {
    return data.end();
  }
};

// Пример использования кучи с пользовательским классом
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

  // Оператор сравнения для корректной работы кучи
  bool operator>(const MyData &other) const
  {
    return value > other.value;
  }

  // Оператор вывода для удобства отладки
  friend std::ostream &operator<<(std::ostream &os, const MyData &data)
  {
    os << data.value;
    return os;
  }

  // Оператор ввода для удобства ввода из потока
  friend std::istream &operator>>(std::istream &is, MyData &data)
  {
    is >> data.value;
    return is;
  }
};

int main()
{
  // Пример использования кучи с пользовательским классом
  Heap<MyData> myHeap;

  // Добавление элементов в кучу
  myHeap.insert(MyData(5));
  myHeap.insert(MyData(10));
  myHeap.insert(MyData(3));

  // Вывод кучи
  std::cout << "Heap: " << myHeap << std::endl;

  // Удаление элемента из кучи
  myHeap.remove();

  // Вывод кучи после удаления
  std::cout << "Heap after removal: " << myHeap << std::endl;

  // Итератор для обхода кучи
  std::cout << "Heap elements using iterator: ";
  for (const auto &item : myHeap)
  {
    std::cout << *item << " ";
  }
  std::cout << std::endl;

  return 0;
}
