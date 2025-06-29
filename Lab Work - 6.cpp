/*
Write a Program to implement Tower of Hanoi using recursion.
*/
#include<iostream>
using namespace std;
 
 
static int k=0;
void towerofhanoi(int n,char from,char to, char helper){
	if(n>0){
	towerofhanoi(n-1,from,helper,to);
	k++;
	towerofhanoi(n-1,helper,to,from);
	
	}
}
int main(){
	int n=3;
	towerofhanoi(n,'A','C','B');
	cout<<"Total number of steps : "<<k;
	return 0;
}
