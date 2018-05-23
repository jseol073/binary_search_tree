#ifndef _b_search_tree_H_
#define _b_search_tree_H_

#include <iostream>
#include <stdio.h>

namespace bst {

template<typename ElementType>
struct Node {
    ElementType data;
    Node<ElementType>* left;
    Node<ElementType>* right;

        Node() {};

        Node(ElementType d, Node<ElementType>* l, Node<ElementType>* r) {
            this->data = d;
            this->left = l;
            this->right = r;
        }

        ElementType getData() {
            return data;
        }

        Node<ElementType>* getLeft() {
            return left;
        }

        Node<ElementType>* getRight() {
            return right;
        }

        void setData(ElementType new_data) {
            data = new_data;
        }

        void setLeft(Node<ElementType>* new_l) {
            left = new_l;
        }

        void setRight(Node<ElementType>* new_r) {
            right = new_r;
     }
 };

template<typename ElementType>
class b_search_tree {
public:
    Node<ElementType>* root;
    int size;
    Node<ElementType>* delete_helper(Node<ElementType>* n, ElementType data);
   // Node<ElementType>* getRoot();
    Node<ElementType>* insert_helper(Node<ElementType>* new_node, ElementType data);
    
    b_search_tree();
    void insert(ElementType data);
    bool lookUp(Node<ElementType>* root_, ElementType data); 
    void delete_element(ElementType data);
    int getSize();
   // std::string toString();
};
#include "../vim/b_search_tree.cpp"
}
#endif
