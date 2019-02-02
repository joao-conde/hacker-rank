#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* prev;
    Node* next;
    int key;
    int value;

    Node(Node* p, Node* n, int k, int val)
        : prev(p), next(n), key(k), value(val){};

    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {
   protected:
    map<int, Node*> mp;  // map the key to the node in the linked list
    unsigned int cp;     // capacity
    Node* tail;          // double linked list tail pointer
    Node* head;          // double linked list head pointer
    virtual void set(int, int) = 0;  // set function
    virtual int get(int) = 0;        // get function
};

class LRUCache : protected Cache {
   public:
    LRUCache(int capacity) {
        cp = capacity;
        tail = nullptr;
        head = nullptr;
    }

    void set(int k, int v) {
        auto it = mp.find(k);
        if (it != mp.end()) {  // node exists, update value, insert at head
            it->second->value = v;
            removeNode(it->second);
            insertAtHead(it->second);
        } else {  // node does not exist
            Node* newNode = new Node(k, v);

            if (tail == nullptr && head == nullptr) {  // first node
                mp.insert({k, newNode});
                newNode->next = newNode;
                newNode->prev = newNode;
                head = newNode;
                tail = newNode;
                return;
            }

            if (mp.size() <
                cp) {  // create new node, capacity allows, insert new at head
                mp.insert({k, newNode});
                insertAtHead(newNode);
            } else {  // create new node but capacity full, remove last node,
                      // insert new at head
                mp.erase(tail->key);
                mp.insert({k, newNode});
                removeNode(tail);
                insertAtHead(newNode);
            }
        }
    }

    int get(int k) {
        auto it = mp.find(k);
        return (it != mp.end() ? it->second->value : -1);
    }

    void removeNode(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void insertAtHead(Node* n) {
        n->next = head;
        head->prev = n;
        n->prev = tail;
        tail->next = n;
    }
};

int main() {
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        } else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
}
