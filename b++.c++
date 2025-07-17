#include <iostream>
#include <vector>
using namespace std;

const int ORDER = 3;

template<typename T>
class Node {
public:
    bool isLeaf;
    vector<T> keys;
    Node<T>* parent;
    vector<Node<T>*> children;
    Node() : isLeaf(true), parent(nullptr) {}
};

template<typename T>
class BPlusTree {
public:
    Node<T>* root;

    BPlusTree() : root(nullptr) {}

    void insert(T key) {
        if (!root) {
            root = new Node<T>();
            root->keys.push_back(key);
        } else {
            Node<T>* leaf = findLeaf(root, key);
            insertIntoNode(leaf, key);
            while (leaf->keys.size() >= ORDER) {
                leaf = splitNode(leaf);
            }
        }
    }

    bool search(T key) {
        if (!root) return false;
        Node<T>* leaf = findLeaf(root, key);
        for (T k : leaf->keys)
            if (k == key) return true;
        return false;
    }

    void display() {
        inorderDisplay(root);
        cout << endl;
    }

private:
    Node<T>* findLeaf(Node<T>* cur, T key) {
        if (cur->isLeaf) return cur;
        int idx = 0;
        while (idx < cur->keys.size() && key > cur->keys[idx]) idx++;
        return findLeaf(cur->children[idx], key);
    }

    void insertIntoNode(Node<T>* node, T key) {
        auto it = node->keys.begin();
        while (it != node->keys.end() && *it < key) ++it;
        node->keys.insert(it, key);
    }

    Node<T>* splitNode(Node<T>* node) {
        Node<T>* newNode = new Node<T>();
        int mid = node->keys.size() / 2;
        newNode->keys.assign(node->keys.begin() + mid, node->keys.end());
        node->keys.erase(node->keys.begin() + mid, node->keys.end());

        newNode->parent = node->parent;
        if (node == root) {
            Node<T>* newRoot = new Node<T>();
            newRoot->isLeaf = false;
            newRoot->keys.push_back(newNode->keys.front());
            newRoot->children.push_back(node);
            newRoot->children.push_back(newNode);
            node->parent = newNode->parent = newRoot;
            root = newRoot;
        } else {
            Node<T>* p = node->parent;
            insertIntoNode(p, newNode->keys.front());
            int idx = 0;
            for (; idx < p->children.size() && p->children[idx] != node; ++idx);
            p->children.insert(p->children.begin() + idx + 1, newNode);
        }
        return node->parent ? node->parent : newNode;
    }

    void inorderDisplay(Node<T>* cur) {
        if (!cur) return;
        if (cur->isLeaf) {
            for (T k : cur->keys) cout << k << " ";
        } else {
            for (int i = 0; i < cur->keys.size(); i++) {
                inorderDisplay(cur->children[i]);
                cout << cur->keys[i] << " ";
            }
            inorderDisplay(cur->children.back());
        }
    }
};

int main() {
    BPlusTree<int> tree;
    int choice, key;
    do {
        cout << "\n--- B+ Tree Menu ---\n";
        cout << "1. Insert\n2. Search\n3. Display (in-order)\n4. Exit\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to insert: "; cin >> key;
                tree.insert(key);
                break;
            case 2:
                cout << "Enter value to search: "; cin >> key;
                cout << (tree.search(key) ? "Found\n" : "Not Found\n");
                break;
            case 3:
                cout << "B+ Tree keys (in-order): ";
                tree.display();
                break;
            case 4:
                cout << "Exiting...\n"; break;
            default:
                cout << "Invalid option!\n";
        }
    } while (choice != 4);
    return 0;
}
