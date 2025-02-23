#include "EvaluatingVisitor.h"

double EvaluatingVisitor::evaluate(Node* node) {
    // Reset currentValue each time we start a new eval
    currentValue = 0.0;
    if (!node) throw std::runtime_error("Null AST node in evaluate()");
    node->accept(this);      // This sets currentValue
    return currentValue;     // Return the value computed by the visit(...)
}

// Handle numbers
void EvaluatingVisitor::visit(NodeNumber* node) {
    currentValue = node->value;
}

// Handle addition
void EvaluatingVisitor::visit(NodePlus* node) {
    double leftVal, rightVal;
    leftVal = evaluate(node->left.get());
    rightVal = evaluate(node->right.get());
    currentValue = leftVal + rightVal;
}

// Handle subtraction
void EvaluatingVisitor::visit(NodeMinus* node) {
    double leftVal, rightVal;
    leftVal = evaluate(node->left.get());
    rightVal = evaluate(node->right.get());
    currentValue = leftVal - rightVal;
}

// Handle multiplication
void EvaluatingVisitor::visit(NodeMultiply* node) {
    double leftVal, rightVal;
    leftVal = evaluate(node->left.get());
    rightVal = evaluate(node->right.get());
    currentValue = leftVal * rightVal;
}

// Handle division
void EvaluatingVisitor::visit(NodeDivide* node) {
    double leftVal, rightVal;
    leftVal = evaluate(node->left.get());
    rightVal = evaluate(node->right.get());
    if (rightVal == 0.0) throw std::runtime_error("Division by zero");
    currentValue = leftVal / rightVal;
}

// Handle exponent
void EvaluatingVisitor::visit(NodePower* node) {
    double baseVal = evaluate(node->left.get());
    double expVal = evaluate(node->right.get());
    currentValue = std::pow(baseVal, expVal);
}

// Handle assignment: evaluate the RHS, store in symbol table
void EvaluatingVisitor::visit(NodeAssign* node) {
    double rhs = evaluate(node->expression.get());
    symbols[node->variable] = rhs;    // store in map
    currentValue = rhs;               // assignment yields the assigned value
}

// Handle variable reference
void EvaluatingVisitor::visit(NodeVarRef* node) {
    auto it = symbols.find(node->varName);
    if (it == symbols.end()) {
        throw std::runtime_error("Undefined variable: " + node->varName);
    }
    currentValue = it->second;  // fetch from symbol table
}
