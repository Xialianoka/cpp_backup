#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &l) {
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;
}

int main()
{

    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_back(50);

    printList(l1);

    //赋值
    list<int> l2;
    l2.assign(l1.begin(), l1.end());
    printList(l2);

    list<int> l3;
    l3.assign(10,100);
    printList(l3);

    list<int> l4;
    l4 = l1;
    printList(l4);

    //交换
    l4.swap(l3);
    printList(l3);
    printList(l4);

    return 0;
    
}