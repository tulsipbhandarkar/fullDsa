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


node* find(node* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    return root;
    if(key>root->data)
    {
        return find(root->right,key);
    }
    if(key<root->data)
    {
        return find(root->left,key);
    }
    
    
}


int main(){
    
    node* root=insertBST(root,500);
    
    insertBST(root,20);
    
    insertBST(root,7);
    
    insertBST(root,8);
    
    insertBST(root,9);
    
    preorder(root);
    
    cout<<endl;
    
    if(find(root,20)!=NULL)
    cout<<1<<endl;
    else
    cout<<0<<endl;
    return 0;
}