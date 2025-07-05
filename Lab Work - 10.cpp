/*
Write a program that generates all the permutations of a given set of digits without repetition.
*/

#include <iostream>

using namespace std;

// q-10 permutation without repetition

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b=temp;
}

void perm(int arr[] , int n,int b){
	if(b==(n-1)){
		for(int j=0;j<n;++j){
			cout<<arr[j];
		}
		cout<<endl;
	}else{
		for(int i=b;i<n;++i){
			swap(arr[b],arr[i]);
			perm(arr,n,b+1);
			swap(arr[b],arr[i]);
		}
	}
}

int main() {

	int n;
	  
	cout<<"enter the size of array : ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;++i){
		cout<<"enter  "<<i+1<<" element = :";
		cin>>arr[i];
	}

	int b=0;
	
	cout<<"RESULT : "<<endl;
	
    perm(arr,n,b);   
	
	
	
	return 0;
}
