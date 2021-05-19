#include<iostream>
using namespace std;

void Maxheapify(int a[],int n,int i)
{
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if((l<=n)&&(a[l]>a[largest]))
    {
        largest=l;
    }
    if((r<=n)&&(a[r]>a[largest]))
    {
        largest =r;
    }
    if(largest!=i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest] = temp;
        Maxheapify(a,n,largest);
    }

}

void heapsort(int a[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        Maxheapify(a,n,i);
    }
    for(int i=n;i>0;i--)
    {
        int temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        Maxheapify(a,n,0);
    }
}

int main()
{
    int n,i;

    cout<<"enter the size of the array";
    cin>>n;

    int a[n];
    cout<<"enter array elements:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    heapsort(a,n-1);
    cout<<"sorted array elements:";
    for(i=0;i<n;i++)
    {
        cout<<" "<<a[i];
    }
    return 0;

}
