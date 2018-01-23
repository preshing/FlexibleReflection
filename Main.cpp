#include <vector>
#include <memory>
#include "Reflect.h"

struct Node {
    std::string key;
    double value;
    std::unique_ptr<Node> next;

    REFLECT()       // Enable reflection for this type
};

int main() {
    // Create an object of type Node
    Node node = {
        "apple",
        5,
        std::unique_ptr<Node>{new Node{
            "banana",
            7,
            std::unique_ptr<Node>{new Node{
                "cherry",
                11,
                nullptr
            }}
        }}
    };

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
REFLECT_STRUCT_MEMBER(next)
REFLECT_STRUCT_END()
