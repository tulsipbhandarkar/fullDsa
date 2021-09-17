#include<iostream>
using namespace std;


void printarr(int a[],int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    
    cout<<endl;
}



void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    
}



void selectionsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            swap(a,i,j);
        }
    }
}



void bubblesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]<a[j+1])
            swap(a,j,j+1);
        }
    }
}



void insertionsort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int current=a[i];
        int j=i-1;
        while(a[j]>current && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=current;
        
    }
}




void merge(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    
    for(int i=0;i<n1;i++)
    {
        b[i]=arr[mid+i+1];
    }
    
    int i=0,j=0,k=l;
    
    while(i<n1 && j<n2)
    {
        if(a[i]<b[i])
        {
            arr[k]=a[i];
            i++;
            j++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    
    while(i<n1)
    {
        arr[k]=a[i];
        i++; k++;
    }
    
    while(j<n2)
    {
        arr[k]=b[j];
        j++; k++;
    }
    
}
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}




int partition(int a[],int l,int r)
{
    int pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        i++;
        swap(a,i,j);
    }
    swap(a,i+1,r);
    
    return i+1;
}
void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int pi=partition(a,l,r);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,r);
    }
}



int binarysearch(int a[],int n,int key)
{
    int start = 0;
    int end = n;
    
    while(start<=end)
    {
        int mid;
        
        mid=(start+end)/2;
        
        
        if(a[mid]==key)
        return mid;
        
        
        else if(a[mid]>key)
        end=mid-1;
        
        else
        start=mid+1;
    
    }
    
    return -1;
}



int linearsearch(int a[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        return i;
    }
    
    
    
    return -1;
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    selectionsort(a,n);
    
    printarr(a,n);
    
    insertionsort(a,n);
    
    printarr(a,n);
    
    bubblesort(a,n);
    
    printarr(a,n);
    
    mergesort(a,0,n-1);
    
    printarr(a,n);
    
    quicksort(a,0,n-1);
    
    printarr(a,n);
    
    cout<<linearsearch(a,n,5);
    
    cout<<endl;
    
    cout<<binarysearch(a,n,6);
    
    cout<<endl;
    
    return 0;
}