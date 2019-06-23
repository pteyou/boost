#include <iostream>
#include <vector>
#include <boost/variant.hpp>
#include <string>
#include <cassert>

int main(){
    typedef boost::variant<boost::blank, int, const char*, std::string> my_var_t;
    my_var_t var;
    assert(var.which() == 0); // First position (blank) assigned by default
    var = 1;
    std::cout << var.which() << std::endl;
    const char* s {"Hello world !"};
    var = s;
    std::cout << var.which() << std::endl;
    std::string ss{s};
    var = ss;
    std::cout << var.which() << std::endl;

    std::string* gs = boost::get<std::string> (&var);
    if (gs) std::cout << *gs << std::endl;
    return 0;
}