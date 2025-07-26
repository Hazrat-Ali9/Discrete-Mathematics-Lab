/*
Write a program to accept a direct graph G and complete the in-degree and out degree of 
each vertex.
*/

//Q17---directed graph ,, logic --> out degree is sum of elements in column
                             //---> in degree is sum of elements in row

#include <iostream>
#include <iomanip>

using namespace std;

int main()

{
    cout<<"ENTER THE NO. OF VERTICES ";
    int size_of_matrix= 0;
    cin>>size_of_matrix;

    char** matrix ;

    matrix = new char*[size_of_matrix];

    for(int i=0 ;i<size_of_matrix ;++i){
        matrix[i] = new char[size_of_matrix];
    }
     for(int i=0;i<size_of_matrix;++i){
        for(int j=0;j<size_of_matrix;++j){
            matrix[i][j] ='0';
        }
    }
    cout<<"no. of directed pairs you want to enter : ";
    int edges =0;
    cin>>edges;
    char x,y;
    for(int i=0;i<edges;++i){
       cout<<"pair : ";
       cin>>x;
       cin>>y;

       int row =((int)x - 97);
       int column = ((int)y -97);


       matrix[row][column]='1';


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

    int sum=0;

    for(int i=0;i<size_of_matrix;++i){  //49
            sum=0;
        for(int j=0;j<size_of_matrix;++j){
            sum +=((int)matrix[i][j] - 48);
        }
        cout<<"out degree of vertex : "<<(char)(i+97)<<" is "<<sum<<endl;

    }
    cout<<"-------------------------------------------------------------------------"<<endl;
     for(int i=0;i<size_of_matrix;++i){  //49
            sum=0;
        for(int j=0;j<size_of_matrix;++j){
            sum +=((int)matrix[j][i] - 48);  //sum of elements in a row
        }
        cout<<"in degree of vertex : "<<(char)(i+97)<<" is "<<sum<<endl;

    }
    return 0;
}

