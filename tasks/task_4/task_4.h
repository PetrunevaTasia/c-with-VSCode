#pragma once
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

class Node {
public:
    int val;
    int p;
    int size = 1;
    int sum;
    Node* left;
    Node* right;

    Node();
    Node(int val_init, Node* left_init, Node* right_init);
};
class Treap {
private:
    Node* root;
    Node* merge(Node* left, Node* right);

    int get_sum(Node* node);
    int get_size(Node* node);
    void update(Node* node);
    void split_by_size(Node* node, int k, Node*& left, Node*& right);
public:
    Treap();
    Treap(const Treap& other);
    ~Treap();
    Treap(Treap&& other);
    Treap& operator=(Treap other);

    void copyTreap(Node* node, int count);
    void deleteTreap(Node* node);
    void insert_pos(int pos, int val);
    void erase(Node* node, int pos);
    int sum(int start, int end);
    Node* get_root();
};
int start(Treap& treap, int arr[], int size, int start, int end);