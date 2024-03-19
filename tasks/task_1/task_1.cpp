#include "task_1.h"

Treap::Node::Node():
    val(0),
    left(nullptr),
    right(nullptr),
    p(rand()) {}

Treap::Node::Node(int val_init, Treap::Node* left_init = nullptr, Treap::Node* right_init = nullptr): 
    val(val_init),
    left(left_init),
    right(right_init),
    sum(val_init),
    p(rand()) {}

Treap::~Treap() {
        deleteTreap(root);
    }
void Treap::deleteTreap(Treap::Node* node) {//static
    if (node != nullptr) {
        deleteTreap(node->left);
        deleteTreap(node->right);
        delete node;
    }
}
Treap::Node* Treap::merge(Node* left, Node* right){
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    if (left->p < right->p) {
        left->right = merge(left->right, right);
        update(left);
        return left;
    }
    else {
        right->left = merge(left, right->left);
        update(right);
        return right;
    }
}
int Treap::get_sum(Node* node){
    if (node == nullptr) {
        return 0;
    }
    return node->sum;
}
int Treap::get_size(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->size;
}
void Treap::update(Node* node){
    if (node == nullptr) {
        return;
    }
    node->size = 1 + get_size(node->left) + get_size(node->right);
    node->sum = node->val + get_sum(node->left) + get_sum(node->right);
}
void Treap::split_by_size(Node* node, int k, Node*& left, Node*& right){
    if (node == nullptr) {
        left = right = nullptr;
        return;
    }
    int size = get_size(node->left);
    if (k <= size) {
        right = node;
        split_by_size(node->left, k, left, node->left);
    }
    else {
        left = node;
        split_by_size(node->right, k - size - 1, node->right, right);
    }
    update(node);
}
void Treap::insert_pos(int pos, int val){
    Node* left = nullptr;
    Node* right = nullptr;
    split_by_size(root, pos - 1, left, right);
    Node* p = new Node(val);
    root = merge(merge(left, p), right);
}
void Treap::erase(Node* node, int pos) {
    Node* left = nullptr;
    Node* right = nullptr;
    Node* right_left = nullptr;
    Node* right_right = nullptr;
    split_by_size(node, pos - 1, left, right);
    split_by_size(right, 1, right_left, right_right);
    root = merge(left, right_right);
}
int Treap::sum(int start, int end){
    Node* left = nullptr;
    Node* right = nullptr;
    Node* right_left = nullptr;
    Node* right_right = nullptr;
    split_by_size(root, start - 1, left, right);
    split_by_size(right, end - start + 1, right_left, right_right);
    return right_left->sum;
}

int start(int arr[], int size, int start, int end) 
{
    Treap t = Treap();
    for (size_t i = 0; i < size; i++)
    {
        t.insert_pos(i + 1, arr[i]);
    }
    int result = t.sum(start, end);
    return result;
}
