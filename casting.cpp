#include <vector>
#include <boost/lexical_cast.hpp>
#include <algorithm>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <deque>
#include <array>

template<class ContainerT>
std::vector<long int> convert(const ContainerT& container){
    typedef typename ContainerT::value_type value_type;
    //auto f = &boost::lexical_cast<long int, value_type>;
    typedef long int (*func_t) (const value_type &);
    func_t f = &boost::lexical_cast<long int, value_type>;
    std::vector<long int> res;
    std::transform(container.begin(), container.end(), std::back_inserter(res), f);
    return res;
}

int main(){
    std::set<std::string> s;
    s.insert(std::string("101"));
    auto v = convert(s);
    std::cout << v.front() << std::endl;
    std::cout << v.back() << std::endl;

    std::deque<std::array<char, 4>> deq;
    deq.push_back({'1', '2', '3', '4'});
    deq.push_front({'0', '1', '2', '3'});
    auto vv = convert(deq);
    std::cout << vv.front() << std::endl;
    std::cout << vv.back() << std::endl;

    auto a = boost::lexical_cast<std::array<char, 5>>(1234);
    std::ostream_iterator<char> osi(std::cout, ", ");
    std::copy(a.begin(), a.end(), osi); std::cout << std::endl;
    return 0;
}