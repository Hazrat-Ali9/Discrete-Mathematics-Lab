/*

Create a class RELATION, use Matrix notation to represent a relation. Include function to check if a relation 
is 
    a) Equivalent, or
    b) Partial Order relation, or
    c) None
    
(Use the function defined in Ques3. to )
*/

#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

class Relation{
    public:
        int rows;
        int columns;
        bool**matrix;

        void init(){
            matrix=new bool*[rows];            //allocating a memory block of size rows
            for (int i = 0; i < rows; i++)
            {
                matrix[i]=new bool[columns];   //Initializing a 2Darray with each row an Array of size columns
            }

        }
        Relation(){
            int size;
            cout<<"Enter the size of set : ";
            cin>>size;
            vector<int> v;
            cout<<"Enter the elements of the set :  ";
            for (int i = 0; i < size; i++)
            {
                int a;
                cin>>a;
                v.push_back(a);
            }
            Remove_Duplicate(v);
            int v_size=v.size();
            rows=v_size;
            columns=v_size;
            init();      //intialising rows and columns of set
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    matrix[i][j]=0;
                }
            }
            int r;
            cout<<"How many relations you want to enter  :";
            cin>>r;
            cout<<"Enter the relations : \n";
            for (int i = 0; i < r; i++)
            {
                int r1,r2;
                for (int j = 0; j < 1; j++)
                {
                    cin>>r1>>r2;
                 
                }
                 if(!(count(v.begin(),v.end() ,r1)&& count(v.begin(),v.end(),r2))){
                        cout<<"Invalid Relation!!";
                        exit(1);
                   }
                int id1,id2;
                id1=Index(v,r1);
                id2=Index(v,r2);
                matrix[id1][id2]=1;
            }
        }
        /*
        Transitive Relation matrix representation
        0 1 0
        0 0 1
        0 0 0
        */
        
        void Display_arr(){
            cout<<"Matrix repersentation :\n"<< endl;
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    cout<<matrix[i][j];
                }
                cout<<endl;
            }
        }
        void Remove_Duplicate(vector<int>& v1){
            sort(v1.begin(),v1.end());
            vector<int> temp_arr;
            for (int i = 0; i < v1.size(); i++)
            {
                if (v1[i]!=v1[i+1])
                {
                    temp_arr.push_back(v1[i]);
                }
            }
            v1.clear();
            for (int i = 0; i < temp_arr.size(); i++)
            {
                v1.push_back(temp_arr[i]);
            }
        }
        int Index(vector<int> v1,int ele){
            vector<int>:: iterator it=find(v1.begin(),v1.end(),ele);
            if (it!=v1.end())
            {
                int pos = it-v1.begin();
                return (pos);
            }
            return -1;
        }

        //Reflexive
        bool isReflexive(){
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (!(matrix[i][i]))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        //Symmetric
        bool isSymmetric(){
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if ((matrix[i][j])&&!(matrix[j][i]))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        //AntiSymmetric
        bool isAntisymmetric(){
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if ((matrix[i][j]&&matrix[j][i])&&(i!=j))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        //Transitive
        bool isTransitive(){
            // // Relation rel = *this; //current Object instantiation
            // // Relation sq = rel*rel;
            // return (((*this)*(*this))<=(*this));
            // // return (sq <= rel);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if(matrix[i][j]){
                        for(int k=0;k<rows;k++){
                            if (matrix[j][k]&& !matrix[i][k])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }
};

int main(){
    Relation rel_obj;
    rel_obj.Display_arr();
   
    cout<<"\nConclusion: \n";
    if (rel_obj.isReflexive()&&rel_obj.isSymmetric()&&rel_obj.isTransitive())
    {
        cout<<"isEquivalence\n";
    }
    else if (rel_obj.isReflexive()&&rel_obj.isAntisymmetric()&&rel_obj.isTransitive())
    {
        cout<<"isPartialOrderRelation\n";
    }
    else
    {
        cout<<"None\n";
    }
    return 0;
}

/*
Equivalency Relation
1 0 0 0
0 1 0 0
0 0 1 1
0 0 1 1
*/


/*
Partial order Relation
1 1 1 1 1
0 1 1 1 1
0 0 1 1 1
0 0 0 1 1
0 0 0 0 1
*/
