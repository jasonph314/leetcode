// Created by jasonph at 2025/11/24 10:01
// leetgo: 1.4.15
// https://leetcode.com/problems/lru-cache/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;
// using a DLL for O(1) put, and hashmap for O(1) get
// 1. once get is called, it goes to the front of our list
// 2. once put is called, it also gets moved to the head
// 3. Need helper functions to shift the nodes around or remove them
// FIRST, let's set up the DLL and Hashmap 

// @lc code=begin

class LRUCache {
private:

    struct Node {
        int key;  // upon deleting, we need to remove it from our hashmap as well
        int value; 
        Node* next;
        Node* prev;
        Node () : key(0), value(0), next(nullptr), prev(nullptr) {}
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr){}

    };
    // setting up the DLL and hashmap
    unordered_map<int, Node*> cache;

    // Add constructors for the struct
    // keep track of size and capacity
    int capacity;
    int size;

    // removeNode -- returns a Node
    void removeNode (Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // addNode to head
    void addToHead (Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;

    }

    // moveToHead -- combination of the other two
    void moveToHead (Node* node){
        removeNode(node);
        addToHead(node);

    }
    
    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }


public:
    LRUCache(int capacity) {
        // initializes our Cache, starting with dummy nodes at the ends of heads and tails
        head = new Node (0,0);
        tail = new Node (0,0);
        // connecting them together
        head->next = tail;
        tail->prev = head;

        // initializing our capacity
        this->capacity = capacity;
        // initialize the size
        size = 0;

    }
    ~LRUCache() {
        // destructor will destroy the entire list from memory
        Node* curr = head;
        while (curr) {
        Node* temp = curr->next;
        delete curr;
        curr = temp;
        // think of reversing but with deleting logic
        }
    }
    
    int get(int key) {
        // if the key exists
        if (cache.find(key) != cache.end()) {
            // return its value
            Node* node = cache[key];
            moveToHead(node); // now most recently used, so move to head
            return node->value;

        }
        else {
        // otherwise return -1
            return -1;
        }        
    }
    
    void put(int key, int value) {

        // if the key exists, access it and update its value
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);

        }
        else { // if it doesn't exist 
            Node* node = new Node(key, value);
            cache[key] = node;
            addToHead (Node);
            size++;
            // if we're at capacity, evict the least recently used    
            if (size > capacity) {
                Node* lru = removeTail();
                cache.erase(lru->key); // no longer empty value
                delete lru;
                size --;

            }
        }
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	LRUCache *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "LRUCache", [&]() {
			int capacity; LeetCodeIO::scan(cin, capacity); cin.ignore();
			obj = new LRUCache(capacity);
			out_stream << "null,";
		} },
		{ "get", [&]() {
			int key; LeetCodeIO::scan(cin, key); cin.ignore();
			LeetCodeIO::print(out_stream, obj->get(key)); out_stream << ',';
		} },
		{ "put", [&]() {
			int key; LeetCodeIO::scan(cin, key); cin.ignore();
			int value; LeetCodeIO::scan(cin, value); cin.ignore();
			obj->put(key, value);
			out_stream << "null,";
		} },
	};
	cin >> ws;
	out_stream << '[';
	for (auto &&method_name : method_names) {
		cin.ignore(2);
		methods.at(method_name)();
	}
	cin.ignore();
	out_stream.seekp(-1, ios_base::end); out_stream << ']';
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
