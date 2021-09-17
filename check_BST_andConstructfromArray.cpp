#include"iostream"
using namespace std;
struct node
{
    struct node* right;
    struct node* left;
    int data;
    node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
        
    }
};

node* insertBST(node* root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    
    if(val>root->data)
    {
        root->right=insertBST(root->right,val);
    }
    
    else
    {
        root->left=insertBST(root->left,val);
    }
    
    return root;
}

void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}

node* sortedArraytoBST(int arr[],int start,int end)
{
    if(start>end)
    return NULL;

    int mid=(start+end)/2;

    node* root=new node(arr[mid]);

    root->left=sortedArraytoBST(arr,start,mid-1);
    root->right=sortedArraytoBST(arr,mid+1,end);
    
    return root;
}


bool similar(node* root1,node* root2)
{
    if(root1==NULL && root2==NULL)
    return true;

    else if(root1==NULL || root2==NULL)
    return false;

    else
    {
        bool cond1= root1->data==root2->data;
        bool cond2= similar(root1->right,root2->right);
        bool cond3= similar(root1->left,root2->left);

        if(cond1 and cond2 and cond3)
        return true;
    }
    return false;
}


node* find(struct node* root,int key)
{
    if(root==NULL)
        return NULL;

    if(root->data==key)
    return root;

    if(root->data > key)
    return find(root->left,key);

    else if(root->data <key)
    return find(root->right,key);
    
}


bool isBST(node* root,node* min,node* max)
{
    if(root==NULL)
    return true;
    
    if(min!=NULL && root->data <= min->data)
    return false;
    
    if(max!=NULL && root->data >= max->data)
    return false;
    
    bool leftValid=isBST(root->left,min,root);
    bool rightValid=isBST(root->right,root,max);
    
    return leftValid && rightValid;
}



int main(){
    
    node* root=insertBST(root,500);
    
    insertBST(root,20);
    
    insertBST(root,7);
    
    insertBST(root,8);
    
    insertBST(root,9);
    
  
    return 0;
}