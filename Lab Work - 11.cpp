/* 
Write a program to calculate Permuatation and Combination for an input value n and r using recursive
formula of n^Cvr and n^Pvr.
*/
#include <iostream>

using namespace std;

int combination(int n,int r){
    if(n==r || r==0) {
        return 1;
    }
    return combination(n-1,r-1)+combination(n-1,r);
}
int permutation(int n, int r){

    if(n==r || r==0){
        return 1;
    }

    return n*permutation(n-1,r-1);


}
int main()
{
    bool flag = true;
    while(flag){
    cout<<"\nClick 1 for -> COMBINATION"<<endl;
    cout<<"Click 2 for -> PERMUTATION"<<endl;
    cout<<"Click 3 to end the program"<<endl;
    cout<<"\nENTER THE CHOICE: ";

    int sel=0;
    cin>>sel;
    if(sel!=3){
    cout<<" n : ";
    int a=0,b=0;
    cin>>a;
    cout<<" r : ";
    cin>>b;


    if(a>0 && b>=0 && a>b){

   cout<<"RESULT : ";
    switch(sel){

    case 1:
            cout<<combination(a,b)<<endl<<endl;
            break;
    case 2 :
            cout<<permutation(a,b)<<endl<<endl;
            break;

    default:cout<<"INVALID INPUT"<<endl;
    }
    }
    else{
    cout<<"NOT COMATIABLE HERE"<<endl;}
    }else{
    flag=false;}
    }
    return 0;
}
