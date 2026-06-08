// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
  struct Node {                    //узел
    T data;
    Node* next;
  };
  Node* head;

 public:
  TPQueue() : head(nullptr) {}     //конструктор
  ~TPQueue() {                     //деструктор
    while (!isEmpty()) {
      pop();
    }
  }
  bool isEmpty() const {
    return head == nullptr;
  }
  void push(const T& item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;
    if (isEmpty()) {                          //если очередь пустая
      head = newNode;
      return;
    }
    if (item.prior > head->data.prior) { //приор элемента выше приор головы
      newNode->next = head;
      head = newNode;
      return;
    }
    Node* current = head; //приор элемента не выше приор головы
    while (current->next != nullptr &&
           current->next->data.prior >= item.prior) {
      current = current->next;
    }
    newNode->next = current->next;            // вставка элемента
    current->next = newNode;
  }

  T pop() {
    if (isEmpty()) {
      throw std::string("Queue is empty");
    }
    Node* temp = head;
    T result = head->data;
    head = head->next;
    delete temp;
    return result;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
