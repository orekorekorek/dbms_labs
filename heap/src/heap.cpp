#pragma once

using namespace heap;

template <typename T>
Heap<T>::Heap() {}

template <typename T>
void Heap<T>::insert(const T &value)
{
  data.push_back(std::make_shared<T>(value));
  heapifyUp();
}

template <typename T>
void Heap<T>::remove()
{
  if (isEmpty())
  {
    throw std::out_of_range("Heap is empty");
  }

  std::swap(data[0], data.back());
  data.pop_back();
  heapifyDown();
}

template <typename T>
const T &Heap<T>::getTop() const
{
  if (isEmpty())
  {
    throw std::out_of_range("Heap is empty");
  }

  return *data[0];
}

template <typename T>
bool Heap<T>::isEmpty() const
{
  return data.empty();
}

template <typename T>
void Heap<T>::heapifyDown()
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

template <typename T>
void Heap<T>::heapifyUp()
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
