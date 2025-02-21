// AST.cpp - Implementation of AST Nodes
#include "AST.h"
#include "Visitor.h"

// Constructor for NodeNumber
NodeNumber::NodeNumber(int val) : value(val) {}

// Accept function for NodeNumber
void NodeNumber::accept(Visitor* visitor) {
    visitor->visit(this);
}

// Constructor for NodePlus
NodePlus::NodePlus(std::unique_ptr<Node> l, std::unique_ptr<Node> r)
    : left(std::move(l)), right(std::move(r)) {}

// Accept function for NodePlus
void NodePlus::accept(Visitor* visitor) {
    visitor->visit(this);
}

// Constructor for NodeAssign
NodeAssign::NodeAssign(std::string var, std::unique_ptr<Node> expr)
    : variable(std::move(var)), expression(std::move(expr)) {}

// Accept function for NodeAssign
void NodeAssign::accept(Visitor* visitor) {
    visitor->visit(this);
}
