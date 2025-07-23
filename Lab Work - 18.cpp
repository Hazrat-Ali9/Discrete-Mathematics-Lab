/* 

Given a graph G. Write a program to find the number of path of length n  between the source and destination
entered by the user.

*/

#include <iostream>

using namespace std;
int main()

//Q18

{
    //given a graph g write a program to find the numbers of paths of length n between
    //the source and destination entered by the user
    
    //logic--->multiply the matrix n times ( where n is path length)

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
    cout<<"no. of pairs you want to enter : ";
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

    int** ab ;
    ab= new int*[size_of_matrix];

     for(int i=0 ;i<size_of_matrix ;++i){
        ab[i] = new int[size_of_matrix];
    }


    for(int i=0;i<size_of_matrix;++i){

        for(int j =0;j<size_of_matrix;++j){
          ab[i][j] = ((int)matrix[i][j])-48;
        }
    }
    int sum=0;


    cout<<"ENTER THE LENGTH OF PATH : ";
    int n=0;
    cin>>n;

 int** temp ;
    temp= new int*[size_of_matrix];

     for(int i=0 ;i<size_of_matrix ;++i){
        temp[i] = new int[size_of_matrix];
    }



    while(n!=1){
    /////////////////////////////////////////////////////////////////////////////////
     for(int i=0;i<size_of_matrix;++i){
            int k=0;
        for(k =0;k<size_of_matrix;++k){
          sum=0;
        for(int j=0;j<size_of_matrix;++j){

            sum +=(((int) matrix[i][j])-48)*(ab[j][k]);
        }
        temp[i][k]= sum;

        }
    }
    n -=1;
    for(int i=0;i<size_of_matrix;++i){
        for(int j =0;j<size_of_matrix;++j){
          ab[i][j] = temp[i][j];
        }
    }
    }
////////////////////////////////////////////////////////////////////////////////////////

    cout<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"A^2"<<endl;
     for(int i=0;i<size_of_matrix;++i){

        for(int j=0;j<size_of_matrix;++j){
            cout<<temp[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"ENTER THE DISTINATION : ";
    char aa,bb;
    cin>>aa;
    cin>>bb;

    cout<<"number of paths(not a simple path) between "<<aa<<" and "<<bb<<" is "<<temp[(((int)aa)-97)][(((int)bb)-97)];
    cout<<endl<<endl;

    return 0;
}

