#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>

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
  void solveLostBlack(RB_Node* rb_node);

  RB_Node* find(const T& value);

  void removeTree(RB_Node* rb_node);  // dfs后序递归

 public:
  struct iterator;
  RedBlackTree() : root_(nullptr), hot_(nullptr), size_(0) {}

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
      node = node->father_;
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
      node = node->father_;
    } else {
      node = node->rightChild_;
      while (node->leftChild_) {
        node = node->leftChild_;
      }
    }
    return node;
  }

  RB_Node* bro() {
    if (father_) {
      if (father_->leftChild_ == this) {
        return father_->rightChild_;
      } else {
        return father_->leftChild_;
      }
    }
    return nullptr;
  }
};

template <typename T>
struct RedBlackTree<T>::iterator {
 public:
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

  iterator(RB_Node* rb_node = nullptr) : _real__node(rb_node) {}
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
         rb_node->father_->RBc_ == RB_COLOR_RED) {  // 排除RR-0
    RB_Node* father_node = rb_node->father_;
    RB_Node* grdfather_node = father_node->father_;
    RB_Node* uncle_node = father_node->bro();
    if (uncle_node && uncle_node->RBc_ == RB_COLOR_RED) {  // RR-2
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

template <typename T>
void RedBlackTree<T>::solveLostBlack(RB_Node* rb_node) {
  while (rb_node != root_) {
    RB_Node* father_node = rb_node->father_;
    RB_Node* bro_node = rb_node->bro();

    if (bro_node->RBc_ == RB_COLOR_RED) {  // LB-1
      father_node->RBc_ = RB_COLOR_RED;
      bro_node->RBc_ = RB_COLOR_BLACK;
      if (root_ == father_node) {
        root_ = bro_node;
      }
      if (father_node->leftChild_ == rb_node) {
        zag(father_node);
      } else {
        zig(father_node);
      }
      father_node = rb_node->father_;
      bro_node = rb_node->bro();
    }

    if (bro_node->leftChild_ &&
        bro_node->leftChild_->RBc_ == RB_COLOR_RED) {  // LB-3
      RB_COLOR old_color = father_node->RBc_;
      father_node->RBc_ = RB_COLOR_BLACK;
      if (father_node->leftChild_ == rb_node) {
        if (root_ == father_node) {
          root_ = bro_node->leftChild_;
        }
        zig(bro_node);
        zag(father_node);
      } else {
        bro_node->leftChild_->RBc_ = RB_COLOR_BLACK;
        if (root_ == father_node) {
          root_ = bro_node;
        }
        zig(father_node);
      }
      father_node->father_->RBc_ = old_color;
      return;
    } else if (bro_node->rightChild_ &&
               bro_node->rightChild_->RBc_ == RB_COLOR_RED) {  // LB-3
      RB_COLOR old_color = father_node->RBc_;
      father_node->RBc_ = RB_COLOR_BLACK;
      if (father_node->leftChild_ == rb_node) {
        bro_node->rightChild_->RBc_ = RB_COLOR_BLACK;
        if (root_ == father_node) {
          root_ = bro_node;
        }
        zag(father_node);
      } else {
        if (root_ == father_node) {
          root_ = bro_node->rightChild_;
        }
        zag(bro_node);
        zig(father_node);
      }
      father_node->father_->RBc_ = old_color;
      return;
    }

    if (father_node->RBc_ == RB_COLOR_RED) {  // LB-2R
      father_node->RBc_ = RB_COLOR_BLACK;
      father_node->RBc_ = RB_COLOR_RED;
      return;
    } else {  // LB-2B
      bro_node->RBc_ = RB_COLOR_RED;
      rb_node = father_node;
    }
  }
}

template <typename T>
bool RedBlackTree<T>::remove(const T& value) {
  RB_Node* rb_node = find(value);
  RB_Node* rb_node_succ;
  if (!rb_node) return false;

  --size_;
  while (rb_node->leftChild_ || rb_node->rightChild_) {
    if (!rb_node->leftChild_) {
      rb_node_succ = rb_node->rightChild_;
    } else if (!rb_node->rightChild_) {
      rb_node_succ = rb_node->leftChild_;
    } else {
      rb_node_succ = rb_node->succ();
    }

    rb_node->value_ = rb_node_succ->value_;
    rb_node = rb_node_succ;
  }

  if (rb_node->RBc_ == RB_COLOR_BLACK) {
    solveLostBlack(rb_node);
  }

  if (rb_node->father_) {
    if (rb_node->father_->leftChild_ == rb_node) {
      rb_node->father_->leftChild_ = nullptr;
    } else {
      rb_node->father_->rightChild_ = nullptr;
    }
  }

  if (rb_node == root_) {
    root_ = nullptr;
  }
  delete rb_node;
  return true;
}

template <typename T>
bool RedBlackTree<T>::remove(iterator& iter) {
  RB_Node* rb_node = iter._real__node;
  iter._real__node = iter._real__node->right_node();
  if (!(iter._real__node)) {
    iter._real__node = iter._real__node->left_node();
  }

  RB_Node* rb_node_succ;
  if (!rb_node) return false;

  --size_;
  while (rb_node->leftChild_ || rb_node->rightChild_) {
    if (!rb_node->leftChild_) {
      rb_node_succ = rb_node->rightChild_;
    } else if (!rb_node->rightChild_) {
      rb_node_succ = rb_node->leftChild_;
    } else {
      rb_node_succ = rb_node->succ();
    }

    rb_node->value_ = rb_node_succ->value_;
    rb_node = rb_node_succ;
  }

  if (rb_node->RBc_ == RB_COLOR_BLACK) {
    solveLostBlack(rb_node);
  }

  if (rb_node->father_) {
    if (rb_node->father_->leftChild_ == rb_node) {
      rb_node->father_->leftChild_ = nullptr;
    } else {
      rb_node->father_->rightChild_ = nullptr;
    }
  }

  if (rb_node == root_) {
    root_ = nullptr;
  }
  delete rb_node;
  return true;
}

int main() {
  using namespace std;

  srand(123456);  // 固定种子，便于复现

  RedBlackTree<int> rbt;
  set<int> oracle;  // 期望集合（不含重复）

  // 1) 随机插入若干元素（包含重复）
  vector<int> inputs;
  for (int i = 0; i < 200; ++i) {
    int v = rand() % 100;  // 0..99，制造重复
    inputs.push_back(v);
  }

  cout << "Inserting elements...\n";
  for (int v : inputs) {
    rbt.insert(v);
    oracle.insert(v);
  }

  // 比对 size()
  if ((int)oracle.size() != rbt.size()) {
    cerr << "[FAIL] size mismatch after insert: oracle=" << oracle.size()
         << " rbt=" << rbt.size() << "\n";
    return 1;
  } else {
    cout << "[OK] size after inserts = " << rbt.size() << "\n";
  }

  // 2) 用迭代器遍历，检查有序性与与 oracle 一致
  vector<int> tree_seq;
  for (auto it = rbt.begin(); it != RedBlackTree<int>::end(); ++it) {
    tree_seq.push_back(*it);
  }
  vector<int> oracle_seq(oracle.begin(), oracle.end());

  if (tree_seq != oracle_seq) {
    cerr << "[FAIL] in-order traversal mismatch after insert.\n";
    cerr << "oracle:";
    for (int x : oracle_seq) cerr << ' ' << x;
    cerr << "\n rbt: ";
    for (int x : tree_seq) cerr << ' ' << x;
    cerr << "\n";
    return 1;
  } else {
    cout << "[OK] in-order traversal matches oracle after insert ("
         << tree_seq.size() << " nodes)\n";
  }

  // 3) 测试 search()
  cout << "Testing search()...\n";
  for (int v = 0; v < 120; ++v) {
    auto it = rbt.search(v);
    bool found_in_oracle = (oracle.find(v) != oracle.end());
    bool found_in_rbt = (it != RedBlackTree<int>::end());
    if (found_in_oracle && !found_in_rbt) {
      cerr << "[FAIL] search(" << v << ") should find but didn't.\n";
      return 1;
    }
    if (!found_in_oracle && found_in_rbt) {
      cerr << "[FAIL] search(" << v << ") found unexpected value " << *it
           << "\n";
      return 1;
    }
    if (found_in_oracle && found_in_rbt && *it != v) {
      cerr << "[FAIL] search(" << v << ") returns " << *it << " but expected "
           << v << "\n";
      return 1;
    }
  }
  cout << "[OK] search() tests passed\n";

  // 4) 测试 lower_bound 和 upper_bound 与 std::set::lower_bound/upper_bound
  // 对比
  cout << "Testing lower_bound() and upper_bound()...\n";
  for (int q = -2; q <= 102; q += 3) {
    auto it_low = rbt.lower_bound(q);
    auto it_up = rbt.upper_bound(q);

    auto s_low_it = oracle.lower_bound(q);
    auto s_up_it = oracle.upper_bound(q);

    bool it_low_end = (it_low == RedBlackTree<int>::end());
    bool it_up_end = (it_up == RedBlackTree<int>::end());
    bool s_low_end = (s_low_it == oracle.end());
    bool s_up_end = (s_up_it == oracle.end());

    if (it_low_end != s_low_end) {
      cerr << "[FAIL] lower_bound(" << q << ") end-ness mismatch\n";
      return 1;
    }
    if (!it_low_end && !s_low_end && *it_low != *s_low_it) {
      cerr << "[FAIL] lower_bound(" << q << ") mismatch: rbt=" << *it_low
           << " oracle=" << *s_low_it << "\n";
      return 1;
    }

    if (it_up_end != s_up_end) {
      cerr << "[FAIL] upper_bound(" << q << ") end-ness mismatch\n";
      return 1;
    }
    if (!it_up_end && !s_up_end && *it_up != *s_up_it) {
      cerr << "[FAIL] upper_bound(" << q << ") mismatch: rbt=" << *it_up
           << " oracle=" << *s_up_it << "\n";
      return 1;
    }
  }
  cout << "[OK] lower_bound/upper_bound tests passed\n";

  // 5) 测试按值删除 remove(value)
  cout << "Testing remove(value)...\n";
  vector<int> to_remove;
  // 从已有的 oracle 中抽取一部分元素删除
  int cnt = 0;
  for (int v : oracle) {
    to_remove.push_back(v);
    if (++cnt >= 12) break;
  }

  for (int v : to_remove) {
    bool removed = rbt.remove(v);
    size_t erased = oracle.erase(v);
    if (removed != (erased == 1)) {
      cerr << "[FAIL] remove(" << v << ") mismatch: removed=" << removed
           << " oracle_erased=" << erased << "\n";
      return 1;
    }
    // 每次删除后比对序列与 size
    vector<int> tree_after;
    for (auto it = rbt.begin(); it != RedBlackTree<int>::end(); ++it)
      tree_after.push_back(*it);
    vector<int> oracle_after(oracle.begin(), oracle.end());
    if (tree_after != oracle_after) {
      cerr << "[FAIL] traversal mismatch after remove(" << v << ")\n";
      return 1;
    }
    if ((int)oracle.size() != rbt.size()) {
      cerr << "[FAIL] size mismatch after remove(" << v
           << "): rbt=" << rbt.size() << " oracle=" << oracle.size() << "\n";
      return 1;
    }
  }
  cout << "[OK] remove(value) tests passed\n";

  // 6) 测试 remove(iterator&)：从 begin 开始逐个删，直到树为空或 oracle 为空
  cout << "Testing remove(iterator&) by repeatedly removing begin()...\n";
  while (!oracle.empty()) {
    auto it = rbt.begin();
    if (it == RedBlackTree<int>::end()) {
      cerr << "[FAIL] begin() == end() but oracle not empty\n";
      return 1;
    }
    int val = *it;
    bool removed = rbt.remove(it);
    size_t erased = oracle.erase(val);
    if (!removed || erased != 1) {
      cerr << "[FAIL] remove(iterator) failed for value " << val << "\n";
      return 1;
    }
    // 再次比对
    vector<int> tree_after;
    for (auto jt = rbt.begin(); jt != RedBlackTree<int>::end(); ++jt)
      tree_after.push_back(*jt);
    vector<int> oracle_after(oracle.begin(), oracle.end());
    if (tree_after != oracle_after) {
      cerr << "[FAIL] traversal mismatch after remove(iterator) (deleted "
           << val << ")\n";
      return 1;
    }
    if ((int)oracle.size() != rbt.size()) {
      cerr << "[FAIL] size mismatch after remove(iterator): rbt=" << rbt.size()
           << " oracle=" << oracle.size() << "\n";
      return 1;
    }
  }

  cout << "[OK] remove(iterator) tests passed; tree should be empty now.\n";

  if (!rbt.empty() || rbt.size() != 0) {
    cerr << "[FAIL] tree not empty at end: size=" << rbt.size() << "\n";
    return 1;
  }

  cout << "All tests PASSED.\n";
  return 0;
}