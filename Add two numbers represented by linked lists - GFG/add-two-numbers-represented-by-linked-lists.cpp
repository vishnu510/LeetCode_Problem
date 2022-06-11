// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* &curr){
        Node* prev = NULL;
        Node* nxt = curr->next;
        curr->next = prev;
        while(nxt){
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            curr->next = prev;
        }
        return curr;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* curr = new Node(0);
        Node* temp = curr;
        int cf =0;
        Node*l1 = reverse(first);
        Node* l2 = reverse(second);
        while(l1 || l2||cf){
            cf+=l1?(l1->data):0;
            cf+=l2?(l2->data):0;
            curr->next = new Node(cf%10);
            cf/=10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            curr = curr->next;
        }
        return reverse(temp->next);
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends