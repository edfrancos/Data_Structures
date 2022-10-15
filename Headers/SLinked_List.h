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

      // Add a new element before the first list element.
      void pushFront(keyType key){
         SNode<keyType>* node = new SNode<keyType>(key);
         node->setTail(HeadList);
         HeadList = node;
         if(TailList == nullptr){
            TailList = node;
         }
      }
      // Remove the first list element.
      void popFront(){
         if(HeadList == nullptr){
            std::cout<<"ERROR: Empty List \n";
            return;
         }
         SNode<keyType>* currentHead = HeadList;
         HeadList = HeadList->getTail();
         delete currentHead; currentHead = nullptr;
         if(HeadList == nullptr){
            TailList = nullptr;
         }
      }
      // Get the key of the first list element.
      keyType topFront(){
         return HeadList->getKey();
      }

   /*  Back Methods  */

      // Add a new element after the last list element.
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
      // Remove the last list element.
      void popBack(){
         if( HeadList == nullptr){
            std::cout<<"ERROR: Empty List \n";
            return;
         }
         if( HeadList == TailList){
            delete HeadList; HeadList = nullptr; TailList = nullptr;
            return;
         }
         SNode<keyType>* currentNode= HeadList;
         while(currentNode->getTail()->getTail() != nullptr){
            currentNode = currentNode->getTail();
         }
         TailList = currentNode;
         TailList->setTail(nullptr);
         currentNode = currentNode->getTail();
         delete currentNode; currentNode = nullptr;
      }
      // Get the key of the last list element.
      keyType topBack(){
         return TailList->getKey();
      }

   
   /*  Special Methods  */

      // Search a key in the list
      bool find(keyType key){
         SNode<keyType>* currentNode = HeadList;
         while(currentNode->getKey() != key){
            currentNode = currentNode->getTail();
            if( currentNode == TailList && currentNode->getKey() != key){
               return false;
            }
         }
         return true;
      }
      // Remove the element that has a specific key
      void erase(keyType key){
         SNode<keyType>* currentNode = HeadList;
         if(HeadList->getKey() == key){
            popFront(); return;
         }
         while(currentNode->getTail()->getKey() != key){
            currentNode = currentNode->getTail();
            if(currentNode == TailList){
               std::cout<<"ERROR: Not found Element \n";
               return;
            };
         }
         SNode<keyType>* deleteNode = currentNode->getTail();
         currentNode->setTail(deleteNode->getTail());
         if(TailList == deleteNode){
            TailList = currentNode;
         }
         delete deleteNode; deleteNode = nullptr;
      }
      // Is the list empty?
      bool empty(){
         if(HeadList == TailList && HeadList==nullptr){
            return true;
         }
         return false;
      }
};

#endif