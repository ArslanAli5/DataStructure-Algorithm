
#include <iostream>

using namespace std;



int main()
{
    string name;
    cout<<"Enter Your Name: ";
    cin>>name;
    for ( int i = name.size() ; i>=0 ; i--)
    {
        cout<<name[i]<<" ";
    }
    
}
