#include<iostream>
using namespace std;

int a[20];
void Merge(int a[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k= lb;
    int b[20];
    while((i<=mid)&&(j<=ub)){
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++)
    {
        a[k]=b[k];
    }
}

void mergesort(int a[],int lb,int ub)
{
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        Merge(a,lb,mid,ub);
    }
}



int main()
{
  int n,i,Size;
  cout<<"enter the size of the array";
    cin>>n;
    cout<<"enter array elements:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    Size =n-1;
    mergesort(a, 0, Size);
    cout<<"sorted array elements:";
    for(i=0;i<n;i++)
    {
        cout<<" "<<a[i];
    }
    return 0;

}
