#include "Serializer.hpp"
#include <iostream>

int main() {
    // Create a Data object
    Data data;
    data.name = "TestData";
    data.value = 42;

    // Print original Data object
    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data content: { name: " << data.name << ", value: " << data.value << " }" << std::endl;

    // Serialize the Data object
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    // Deserialize back to Data*
    Data* ptr = Serializer::deserialize(raw);

    // Print deserialized Data object
    std::cout << "Deserialized Data address: " << ptr << std::endl;
    std::cout << "Deserialized Data content: { name: " << ptr->name << ", value: " << ptr->value << " }" << std::endl;

    // Verify that the original and deserialized addresses match
    if (ptr == &data) {
        std::cout << "Success: Addresses match, deserialization is correct!" << std::endl;
    } else {
        std::cout << "Error: Addresses do not match!" << std::endl;
    }

    return 0;
}