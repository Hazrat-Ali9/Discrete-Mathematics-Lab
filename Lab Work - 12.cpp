/* 
Write a Program to accept the truth value of variable x and y, and print the truth table of the following
logical operations: 
    a) Conjunction P ^ Q                                f) Exclusive NOR   (P@Q)'
    b) Disjunction P v Q                                g) Negation        P'
    c) Exclusive OR P@Q                                 h) NAND            (P^Q)'
    d) Conditional  P->Q                                i) NOR             (P V Q)'
    e) Bi-conditional P<->Q

 */


#include<iostream>
using namespace std;

void Input(char a[],char b[]){
    for (int i = 0; i < 4; i++)
    {
        cin>>a[i]>>b[i];
    }
}
void Input(char a[]){
    for (int i = 0; i < 2; i++)
    {
        cin>>a[i];
    }
}

void Conjunction(char a[],char b[]){
    cout<<"Conjunction"<<endl;
    for (int i = 0; i < 4; i++)
    {
        if (a[i]=='T'&&b[i]=='T')
        {
            cout<<"T\n";
        }
        else
        {
            cout<<"F\n";
        }
    }
}

void Disjunction(char a[],char b[]){
    cout<<"Disjunction\n";
    for (int i = 0; i < 4; i++)
    {
        if (a[i]=='T'||b[i]=='T')
        {
            cout<<"T\n";
        }
        else
        {
            cout<<"F\n";
        }
    }
}
void ExclusiveOr(char a[],char b[]){
    cout<<"ExclusiveOr\n";
    for (int i = 0; i < 4; i++)
    {
        if (a[i]==b[i])
        {
            cout<<"F\n";
        }
        else
        {
            cout<<"T\n";
        }
    }
}

void Conditional(char a[],char b[]){
    cout<<"Conditional\n";
    for (int i = 0; i < 4; i++)
    {
        if (a[i]=='T'&&b[i]=='F')
        {
            cout<<"F\n";
        }
        else
        {
            cout<<"T\n";
        }
    }
}
void BiConditional(char a[],char b[]){
    cout<<"Bi-conditional\n";
    for (int i = 0; i < 4; i++)
    {
        if (a[i]==b[i])
        {
            cout<<"T\n";
        }
        else
        {
            cout<<"F\n";
        }
    }
}
void Xnor(char a[],char b[]){
    cout<<"Xnor\n";
    for (int i = 0; i < 4; i++)
    {
        if (a[i]==b[i])
        {
            cout<<"T\n";
        }
        else
        {
            cout<<"F\n";
        }
    }
}
void Negation(char a[]){
    cout<<"Negation\n";
    for(int i=0;i<2;i++){
        if (a[i]=='T')
        {
            cout<<"F"<<endl;
        }
        else
        {
            cout<<"T"<<endl;
        }
    }
}

void Nand(char a[],char b[]){
    cout<<"Nand\n";
    for (int i = 0; i < 4; i++)
    {
        if (a[i]=='T'&&b[i]=='T')
        {
            cout<<"F\n";
        }
        else
        {
            cout<<"T\n";
        }
    }
}

void Nor(char a[],char b[]){
    cout<<"Nor\n";
    for (int i = 0; i < 4; i++)
    {
        if (a[i]=='T'||b[i]=='T')
        {
            cout<<"F\n";
        }
        else
        {
            cout<<"T\n";
        }
    }
}

int main(){
    char ch1[4];
    char ch2[4];
    cout <<"\nSelect the interger number from the below list for the logical operation that you want to print.\n\n";
    cout<<"1.Conjunction\n";
    cout<<"2.Disjunction\n";
    cout<<"3.Exclusive OR\n";
    cout<<"4.Conditional\n";
    cout<<"5.Bi-conditional\n";
    cout<<"6.Exclusive NOR\n";
    cout<<"7.Negation\n";
    cout<<"8.NAND\n";
    cout<<"9.NOR\n";
    cout<<"10.Exit\n";
    int choice;
    while (true)
    {
        cout<<"Enter your whole number choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"X Y"<<endl;
            Input(ch1,ch2);
            Conjunction(ch1,ch2);
            break;
        case 2:
            cout<<"X Y"<<endl;
            Input(ch1,ch2);
            Disjunction(ch1,ch2);
            break;
        case 3:
            cout<<"X Y"<<endl;
            Input(ch1,ch2);
            ExclusiveOr(ch1,ch2);
            break;
        case 4:
            cout<<"X Y"<<endl;
            Input(ch1,ch2);
            Conditional(ch1,ch2);
            break;
        case 5:
            cout<<"X Y"<<endl;
            Input(ch1,ch2);
            BiConditional(ch1,ch2);
            break;
        case 6:
            cout<<"X Y"<<endl;
            Input(ch1,ch2);
            ExclusiveOr(ch1,ch2);
            break;
        case 7:
            cout<<"X"<<endl;
            Input(ch1);
            Negation(ch1);
            break;
        case 8:
            cout<<"X Y"<<endl;
            Input(ch1,ch2);
            Nand(ch1,ch2);
            break;
        case 9:
            cout<<"X Y"<<endl;
            Input(ch1,ch2);
            Nor(ch1,ch2);
            break;
        case 10:
            exit(1);
        default:
            cout<<"Invalid Choice!!";
            break;
        }
    }
    return 0;
}
