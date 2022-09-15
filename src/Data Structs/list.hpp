/*
    Created by ChangGyu Choi.
                                */

template<typename T>
struct List {
  struct Node {
    T data;
    Node* next;
    Node* prev;
  };

  Node* head_;
  Node* tail_;
  unsigned int size_ = 0;

  List() {
    head_ = new Node();
    tail_ = new Node();
    head_->next = tail_;
    tail_->prev = head_;
  }

  ~List() {
    delete head_;
    delete tail_;
  }

  inline void _insertInternal(Node* p, Node* q) {
    q->next = p;
    q->prev = p->prev;
    p->prev->next = q;
    p->prev = q;
  }

  void prepend(T data) {
    register Node* p = head_->next;
    register Node* newNode = new Node();
    newNode->data = data;
    _insertInternal(p, newNode);
    ++size_;
  }

  void append(T data) {
    register Node* p = tail_;
    register Node* newNode = new Node();
    newNode->data = data;
    _insertInternal(p, newNode);
    ++size_;
  }

  void insert(unsigned int idx, T data) {
    if (idx >= size_)
      return;

    register Node* p = head_->next;
    for (register int i = 0; i < idx; ++i) {
      p = p->next;
    }

    register Node* newNode = new Node();
    newNode->data = data;
    _insertInternal(p, newNode);
    ++size_;
  }

  void erase(unsigned int idx) {
    if (idx >= size_)
      return;

    register Node* p = head_->next;
    for (register int i = 0; i < idx; ++i) {
      p = p->next;
    }

    p->next->prev = p->prev;
    p->prev->next = p->next;
    --size_;
    delete p;
  }

  Node* find(unsigned int idx) {
    if (idx >= size_)
      return nullptr;

    register Node* p = head_->next;
    for (register int i = 0; i < idx; ++i) {
      p = p->next;
    }

    return p;
  }

  int size() {
    return size_;
  }
};
