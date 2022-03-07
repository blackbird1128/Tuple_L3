#ifndef T_TUPLE_H
#define T_TUPLE_H


#include <iostream>
#include <typeinfo>


namespace t {


  template<class T , class... TypesT>
  class Tuple  {

    template<typename> friend class Tuple;
    

  private:

    Tuple<TypesT...> tail;

  public:


    T value;
    std::size_t sizeTail;
    /**
     * Default constructor
     */

    Tuple() : sizeTail(0) {
    }


    /**
     * Constructor to initialize values
     */

    Tuple(T firstArg , TypesT... restArg) {
      
      value = firstArg;
      sizeTail = sizeof...(restArg);
    //  std:: cout << "sizeTail: " << sizeTail << std::endl;
     // std::cout << "type: " << typeid(value).name() << std::endl;
      tail = Tuple<TypesT...>(restArg...);
    }

    /**
     * Value getter
     */
    template<int index>
    auto get() {
      if constexpr (index == 0) {
        return value;
      } else {
          return tail.template get<index-1>();
      }   
    }

    /**
     * Addition between to tuples
     */
    template <typename OtherType, typename ... OtherTypes>
    Tuple<OtherType , OtherTypes...> operator+(const Tuple<OtherType, OtherTypes...>& other) {
      friend class Tuple<OtherType , OtherTypes...>;
      return Tuple<OtherType , OtherTypes...>(value + other.value , tail + other.tail);
    }

    /**
     * Addition between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<OtherTypes...> operator+=(const Tuple<OtherTypes...>& other) {
      this->value += other.value;
      this->tail += other.tail;
      return *this;
    }

    /**
     * Substraction between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<OtherTypes...> operator-(const Tuple<OtherTypes...>& other) {
      return Tuple<OtherTypes...>(value - other.value , tail - other.tail);
    }

    /**
     * Substraction between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<OtherTypes...>& operator-=(const Tuple<OtherTypes...>& other) {
      this->value -= other.value;
      this->tail -= other.tail;
      return *this;
    }

    /**
     * Multiplication between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<OtherTypes...> operator*(const Tuple<OtherTypes...>& other) {
      return Tuple<OtherTypes...>(value * other.value , tail * other.tail);
    }

    /**
     * Multiplication between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<OtherTypes...>& operator*=(const Tuple<OtherTypes...>& other) {
      this->value *= other.value;
      this->tail *= other.tail;
    }

    /**
     * Division between to tuples
     */
    template <typename ... OtherTypes>
    Tuple<OtherTypes...> operator/(const Tuple<OtherTypes...>& other) {
      return Tuple<OtherTypes...>(value / other.value , tail / other.tail);
    }

    /**
     * Division between to tuples - in place
     */
    template <typename ... OtherTypes>
    Tuple<OtherTypes...>& operator/=(const Tuple<OtherTypes...>& other) {
      this->value /= other.value;
      this->tail /= other.tail;
      return *this;
    }

    /**
     * Comparaison operators
     */
    template <typename ... OtherTypes>
    bool operator==(const Tuple<OtherTypes...>& other) { 

      return (value == other.value) && (tail == other.tail);
     }

    template <typename ... OtherTypes>
    bool operator!=(const Tuple<OtherTypes...>& other) {
      return (value != other.value) || (tail != other.tail);
    }

    template <typename ... OtherTypes>
    bool operator<(const Tuple<OtherTypes...>& other) {
      if(value == other.value) {
        return tail < other.tail;
      }
      return value < other.value;

    }

    template <typename ... OtherTypes>
    bool operator<=(const Tuple<OtherTypes...>& other) {
      if(value == other.value) {
        return tail <= other.tail;
      }
      return value <= other.value;

    }

    template <typename ... OtherTypes>
    bool operator>(const Tuple<OtherTypes...>& other) {
      if(value == other.value) {
        return tail > other.tail;
      }
      return value > other.value;


    }

    template <typename ... OtherTypes>
    bool operator>=(const Tuple<OtherTypes...>& other) {
      if(value == other.value) {
        return tail >= other.tail;
      }
      return value >= other.value;

    }


    /**
     * Concatenate two tuples
     */
    // template <typename ... OtherTypes>
    // Tuple<T , TypesT... , OtherTypes...> operator|(Tuple<OtherTypes...>&& other) {

    //   sizeTail += other.sizeTail;
    //   return std::move(tail)  | std::move(other);
      
    // }
    
  // };



  };


    /**
   * Helper function to create a tuple
   */
  template <class... Types>
  constexpr Tuple<Types...> makeTuple(Types&&... args) {
    return Tuple<Types...>(std::forward<Types>(args)...);
  }



  template <typename T>
  class Tuple<T> {

    template<typename> friend class Tuple;

    public:

    Tuple()
    {
   //   std::cout << "type: " << typeid(value).name() << std::endl;
    }

    Tuple(T arg): value(arg)
    {

   //   std::cout << "tail constructor" << std::endl;
  //    std::cout << "value: " << value << std::endl;
    }



    template<int index>
    auto  get() {

        return value;    
    }


    template <typename Type>
    bool operator==(const Tuple<Type>& other) {
      return value == other.value;
    }

    template <typename Type>
    bool operator!=(const Tuple<Type>& other) {
      return value != other.value;
    }

    template <typename Type>
    bool operator<(const Tuple<Type>& other) {
      return value < other.value;
    }

    template <typename Type>
    bool operator<=(const Tuple<Type>& other) {
      return value <= other.value;
    }

    template <typename Type>
    bool operator>(const Tuple<Type>& other) {
      return value > other.value;
    }

    template <typename Type>
    bool operator>=(const Tuple<Type>& other) {
      return value >= other.value;
    }

    template <typename Type>
    Tuple<Type> operator+=(const Tuple<Type>& other) {
      this->value += other.value;
      return *this;
    }

    template <typename Type>
    Tuple<Type> operator-=(const Tuple<Type>& other) {
      this->value -= other.value;
      return *this;
    }

    template <typename Type>
    Tuple<Type> operator+(const Tuple<Type>& other) {
      return Tuple<Type>(value + other.value);
    }

    template <typename Type>
    Tuple<Type> operator-(const Tuple<Type>& other) {
      return Tuple<Type>(value - other.value);
    }

    template <typename Type>
    Tuple<Type> operator*(const Tuple<Type>& other) {
      return Tuple<Type>(value * other.value);
    }

    template <typename Type>
    Tuple<Type> operator/(const Tuple<Type>& other) {
      return Tuple<Type>(value / other.value);
    }

    // template <typename ...Types>
    // Tuple<T ,Types...> operator|(Tuple<Types...>&& other) {
    //   return Tuple<T , Types...>(value , other);
    // }

    


    private:
      T value;

  };

}



#endif // T_TUPLE_H
