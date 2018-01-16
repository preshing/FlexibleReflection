#include "Reflect.h"

namespace reflect {

//--------------------------------------------------------
// A type descriptor for int
//--------------------------------------------------------

struct TypeDescriptor_Int : TypeDescriptor {
    TypeDescriptor_Int() : TypeDescriptor{"int", sizeof(int)} {
    }
    virtual void dump(const void* obj, int) const override {
        std::cout << "int{" << *(const int*) obj << "}";
    }
};

TypeDescriptor_Int Reflection_Int;

template <>
TypeDescriptor* getPrimitiveDescriptor<int>() {
    return &Reflection_Int;
}

//--------------------------------------------------------
// A type descriptor for std::string
//--------------------------------------------------------

struct TypeDescriptor_StdString : TypeDescriptor {
    TypeDescriptor_StdString() : TypeDescriptor{"std::string", sizeof(std::string)} {
    }
    virtual void dump(const void* obj, int) const override {
        std::cout << "std::string{\"" << *(const std::string*) obj << "\"}";
    }
};

TypeDescriptor_StdString Reflection_StdString;

template <>
TypeDescriptor* getPrimitiveDescriptor<std::string>() {
    return &Reflection_StdString;
}

} // namespace reflect
