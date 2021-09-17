#include"iostream"
using namespace std;
struct node{
    struct node* left;
    struct node* right;
    int data;
    node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};
int maxsumUtil(struct node* root,int ans)
{
    if(root==NULL)
    return 0;
    
    int right=maxsumUtil(root->right,ans);
    int left=maxsumUtil(root->left,ans);

    int nodemax=max(root->data,max(root->data+right+left,max(root->data+left,root->data+right)));

    ans=max(ans,nodemax);
    
    int singlepath=max(root->data,max(root->data+left,root->data+right));
    return singlepath;
}


int maxpathsum(struct node* root)
{
  

    int ans=INT_MIN;
    maxsumUtil(root,ans);
    return ans;
}

int main()
{

struct node* root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right=new node(5);
root->right->left=new node(6);
root->right->right=new node(7);
root->right->right->right=new node(78);


    return 0;
}