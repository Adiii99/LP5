#include<iostream>
#include<stdlib.h>
#include<omp.h>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void swap(int &a, int &b)
{

    int test;
    test=a;
    a=b;
    b=test;

}

int main()
{

    int *a,n;
    cout<<"\n enter total no of elements=>";
    cin>>n;
    a=new int[n];

    srand(time(0));

    for(int i=0;i<n;i++)
    {
   	  a[i] = rand() % 100;
    }

    clock_t start = clock();
    bubbleSort(a,n);
    clock_t end = clock();

    double sequentialTime = double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    #pragma omp parallel
    {
        bubbleSort(a,n);
    }
    end = clock();

    double parallelTime = double(end-start)/CLOCKS_PER_SEC;

    cout<<"sequential bubble sort time:" << sequentialTime << "seconds" << endl;
    cout<<"parallel bubble sort time:" << parallelTime << "seconds" << endl;

    // cout<<"\n sorted array is=>";
    // for(int i=0;i<n;i++)
    // {
   	//  cout<<a[i]<<endl;
    // }


    return 0;
}

