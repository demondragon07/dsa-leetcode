//{ Driver Code Starts
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
    private:
    Node*solve(Node*first,Node*second){
    
    if(first->next==NULL){
        first->next=second;
        return first;
    }
    
    Node*curr1=first;
    Node*next1=curr1->next;
    Node*curr2=second;
    Node*next2=curr2->next;
    
    while(next1!=NULL && curr2!=NULL){
        if((curr2->data>=curr1->data)&&(curr2->data<=next1->data)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }else{
            curr1=next1;
            next1=next1->next;
            
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    
    return first;
    
}

Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1==NULL){
        return head2;
    }
    
    if(head2==NULL){
        return head1;
    }
    
    if(head1->data<=head2->data){
         return solve(head1,head2);
    }else{
        return solve(head2,head1);
    }
    
} 
    
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        for(int i=1;i<K;i++){
           arr[i]= sortedMerge(arr[i-1],arr[i]);
        }
         
         return arr[K-1];
         
    }
};



//{ Driver Code Starts.
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