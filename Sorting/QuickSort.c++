/* Quick Sort using
     Text File of random numbers*/
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
        if(arr[j]<pivot){
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
    ifstream fin1("Input.txt",ios::in);
    int x, i=0;
    while(fin1>>x){
        i++;
    }
    fin1.close();
    int size=i;
    printf("\nArray size=%d\n",size);
    int arr[size];
    ifstream fin2("Input.txt",ios::in);
    int y;
    i=0;
    while(fin2>>y){
        arr[i]=y;
        i++;
    }
    fin2.close();
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    int start, end;
    start=clock();
    quick_sort(arr,0,size-1);
    end=clock();
    ofstream fout2("Input2.txt",ios::out);
    printf("\n\nSorted array:\n");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
        fout2<<arr[i];
        fout2<<" ";
    }
    double time;
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime elapsed = %f seconds\n",time);
    return 0;
}