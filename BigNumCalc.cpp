#include "BigNumCalc.h"
#include <algorithm>
#include <stdexcept>
#include <string>

// Constructor
BigNumCalc::BigNumCalc() {}

// Destructor
BigNumCalc::~BigNumCalc() {}

// Create a list representing the provided string
std::list<int> BigNumCalc::buildBigNum(const std::string &numString) {
  std::list<int> bigNumCalc_list;
  for (char ch : numString) {
    if (!std::isdigit(ch)) {
      throw std::invalid_argument(
          "Input string contains non-digit characters.");
    }
    bigNumCalc_list.push_back(ch - '0'); // Convert char to int
  }
  return bigNumCalc_list;
}

// Add method
std::list<int> BigNumCalc::add(const std::list<int> &num1,
                               const std::list<int> &num2) {
  std::list<int> bigNum1 = num1;
  std::list<int> bigNum2 = num2;
  std::list<int> result;
  int carry = 0;

  while (!bigNum1.empty() || !bigNum2.empty() || carry) {
    int sum = carry;
    if (!bigNum1.empty()) {
      sum += bigNum1.back(); // add the last digit of num1
      bigNum1.pop_back();    // remvoe the last digit of num1
    }

    if (!bigNum2.empty()) {
      sum += bigNum2.back();
      bigNum2.pop_back();
    }

    carry = sum / 10; // sum > 0 ? carry = 1 : carry = 0;
    result.push_front(sum % 10);
  }

  return result;
}

// Subtract method
std::list<int> BigNumCalc::sub(const std::list<int> &num1,
                               const std::list<int> &num2) {
  std::list<int> bigNum1 = num1;
  std::list<int> bigNum2 = num2;
  std::list<int> result;
  int borrow = 0;

  while (!bigNum1.empty() || !bigNum2.empty()) {
    int diff = 0;
    if (!bigNum1.empty()) {
      diff = bigNum1.back() -
             borrow; // subtract borrow from the current digit of num1
      bigNum1.pop_back();
    }

    if (!bigNum2.empty()) {
      diff -= bigNum2.back(); // subtract the last digit of num2
      bigNum2.pop_back();     // remove the last digit of num 2
    }

    if (diff < 0) {
      diff += 10; // borrow from the next digit
      borrow = 1;
    } else {
      borrow = 0;
    }

    result.push_front(diff);
  }

  // Remove leading zeros from the result
  while (result.size() > 1 && result.front() == 0) {
    result.pop_front();
  }

  return result;
}

// Multiply method (num2 contains only one digit)
std::list<int> BigNumCalc::mul(const std::list<int> &num1,
                               const std::list<int> &num2) {
  std::list<int> result;
  int carry = 0;

  // num2 is assumed to have only one element
  int multiplier = num2.front();

  // Iterate over num1 from least significant to most significant digit
  // (backwards)
  for (auto it1 = num1.rbegin(); it1 != num1.rend(); ++it1) {
    int product = (*it1) * multiplier + carry;
    carry = product / 10;            // get the carry
    result.push_front(product % 10); // store the current digit
  }

  // If there's any carry left, add it to the result
  if (carry > 0) {
    result.push_front(carry);
  }

  // Remove leading zeros from the result (if necessary)
  while (result.size() > 1 && result.front() == 0) {
    result.pop_front();
  }

  return result;
}