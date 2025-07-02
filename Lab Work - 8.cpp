/*
Write a program to implement Bubble Sort. Find the nnumber of comparisons during each
pass and diaplay the intermediate result. Use the observed values to plot a graph to analyse the complexity 
of algorithm.
*/

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////
int small(int arr[],int ar_size){

    int small = arr[0];

    for(int i=1;i<ar_size;++i){
        if(arr[i]<small){
            small=arr[i];
        }
    }
    return small;
}
//////////////////////////////////////////////////////////////////////

int main()
{
	int ar_size;
    cout<<"enter the size of array ";
    cin>>ar_size;
     int arr[ar_size];
     for(int i =0;i<ar_size;++i){
     	cout<<"enter "<<i+1<< " : ";
     	cin>>arr[i];
	 }
	
    int temp;

   int x=small(arr,ar_size); //for reducing no. of passes


  bool done=false;
    for(int i=0;i<ar_size;++i){  //passes
            for(int j=0;j<ar_size-1;++j){
                for(int k=0;k<ar_size; ++k){

        cout<<arr[k]<<" , ";}
        cout<<endl;

                if(arr[j]> arr[j+1]){
                     temp= arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }

            }
            if(x==arr[0]){      //for reducing no. of passes
                break;
            }

            cout<<endl<<endl;
    }
    return 0;
}
