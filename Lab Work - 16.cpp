/*
Write a program to repersent Graphs using the Adjacency Matrix and check if it ia a complete graph.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Graph{
    int vertex;
    int **mat;
    public:
        void init(){
            mat=new int*[vertex];
            for (int i = 0; i < vertex; i++)
            {
                mat[i]=new int[vertex];
            }
        }
        Graph(){
            this->vertex=0;
            init();
        }
        void Display(int **m,int s){
            for(int i =0;i<s;i++){
                for(int j=0;j<s;j++){
                    cout<<m[i][j]<<" ";
                }
                cout<<endl;
            }

        }
        void Input(){
            int ver;
            cout<<"How many edges are there in your Graph : ";
            cin>>ver;
            this->vertex=ver;
            init();
            for (int i = 0; i < vertex; i++)
            {
                for (int j = 0; j < vertex; j++)
                {
                    this->mat[i][j]=0;
                }
            }
            int n;
            cout<<"Enter the number of vertices : ";
            cin>>n;
            cout<<"Enter the vertices of the graph : \n";
            for (int i = 0; i < n; i++)
            {
                int v1,v2;
                for(int j=0;j<1;j++){
                    cin>>v1>>v2;
                }
                this->mat[v1-1][v2-1]=1;
            }
            cout<<"Adjacency Matrix : \n"; 
            Display(mat,vertex);
        }
	bool check_CompleteGraph(){
 		bool flag = true;
 		for(int i= 0; i < vertex; i++){
 			for(int j = 0; j < vertex; j++){
 				if(i!= j){
 					if(mat[i][j]!= 1){
 						flag = true;
				 	}
				 	else{
				 		flag = false;
				 	}
			 	}
		 	}
		 	if(flag == true){
		 		break;
		 	}
		 	
			}
			return flag;
	 }
};
int main(){
    Graph *gh = new Graph();
    gh->Input();
    if(gh->check_CompleteGraph()) 
    {
        cout<<"\nisComplete_Graph";
    }
    else{
        cout<<"\nisNotComplete_Graph";
    }
    return 0;
}

// Graph Program 