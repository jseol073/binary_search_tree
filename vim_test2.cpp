#include <iostream>
#include "b_search_tree.hpp"
#include <string>

using namespace std;
int main() {
    bst::b_search_tree<int> test;
    int array[] = {5, 6, 2, 1, 3};
    for (int i : array) {
        test.insert(i);
    }
    string all_nodes = test.toString(test.getRoot());
    cout << all_nodes << endl;
    test.delete_element(5);
    cout << all_nodes << endl;
    return 0;
}
