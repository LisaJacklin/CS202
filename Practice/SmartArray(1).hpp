#ifndef SMARTARRAY_HPP
#define SMARTARRAY_HPP

#include <cstddef>

template <typename T>
class SmartArray {
public:
   // Constructor
   explicit SmartArray(int size);

   // Copy Constructor
   SmartArray(const SmartArray &);

   // Destructor
   ~SmartArray();

   SmartArray & operator=(const SmartArray & orig);

   T & operator[](std::size_t index);

   const T & operator[](std::size_t index) const;

   [[nodiscard]] int size() const;

private:
   int _size;
   T * _data;
};

template <typename T>
SmartArray<T>::SmartArray(int size) : _size(size), _data(new T[size]) {
}

template <typename T>
SmartArray<T>::SmartArray(const SmartArray &orig)
              : _size(orig._size), _data(new T[orig._size]) {
   for (int i = 0; i < _size; ++i)
      _data[i] = orig._data[i];
}

template <typename T>
SmartArray<T>::~SmartArray() {
   delete[] _data;
}

template <typename T>
SmartArray<T> & SmartArray<T>::operator=(const SmartArray &orig) {
   // check for self assignment
   if(&orig == this)
      return *this;  // returns ourself

   // deallocate data
   delete [] _data;

   // copy constructor code - not DRY
   _size = orig._size;
   _data = new T [_size];
   for (int i = 0; i < _size; ++i)
      _data[i] = orig._data[i];

   // return yourself
   return *this;
}

// s[i] = 55;
template <typename T>
T & SmartArray<T>::operator[](std::size_t index) {
   return _data[index];
}

// int a = s[i];
template <typename T>
const T & SmartArray<T>::operator[](std::size_t index) const {
   return _data[index];
}

template <typename T>
int SmartArray<T>::size() const {
   return _size;
}

#endif
