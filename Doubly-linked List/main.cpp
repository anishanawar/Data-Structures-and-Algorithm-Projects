#include <iostream>
#include "IntList.h"
using namespace std;

int main(){
    IntList myList;
    if(myList.empty()){
        cout<<"myList is empty"<<endl;
    }
    else{
        cout<<"myList is not empty"<<endl;
    }
 
    cout<<"Testing push_back..."<<endl;
    cout<<"push_back: 2"<<endl;
    myList.push_back(2);
    cout << "push_back: 4" << endl;
    myList.push_back(4);
    cout << "push_back: 6" << endl;
    myList.push_back(6);
    cout << myList << endl;

    cout<<"Testing push_front..."<<endl;
    cout<<"push_front: 3"<<endl;
    myList.push_front(3);
    cout<<"push_front: 5"<<endl;
    myList.push_front(5);
    cout<<"push_front: 7"<<endl;
    myList.push_front(7);
    
    cout<<myList<<endl;

    cout<<"Testing pop_back..."<<endl;
    myList.pop_back();
    cout << myList << endl;

    cout << "Testing pop_back..." << endl;
    myList.pop_front();
    cout << myList << endl;

    cout<<"Testing printReverse..."<<endl;
    myList.printReverse();
    cout<<endl;

    if (myList.empty()){
        cout << "myList is empty" << endl;
    }
    
    else{
        cout << "myList is not empty" << endl;
    }
}