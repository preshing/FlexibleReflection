#include <vector>
#include "Reflect.h"

struct Node {
    std::string key;
    int value;
    std::vector<Node> children;

    REFLECT()       // Enable reflection for this type
};

int main() {
    // Create an object of type Node
    Node node = {"apple", 3, {{"banana", 7, {}}, {"cherry", 11, {}}}};

    // Find Node's type descriptor
    reflect::TypeDescriptor* typeDesc = reflect::TypeResolver<Node>::get();

    // Dump a description of the Node object to the console
    typeDesc->dump(&node);

    return 0;
}

// Define Node's type descriptor
REFLECT_STRUCT_BEGIN(Node)
REFLECT_STRUCT_MEMBER(key)
REFLECT_STRUCT_MEMBER(value)
REFLECT_STRUCT_MEMBER(children)
REFLECT_STRUCT_END()
