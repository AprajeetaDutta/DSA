//TextFile of sorted array in descending order using quick_sort
#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<time.h>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot=arr[r];
    int i=l-1;
    int temp;
    for(int j=l;j<r;j++){
        if(arr[j]>pivot){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return (i+1);
}
void quick_sort(int arr[], int l, int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,r);
    }
}
int main(){
    ifstream fin1("Random.txt",ios::in);
    int size=10000;
    int arr[size], i;
    srand(time(0));
    for(i=0;i<size;i++){
        arr[i]=rand();
    }
    /*for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }*/
    quick_sort(arr,0,size-1);
    ofstream fout2("SortedDesc.txt",ios::out);
    printf("\n\nSorted array descending:\n");
    for(i=0;i<size;i++){
        //printf("%d ",arr[i]);
        fout2<<arr[i];
        fout2<<" ";
    }
    return 0;
}