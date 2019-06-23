#include<boost/any.hpp>
#include<iostream>
#include<vector>
#include<string>

int main(){
    std::vector<boost::any> vars;
    vars.push_back(10);
    const char* c_str {"Hello there"};
    vars.push_back(c_str);
    std::string a{"allo"};
    vars.push_back(a);

    std::string vba {boost::any_cast<std::string>(vars.back())};
    std::cout << vba << std::endl;

    boost::any variable(std::string("Hello world!"));
    std::string* s2 = boost::any_cast<std::string>(&variable);
    if(s2) std::cout << *s2 << std::endl;
    return 0;
}