// class invariant:
// _denominator is always > 0
template<typename T>
class Rational {
   template <typename U>
   friend std::ostream& operator<<(std::ostream &, const Rational<U> &rhs);

   template <typename U>
   friend Rational<U> operator+(const Rational<U> &lhs, const Rational<U> &rhs);

   template <typename U>
   friend Rational<U> operator-(const Rational<U> &lhs);

   template <typename U>
   friend bool operator==(const Rational<U> &lhs, const Rational<U> &rhs);

   template <typename U>
   friend bool operator<(const Rational<U> &lhs, const Rational<U> &rhs);



public:
   Rational<T>(int=0,int=1); //NOLINT(google-explicit-constructor): Allow implicit conversion from int
   Rational<T> & operator+=(const Rational<T>& rhs);
   Rational<T> & operator-=(const Rational<T>& rhs);
   Rational<T> & operator*=(const Rational<T>& rhs);
   Rational<T> & operator/=(const Rational<T>& rhs);
   Rational<T> & operator++();        //prefix ++
   Rational<T> operator++(int); //postfix ++
   Rational<T> & operator--();        //prefix --
   Rational<T> operator--(int); //postfix --
private:
   void reduce();

   int _numerator;
   int _denominator;
};

/*
Rational operator-(const Rational &lhs, const Rational &rhs);
Rational operator*(Rational lhs, const Rational &rhs);
Rational operator/(Rational lhs, const Rational &rhs);
bool operator!=(const Rational &lhs, const Rational &rhs);
bool operator>(const Rational &lhs, const Rational &rhs);
bool operator<=(const Rational &lhs, const Rational &rhs);
bool operator>=(const Rational &lhs, const Rational &rhs);
*/

template<typename T>
Rational<T>::Rational(int num, int den) : _numerator(num), _denominator(den) {
   reduce();
}
template<typename T>
std::ostream &operator<<(std::ostream &os, const Rational<T> &rhs) {
   os << rhs._numerator;
   if (rhs._denominator != 1)
      os << "/" << rhs._denominator;
   return os;
}
template<typename T>
Rational<T> & Rational<T>::operator+=(const Rational<T> &rhs) {
   // a/b + c/d = (ad+bc)/ad
   _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
   _denominator *= rhs._denominator;
   reduce();
   return *this;
}
template <typename T>
Rational<T>& Rational<T>::operator-=(const Rational<T>& rhs) { //Canonical
    *this = *this - rhs; //uses Rational::operator- to define operator-=
    return *this;
}
template <typename T>
Rational<T>& Rational<T>::operator*=(const Rational<T>& rhs) {
    _numerator *= rhs._numerator;
    _denominator *= rhs._denominator;
    reduce();
    return *this;
}
template <typename T>
Rational<T>& Rational<T>::operator/=(const Rational<T>& rhs) {
    *this *= {rhs._denominator, rhs._numerator};
    reduce();
    return *this;
}

template <typename T>
Rational<T>& Rational<T>::operator++() {//prefix ++
    return *this += 1;
}
template <typename T>
Rational<T> Rational<T>::operator++(int) {//postfix ++
    auto copy{ *this };
    ++(*this);
    return copy;
} //HELP
template <typename T>
Rational<T>& Rational<T>::operator--() {//prefix --
    return *this -= 1;
}
template <typename T>
Rational<T> Rational<T>::operator--(int) {//postfix --
    auto copy{ *this };
    --(*this);
    return copy;
} //HELP

template<typename T>
bool operator==(const Rational<T>& lhs, const Rational<T>& rhs) {
    return lhs._numerator == rhs._numerator && lhs._denominator == rhs._denominator;
}
template<typename T>
bool operator<(const Rational <T>& lhs, const Rational<T>& rhs) {
    return lhs._numerator * rhs._denominator < rhs._numerator* lhs._denominator;
}
template<typename T>
bool operator!=(const Rational<T>& lhs, const Rational<T>& rhs) {//canonical
    return !(rhs == lhs);
}
template<typename T>
bool operator>(const Rational <T>& lhs, const Rational<T>& rhs) {//canonical
    return rhs < lhs;
}
template<typename T>
bool operator<=(const Rational<T>& lhs, const Rational<T>& rhs) {//canonical
    return !(rhs > lhs);
}
template<typename T>
bool operator>=(const Rational<T>& lhs, const Rational<T>& rhs) {//canonical
    return !(rhs < lhs);
}


template<typename T>
void Rational<T>::reduce() {
    T gcd = std::gcd(_numerator,_denominator);
   _numerator /= gcd;
   _denominator /= gcd;
   if (_denominator < 0) {
      _numerator *= -1;
      _denominator *= -1;
   }
}

template<typename U>
Rational<U> operator+(const Rational<U>& lhs, const Rational<U>& rhs) { //canonical
    auto temp{ lhs };
    temp += rhs;
    return temp;
}


template<typename U>
Rational<U> operator-(const Rational<U> &lhs) {
   return { -lhs._numerator, lhs._denominator };
}

template<typename U>
Rational<U> operator-(const Rational<U> &lhs, const Rational<U> &rhs) {
   return lhs + -rhs;
}

// pass lhs by value because we were going to copy it anyway
template<typename U>
Rational<U> operator*(Rational<U> lhs, const Rational<U> &rhs) { //Canonical
   return lhs *= rhs;
}

// pass lhs by value because we were going to copy it anyway
template<typename U>
Rational<U> operator/(Rational<U> lhs, const Rational<U> &rhs) { //Canonical
   return lhs /= rhs;
}
