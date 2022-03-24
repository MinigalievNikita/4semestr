#include "Vector2.h"
#include <iostream>

int main() {
    int k = 3;
    vec2 r;
    vec2 a(3, 4);
    vec2 b(4, 3);
    vec2 c(3,4);
    std::cout << a + b << "\n";
    
    std::cout << a - b << "\n";
    k = a * b;
    std::cout << k << "\n";
    k = a ^ b;
    std::cout << k << "\n";
    
    std::cout << a * 3 << "\n";
    
    std::cout << a / 3 << "\n";
    
    std::cout << a.rotated(3.14) << "\n";
    std::cout << a.getrotate(3.14) << "\n";
    std::cout << 3 * a << "\n";
    std::cout << c.len() << "\n";
    std::cout << c.norm() << "\n";
    std::cout << c.perpen() << "\n";
    vec2 q = -c;
    std::cout << q ;
}
