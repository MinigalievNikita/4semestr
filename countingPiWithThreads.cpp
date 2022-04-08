#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
#include <future>
#include <numeric>
#include <functional>
#include "Vector2.h"

const int N = 8;
const long Quantity = 1000000000;
const int R = 2;

int main() {
    std::vector<vec2> quantity;
    for(long i = 0; i < Quantity; ++i) {
        vec2 temp;
        temp.x = (float)(rand()) / RAND_MAX * 2 * R - R;
        temp.y = (float)(rand()) / RAND_MAX * 2 * R - R;
        quantity.push_back(temp);
    }
    
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    
    std::vector<std::future<long>> f;
    for(int i = 0; i < N; ++i) {
        f.push_back(std::async([&quantity, i](){
            long sum = 0;
            for(long k = i * Quantity / N; k < (i + 1) * Quantity / N; ++k){
                if(quantity[k].len() <= R) {
                    sum++;
                }
            }
            return sum;
        }));
    }
    long Sum = 0;
    
    for(auto& result : f) {
      //  std::cout<<result.get() << "-Количество попаданий";
        Sum += result.get();
        std::cout<< Sum << std::endl;
    }
   // (Sum/Quantity) * (2 * R * 2 * R)
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    
    std::cout << ((float)Sum/(float)Quantity) * 4 << "Площадь" << std::endl;
    std::cout << diff.count() << "s" << "Итого секуунд" << std::endl;
}
