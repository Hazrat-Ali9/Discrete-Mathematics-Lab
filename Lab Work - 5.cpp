/*
Create a class SET and take two sets as input from user to perform following SET Operation:
    a) Subset: Check whether one set is a subset of other or not.
    b) Union and Intersection of two Sets.
    c) Complement: Assume Universial Set as per the input elements from the user.
    d) Set Difference and Symmetric Difference between two SETS. 
    e) Certesian Product of Sets.
*/

#include <iostream>
#include <iomanip>
//q2
using namespace std;

class Set{
    private:
    int* set_a; // declaring pointer to integer , pointing no where
    int size_x;  // a member variable size_x which will be used to store the size of set



    public:
    Set(){}
    void input_elements(){
        cout<<"ENTER THE SIZE OF SET = ";
        cin>>size_x;
        set_a = new int[size_x]; //allocating memory for the SET dynamically, address of memory will be assigned to set_a
        for(int i=0;i<size_x;++i){
                cout<<i+1<<". ELEMENT  = ";
                cin>>set_a[i];                //taking input to the array
        }
        remove_dupilcates();                  //after taking inputs we removed the duplicay
    }

    void remove_dupilcates(){     //this removes the duplicates from set
    for(int i=0;i<size_x;++i){
        for(int j=i+1;j<size_x;){
            if(set_a[i]==set_a[j]){     //if founded the duplicate

                for(int k=j; k+1 <size_x;++k){  //than push t\one element on left side so that nearest duplicate is overwritten
                    set_a[k]=set_a[k+1];
                }

                size_x -=1;  //decraese a size bcoz one duplicate is overwritten
            }else{
            ++j;  //if the element is not eual than increment by 1 to compare with next element
            }
        }
    }


    }

//----------------------------------------------------is subset ?-------------------------------------
   // a) subset : check whether calling set is a subset of passed set
     bool is_subset( Set that){  //A
    
    if(size_x>that.size_x){
        return false;
    }
        
        int count=0;
            for(int i=0;i<that.size_x;++i){
                for(int j=0;j<size_x;++j){
                    if(that.set_a[i]==set_a[j]){  //comparing that a set which have less no. of elements
                        ++count;                 //, does its all elements are equal to first set
                    }
                }
            }
                if(count==size_x){
                    return true;
                }else{
                    return false;
                }
    
        }

    

    
//------------------------------------------------------------------------------------------------------------
    //b) union and intersection of two sets
    void print_union(Set that){

        cout<<"UNION OF 1ST AND 2ND SET = ";
        int nsize =size_x + (that.size_x);
        int *narr;
        narr = new int[size_x + (that.size_x)];    //new array to contain the union will be made on runtime
        bool xx=false;

        for(int i=0;i<nsize;++i){
            if(!xx){
            narr[i]= set_a[i];}else{
                narr[i]= that.set_a[i-size_x];
            }
            if(i == size_x-1){
                xx=true;
            }
        }

        remove_dupilcates(narr,nsize);
        for(int i=0;i<nsize;++i){
            cout<<narr[i]<<" , ";
        }


    }
//-----------------------------------------------------------------------------------------------------------------
 void print_intersection(Set that){
        cout<<"INTERSECTION OF A AND B : ";  // prints the elements which are present in both Sets
            bool x=false;
            for(int i=0;i<that.size_x;++i){      //this loop begins to chose a element from the set

                for(int j=0;j<size_x;++j){    // for each outer loop it runs to select element from the 2nd set
                    if(that.set_a[i]==set_a[j]){     // if any  element from A is found to be equal to B
                            cout<<that.set_a[i]<<"  ";  //than it prints the data
                        x = true;
                    }
                    if(x==true){  //this is just used to save the time , so that it does not necessary runs the loop
                        x=false;
                        continue;
                    }
                }
        }

    }
    //-------------------------------------------------------------------------------------------------------------------------
  //   c) compliment : assume universal set as per the input elements from the user

  void print_compliment(int usize,int* arr){
            bool x = false;

            for(int i=0;i<usize;++i){
                x = false;
                for(int j=0;j<size_x;++j){
                        if(arr[i]==set_a[j]){
                            x = true;
                        }
                }
                 if(x==false){
                            cout<<arr[i]<<"  ";
                        }
            }

}
    //------------------------------------------------------------------------------------------------------------
    //d) set difference and symmetric difference bw two sets
      void print_difference(Set that){


            bool x = false;                   //will be used to exit from the loop when some conditon comes
            for(int i=0;i<size_x;++i){        //takes a element from the array and than runs 2nd loop for every element
                x = false;
                for(int j=0;j<that.size_x;++j){   //takes all element from the Set B for rach element in set A
                        if(set_a[i]==that.set_a[j]){  //if taken data is equal
                            x = true;               //x is set to true only when some element in Set B is equl to SEt A
                        }
                }
                 if(x==false){  // if not found equal in a loop than x remains false thus, if block runs and a element is printed
                            cout<<set_a[i]<<"  "; // which is present in SEt A but not in B
                        }                          //hence we found the difference
            }
    }
    //------------------------------------------------------------------------------------------------------------


    //-------------------------------------------------------------------------------------------------------
    //e) cartesian product of sets
      void print_cartseian_product(Set that){
        cout<<"cartesian product : A X B "<<endl;

        for(int i=0;i<size_x;++i){           //taking x element
            for(int j=0;j<that.size_x;++j){   //takes all y element from 2nd Set for every x ,
                    cout<<set_a[i]<<" , ";
                    cout<<that.set_a[j]<<" ; ";
            }
        }
         }

