//Merge Sort using Random array textfile
#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<time.h>
using namespace std;

int count=0;
int merge(int arr[], int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];
    int i,j;
    for(i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[m+j+1];
    }
    i=0;
    j=0;
    int k=l;
    while(i<n1 && j<n2){
        count++;
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int l, int r){
    if(l<r){
        count++;
        int m=l+(r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void print_array(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    ifstream fin1("C:/Users/KIIT/Desktop/Semester 5th/DAA(Lab)/Files/Random.txt",ios::in);
    int x, i=0;
    while(fin1>>x){
        i++;
    }
    fin1.close();
    int size=i;
    printf("\nArray size=%d\n",size);
    int arr[size];
    ifstream fin2("C:/Users/KIIT/Desktop/Semester 5th/DAA(Lab)/Files/Random.txt",ios::in);
    int y;
    i=0;
    while(fin2>>y){
        arr[i]=y;
        i++;
    }
    int start, end;
    start=clock();
    merge_sort(arr,0,size-1);
    printf("\nNumber of comparisons: %d\n",count);
    end=clock();
    double time;
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime elapsed = %f seconds\n",time);
    return 0;
}