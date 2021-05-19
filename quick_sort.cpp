#include<iostream>
using namespace std;


template<class T>
void qsort(T a[],int lb, int ub)
{
    int i,j,key,b;

    if(lb<ub)
    {
        i=lb;
        j=ub;
        key=a[i];
        while(i<j)
        {

            while((a[i]<=key)&&(i<=ub)){
                i++;
            }

            while((a[j]>key)&&(j>=lb)){
                j--;
            }
            if(i<j){
                b=a[i];
                a[i]=a[j];
                a[j]=b;
            }

        }

        b=a[lb];
        a[lb]=a[j];
        a[j]=b;
    }
    else
        return;
    qsort(a,lb,j-1);
    qsort(a,j+1,ub);

}

int main()
{
    int a[20],n,i,size;
    cout<<"enter the size of the array";
    cin>>n;
    cout<<"enter array elements:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    size =n-1;
    qsort(a, 0, size);
    cout<<"sorted array elements:";
    for(i=0;i<n;i++)
    {
        cout<<" "<<a[i];
    }
    return 0;
}
