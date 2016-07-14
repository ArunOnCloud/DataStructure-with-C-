#include<iostream>
using namespace std;

void update(int* a,int n,int index,int val)
{
    cout<<"update\n";
    index+=1;
    while(index<=n)
    {
        a[index]+=val;
        index += index & (-index);

    }
}
int getsum(int* a,int index)
{
    cout<<"getsum\n";
    index+=1;
    int sum=0;
    while(index>0)
    {
        sum+=a[index];
        index-=index & ( -index);
    }
    return sum;
}
int* buildBIT(int* a,int n)
{
    cout<<"buildBIT\n";
    int* arr=new int[n+1];
    for(int i=0;i<n+1;i++)
    arr[i]=0;
    for(int i=0;i<n;i++)
    {
        update(arr,n,i,a[i]);
    }
    // now building bit

    return arr;
}
int main()
{
    int a[]={3,4,5,1,12,13,9,0};
    int n=8;
    int* arr=buildBIT(a,n);
    cout<<getsum(arr,6)<<endl;
    return 0;
}
