#include <unordered_map>
using namespace std;

class LRUCache {
   private:
    class Node {
       public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

    // Insert node right after head (Most Recently Used)
    void insert(Node* node) {
        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }

    // Remove a node from the linked list
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        Node* node = cache[key];

        // Move to front (MRU)
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {
        // Key already exists
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];

            node->value = value;

            remove(node);
            insert(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        cache[key] = node;
        insert(node);

        // Remove LRU if capacity exceeded
        if (cache.size() > capacity) {
            Node* lru = tail->prev;

            remove(lru);

            cache.erase(lru->key);

            delete lru;
        }
    }
};