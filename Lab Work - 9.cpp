/*
Write a program to implement Insertion Sort. Find the nnumber of comparisons during each
pass and diaplay the intermediate result. Use the observed values to plot a graph to analysethe complexity 
of algorithm.
*/
#include<iostream>
using namespace std;
int main()
{
    int n, i, arr[50], j, temp;
    cout<<"Enter the Size of array: ";
    cin>>n;
    cout<<"Enter elements ";
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"\n";
    int index,ele;
    for(i=1; i<n; i++)
    {
        int elem = arr[i];
        if(elem<arr[i-1])
        {
            for(j=0; j<=i; j++)
            {
                if(elem<arr[j])
                {
                     index = j;
                    for(int k=i; k>j; k--)
                        arr[k] = arr[k-1];
                    break;
                }
            }
        }
        else
            continue;
        arr[index] = elem;}
    
    cout<<"\nArray Sorted Successfully!\n";
    
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
