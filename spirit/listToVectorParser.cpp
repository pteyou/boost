#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/spirit/include/support_istream_iterator.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

namespace client{
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;
    namespace phoenix = boost::phoenix;

    template<class Iterator>
    bool parseListInVector(Iterator begin, Iterator end, std::vector<int> &v){
        using qi::phrase_parse;
        using phoenix::push_back;
        //using phoenix::ref;
        using qi::_1;
        using ascii::space;
        using qi::int_;
        /* 
        bool res = phrase_parse(begin, end, 
        (
            int_[push_back(phoenix::ref(v), _1)] >> *(',' >> int_[push_back(phoenix::ref(v), _1)])
            //int_[push_back(phoenix::ref(v), _1)] % ','
        ), space);
        */
        bool res = phrase_parse(begin, end, 
        (
            int_ % ','
        ), space, v);
        if(begin != end) return false;
        return res;
    }
}

int main(){
    std::ifstream ifs("test.dat");
    boost::spirit::istream_iterator beg(ifs), en;
    std::vector<int> test;
    bool r = client::parseListInVector(beg, en, test);
    if(!r) {
        std::cout << "error"<<std::endl;
        return -1;
    }
    std::ostream_iterator<int> out(std::cout, ", ");
    std::copy(test.begin(), test.end(), out);
    std::cout << std::endl;
    ifs.close();
    return 0;
}