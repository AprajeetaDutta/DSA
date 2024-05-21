//Heap Sort
#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<time.h>
using namespace std;

void swap(int* a, int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]<arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]<arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n){
    int i;
    for(i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    for(i=n-1;i>=0;i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}
int main(){
    ifstream fin1("C:/Users/KIIT/Desktop/Semester 5th/DAA(Lab)/Files/Random.txt",ios::in);
    int x, i=0;
    while(fin1>>x){
        i++;
    }
    fin1.close();
    int size=i;
    cout<<"Array size= "<<size<<endl;
    int arr[size];
    ifstream fin2("C:/Users/KIIT/Desktop/Semester 5th/DAA(Lab)/Files/Random.txt",ios::in);
    int y;
    i=0;
    while(fin2>>y){
        arr[i]=y;
        i++;
    }
    fin2.close();
    heap_sort(arr,size);
    cout<<"Sorted array:"<<endl;
    print(arr,size);
    return 0;
}