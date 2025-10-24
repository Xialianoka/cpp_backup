#include <cstdio>

#define bro(x) ((x->father->lc == x) ? (x->father->rc) : (x->father->lc))

using RB_COLOR = bool;
#define RB_COLOR_RED true
#define RB_COLOR_BLACK false

template <typename T>
class RedBlackTree {
 private:
  struct RB_Node;
  RB_Node* root_;
  RB_Node* hot_;

  int size_;

  void init(const T& value);

  RB_Node* zig(RB_Node* rb_node);  // 右旋
  RB_Node* zag(RB_Node* rb_node);  // 左旋

  void solveDoubleRed(RB_Node* rb_node);
  void solveDoubleBlack(RB_Node* rb_node);

  RB_Node* find(const T& value);

  void removeTree(RB_Node* rb_node);  // dfs后序递归

 public:
  struct iterator;
  RedBlackTree();

  iterator insert(const T& value);

  bool remove(const T& value);
  bool remove(iterator& iter);

  iterator search(const T& value);
  iterator lower_bound(const T& value);
  iterator upper_bound(const T& value);

  int size();

  bool empty();

  void clear();

  iterator begin();

  static iterator end();
};

template <typename T>
struct RedBlackTree<T>::RB_Node {
  T value_;
  RB_COLOR RBc_;
  RB_Node* leftChild_;
  RB_Node* rightChild_;
  RB_Node* father_;

  RB_Node(const T& value = T(), RB_COLOR RBc = RB_COLOR_RED,
          RB_Node* leftChild = nullptr, RB_Node* rightChild = nullptr,
          RB_Node* father = nullptr)
      : value_(value),
        RBc_(RBc),
        leftChild_(leftChild),
        rightChild_(rightChild),
        father_(father) {}

  RB_Node* succ() {
    RB_Node* node = rightChild_;
    if (!node) return nullptr;
    while (node->leftChild_) {
      node = node->leftChild_;
    }
    return node;
  }

  RB_Node* left_node() {
    RB_Node* node = this;
    if (!this->leftChild_) {
      while (node->father_ && node->father_->leftChild_ == node) {
        node = node->father_;
      }
      node = node->father;
    } else {
      node = node->leftChild_;
      while (node->leftChild_) {
        node = node->leftChild_;
      }
    }
    return node;
  }

  RB_Node* right_node() {
    RB_Node* node = this;
    if (!this->rightChild_) {
      while (node->father_ && node->father_->rightChild_ == node) {
        node = node->father_;
      }
      node = node->father;
    } else {
      node = node->rightChild_;
      while (node->leftChild_) {
        node = node->leftChild_;
      }
    }
    return node;
  }
};

template <typename T>
struct RedBlackTree<T>::iterator {
 private:
  RB_Node* _real__node;

 public:
  T& operator*() { return _real__node->value_; }

  bool operator==(const iterator& other) {
    return _real__node == other._real__node;
  }

  bool operator!=(const iterator& other) {
    return _real__node != other._real__node;
  }

  iterator& operator=(iterator& other) {
    _real__node = other._real__node;
    return *this;
  }

  iterator& operator++() {
    _real__node = _real__node->right_node();
    return *this;
  }

  iterator& operator--() {
    _real__node = _real__node->left_node();
    return *this;
  }

  iterator(const RB_Node* rb_node = nullptr) : _real__node(rb_node) {}
  iterator(const T& value) : _real__node(find(value)) {}
  iterator(const iterator& other) : _real__node(other._real__node) {}
};

template <typename T>
void RedBlackTree<T>::init(const T& value) {
  root_ = new RB_Node(T(), RB_COLOR_BLACK, nullptr, nullptr, nullptr);
  size_ = 1;
}

template <typename T>
typename RedBlackTree<T>::RB_Node* RedBlackTree<T>::find(const T& value) {
  RB_Node* node = root_;
  hot_ = nullptr;
  while (node && node->value_ != value) {
    hot_ = node;
    if (node->value_ > value) {
      node = node->leftChild_;
    } else {
      node = node->rightChild_;
    }
  }
  return node;
}

template <typename T>
typename RedBlackTree<T>::iterator RedBlackTree<T>::search(const T& value) {
  return iterator(find(value));
}

template <typename T>
typename RedBlackTree<T>::iterator RedBlackTree<T>::lower_bound(
    const T& value) {
  RB_Node* node = root_;
  hot_ = nullptr;
  while (node) {
    hot_ = node;
    if (node->value_ >= value) {
      node = node->leftChild_;
    } else {
      node = node->rightChild_;
    }
  }

  if (hot_->value_ == value) {
    node = hot_;
  } else {
    node = hot_->right_node();
  }
  return iterator(node);
}

template <typename T>
typename RedBlackTree<T>::iterator RedBlackTree<T>::upper_bound(
    const T& value) {
  RB_Node* node = root_;
  hot_ = nullptr;
  while (node) {
    hot_ = node;
    if (node->value_ > value) {
      node = node->leftChild_;
    } else {
      node = node->rightChild_;
    }
  }

  if (hot_->value_ > value) {
    node = hot_;
  } else {
    node = hot_->right_node();
  }
  return iterator(node);
}

