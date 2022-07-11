// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node*rev(Node*&temp)

    {

        Node*next; 

        Node*prev=nullptr; 

        while(temp)

        { next=temp->next; 

            temp->next=prev; 

            prev=temp; 

            temp=next; 

            

        }

        return prev;

    }

   Node* addOne(Node *head) 

   {

       Node* ans=head;

       ans=rev(ans);

       Node* temp=ans; 

       int sum,carry=1; Node*prev;

       while(temp !=NULL){

           sum=temp->data;

           sum+=carry;

           carry=sum/10;

           temp->data=sum%10;

           prev=temp; 

           temp=temp->next;

       }

       if(carry>0){

           prev->next=new Node(carry);

       }

       return rev(ans);

}
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends