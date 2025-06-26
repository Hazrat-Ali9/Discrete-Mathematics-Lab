#include <iostream>
#include <iomanip>
//q3
using namespace std;
//create a class RELEATION , use Matrix notation to represent a releation.
// Include functions to check if a relation is reflexive , symmetric ,
// Anti symmetric and Transitive . write a program to use this class.

class Relation{
    private:
    int m;            //  length of Set            {1 2 3}  A x A
    int* setx;        //set of element
    int** arr;        // pointer to ( pointer to int)  to use it for dynamic allocation
public:
    Relation(){
        m=0;

    }
    void input(){
        cout<<"no. of elements in set A to create a releation  = ";
        cin>>m;

    arr = new int*[m];                        //dynamic array of pointers
    for(int i=0;i<m;++i){
        arr[i] = new int[m];                  //allocating each pointer to an array of integers of size m
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            arr[i][j]=0;                       //assigning zero to each element i the matrix
        }
    }



    setx = new int[m];                        //set of elements


    for(int i=0;i<m;++i){
            cout<<"ELEMENT NO. "<<i+1<<" = ";
        cin>>setx[i];
    }

    cout<<"enter the number of reletion = ";
    int no_of_releation =0 ;
    cin>>no_of_releation;


    int a,b;                                // 1 2 , 4 5
    int pp=0;
    while(pp !=no_of_releation){     // {1 2 3}
            ++pp;
            cout<<"Relation no. "<<pp<<"  : ";
    cin>>a>>b;        // 1 5

    bool check1 = false,check2=false;
    for(int i=0;i<m;++i){
        if(a==setx[i] ){   //1
            check1= true;
        }
        if(b==setx[i]){
            check2 = true;
        }

    }

    if(check1 && check2){
    for(int i=0;i<m;++i){
        if(a==setx[i]){
            a=i;
        }
        if(b==setx[i]){
            b=i;
        }
    }

    }else{
        cout<<"Invalid input ,not in domain"<<endl;
        exit(0);
    }

    arr[a][b]=1;
    }

    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    }
    bool isReflexive(){
        for(int i=0;i<m;++i){
            if(arr[i][i]!=1){
                return false;
            }
        }
        return true;
    }
    bool isSymmetric(){
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                if(arr[i][j]==1){
                    if(arr[j][i]==1){
                        continue;
                    }else{
                    return false;}
                }
            }
        }
        return true;

    }
      bool isAntiSymmetric(){
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
            if(i !=j){
                if(arr[i][j]==1){
                    if(arr[j][i]==0){
                        continue;
                    }else{
                    return false;}
                }
                    }
            }
        }
        return true;

    }


    bool isTransitive(){

        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
           if(arr[i][j]==1){
            for(int c=0;c<m;++c){
                if(arr[j][c]==1){
                    if(arr[i][c]!=1){
                        return false;
                    }
                }
            }
           }
            }
        }
        return true;

    }
};

int main()
{

    Relation A; //creating object
    A.input(); //calling member method
    cout<<boolalpha;


    int ch;
    bool xx = false;
    while(xx != true){
    cout<<"-----------------MENU-----------------\n";
    cout<<"1.]Reflexive"<<endl;
    cout<<"2.]Transitve"<<endl;
    cout<<"3.]Antisymmetric"<<endl;
    cout<<"4.]Symmetric"<<endl;
    cout<<"5.]close THE MENU "<<endl;
    cout<<"\n select an option :";

    cin>>ch;
    switch(ch){
    case 1:if(A.isReflexive())
           cout<<"Reflexive\n";
           else
            cout<<"Not Reflexive\n";
            break;
    case 2:if(A.isTransitive())
           cout<<"Transitive\n";
           else
            cout<<"Not Transitive\n";
            break;
    case 3:if(A.isAntiSymmetric())
           cout<<"AntiSymmetric\n";
           else
            cout<<"Not AntiSymmetric\n";
            break;
    case 4:if(A.isSymmetric())
           cout<<"Symmetric\n";
           else
            cout<<"Not Transitive\n";
            break;
    case 5:xx= true;
           break;
    default:cout<<"INVALID INPUT!\n";
            break;

    }
    }
    return 0;
}
