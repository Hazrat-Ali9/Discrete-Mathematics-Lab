/*

Write a function to store a function (polynomial/expression), and then evaluate the ploynomial.
(For example store f(x) = 4n^3 + 2n + 9 in an array and for a given value of n, say n=5, evaluate. (i.e. 
 compare the value of f(5)).

*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "enter the order of the polynomial : " << endl;
    int p =0;
    cin>>p;
    p +=1;

    int* arr = new int[p];

    for(int i=0;i<p;++i){
        cout<<"coefficient of term , with  power of x "<<i<<" : ";
        cin>>arr[i];
    }
    cout<<endl;
    for(int i =0;i<p;++i)
    {
        cout<<arr[i]<<"  , ";
    }

    cout<<"enter the value of x , to find f(x) : ";
    int n=0,sum=0;
    cin>>n;

    for(int i =0 ;i<p;++i){
        //term 1
        sum += arr[i]*pow(n,i);

    }
    cout<<" f(x) : "<<sum<<endl;


    return 0;
}
