/*1. Binary Search using
     Text File of random numbers*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<time.h>
using namespace std;

int binary_search(int arr[], int l, int r, int x){
    if(l<=r){
        int m= l+(r-l)/2;
        if(arr[m]==x){
            return m;
        }
        if(arr[m]<x){
            l=m+1;
        }
        else{
            r=m-1;
        }
        return binary_search(arr,l,r,x);
    }
    return -1;
}
int main(){
    ifstream fin1("Input2.txt",ios::in);
    int x, i=0;
    while(fin1>>x){
        i++;
    }
    fin1.close();
    int size=i;
    printf("\nArray size=%d\n",size);
    int arr[size];
    ifstream fin2("Input2.txt",ios::in);
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
    int element;
    printf("\nEnter a number: ");
    scanf("%d",&element);
    int start, end;
    start=clock();
    int result=binary_search(arr,0,size-1,element);
    if(result==-1){
        printf("\nElement not present");
    }
    else{
        printf("\nElement present at index %d",result);
    }
    end=clock();
    double time;
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime elapsed = %f seconds\n",time);
    return 0;
}
