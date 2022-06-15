// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node* l1,Node* l2){
        Node* res = new Node(0);
        Node* ans = res;
        Node* p1 = l1;
        Node* p2 = l2;
        if(p1==NULL) return p2;
        if(p2==NULL) return p1;
        while(p1!=NULL && p2!=NULL){
            if(p1->data<p2->data){
                ans->next = p1;
                ans = ans->next;
                p1 = p1->next;
            }
            else{
                ans->next = p2;
                ans = ans->next;
                p2 = p2->next;
            }
        }
        while(p1!=NULL){
            ans->next = p1;
            ans = ans->next;
            p1 = p1->next;
        }
        while(p2!=NULL){
            ans->next  = p2;
            ans = ans->next;
            p2 = p2->next;
        }
        return res->next;
    }
    Node* partition(Node* arr[],int s,int e){
        if(s>e) return NULL;
        if(s==e) return arr[s];
        int mid = s+(e-s)/2;
        Node* l1 = partition(arr,s,mid);
        Node* l2 = partition(arr,mid+1,e);
        return merge(l1,l2);
    }
    
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           if(K==0) return NULL;
           return partition(arr,0,K-1);
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends