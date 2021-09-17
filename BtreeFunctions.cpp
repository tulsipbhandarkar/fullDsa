#include"iostream"
using namespace std;


struct node
{
    struct node* left;
    struct node* right;
    int data;
    node(int val)
    {
     
     data = val;
     left = NULL;
     right = NULL;
     
    }
    
};


int calcSumof(struct node* root)
{
    if(root == NULL)
    return 0;
    
    return calcSumof(root->left) + calcSumof(root->right) + root->data;
}





int calcNumberOfNodes(struct node* root)
{
    if(root == NULL)
    return 0;
    
    return calcNumberOfNodes(root->right) + calcNumberOfNodes(root->left) + 1;
}




void sumatKthLevel(node* root,int k,int* ans){
     if(root == NULL){
        return;
    }
    
    if(k == 1){
        *ans += root->data;
    }
    sumatKthLevel(root->left,k-1,ans);
    sumatKthLevel(root->right,k-1,ans);
}




void sumreplace(struct node* &root)
{
    if(root == NULL)
    return;
    
    sumreplace(root->left);
    sumreplace(root->right);
    
    if(root->right!=NULL)
    {
        root->data+=root->right->data;
    }
    if(root->left!=NULL)
    {
        root->data+=root->left->data;
    }
}



int calcHeight(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return max(calcHeight(root->left),calcHeight(root->right)) + 1;

}



int calculateDiameter(struct node* root)
{
    if(root==NULL)
    return 0;
    
    int ld=calcHeight(root->left);
    int rd=calcHeight(root->right);
    int cd=ld+rd+1;
    
    return max(cd,max(calculateDiameter(root->right),calculateDiameter(root->left)));
}



int main()
{
int ans=0;
struct node* root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right=new node(5);
root->right->left=new node(6);
root->right->right=new node(7);
root->right->right->right=new node(78);

cout<<calcNumberOfNodes(root)<<endl;

cout<<calcSumof(root)<<endl;

cout<<calcHeight(root)<<endl;

cout<<calculateDiameter(root)<<endl;

return 0; 

}
/*
     1
    /\
   2  3
  /\  /\
 4  5 6 7
*/
 