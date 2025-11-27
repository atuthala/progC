/*
создал github Generate a PAT на 30 дней
создал строчку на телефоне
добавил больше комментариев
  */

#include <iostream>

class Node {
public:
  int data;
  Node *prev, *next;

public:
  Node(double data) {
    this->data = data;
    this->prev = this->next = NULL;
  }
};

class LinkedList {
public:
  Node *head, *tail;

public:
  LinkedList() { this->head = this->tail = NULL; }

  ~LinkedList() {
    while (head != NULL)
      pop_front();
  }

  Node *push_front(int data = 0) {
    Node *ptr = new Node(data);

    ptr->next = head;

    ptr->prev = tail;

    if (head != NULL)
      head->prev = ptr;
    if (tail == NULL)
      tail = ptr;
    head = ptr;

    return ptr;
  }

  Node *push_back(int data = 0) {
    Node *ptr = new Node(data);

    ptr->prev = tail;
    if (tail != NULL)
      tail->next = ptr;
    if (head == NULL)
      head = ptr;
    tail = ptr;

    return ptr;
  }

  void pop_front() {
    if (head == NULL)
      return;

    Node *ptr = head->next;
    if (ptr != NULL)
      ptr->prev = NULL;
    else
      tail = NULL;

    delete head;
    head = ptr;
  }

  void pop_back() {
    if (tail == NULL)
      return;

    Node *ptr = tail->prev;
    if (ptr != NULL)
      ptr->next = NULL;
    else
      head = NULL;

    delete tail;
    tail = ptr;
  }

  Node *getAt(int index) {
    Node *ptr = head;
    int n = 0;

    while (n != index) {
      if (ptr == NULL)
        return ptr;
      ptr = ptr->next;
      n++;
    }

    return ptr;
  }

  Node *operator[](int index) { return getAt(index); }

  Node *insert(int index, double data) {
    Node *right = getAt(index);
    if (right == NULL)
      return push_back(data);

    Node *left = right->prev;
    if (left == NULL)
      return push_front(data);

    Node *ptr = new Node(data);

    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;

    return ptr;
  }

  void erase(int index) {
    Node *ptr = getAt(index);
    if (ptr == NULL)
      return;

    if (ptr->prev == NULL) {
      pop_front();
      return;
    }

    if (ptr->next == NULL) {
      pop_back();
      return;
    }

    Node *left = ptr->prev;
    Node *right = ptr->next;
    left->next = right;
    right->prev = left;

    delete ptr;
  }

  void show_list() const {
    Node *p_beg = head;
    while (p_beg) {
      std::cout << p_beg->data << ' ';
      p_beg = p_beg->next;
    }
    std::cout << std::endl;
  }
};

int main(void) {
  using namespace std;
  int numbers[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};
  // здесь пишите программу

  LinkedList digits;
  int len = std::size(numbers);
  for (int i = 0; i < len; ++i) {
    digits.push_back(numbers[i]);
  }

  digits.show_list();
  //__assertion_tests(digits); // эту строчку не убирать (должна стоять перед
  // return 0)
  return 0;
}
