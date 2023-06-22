//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
   private:
   Node*parentmapping(Node*root,int target, map<Node*,Node*>&parenttomap){
     
       Node*res=NULL;
       queue<Node*>q;
       q.push(root);
       parenttomap[root]=NULL;
       while(!q.empty()){
           Node*frontend=q.front();
           q.pop();
           if(frontend->data==target){
               res=frontend;
           }
           if(frontend->left){
               parenttomap[frontend->left]=frontend;
               q.push(frontend->left);
           }
           if(frontend->right){
               parenttomap[frontend->right]=frontend;
               q.push(frontend->right);
           }
       }
       
       return res;
   }
    
    
 int burntree(Node*root, map<Node*,Node*>&parenttomap){
     map<Node*,bool>visited;
     queue<Node*>q;
     int ans=0;
     q.push(root);
     visited[root]=true;
     
     while(!q.empty()){
        bool flag=0;
        int n=q.size();
        for(int i=0;i<n;i++){
            Node*frontend=q.front();
            q.pop();
            
            if(frontend->left && !visited[frontend->left]){
                flag=1;
                visited[frontend->left]=1;
                q.push(frontend->left);
            }
            
            if(frontend->right && !visited[frontend->right]){
                flag=1;
                visited[frontend->right]=1;
                q.push(frontend->right);
            }
            
            if( parenttomap[frontend] && !visited[parenttomap[frontend]]){
                flag=1;
                visited[parenttomap[frontend]]=1;
                q.push(parenttomap[frontend]);
            }
            
        }
        
        if(flag==1){
            ans++;
        }
         
     }
     
     return ans;
 }    
    
  public:
    int minTime(Node* root, int target) 
    {
       map<Node*,Node*>parenttomap;
       Node*targetnode=parentmapping(root,target,parenttomap);
        return burntree(targetnode,parenttomap);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends