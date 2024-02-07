#include <iostream>
#include <vector>
#include <memory>

namespace heap
{
  /**
   * @brief Heap Class template implementation.
   *
   * The Heap class is a template class that represents a binary heap data structure.
   * It provides methods to insert, remove, and access elements in the heap.
   * The heap is implemented using a vector of shared pointers to elements.
   *
   * @tparam T Type of elements stored in the heap.
   */
  template <typename T>
  class Heap
  {
  private:
    std::vector<std::shared_ptr<T>> data; /**< Vector of shared pointers to store elements in the heap. */

    /**
     * @brief Helper method to maintain the heap property by moving the last element up.
     *
     * This method is called after inserting a new element to maintain the heap property.
     */
    void heapifyUp();
    /**
     * @brief Helper method to maintain the heap property by moving the root element down.
     *
     * This method is called after removing the root element to maintain the heap property.
     */
    void heapifyDown();
    /**
     * @brief Check if the heap is empty.
     *
     * @return true if the heap is empty, false otherwise.
     */
    bool isEmpty() const;

  public:
    /**
     * @brief Default constructor for the Heap class.
     *
     * Initializes an empty heap.
     */
    Heap();

    /**
     * @brief Insert a new element into the heap.
     *
     * @param value The value of the element to be inserted.
     */
    void insert(const T &value);
    /**
     * @brief Remove the top element from the heap.
     *
     * Removes the element with the highest priority (root) from the heap.
     */
    void remove();
    /**
     * @brief Get the value of the top element in the heap.
     *
     * @return A constant reference to the value of the top element.
     */
    const T &getTop() const;

    /**
     * @brief Overloaded output stream operator to print the elements of the heap.
     *
     * @param os The output stream.
     * @param heap The Heap object to be printed.
     * @return A reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Heap<T> &heap)
    {
      for (const auto &item : heap.data)
      {
        os << *item << " ";
      }
      return os;
    };
    /**
     * @brief Overloaded input stream operator to insert values into the heap.
     *
     * Reads values from the input stream and inserts them into the heap.
     * @param is The input stream.
     * @param heap The Heap object to insert values into.
     * @return A reference to the input stream.
     */
    friend std::istream &operator>>(std::istream &is, Heap<T> &heap)
    {
      T value;

      while (is >> value)
      {
        heap.insert(value);
      }

      return is;
    };

    /**
     * @brief Get an iterator pointing to the beginning of the heap.
     *
     * @return An iterator pointing to the beginning of the heap.
     */
    typename std::vector<std::shared_ptr<T>>::iterator begin()
    {
      return data.begin();
    };
    /**
     * @brief Get an iterator pointing to the end of the heap.
     *
     * @return An iterator pointing to the end of the heap.
     */
    typename std::vector<std::shared_ptr<T>>::iterator end()
    {
      return data.end();
    };
  };
}

#include "heap.cpp"
