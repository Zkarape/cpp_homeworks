#include "vectorMine.hpp"


int main() {
    // Testing default constructor
    Vector<int> vec1;
    std::cout << "vec1 (default constructor): size = " << vec1.size() << ", capacity = " << vec1.capacity() << "\n";

    // Testing constructor with count and value
    Vector<int> vec2(5, 42);
    std::cout << "vec2 (constructor with count and value): size = " << vec2.size() << ", capacity = " << vec2.capacity() << "\n";
    std::cout << "vec2 elements: ";
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << "\n";

    // Testing push_back
    vec2.push_back(99);
    std::cout << "vec2 after push_back: size = " << vec2.size() << ", capacity = " << vec2.capacity() << "\n";
    std::cout << "vec2 elements: ";
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << "\n";

    // Testing pop_back
    vec2.pop_back();
    std::cout << "vec2 after pop_back: size = " << vec2.size() << ", capacity = " << vec2.capacity() << "\n";
    std::cout << "vec2 elements: ";
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << "\n";

    // Testing resize
    vec2.resize(10, 1);
    std::cout << "vec2 after resize: size = " << vec2.size() << ", capacity = " << vec2.capacity() << "\n";
    std::cout << "vec2 elements: ";
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << "\n";

    // Testing reserve
    vec2.reserve(20);
    std::cout << "vec2 after reserve: size = " << vec2.size() << ", capacity = " << vec2.capacity() << "\n";

    // Testing copy constructor
    Vector<int> vec3(vec2);
    std::cout << "vec3 (copy of vec2): size = " << vec3.size() << ", capacity = " << vec3.capacity() << "\n";
    std::cout << "vec3 elements: ";
    for (size_t i = 0; i < vec3.size(); ++i) {
        std::cout << vec3[i] << " ";
    }
    std::cout << "\n";

    // Testing move constructor
    Vector<int> vec4(std::move(vec3));
    std::cout << "vec4 (moved from vec3): size = " << vec4.size() << ", capacity = " << vec4.capacity() << "\n";
    std::cout << "vec4 elements: ";
    for (size_t i = 0; i < vec4.size(); ++i) {
        std::cout << vec4[i] << " ";
    }
    std::cout << "\n";
    std::cout << "vec3 after move: size = " << vec3.size() << ", capacity = " << vec3.capacity() << "\n";

    // Testing copy assignment operator
    vec1 = vec4;
    std::cout << "vec1 (assigned from vec4): size = " << vec1.size() << ", capacity = " << vec1.capacity() << "\n";
    std::cout << "vec1 elements: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << "\n";

    // Testing move assignment operator
    vec1 = std::move(vec4);
    std::cout << "vec1 (moved from vec4): size = " << vec1.size() << ", capacity = " << vec1.capacity() << "\n";
    std::cout << "vec1 elements: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << "\n";
    std::cout << "vec4 after move: size = " << vec4.size() << ", capacity = " << vec4.capacity() << "\n";

    return 0;
}