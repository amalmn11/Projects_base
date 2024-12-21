#include<list>
#include <iostream>
using namespace std;


int main()
{
    list<int> coll;
    for (int i = 0; i < 10; i++)
        coll.push_back(i);



    list<int>::const_iterator pos;
    for (pos = coll.begin(); pos != coll.end(); pos++)
        cout<<*pos<<" ";

    cout << endl;

    while (!coll.empty())
    {
        cout << coll.front() << " ";
        coll.pop_front();
    }
    cout << coll.front() << " ";
}