template <typename T>
typename RedBlackTree<T>::RB_Node* RedBlackTree<T>::zig(
    typename RedBlackTree<T>::RB_Node* rb_node) {
  if (!rb_node || !rb_node->leftChild_) return rb_node;
  rb_node->leftChild_->father_ = rb_node->father_;
  if (rb_node->father_) {
    if (rb_node->father_->leftChild_ == rb_node) {
      rb_node->father_->leftChild_ = rb_node->leftChild_;
    } else {
      rb_node->father_->rightChild_ = rb_node->leftChild_;
    }
  }
  if (rb_node->leftChild_->rightChild_) {
    rb_node->leftChild_->rightChild_->father_ = rb_node;
  }
  rb_node->father_ = rb_node->leftChild_;
  rb_node->leftChild_ = rb_node->leftChild_->rightChild_;
  rb_node->father_->rightChild_ = rb_node;
  return rb_node->father_;
}

template <typename T>
typename RedBlackTree<T>::RB_Node* RedBlackTree<T>::zag(
    typename RedBlackTree<T>::RB_Node* rb_node) {
  if (!rb_node || !rb_node->rightChild_) return rb_node;
  rb_node->rightChild_->father_ = rb_node->father_;
  if (rb_node->father_) {
    if (rb_node->father_->leftChild_ == rb_node) {
      rb_node->father_->leftChild_ = rb_node->rightChild_;
    } else {
      rb_node->father_->rightChild_ = rb_node->rightChild_;
    }
  }
  if (rb_node->rightChild_->leftChild_) {
    rb_node->rightChild_->leftChild_->father_ = rb_node;
  }
  rb_node->father_ = rb_node->rightChild_;
  rb_node->rightChild_ = rb_node->rightChild_->leftChild_;
  rb_node->father_->leftChild_ = rb_node;
  return rb_node->father_;
}

template <typename T>
typename RedBlackTree<T>::iterator RedBlackTree<T>::insert(const T& value) {
  RB_Node* node = find(value);
  if (node) {
    return iterator(node);
  }
  if (!hot_) {
    init(value);
    return iterator(root_);
  }
  ++size_;
  node = new RB_Node(value, RB_COLOR_RED, nullptr, nullptr, hot_);
  if (hot_->value_ > value) {
    hot_->leftChild_ = node;
  } else {
    hot_->rightChild_ = node;
  }
  solveDoubleRed(node);
  return iterator(node);
}

template <typename T>
void RedBlackTree<T>::solveDoubleRed(RB_Node* rb_node) {
  while (rb_node->father_ &&
         rb_node->father_->RBc_ == RB_COLOR_BLACK) {  // 排除RR-0
    RB_Node* father_node = rb_node->father_;
    RB_Node* grdfather_node = father_node->father_;
    RB_Node* uncle_node = bro(father_node);
    if (uncle_node->RBc_ == RB_COLOR_RED) {  // RR-2
      grdfather_node->RBc_ = RB_COLOR_RED;
      father_node->RBc_ = RB_COLOR_BLACK;
      uncle_node->RBc_ = RB_COLOR_BLACK;
    } else {  // RR-1
      if (grdfather_node->leftChild_ == father_node) {
        if (father_node->leftChild_ == rb_node) {
          if (grdfather_node == root_) {
            root_ = father_node;
          }
          zig(grdfather_node);
          grdfather_node->RBc_ = RB_COLOR_RED;
        } else {
          if (grdfather_node == root_) {
            root_ = rb_node;
          }
          zag(father_node);
          zig(grdfather_node);
          rb_node->RBc_ = RB_COLOR_BLACK;
          grdfather_node->RBc_ = RB_COLOR_RED;
        }
      } else {
        if (father_node->leftChild_ == rb_node) {
          if (grdfather_node == root_) {
            root_ = rb_node;
          }
          zig(father_node);
          zag(grdfather_node);
          rb_node->RBc_ = RB_COLOR_BLACK;
          grdfather_node->RBc_ = RB_COLOR_RED;
        } else {
          if (grdfather_node == root_) {
            root_ = father_node;
          }
          zag(grdfather_node);
          father_node->RBc_ = RB_COLOR_BLACK;
          grdfather_node->RBc_ = RB_COLOR_RED;
        }
      }
    }
  }
  if (rb_node == root_) {
    rb_node->RBc_ = RB_COLOR_BLACK;
  }
}

template <typename T>
typename RedBlackTree<T>::iterator RedBlackTree<T>::begin() {
  RB_Node* ptr = root_;
  while (ptr->leftChild_) {
    ptr = ptr->leftChild_;
  }
  return iterator(ptr);
}

template <typename T>
typename RedBlackTree<T>::iterator RedBlackTree<T>::end() {
  return iterator(nullptr);
}

template <typename T>
int RedBlackTree<T>::size() {
  return size_;
}

template <typename T>
bool RedBlackTree<T>::empty() {
  return !size_;
}

template <typename T>
void RedBlackTree<T>::clear() {
  removeTree(root_);
  size_ = 0;
  root_ = nullptr;
}

template <typename T>
void RedBlackTree<T>::removeTree(RB_Node* rb_node) {
  if (!rb_node) {
    return;
  }

  if (rb_node->leftChild_) removeTree(rb_node->leftChild_);
  if (rb_node->rightChild_) removeTree(rb_node->rightChild_);
  delete rb_node;
}

int main() { return 0; }