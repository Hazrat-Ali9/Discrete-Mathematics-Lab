/*
Graph question in that it should sccept an input n from the user and graphically represent the values of T(n)
 where n varies from 0 to n for the recurrence relations. For e.g. T(n) = T(n-1) + n, T(0) - 1, T(0)- T(n-1)+ n^2

*/


#include<iostream>

using namespace std;

int Recurr1(int n){		//Function to evaluate first recurrence relation

    if(n == 0){
	cout << endl;
	cout << " | T(0) | 1 |" << "\tBase Case" << endl; 	//Base Case
	return 1;
    }
    else{
	
	int a = n + Recurr1(n-1) ; 				//evaluating w.r.t given relation
	cout << " | T(" << n << ") | " << a << " |" << "\t = T(" << n-1 << ") + " << n << endl;

	return a;
    }
}

int Recurr2(int n){		//Function to evaluate Second recurrence relation

    if(n == 0){
	cout << endl;
	cout << " | T(0) | 1 |" << "\tBase Case" << endl; 	//Base Case
	return 1;
    }
    else{

	int a = n*n + Recurr2(n-1) ; 				//evaluating w.r.t given relation
	cout << " | T(" << n << ") | " << a << " |" << "\t = T(" << n-1 << ") + " << n*n << endl;

	return a;
    }
}

int Recurr3(int n){		//Function to evaluate Third recurrence relation

    if(n == 1){
	cout << endl;
	cout << " | T(1) | 1 |" << "\tBase Case" << endl; 	//Base Case
	return 1;
    }
    else{

	int a = n + 2*Recurr3(n/2) ; 				//evaluating w.r.t given relation
	cout << " | T(" << n << ") | " << a << " |" << "\t = 2*T(" << n/2 << ") + " << n << endl;

	return a;
    }
}

int main(){		//main driver function

    int n,c;		//variable declaration
		//start menu

    cout << "\nWhich relation do you want to see?\n1.T(n) = T(n-1) +n\n2.T(n) = T(n-1) + n^2\n3.T(n) = 2*T(n/2) + n";
    cout << "\n4. To show all\nAny other number to quit\nInput: ";
    cin >> c;		//taking inputs
    
    if(!(c==1 || c==2 || c==3 || c==4))
	return 0;

    cout << "Enter Number: ";		//calling given fuction
    cin >> n;
    
    if(c==1 || c==4)
	Recurr1(n);
    if(c==2 || c==4)
	Recurr2(n);
    if(c==3 || c==4)
	Recurr3(n);
}
