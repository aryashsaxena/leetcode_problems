//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node* f(int pst,int pend,int post[]){
    if(pend<pst) return NULL;
    
    Node* root=new Node(post[pend]);
    
    int i=upper_bound(post+pst,post+pend,post[pend])-post;
    
    root->left=f(pst,i-1,post);
    root->right=f(i,pend-1,post);
    return root;
}

Node *constructTree (int post[], int size)
{
//code here
    return f(0,size-1,post);
}