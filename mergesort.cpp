#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int left,int mid,int right)
{
    int n1 = mid-left+1; // temporary left array[n1] size declaration
    int n2 = right-mid;// temporary right array[n2] size declaration
    int a[n1];  //left temporary array of size n1
    int b[n2];// right temporary array of size n2

// array element insertion through for loop in the new temporary left and right array's
for(int i =0 ; i<n1; i++)
{
    a[i]= arr[left+i]; // left+i coz if left array starts from index 0 then i is also 0 so [  left+i = (0+0)= 0[index] ]
                     // if left array starts from index 1 then left + i will be [ left+i = (1+0)= 1[index] ]
}
for(int i =0 ; i<n2; i++)
{
    b[i]= arr[mid+1+i]; // mid+1+i coz if right array starts from mid+1 which is index 3 then i is also 0 so [  mid+1+i = (3+0)= 3[index] ]
                     // if right array starts from index 5 (mid+1) then  mid+1+i will be [ mid+1+i = (5+0)= 5[index] ]
}
//to merge the a[] and b[] array's into original array[] in sorted way we have to do

//we have take indices i=0; j=0; k= left;

int i = 0 ;
int j = 0 ;
int k = left ;// to copy the value into original array we have to take another temporary array which will starts from index k [left]

//NOW main game starts from here
// we will check the condition for each left and right temporary array to sort the smallest into the new temporary array[k] ;

while(i<n1 && j<n2)
 {

  if(a[i]<b[j])

   {
    arr[k]=a[i];
     k++;
     i++;
    }

else{
    arr[k]=b[j];

    k++;
    j++;
}}
//to add left out array elements into the new temporary sorted array we have to
while(i<n1)
{
    arr[k]=a[i];
     k++;
     i++;
}
while(j<n2)
{
   arr[k]=b[j];
    k++;
    j++;
}
}

void mergesort(int arr[],int left, int right){
if(left == right){
    return;
}
else if(left < right){

    int mid = (left+right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);

    merge(arr,left,mid,right);

}

}
int main()
{

    cout<<"Enter the size of Array[] : ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the Elements of Array[] : ";
    for(int i = 0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

  mergesort(arr,0,n-1);

  cout<<"Sorted Array[] : ";

  for(int i = 0 ; i<n ; i++)
    {
      cout<<arr[i]<<" ";
    }

    return 0;
}
