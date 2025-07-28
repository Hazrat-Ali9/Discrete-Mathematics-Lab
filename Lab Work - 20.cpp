/* 
Given an adjaceny matrix of a graph, write a program to check whether a given set of vertices{v1,v2,v3,...,vk}
 from an Euler Path / Euler Circuit (for circuit assume Vk = Vi).

*/
#include <iostream>
#include <iomanip>

using namespace std;


//q19 -->logic -->euler path if 2 vertices have odd degree
//               >euler circuit --> there is no odd degree
int main()
{
    cout<<"ENTER THE NO. OF VERTICES ";  //IS EQUAL TO MATRIX SIZE
    int size_of_matrix= 0;
    cin>>size_of_matrix;

    char** matrix ;                   //will use char to take vertecies

    matrix = new char*[size_of_matrix];

    for(int i=0 ;i<size_of_matrix ;++i){
        matrix[i] = new char[size_of_matrix];
    }
     for(int i=0;i<size_of_matrix;++i){
        for(int j=0;j<size_of_matrix;++j){
            matrix[i][j] ='0';
        }
    }
    cout<<"no. of pairs you want to enter : ";
    int edges =0;
    cin>>edges;
    char x,y;
    for(int i=0;i<edges;++i){
       cout<<"pair : ";
       cin>>x;
       cin>>y;

       int row =((int)x - 97);    // a is the input than row will be 0
       int column = ((int)y -97);

       matrix[row][column]='1';
       matrix[column][row]='1';

    }
    cout<<"   ";
    for(int i=0;i<size_of_matrix;++i){
        cout<< (char)(i+97)<<"  ";
    }
    cout<<endl;

    for(int i=0;i<size_of_matrix;++i){
            cout<< (char)(i+97)<<"  ";
        for(int j=0;j<size_of_matrix;++j){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }

    //EULER PATH
    int degrees[size_of_matrix];

    int sum=0;

    for(int i=0;i<size_of_matrix;++i){
            sum =0;
        for(int j=0;j<size_of_matrix;++j){
            sum += ((int)matrix[i][j])-48;
        }
       degrees[i]=sum;
    }

    int oddcounter =0;
    int evencounter=0;
    for(int i=0;i<size_of_matrix;++i){
        if(degrees[i] % 2 != 0){
            oddcounter +=1;
        }else{
     evencounter++;
        }
    }
    if(oddcounter ==2){
        cout<<"THE GRAPH IS : EULER'S PATH "<<endl;
    }else if(evencounter==size_of_matrix){
          cout<<"THE GRAPH IS : EULER'S CIRCUIT  and euler path"<<endl;
    }else{
        cout<<"THE GRAPH IS  NOT  EULER'S PATH "<<endl;
    }

    return 0;
}
