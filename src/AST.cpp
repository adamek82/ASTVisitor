// AST.cpp - Implementation of AST Nodes
#include "AST.h"
#include "Visitor.h"

// Constructor for NodeNumber
NodeNumber::NodeNumber(double val) : value(val) {}

// Accept function for NodeNumber
void NodeNumber::accept(Visitor* visitor) {
    visitor->visit(this);
}

// Constructor for NodeVarRef
NodeVarRef::NodeVarRef(std::string name)
    : varName(std::move(name)) {}

// Accept function for NodeVarRef
void NodeVarRef::accept(Visitor* visitor) {
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

// Constructor for NodeMinus
NodeMinus::NodeMinus(std::unique_ptr<Node> l, std::unique_ptr<Node> r)
    : left(std::move(l)), right(std::move(r)) {}

// Accept function for NodeMinus
void NodeMinus::accept(Visitor* visitor) {
    visitor->visit(this);
}

// Constructor for NodeMultiply
NodeMultiply::NodeMultiply(std::unique_ptr<Node> l, std::unique_ptr<Node> r)
    : left(std::move(l)), right(std::move(r)) {}

// Accept function for NodeMultiply
void NodeMultiply::accept(Visitor* visitor) {
    visitor->visit(this);
}

// Constructor for NodeDivide
NodeDivide::NodeDivide(std::unique_ptr<Node> l, std::unique_ptr<Node> r)
    : left(std::move(l)), right(std::move(r)) {}

// Accept function for NodeDivide
void NodeDivide::accept(Visitor* visitor) {
    visitor->visit(this);
}

NodePower::NodePower(std::unique_ptr<Node> l, std::unique_ptr<Node> r)
    : left(std::move(l)), right(std::move(r)) {}

void NodePower::accept(Visitor* visitor) {
    visitor->visit(this);
}
