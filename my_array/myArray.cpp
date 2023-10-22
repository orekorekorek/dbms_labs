#include <iostream>
#pragma once

namespace myArray {
  /**
   * Initialize an array with a given size and fill it from std::cin.
   *
   * @param size The size of the array.
   * @return A pointer to the dynamically allocated array.
   */
  int* initializeArray(size_t size) {
      int* arr = new int[size];
      std::cout << "Enter " << size << " integers, separated by spaces:" << std::endl;
      for (size_t i = 0; i < size; i++) {
          if (!(std::cin >> arr[i])) {
              std::cerr << "Invalid input. Exiting." << std::endl;
              exit(1);
          }
      }
      return arr;
  }

  /**
   * Print the elements of the array.
   *
   * @param arr The array to be printed.
   * @param size The size of the array.
   */
  void printArray(const int* arr, int size) {
      for (int i = 0; i < size; i++) {
          std::cout << arr[i] << " ";
      }
      std::cout << std::endl;
  }

  /**
   * Find the minimum value in the array.
   *
   * @param arr The array to be searched.
   * @param size The size of the array.
   * @return The minimum value in the array.
   */
  int findMin(const int* arr, int size) {
      if (size == 0) {
          return 0; // Return 0 for an empty array.
      }
      int min = arr[0];
      for (int i = 1; i < size; i++) {
          if (arr[i] < min) {
              min = arr[i];
          }
      }
      return min;
  }

  /**
   * Find the maximum value in the array.
   *
   * @param arr The array to be searched.
   * @param size The size of the array.
   * @return The maximum value in the array.
   */
  int findMax(const int* arr, int size) {
      if (size == 0) {
          return 0; // Return 0 for an empty array.
      }
      int max = arr[0];
      for (int i = 1; i < size; i++) {
          if (arr[i] > max) {
              max = arr[i];
          }
      }
      return max;
  }
}
