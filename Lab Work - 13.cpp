//q 12 . X1 + X2 + X3 + X4  = 5;
//POSSIBLE VALUES OF X1, X2 , X3 , X4

#include <iostream>
using namespace std;
void print(int arr[] ,int n){
	for(int i=0;i<n;++i){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
}

void possibleSolutions(int arr[] , int k,int n, int s){
	if(k==0){
		arr[k]=s;
		print(arr,n);
		return;
	}
	
	for(int i=0;i<=s;++i){
		arr[k]=i;
		possibleSolutions(arr,k-1,n,s-i);
	}
}

int main() {
	int n;
	int c;
	cout<<" enter the n : ";
	cin>>n;
	int arr[n];
	cout<<" enter the c : ";
    cin>>c;
    
    for(int i=0;i<n;++i){
    arr[i] = i;
	}
	
	cout<<"RESULT : ";
	
	possibleSolutions(arr,n-1,n,c);
	return 0;
}