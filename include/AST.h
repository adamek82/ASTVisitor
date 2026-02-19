// AST.h - Abstract Syntax Tree definitions
#ifndef AST_H
#define AST_H

#include "Visitor.h"
#include <memory>
#include <string>

// Base AST Node class
class Node {
public:
    virtual void accept(Visitor* visitor) = 0;
    virtual ~Node() = default;
};

// Number Node
class NodeNumber : public Node {
public:
    double value;
    explicit NodeNumber(double val);
    void accept(Visitor* visitor) override;
};

// Node for referencing a variable (like `x`, `y`)
class NodeVarRef : public Node {
public:
    std::string varName;
    explicit NodeVarRef(std::string name);
    void accept(Visitor* visitor) override;
};

// Addition Node
class NodePlus : public Node {
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    NodePlus(std::unique_ptr<Node> l, std::unique_ptr<Node> r);
    void accept(Visitor* visitor) override;
};

// Assignment Node
class NodeAssign : public Node {
public:
    std::string variable;
    std::unique_ptr<Node> expression;

    NodeAssign(std::string var, std::unique_ptr<Node> expr);
    void accept(Visitor* visitor) override;
};

// Subtraction Node
class NodeMinus : public Node {
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    NodeMinus(std::unique_ptr<Node> l, std::unique_ptr<Node> r);
    void accept(Visitor* visitor) override;
};

// Multiplication Node
class NodeMultiply : public Node {
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    NodeMultiply(std::unique_ptr<Node> l, std::unique_ptr<Node> r);
    void accept(Visitor* visitor) override;
};

// Division Node
class NodeDivide : public Node {
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    NodeDivide(std::unique_ptr<Node> l, std::unique_ptr<Node> r);
    void accept(Visitor* visitor) override;
};

class NodePower : public Node {
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    NodePower(std::unique_ptr<Node> l, std::unique_ptr<Node> r);
    void accept(Visitor* visitor) override;
};

#endif // AST_H
