// https://leetcode.com/problems/lfu-cache/description/
class LFUCache {
    public:
        // Node class represents a single key-value pair along with its frequency count
        class Node {
        public:
            int key;  // Stores the key
            int val;  // Stores the value
            int cnt;  // Frequency count of the key
            Node* prev = NULL;
            Node* next = NULL;
    
            // Constructor to initialize the node with key and value, default frequency = 1
            Node(int key_, int val_) {
                key = key_;
                val = val_;
                cnt = 1;  // When a key is first inserted, its count is 1
            }
        };
    
        // Doubly linked list to store keys of the same frequency in order (Least Recently Used (LRU) comes last)
        class LinkedList {
        public:
            int size;  // Number of elements in the list
            Node* head;
            Node* tail;
    
            // Constructor to initialize dummy head and tail for easy insert/delete operations
            LinkedList() {
                head = new Node(-1, -1);
                tail = new Node(-1, -1);
                head->next = tail;
                tail->prev = head;
                size = 0;
            }
    
            // Adds a new node at the beginning (Most Recently Used position)
            void add(Node* nee) {
                Node* temp = head->next;
                nee->next = temp;
                nee->prev = head;
                head->next = nee;
                temp->prev = nee;
                size++;
            }
    
            // Removes a given node from the list
            void delet(Node* del) {
                Node* delprev = del->prev;
                Node* delnext = del->next;
                delprev->next = delnext;
                delnext->prev = delprev;
                size--;
            }
        };
    
        // Maps to store key-value and frequency information
        map<int, Node*> mppKey;  // Key -> Node (storing the value and frequency)
        map<int, LinkedList*> mppList;  // Frequency -> Doubly Linked List of nodes
        int cap;  // Maximum capacity of LFU cache
        int mini; // Minimum frequency present in the cache
        int curr; // Current size of the cache
    
        // Constructor to initialize the LFU cache with the given capacity
        LFUCache(int capacity) {
            cap = capacity;
            mini = 0;  // Initially, the minimum frequency is set to 0
            curr = 0;  // Current number of keys in cache is 0
        }
    
        // Function to update the frequency of a node when it's accessed (get or put)
        void update(Node* node) {
            mppKey.erase(node->key);  // Remove node from key map (will be re-added)
            mppList[node->cnt]->delet(node);  // Remove node from its current frequency list
    
            // If this was the last node of the minimum frequency list, increase min frequency
            if (node->cnt == mini && mppList[node->cnt]->size == 0) {
                mini++;
            }
    
            // Move node to next frequency level
            LinkedList* neeHighList = new LinkedList();
            if (mppList.find(node->cnt + 1) != mppList.end()) {
                neeHighList = mppList[node->cnt + 1];  // Get existing frequency list if present
            }
    
            node->cnt++;  // Increase frequency
            neeHighList->add(node);  // Add node to the new frequency list
            mppList[node->cnt] = neeHighList;  // Update frequency list in the map
            mppKey[node->key] = node;  // Re-add the node to the key map
        }
    
        // Retrieves the value of the key if present; otherwise, returns -1
        int get(int key) {
            if (mppKey.find(key) != mppKey.end()) {
                Node* node = mppKey[key];  // Get the node
                int res = node->val;  // Store the value to return
                update(node);  // Update its frequency
                return res;
            }
            return -1;  // Key not found
        }
    
        // Inserts a new key-value pair or updates an existing key's value
        void put(int key, int value) {
            if (cap == 0) return;  // If capacity is zero, do nothing
    
            // If key already exists, update the value and increase frequency
            if (mppKey.find(key) != mppKey.end()) {
                Node* node = mppKey[key];
                node->val = value;
                update(node);
            } 
            else {
                // If cache is full, remove the Least Frequently Used (LFU) key
                if (curr == cap) {
                    LinkedList* minifreq = mppList[mini];  // Get the list with minimum frequency
                    mppKey.erase(minifreq->tail->prev->key);  // Remove the LRU key from key map
                    mppList[mini]->delet(minifreq->tail->prev);  // Remove from the frequency list
                    curr--;  // Decrement current size
                }
    
                // Insert new key-value pair with frequency 1
                curr++;
                mini = 1;  // Reset min frequency to 1
                LinkedList* freq = new LinkedList();
                if (mppList.find(mini) != mppList.end()) {
                    freq = mppList[mini];  // Get existing list if present
                }
                Node* nee = new Node(key, value);
                freq->add(nee);  // Add to frequency list
                mppKey[key] = nee;  // Add to key map
                mppList[mini] = freq;  // Update frequency map
            }
        }
    };
    
    /**
     * Your LFUCache object will be instantiated and called as such:
     * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key, value);
     */