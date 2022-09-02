#include <iostream>

extern "C" {
    long int test_main();
}

int main() {
    std::cout << "output of test_main() " << test_main() << std::endl;
}