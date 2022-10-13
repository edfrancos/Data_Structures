#ifndef SNODE_H
#define SNODE_H

template <typename keyType>
class SNode{
   private:
      keyType Key;
      SNode* Tail;
   public:
   // Constructors
      SNode(keyType _key){
         Key = _key;
         Tail = nullptr;
      }
   // Key Methods
      void setKey(keyType _key){ Key = _key;};
      keyType getKey(){return Key;};
   // Tail Methods
      void setTail(SNode* _tail){ Tail = _tail;};
      SNode* getTail(){ return Tail;};
};

#endif
