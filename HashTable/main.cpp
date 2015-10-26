#include "mainwindow.h"
#include <QApplication>
#include "teaching_entry.h"
#include <iostream>
#include <linkedlist.h>

using namespace std;

int main(int argc, char *argv[])
{

    LinkedList temp = LinkedList();
    teaching_entry t1 = teaching_entry();
    cout << "made an entry" << endl;
    t1.set_member("John One");
    cout << "added to entry" << endl;
    teaching_entry t2 = teaching_entry();
    cout << "made second entry" << endl;
    t2.set_member("John One");
     cout << "added to entry" << endl;
    teaching_entry t3 = teaching_entry();
    cout << "made 3rd entry" << endl;
    t3.set_member("John One");
     cout << "added to entry" << endl;
    cout << t1.get_member() <<endl;
    cout << t2.get_member() <<endl;
    cout << t3.get_member() <<endl;

    temp.add(t1);
    cout << "added entry to list" << endl;
    temp.add(t2);
    cout << "added entry to list" << endl;
    temp.add(t3);
    cout << "added entry to list" << endl;

    Node<teaching_entry> * n = temp.find("John One");
    cout << "searched list" << endl;
    if(n!=nullptr){
        cout<< n->getValue().get_member() << endl;
    }
    else{
        cout<< "hey!" << endl;
    }


    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    return 0;
}
