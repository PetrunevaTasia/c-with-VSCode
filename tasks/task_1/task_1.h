#include <iostream>
#include <cstdlib>
#include <stdlib.h>
class Treap {
    struct Node {//inside treap //private or struct
        int val;
        int p;
        int size = 1;
        int sum;
        Node* left;
        Node* right;
        Node();
        Node(int val_init, Node* left_init, Node* right_init);            
    };
private:
    Treap::Node* root = nullptr;
    Treap::Node* merge(Node* left, Node* right);
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