/*

Write a Program to generate the Fibonacci Series using recursion.

*/

#include <iostream>
using namespace std;
int fibonacci(int num); 
int main() 
{
   int n;
   int input=0;
   cout<<endl<<"Enter the number of terms in the Fibonacci Series: ";
   cin>>n;
   cout<<endl<<"Fibonacci Series is: "<<endl;
   while(input < n) 
   {
      cout<<" "<<fibonacci(input);
      input++;
   }
   return 0;
}
int fibonacci(int num) 
{
   if((num == 1)||(num == 0)) 
   {
      return(num);
   }
   else 
   {
      return(fibonacci(num-1) + fibonacci(num-2));
   }
}