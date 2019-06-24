#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <iostream>
#include <set>


int main(){
    std::set<boost::tuple<int, double, int>> s;
    s.insert(boost::make_tuple(1, 1.0, 2));
    s.insert(boost::make_tuple(2, 2.0, 3));
    for(auto &t : s){
        std::cout << boost::get<1>(t) << std::endl;
    }
    return 0;
}