#include "listMine.hpp"


int main() {
    LinkedList<int> intList;
    intList.append(1);
    intList.append(2);
    intList.append(3);
    intList.display();

    intList.remove(2);
    intList.display();

    intList.remove(4);
    intList.display();

    LinkedList<std::string> strList;
    strList.append("hello");
    strList.append("world");
    strList.display();

    strList.remove("hello");
    strList.display();

    return 0;
}