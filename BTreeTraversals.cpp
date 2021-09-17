#include"iostream"
using namespace std;
struct node
{
    struct node* left;
    struct node* right;
    int data;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void postorder(struct node* root)
{
if(root==NULL)
return;

postorder(root->left);
postorder(root->right);
cout<<root->data<<" ";

}


void preorder(struct node* root)
{
if(root==NULL)
return;

cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);

}





void inorder(struct node* root)
{
if(root==NULL)
return;

inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}




int main()
{
struct node* root=new node(3);
root->left=new node(2);
root->right=new node(5);
root->left->left=new node(6);
root->left->right=new node(7);
root->right->left=new node(19);
root->right->right=new node(20);
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;
    return 0;
}