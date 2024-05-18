//Text File of random numbers
#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<time.h>
using namespace std;

int main(){
    ofstream fout("Random.txt",ios::out);
    int size=10;
    int arr[size], i;
    srand(time(0));
    for(i=0;i<size;i++){
        arr[i]=rand();
        fout<<arr[i];
        fout<<" ";
    }
    fout.close();
    ifstream fin("Random.txt",ios::in);
    int x;
    printf("\n");
    /*while(fin>>x){
       printf("%d ",x);
    }*/
    fin.close();
    return 0;
}