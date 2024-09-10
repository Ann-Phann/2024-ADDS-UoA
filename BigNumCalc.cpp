#include "BigNumCalc.h"

BigNumCalc::BigNumCalc() {}

BigNumCalc::~BigNumCalc() {}

std::list <int> BigNumCalc::buildBigNum (std::string numString) {
    std::list <int> list;
    for (char c : numString) {
        list.push_back(c - '0');
    }
    return list;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
    //copy list to work on for best practice: not change any in original list
    std::list <int> list1 = num1;
    std::list <int> list2 = num2;

    std::list <int> result;
    
    //create sum 
    int sum = 0;
    int carry = 0;

    while (!list1.empty() || !list2.empty()) {
        //carry the 'carry' to the next stage
        sum = carry;
        if (!list1.empty()) {
            sum = sum + list1.back();
            list1.pop_back();
        }
        
        if(!list2.empty()) {
            sum = sum + list2.back();
            list2.pop_back();
        }

        carry = sum/10;
        sum = sum %10;

        result.push_front(sum);
    }
    return result;
}

std::list<int> BigNumCalc:: sub(std::list<int> num1, std::list<int> num2){
    std::list <int> list1 = num1;
    std::list <int> list2 = num2;
    std::list <int> result;

    int difference = 0;
    int borrow = 0;
    
    while (!list1.empty() || !list2.empty()) {
        if(!list1.empty()) {
            difference = list1.back() - borrow;
            list1.pop_back();
        }
        if(!list2.empty()) {
            difference = difference - list2.back();
            list2.pop_back();
        }
        if (difference >= 0) {
            borrow = 0;
        } else {
            difference = difference + 10;
            borrow = 1;
        }

        result.push_front(difference);
    }
    // Remove leading zeros in the result
    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }
    return result;
}

std::list<int> BigNumCalc:: mul(std::list<int> num1, std::list<int> num2) {
    std::list <int> list1 = num1;
    std::list <int> list2 = num2;
    std::list <int> result;

    int carry = 0;
    int multi = 0;
    while (!list1.empty()) {
        multi = list1.back() * list2.back() + carry;
        carry = multi/10;
        
        list1.pop_back();

        result.push_front(multi % 10);
    }
    if (carry > 0) {
        result.push_front(carry);
    }
    return result;
}