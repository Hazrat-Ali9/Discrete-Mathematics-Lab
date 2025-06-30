/* 
Wrie a program to implement binary search using recursion.
*/
#include <iostream>
#include <cmath>

using namespace std;

//7 BINARY SEARCH
int binary_searchx(int arr[], int first,int last,int mid,int element){

int ar_size =last+1;
//int elementx = element;
  for(int i=0;i<ar_size;++i){
        mid= ceil(((double)first+last)/2);
        if(element>arr[mid]){
            first=mid;
            binary_searchx(arr,first,last,mid,element);
        }else if(element<arr[mid]){
            last= mid;
            binary_searchx(arr,first,last,mid,element);
        }else{
            return mid;
        }
    }

}
int main()
{
    //binary search
    int ar_size;
    cout<<"enter the size of array : ";
    cin>>ar_size;
     int arr[ar_size];
     for(int i =0;i<ar_size;++i){
     	cout<<"enter "<<i+1<< " : ";
     	cin>>arr[i];
	 }
	 cout<<"enter the element u want to search : ";
	 int element ;
	 cin>>element;

    int first=0,last=ar_size-1,mid=0;  //indexes

   cout<<"answer is : at index "<< binary_searchx(arr,first,last,mid,element);
   
    return 0;
}
