#include <iostream>
#include <boost/program_options.hpp>

namespace opt = boost::program_options;

int main(int argc, char* argv[]){
    opt::options_description desc("All options");
    desc.add_options() 
        ("apples,a", opt::value<int>()->default_value(10), "number of apples")
        ("oranges,o", opt::value<int>(), "number of oranges")
        ("name,n", opt::value<std::string>()->default_value("Root"), "Your name")
        ("help,h", "Display help options");
    opt::variables_map vmap;
    opt::store(opt::parse_command_line(argc, argv, desc), vmap);
    opt::notify(vmap);

    if(vmap.count("help")){
        std::cout << desc << std::endl;
        return 1;
    }
    if(vmap.count("name"))
        std::cout << "Hi " << vmap["name"].as<std::string>() << " !\n";
    if(!vmap.count("oranges")){
        std::cout << "number of oranges is mandatory" << std::endl;
        return 1;
    }
    std::cout << "The sum of is " 
              << vmap["apples"].as<int>() + vmap["oranges"].as<int>()
              << " fruits" << std::endl;
    return 0;
}