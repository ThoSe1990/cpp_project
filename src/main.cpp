


#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iostream>

int main ()
{
    std::cout << "hello world\n";


    std::vector<int> v = {
        1,2,3,4,5
    };

    for ( const auto& e : v) {
        std::cout << e << std::endl;
    }
        

    return 0;
}

