// https://leetcode.com/problems/lru-cache/description/
class LRUCache {
    public:
        class Node {
        public:
            int key, value;
            Node* next, *prev;
            Node(int key, int value) {
                this->key = key;
                this->value = value;
                next = NULL;
                prev = NULL;
            }
        };
    
        int capacity;
        unordered_map<int, Node*> mp; // Hashmap to store key and corresponding node address
    
        Node* head = new Node(-1, -1); // Dummy head node
        Node* tail = new Node(-1, -1); // Dummy tail node
    
        LRUCache(int capacity) {
            this->capacity = capacity;
            head->next = tail;
            tail->prev = head;
        }
    
        // Function to remove a node from the doubly linked list
        void deleteNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    
        // Function to insert a node at the head of the doubly linked list
        void insertAtHead(Node* node) {
            Node* temp = head->next;
            head->next = node;
            node->prev = head;
    
            node->next = temp;
            temp->prev = node;
        }
        
        // Function to retrieve a value from the cache
        int get(int key) {
            if (mp.find(key) == mp.end())
                return -1; // Key not found
            else {
                Node* currNode = mp[key];
                deleteNode(currNode); // Remove node from current position
                insertAtHead(currNode); // Move node to front (most recently used)
                return currNode->value;
            }
        }
        
        // Function to insert or update a key-value pair in the cache
        void put(int key, int value) {
            if (mp.find(key) != mp.end()) {
                // If key exists, update value and move to front
                Node* currNode = mp[key];
                currNode->value = value;
                deleteNode(currNode);
                insertAtHead(currNode);
            } else {
                Node* newNode = new Node(key, value);
                if (mp.size() == capacity) {
                    // If cache is full, remove the least recently used (LRU) node
                    Node* todel = tail->prev;
                    mp.erase(todel->key);
                    deleteNode(todel);
                    insertAtHead(newNode);
                    mp[key] = newNode;
                    delete todel;
                } else {
                    // If cache is not full, simply insert at head
                    insertAtHead(newNode);
                    mp[key] = newNode;
                }
            }
        }
    };
    