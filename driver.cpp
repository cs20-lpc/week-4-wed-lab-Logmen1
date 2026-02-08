#include "DoublyList.hpp"

using namespace std;

int main()
{

    DoublyList<int> dlist;
    dlist.append(4);
    dlist.append(30);
    dlist.append(23);

    cout << dlist.getLength() << " ";

    cout << dlist.getElement(1) << " ";

    dlist.insert(1, 19);
    cout << dlist.getElement(1) << " ";

    dlist.remove(1);
    dlist.getLength();

    dlist.replace(2, 54);
    cout << dlist.getElement(2) << " ";

    bool found = dlist.search(54);
    cout << found << " ";

}