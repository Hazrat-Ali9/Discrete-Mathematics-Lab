/*

Write a Program to create a SET A and determine the cardinality of SET for an input array of element 
(repetition allowed) and perform the following opertion on the SET:
	a) ismember (a, A): check whether an element belongs to set or not and return value as true/false.
	b) powerset(A): list all the element of power set of A.

*/

#include <iostream>
using namespace std;

class set{
	private:
		int n;
		int *s;
	public:
		void input(int a){
			n=a;
			s = new int[n];
			cout<<"\nEnter Elements for the set :\n";
			for(int i=0;i<n;i++){
				cin>>s[i];
			}
		}
		void disp(void){
			cout<<"\nThe set is : \n";
			cout<<s[0];
			for(int i=1;i<n;i++){
				cout<<","<<s[i];
			}
			cout<<"\nSize of the set is : "<<n<<endl;	
		}
		void add(int x){
			int  a=n;
			n+=x;
			cout<<"\nEnter next elements for the set :\n";
			for(int i=a;i<n;i++){
				cin>>s[i];
			}
		}
		void unique(void){
			int k=1;
			for(int i=1;i<n;i++){
				int x=s[i];
				for(int j=i-1;j>=0;j--){
					if(x!=s[j]){
						if(j==0){
							s[k]=x;
							k++;
						}
					}
					else{
						break;
					}
				}
			}
			n=k;
		}
		bool ismember(int x){
			for(int i=0;i<n;i++){
				if(x==s[i]){
					return true;
				}
			}
			return false;
		}
		void powerset(void){
			int x=1;
			for(int i=1;i<=n;i++){
				x*=2;
			}
			cout<<"{ ";
			for(int i=0;i<x;i++){
				cout<<"{";
				for(int j=0;j<n;j++){
					if(i&(1<<j)){
						cout<<s[j]<<",";
					}
				}
				cout<<"},";
			}
			cout<<"}\n\n";
		}
};

int main(){
	int n;
	cout<<"\nEnter the size of the Set : ";
	cin>>n;
	set a;
	a.input(n);
	a.disp();
	
	
	a.unique();
	a.disp();
	
	
	cout<<"\nPower-set : \n";
	a.powerset();
	
	
	int x;
	cout<<"\n\nHow many elements want to add : ";
	cin>>x;
	a.add(x);
	a.disp();
	
	int s;
	cout<<"\nEnter which number want to search in the set : ";
	cin>>s;
	bool y=a.ismember(s);
	if(y==1){
		cout<<"\n"<<s<<" is present in the set.\n";
	}
	else{
		cout<<"\n"<<s<<" is not present in the set.";
	}
	
	return 0;
}