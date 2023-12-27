#include "gtest/gtest.h"
#include "../src/heap.h"

/**
 * @brief MyData Class implementation.
 *
 * The MyData class represents a simple data container with a single integer value.
 * It includes methods for retrieving the stored value, as well as operators for
 * comparison, output, and input for convenient usage in data structures like heaps.
 */
class MyData
{
private:
  int value; /**< The integer value stored in MyData. */

public:
  /**
   * @brief Constructor for MyData.
   *
   * @param val The initial value to be stored in MyData.
   */
  MyData(int val) : value(val) {};

  /**
   * @brief Get the stored value in MyData.
   *
   * @return The integer value stored in MyData.
   */
  int getValue() const
  {
    return value;
  };

  /**
   * @brief Comparison operator for MyData.
   *
   * Enables comparison between two MyData objects based on their stored values.
   *
   * @param other Another MyData object to compare with.
   * @return true if the current object's value is greater than the other's, false otherwise.
   */
  bool operator>(const MyData &other) const
  {
    return value > other.getValue();
  };

  /**
   * @brief Output stream operator for MyData.
   *
   * Enables convenient printing of MyData objects to an output stream.
   *
   * @param os The output stream.
   * @param data The MyData object to be printed.
   * @return A reference to the output stream.
   */
  friend std::ostream &operator<<(std::ostream &os, const MyData &data)
  {
    os << data.value;
    return os;
  };

  /**
   * @brief Input stream operator for MyData.
   *
   * Enables convenient reading of MyData objects from an input stream.
   *
   * @param is The input stream.
   * @param data The MyData object to store the read value.
   * @return A reference to the input stream.
   */
  friend std::istream &operator>>(std::istream &is, MyData &data)
  {
    is >> data.value;
    return is;
  };
};

TEST(HeapTest, InsertAndExtract)
{
  Heap<MyData> heap;

  heap.insert(MyData(5));
  heap.insert(MyData(10));
  heap.insert(MyData(3));

  EXPECT_EQ(heap.getTop().getValue(), 10);
  heap.remove();
  EXPECT_EQ(heap.getTop().getValue(), 5);
  heap.remove();
  EXPECT_EQ(heap.getTop().getValue(), 3);
  heap.remove();
  EXPECT_THROW(heap.getTop(), std::out_of_range);
  EXPECT_THROW(heap.remove(), std::out_of_range);
}

TEST(HeapTest, Iterators)
{
  Heap<MyData> heap;

  heap.insert(MyData(5));
  heap.insert(MyData(10));
  heap.insert(MyData(3));

  auto it = heap.begin();
  EXPECT_EQ((*it)->getValue(), 10);

  ++it;
  EXPECT_EQ((*it)->getValue(), 5);

  ++it;
  EXPECT_EQ((*it)->getValue(), 3);
}

TEST(HeapTest, InsertUsingInputOperator)
{
  Heap<int> heap;

  std::istringstream input("5 10 3");
  input >> heap;

  EXPECT_EQ(heap.getTop(), 10);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
