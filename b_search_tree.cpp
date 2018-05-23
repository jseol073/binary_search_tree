#include <utility> 
#include "b_search_tree.hpp"
#include <iostream>
#include <stdio.h>

using namespace bst;

template<typename ElementType>
b_search_tree<ElementType>::b_search_tree() {
    root = nullptr;
}

template<typename ElementType>
void b_search_tree<ElementType>::insert(ElementType data) {
    root = insert_helper(root, data);
}

template<typename ElementType>
Node<ElementType>* b_search_tree<ElementType>::insert_helper(Node<ElementType>* new_node, ElementType data) {
    if (root == nullptr) {
        return new Node<ElementType>(data, nullptr, nullptr);
    }
    if (new_node->data > root->data) {
        new_node->setLeft(insert_helper(new_node->getLeft(), data));  
        return new_node;
    } else {
        new_node->setRight(insert_helper(new_node->getRight(), data));
        return new_node;
    }
    size++;
}

template<typename ElementType>
void b_search_tree<ElementType>::delete_element(ElementType data) {
    root = delete_helper(root, data);
}

template<typename ElementType>
Node<ElementType>* b_search_tree<ElementType>::delete_helper(Node<ElementType>* n, ElementType data) {
    if (n == nullptr) {
        return nullptr;
    } 
    if (data < n->data) {
        n->setLeft(delete_helper(n->getLeft(), data));
        return n;
    } else if (data > n->data) {
        n->setRight(delete_helper(n->getRight(), data));
        return n;
    }
}

template<typename ElementType>
bool b_search_tree<ElementType>::lookUp(Node<ElementType>* root_, ElementType data) {
   if (root_ == nullptr) {
       return false;
   } 
   if (root_->data == data) {
       return true;
   }
   if (root_->data < data) {
       return lookUp(root_->left, data);
   } else {
       return lookUp(root_->right, data);
   }
}

//template<typename ElementType>
//Node* b_search_tree<ElementType>::getRoot() {
  //  return this->root;
//}

template<typename ElementType>
int b_search_tree<ElementType>::getSize() {
    return this->size;
}
