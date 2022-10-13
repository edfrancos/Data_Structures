#include <iostream>
#include "./SNode.h"

#ifndef SLINKED_LIST_H
#define SNODE_H

template <typename keyType>
class SLinked_List{
   private:
      SNode<keyType>* HeadList;
      SNode<keyType>* TailList;
   public:
      // Constructors
      SLinked_List(){
         HeadList = nullptr;
         TailList = nullptr;
      }
      /*  Front Methods  */
      void pushFront(keyType key){
         SNode<keyType>* node = new SNode<keyType>(key);
         node->setTail(HeadList);
         HeadList = node;
         if(TailList == nullptr){
            TailList = node;
         }
      }
      void popFront(){
         if(HeadList == nullptr){
            std::cout<<"ERROR: Empty List"<<std::endl;
            return;
         }
         SNode<keyType>* currentHead = HeadList;
         HeadList = HeadList->getTail();
         delete currentHead; currentHead = nullptr;
         if(HeadList == nullptr){
            TailList = nullptr;
         }
      }
      // Back Methods
      void pushBack(keyType key){
         SNode<keyType>* node = new SNode<keyType>(key);
         if(TailList == nullptr){
            HeadList = node;
            TailList = node;
            return;
         }
         TailList->setTail(node);
         TailList = node;
      }
      void popBack(){
         if( HeadList == nullptr){
            std::cout<<"ERROR: Empty List"<<std::endl;
            return;
         }
         if( HeadList == TailList){
            delete HeadList; HeadList = nullptr; TailList = nullptr;
            return;
         }
         SNode<keyType>* currentNode=HeadList;
         while(currentNode->getTail()->getTail() == nullptr){
            currentNode = currentNode->getTail();
         }
         TailList = currentNode;
         currentNode = currentNode->getTail();
         delete currentNode; currentNode = nullptr;
      }
      // Special Methods
};

#endif