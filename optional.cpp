#include <boost/optional.hpp>
#include <iostream>
#include <stdlib.h>

class lock_device {
    explicit lock_device(const char* param) {
        std::cout << "*** Device is locked and message is " << param << " ***" << std::endl;
    }
public:
    ~lock_device(){
        std::cout << "*** Device is unlocked ***" << std::endl;
    }
    void use() {
        std::cout << "using device" << std::endl;
    }
    static boost::optional<lock_device> try_lock(int r){
        if(!(r%2)) { // ok for lock
            return lock_device(std::to_string(r).c_str());
        }
        else {
            return boost::none;
        }
    }
};

int main(){
    srandom(5);
    for(int i=0; i<5; i++){
        int k = rand();
        boost::optional<lock_device> t = lock_device::try_lock(k);
        if(t) {
            t->use();
            return 0;
        }
        else{
            std::cout << "...try again" << std::endl;
        }
    }
    std::cout << "Epic Fail" << std::endl;
    return -1;
}