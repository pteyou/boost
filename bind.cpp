#include <boost/bind.hpp>
#include <functional>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

class Number{};
Number operator+ (Number n1, Number n2) {
    std::cout << "sum occuring" << std::endl;
    return n1;
}


template<class T>
void mul_2_bind (std::vector<T> &v){
    std::for_each(v.begin(), v.end(), boost::bind(std::plus<T>(), _1, _1));
}

template<class T>
struct mult2 : public std::unary_function<T, T> {
    T operator() (T t) {
        return t+t;
    }
};

template<class T>
void mul_2_ft (std::vector<T> &v){
    std::for_each(v.begin(), v.end(), mult2<T>());
}

int main(){
    std::vector<Number> v(3);
    //std::iota(v.begin(), v.end(), 1);
    mul_2_bind(v);
    mul_2_ft(v);
    //std::cout << v[9] << std::endl;
    return 0;
}