    ~Set(){}



void remove_dupilcates(int* set_a,int& size_x){     //this removes the duplicates from set
    for(int i=0;i<size_x;++i){
        for(int j=i+1;j<size_x;){
            if(set_a[i]==set_a[j]){     //if founded the duplicate

               // set_a[j]=0;
                for(int k=j; k+1 <size_x;++k){  //than push t\one element on left side so that nearest duplicate is overwritten
                    set_a[k]=set_a[k+1];
                }

                size_x -=1;  //decraese a size bcoz one duplicate is overwritten
            }else{
            ++j;  //if the element is not eual than increment by 1 to compare with next element
            }
        }
    }


}
void output_elements(){ //for output of the elements of the Set(which has no duplicate)

    cout<<"{"  ;
    for(int i=0;i<size_x;++i){
        cout<<set_a[i];
        if(i!=(size_x-1)){
                cout<<" , ";
        }
    }
    cout<< "}";
    }

void output_elements(int* temp,int temp_size){ //for output of the elements of the Set(which has no duplicate)

    cout<<"{"  ;
    for(int i=0;i<size_x;++i){
        cout<<set_a[i];
        if(i!=(size_x-1)){
                cout<<" , ";
        }
    }
    cout<< "}";
    }


};

int main()
{
    cout<<boolalpha;
    Set A;
    A.input_elements();

    Set B;
    B.input_elements();


     bool xyz = true;

     cout<<" SET A : ";
     A.output_elements();
     cout<<endl;
     cout<<" SET B : ";
     B.output_elements();
     cout<<endl;
     while(xyz){
    cout<<"1. is subset  "<<endl;
    cout<<"2. union and intersection "<<endl;
    cout<<"3. Compliment "<<endl;
    cout<<"4. SET DIFFERENCE of A and B,  SYMMETRIC DIFFERENCE of A and B"<<endl;
    cout<<"5. CARTESIAN PRODUCT of of A and B "<<endl;
    cout<<"6. QUIT THE PROGRAM "<<endl<<endl;

    cout<<"SELECT AN OPTION plz "<<endl<<endl;
    int a;
    cin>>a;

    if(a==1){
            cout<<"1.check A is subset of B"<<endl;
            cout<<"2.check B is subset of A"<<endl;
            cout<<"3. both option 1 and option 2 "<<endl;
            int sela=0;
            cin>>sela;

            switch(sela){
        case 1: cout<<B.is_subset(A);
                cout<<endl;
                break;
        case 2: cout<<A.is_subset(B);  //Is B subset of A
                cout<<endl;
                break;
        case 3:cout<<B.is_subset(A);
               cout<<endl;
               cout<<A.is_subset(B);  //Is B subset of A
               cout<<endl;
               break;
            }


    } else if(a==2){

    A.print_union(B);
    A.print_intersection(B);
    }else if(a==3){
         cout<<"ENTER THE SIZE OF UNIVERSAL SET : ";
            int usize=0;
            cin>>usize;
            int arr[usize];
            cout<<"enter the elements of universal set------------"<<endl;
            for(int i=0;i<usize;++i){
                cout<<i+1<<" .element : ";
                cin>>arr[i];
            }
            cout<<"1.complement A"<<endl;
            cout<<"2.complement B"<<endl;
            cout<<"3.both "<<endl;
            int sel=0;
            cout<<"------------------------------------------------------"<<endl;
            cout<<"SELECT : ";
            cin>>sel;

            switch(sel){

                case 1:cout<<"compliment of A"<<endl;
                    A.print_compliment(usize,arr);
                    break;
              case 2:  cout<<"compliment of B"<<endl;
                    B.print_compliment(usize,arr);
                    break;
              case 3 :
                cout<<"compliment of A"<<endl;
                A.print_compliment(usize,arr);
                cout<<endl;
                cout<<"compliment of B"<<endl;
                    B.print_compliment(usize,arr);
                   }
    }
            else if(a==4){

            cout<<"1.A - B "<<endl;
            cout<<"2.B - A "<<endl;
            cout<<"3. both option 1 and option 2 "<<endl;
            int sela=0;
            cin>>sela;

            switch(sela){
        case 1: cout<<" A - B = ";
            A.print_difference(B);
                cout<<endl;
                break;
        case 2:cout<<" B - A = ";
             B.print_difference(A);
                cout<<endl;
                break;
        case 3:
            cout<<" A - B = ";
            A.print_difference(B);
               cout<<endl;
               cout<<" B - A = ";
               B.print_difference(A);
               cout<<endl;
               break;
            }

        cout<<"SYMMETRIC DIFFERENCE : ";
        A.print_difference(B);
        B.print_difference(A);

        }else if(a==5){
            cout<<"Cartesian product-------------------------------"<<endl;
            A.print_cartseian_product(B);
            cout<<"======================================================"<<endl;
            B.print_cartseian_product(A);
        }else if(a==6){
            cout<<"program closing..."<<endl;
            xyz = false;
        }
        else{
        cout<<"Invalid input entered by you"<<endl;
        }
        cout<<endl;
        cout<<"======================================================================"<<endl;
     }
        return 0;
}

