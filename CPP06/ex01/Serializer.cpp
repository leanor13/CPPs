#include "Serializer.hpp"

// Private constructor, copy constructor, assignment operator, and destructor
Serializer::Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) { return *this; }
Serializer::~Serializer() {}

// Convert Data* to uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// Convert uintptr_t back to Data*
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
