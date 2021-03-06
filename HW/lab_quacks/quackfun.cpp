/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T sum(stack<T>& s)
{
    
    // Your code here
    if (s.size() == 0) {
      return 0;
    }
    
    T top = s.top();
    T result = 0;
    s.pop();
    result = top + sum(s);
    s.push(top);
    return result;

    return T(); // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets. 
 * A string will consist of 
 * square bracket characters, [, ], and other characters. This function will return
 * true if and only if the square bracket characters in the given
 * string are balanced. For this to be true,
 * all brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is balanced,
 * "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is balanced.
 *
 * For this function, you may only create a single local variable of type stack<char>!
 * No other stack or queue local objects may be declared. Note that you may still
 * declare and use other local variables of primitive types.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return Whether the input string had balanced brackets
 */
bool isBalanced(queue<char> input)
{

    // @TODO: Make less optimistic
    stack<char> reverse;
    int size = input.size();

    for (int i = 0; i < size; i++) {  //1. push all data to the stack but push back to the queue everytime
      input.push(input.front());  //push the front element to the end of the queue
      reverse.push(input.front());  //push the front element of the queue to the stack
      input.pop();  //pop the front element of the queue
    }

    int result = 0;
    while (reverse.size() != 0) {
      if (reverse.top() == (char)']') {
        result += 1;
      }
      if (reverse.top() == (char)'[') {
        result -= 1;
      }
      if (result < 0 ) {
        return false;
      }
      reverse.pop();
    }
    if (result == 0) {
      return true;
    }
    return false;
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 *  complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble(queue<T>& q)
{
  stack<T> s;
  queue<T> q2;

  // Your code here
  int size = q.size();

  for (int i = 0; i < size; i++) {
    int remaining_size = q.size();
    
    if ((i + 1) % 2 != 0) {
      for (int j = 0; j < std::min(remaining_size, (i + 1)); j++) {
        q2.push(q.front());
        q.pop();
      }
    }
    if ((i + 1) % 2 == 0) {
      for (int j = 0; j < std::min(remaining_size, (i + 1)); j++) {
        s.push(q.front());
        q.pop();
      }
      for (int j = 0; j < std::min(remaining_size, (i + 1)); j++) {
        q2.push(s.top());
        s.pop();
      }
    }
  }
  q = q2;
}

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note The back of the queue corresponds to the top of the stack!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{
    bool retval = true; // optional

    if (s.size() > 0) {
      T temp1 = s.top();
      T temp2 = q.front();

      if (s.size() == 0) {
        s.push(temp1);
        if (temp1 != temp2) {
          return false;
        }
      }
      
      s.pop();
      retval = verifySame(s, q);
      s.push(temp1);

      temp2 = q.front();
      q.pop();
      q.push(temp2);
      if (temp1 != temp2) {
        return false;
      }
    }
    return retval;
}

}
