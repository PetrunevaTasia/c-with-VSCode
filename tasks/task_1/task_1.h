#include <iostream>
#include <cstdlib>
#include <stdlib.h>
class Node {//inside treap
public://private or struct
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
    Node* root = nullptr;
    Node* merge(Node* left, Node* right);
    int get_sum(Node* node);
    int get_size(Node* node);
    void update(Node* node);
    void split_by_size(Node* node, int k, Node*& left, Node*& right);
    static void deleteTreap(Node* node);
public:
    ~Treap();
    void insert_pos(int pos, int val);
    void erase(Node* node, int pos);
    int sum(int start, int end);
};
int start(int arr[], int size, int start, int end);