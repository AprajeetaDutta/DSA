//Insertion using Random array textfile 
#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<time.h>
using namespace std;

void insertion_sort(int arr[], int n){
    int count=0, temp;
    for(int i=0;i<n;i++){
        count++;
        for(int j=i;j<n;j++){
            if(arr[i]>arr[j]){
                count++;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nNumber of comparisons: %d\n",count);
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
    fin2.close();
    int start, end;
    start=clock();
    insertion_sort(arr,size);
    end=clock();
    double time;
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime elapsed = %f seconds\n",time);
    return 0;
}