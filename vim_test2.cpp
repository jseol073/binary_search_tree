#include <iostream>
#include "b_search_tree.hpp"

using namespace std;
int main() {
    bst::b_search_tree<int> test;
    int array[] = {5, 6, 2, 1, 3};
    for (int i : array) {
        test.insert(i);
    }
    return 0;
}
