/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */
#include <iostream> 
#include <stack> 
using namespace std; 

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <typename T>
List<T>::~List() {
  /// @todo Graded in MP3.1
  _destroy();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  if (head_ != NULL) {
    delete head_;
  }
  if (tail_ != NULL) {
    delete tail_;
  }
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode *insert_node = new ListNode(ndata);
  if (head_ != NULL) {
    head_->prev = insert_node;
    insert_node->next = head_;
    head_ = insert_node;
  } else {
    head_ = insert_node;
    tail_ = head_;
  }
  length_ += 1;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode *insert_node = new ListNode(ndata);
  if (head_ != NULL) {
    insert_node->prev = tail_;
    tail_->next = insert_node;
    tail_ = insert_node;
  } else {
    head_ = insert_node;
    tail_ = head_;
  }
  length_ += 1;
}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.1
  ListNode *oldEnd = endPoint;  //store the old end ptr so that we can let head_ point to it
  ListNode *fake_endPoint = endPoint->prev;

  if (endPoint->next != NULL) {
      endPoint->next->prev = startPoint;
  }
  if (startPoint->prev == NULL) {

    startPoint->prev = startPoint->next;
    startPoint->next = endPoint->next;
    
    endPoint->prev = NULL;
    endPoint->next = fake_endPoint;
    endPoint = endPoint->next;

    while (endPoint != startPoint) {
      fake_endPoint = endPoint->prev;
      endPoint->prev = endPoint->next;
      endPoint->next = fake_endPoint;
      endPoint = endPoint->next;
    }
    head_ = oldEnd;
  } else {
    
    startPoint->prev->next = endPoint;
    endPoint->prev = startPoint->prev;

    startPoint->prev = startPoint->next;
    startPoint->next = endPoint->next;


    endPoint->next = fake_endPoint;
    endPoint = endPoint->next;

    while (endPoint != startPoint) {
      fake_endPoint = endPoint->prev;
      endPoint->prev = endPoint->next;
      endPoint->next = fake_endPoint;
      endPoint = endPoint->next;
    }
    
    startPoint = oldEnd;
  }
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.1
  
  stack<ListNode*> s;
  int size_remaining = length_;
  int choose_k = 0;
  if (length_ / n * n == length_) {
    choose_k = length_ / n;
  } else {
    choose_k = length_ / n + 1;
  }

  for (int k = 0; k < choose_k; k++) {
    for (int i = 0; i < std::min(n, size_remaining); i++) {
      s.push(head_);
      if (head_->next != NULL) {
        head_ = head_->next;
      }
    }
    for (int i = 0; i < std::min(n, size_remaining - 1); i++) {
        head_ = head_->prev;
    }
    if (head_ != s.top()) {
      reverse(head_, s.top());
    }

    for (int i = 0; i < std::min(n, size_remaining - 1); i++) {
        head_ = head_->next;
    }

    size_remaining -= n;
  }
  for (int i = 0; i < length_ - 1; i++) {
    head_ = head_->prev;
  }
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
  while (head_ != tail_ && tail_ != NULL) {
    tail_->next = head_->next;
    head_->next = head_->next->next;
    head_ = head_->next;
    tail_->next->next = NULL;
    tail_ = tail_->next;
  }
  while (head_->prev != NULL) {
    head_ = head_->prev;
  }
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <typename T>
List<T> List<T>::split(int splitPoint) {
    if (splitPoint > length_)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode * secondHead = split(head_, splitPoint);

    int oldLength = length_;
    if (secondHead == head_) {
        // current list is going to be empty
        head_ = NULL;
        tail_ = NULL;
        length_ = 0;
    } else {
        // set up current list
        tail_ = head_;
        while (tail_ -> next != NULL) {
            tail_ = tail_->next;
        }
        length_ = splitPoint;
    }
    // set up the returned list
    List<T> ret;
    ret.head_ = secondHead;
    ret.tail_ = secondHead;
    if (ret.tail_ != NULL) {
        while (ret.tail_->next != NULL)
            ret.tail_ = ret.tail_->next;
    }
    ret.length_ = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.2
  for (int i = 0; i < splitPoint; i++) {
    if (start->next != NULL) {
      start = start->next;
    }
  }
  if (splitPoint == 0) {
    return start;
  }
  start->prev->next = NULL;
  if (start != NULL) {
    return start;
  } else {
    return NULL;
  }

}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  ListNode *curr = nullptr;
  ListNode *head = nullptr;
  bool f_s = true;

  if (first == NULL && second == NULL) {
    return NULL;
  }
  if (first != NULL && second == NULL) {
    head = first;
    return head;
  }
  if (first == NULL && second != NULL) {
    head = second;
    return head;
  }
  if (first != NULL && second != NULL) {
    if (first->data < second->data) {
      curr = second;
      head = first;
    } else if (second->data < first->data) {
      f_s = false;
      curr = first;
      head = second;
    } else {
      curr = second;
      head = first;
    }
  }
  while (first->next != NULL && second->next != NULL) {
    if (second->data < first->data && (first->data < second->next->data || first->data == second->next->data)) {
      curr = second->next;
      second->next = first;
      first->prev = second;
      second = curr;
    } else if (first->data < second->data && (second->data < first->next->data || second->data == first->next->data)) {
      curr = first->next;
      first->next = second;
      second->prev = first;
      first = curr;
    } else if (second->data < first->data && second->next->data < first->data) {
      second = second->next;
    } else if (first->data < second->data && first->next->data < second->data) {
      first = first->next;
    } else if (first->data == second->data) {
      if (curr == second) {
        curr = first->next;
        first->next = second;
        second->prev = first;
        first = curr;
      } else if (curr == first) {
        curr = second->next;
        second->next = first;
        first->prev = second;
        second = curr;
      }
    }
  }
  while (first->next == NULL && second->next != NULL) {
    if (second->data < first->data && (first->data < second->next->data || first->data == second->next->data)) {
      curr = second->next;
      second->next = first;
      first->prev = second;
      second = curr;
    } else if (second->data < first->data && second->next->data < first->data) {
      second = second->next;
    } else if (first->data < second->data) {
      first->next = second;
      second->prev = first;
    } else if (first->data == second->data) {
      if (curr == second) {
        first->next = second;
        second->prev = first;
      } else if (curr == first) {
        curr = second->next;
        second->next = first;
        first->prev = second;
        second = curr;
      }
    }
  }
  while (first->next != NULL && second->next == NULL) {
    if (first->data < second->data && (second->data < first->next->data || second->data == first->next->data)) {
      curr = first->next;
      first->next = second;
      second->prev = first;
      first = curr;
    } else if (first->data < second->data && first->next->data < second->data) {
      first = first->next;
    } else if (second->data < first->data) {
      second->next = first;
      first->prev = second;
    } else if (first->data == second->data) {
      if (curr == second) {
        curr = first->next;
        first->next = second;
        second->prev = first;
        first = curr;
      } else if (curr == first) {
        second->next = first;
        first->prev = second;
      }
    }
  }
  if (first->next == NULL && second->next == NULL) {
    if (first->data < second->data) {
      first->next = second;
      second->prev = first;
    } else if (second->data < first->data) {
      second->next = first;
      first->prev = second;
    } else if (first->data == second->data) {
      if (curr == second) {
        first->next = second;
        second->prev = first;
      } else if (curr == first) {
        second->next = first;
        first->prev = second;
      }
    }
  }

  return head;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <typename T>
void List<T>::sort() {
    if (empty())
        return;
    head_ = mergesort(head_, length_);
    tail_ = head_;
    while (tail_->next != NULL)
        tail_ = tail_->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  ListNode *second = nullptr;

  if (chainLength <= 1) {
    return start;
  } else {
    second = split(start, chainLength / 2);
    if (chainLength % 2 == 0) {
      start = merge(mergesort(start, chainLength / 2), mergesort(second, chainLength / 2));
    } else {
      start = merge(mergesort(start, chainLength / 2), mergesort(second, chainLength / 2 + 1));
    }
  }

  return start;
}
