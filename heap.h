#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m_;
  PComparator comp_;
  std::vector<T> data_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
  : m_(m), comp_(c)
{
  if(m_ < 2) {
    throw std::invalid_argument("heap must have at least two children");
  }
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data_.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data_.push_back(item);
  size_t index = data_.size() - 1;

  while(index > 0) {
    size_t parent = (index - 1) / m_;
    if(!comp_(data_[index], data_[parent])) {
      break;
    }
    T temp = data_[index];
    data_[index] = data_[parent];
    data_[parent] = temp;
    index = parent;
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");

  }

  data_[0] = data_.back();
  data_.pop_back();

  size_t parent = 0;
  while(parent < data_.size()) {
    size_t best = parent;
    size_t firstChild = parent * m_ + 1;

    for(int i = 0; i < m_; i++) {
      size_t child = firstChild + i;
      if(child < data_.size() && comp_(data_[child], data_[best])) {
        best = child;
      }
    }

    if(best == parent) {
      break;
    }
    T temp = data_[parent];
    data_[parent] = data_[best];
    data_[best] = temp;
    parent = best;
  }
}



#endif

