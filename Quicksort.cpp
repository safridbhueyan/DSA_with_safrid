#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low, int high){
int pivot = arr[high];
int i = (low - 1);
for(int j = low; j<=high-1; j++){
if(arr[j]<=pivot)
{
    i++;
   // swap(arr[i],arr[j]);
   int temp = arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
}}
i++;
//swap(arr[i+1],arr[high]);
int temp = arr[i];
arr[i]=arr[high];
arr[high]=temp;
return i;
}

void quicksort(int arr[],int low , int high){

if(low<high){
    int pivotIndex = partition(arr,low,high);
    quicksort(arr,low,pivotIndex-1);
    quicksort(arr,pivotIndex+1,high);
}

}
int main(){
    cout<<"Enter the Array[] index number : ";
    int n;
    cin>>n;
    cout<<"Enter the Array[] values : ";
    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
quicksort(arr,0,n-1);
cout<<"sorted Array[] : ";
 for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}
