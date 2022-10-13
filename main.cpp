#include <iostream>
#include "./Headers/SLinked_List.h"
#include "./Headers/SNode.h"

int main(){
   SLinked_List<int> list1 = SLinked_List<int>();
   list1.pushBack(3);
   list1.pushFront(2);
   list1.pushBack(4);
   list1.pushFront(1);
   list1.pushBack(5);
   list1.pushFront(0);
   return 0;
}