// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    	struct DLLNode {
		int key;
		int val;
		DLLNode *prev;
		DLLNode *next;
		DLLNode(int a, int b): val(a), key(b), prev(NULL), next(NULL) {}
	};

	DLLNode *head, *tail;
	unordered_map<int, DLLNode*> keyToAddress;
	int LRUsize;
    LRUCache(int capacity)
    {
        // code here
        keyToAddress.clear();
		head=NULL;
		tail=NULL;
		LRUsize=capacity;
    }
    
    //Function to return value corresponding to the key.
    
	void removeNode(DLLNode *node) {
		auto prevNode=node->prev;
		auto nextNode=node->next;

		if(prevNode) prevNode->next=nextNode;
		else tail=nextNode;

		if(nextNode) nextNode->prev=prevNode;
		else head=prevNode;

		node->next=NULL;
		node->prev=NULL;
	}
    void insertNode(DLLNode *node) {
		if(head==NULL) {
			head=tail=node;
		} else {
			node->prev=head;
			head->next=node;
			head=node;
		}
	}
    int get(int key)
    {
        // your code here
        if(keyToAddress.find(key)!=keyToAddress.end()) {
			auto node=keyToAddress[key];
			removeNode(node);
			insertNode(node);

			return node->val;
		} 
		return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(keyToAddress.find(key)!=keyToAddress.end()) {
			auto node=keyToAddress[key];
			removeNode(node);

			node->val=value;
			insertNode(node);
		} else { 
			auto node=new DLLNode(value, key);
			keyToAddress[key]=node;

			if(keyToAddress.size()>LRUsize) {
				DLLNode *tailNode=tail;
				removeNode(tail);

				keyToAddress.erase(tailNode->key);
				delete(tailNode);
			}

			insertNode(node);
		}
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends