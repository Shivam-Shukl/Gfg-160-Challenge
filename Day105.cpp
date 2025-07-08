
#include <iostream>
#include <algorithm>
#include <utility>  // For std::pair
using namespace std;

class Solution {
public:
    pair<int,int>* a;
    int index;
    int size;

    Solution() {
        size = 1000000;  // clearer integer literal
        a = new pair<int, int>[size];
        index = -1;
    }
    
    ~Solution() {
        delete[] a;
    }

    // Add an element to the top of Stack
    void push(int x) {
        if (index == size - 1) return;  // Stack overflow check
        else if (index == -1) {
            index++;
            a[index] = {x, x};
        } else {
            int currentMin = a[index].second;
            if (x < currentMin) currentMin = x;
            index++;
            a[index] = {x, currentMin};
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (index != -1) {
            
            index--;
        }
    }

    // Returns top element of the Stack
    int peek() {
        if (index != -1)
            return a[index].first;
        else
            return -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        if (index == -1)
            return -1;
        else
            return a[index].second;
    }
};



