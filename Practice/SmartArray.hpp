#ifndef CS202CLASSEXAMPLE_SMARTARRAY_HPP
#define CS202CLASSEXAMPLE_SMARTARRAY_HPP
#include <cstddef>
class SmartArray {
public:
   // Constructor
   explicit SmartArray(int size);

   // Copy Constructor
   SmartArray(const SmartArray &);

   // Destructor
   ~SmartArray();

   SmartArray & operator=(const SmartArray & orig);

   int & operator[](std::size_t index);

   const int & operator[](std::size_t index) const;

   [[nodiscard]] int size() const;

private:
   int _size;
   int * _data;
};
#endif//CS202CLASSEXAMPLE_SMARTARRAY_HPP
