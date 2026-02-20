// EvaluatingVisitor.cpp
#include "EvaluatingVisitor.h"

double EvaluatingVisitor::evaluate(Node* node) {
    if (!node) {
        throw std::runtime_error("Null AST node in evaluate()");
    }

    // ważne: czyścisz stos dla pojedynczego “run”
    valueStack.clear();

    node->accept(this);

    if (valueStack.size() != 1) {
        throw std::runtime_error(
            "Evaluator bug: expected exactly one value on stack after evaluation, got " +
            std::to_string(valueStack.size())
        );
    }

    return pop();
}

// Number => push(value)
void EvaluatingVisitor::visit(NodeNumber* node) {
    push(node->value);
}

// VarRef => push(symbols[name])
void EvaluatingVisitor::visit(NodeVarRef* node) {
    auto it = symbols.find(node->varName);
    if (it == symbols.end()) {
        throw std::runtime_error("Undefined variable: " + node->varName);
    }
    push(it->second);
}

// Plus => evalBinary(left, right, +)
void EvaluatingVisitor::visit(NodePlus* node) {
    evalBinary(node->left.get(), node->right.get(),
               [](double a, double b) { return a + b; });
}

void EvaluatingVisitor::visit(NodeMinus* node) {
    evalBinary(node->left.get(), node->right.get(),
               [](double a, double b) { return a - b; });
}

void EvaluatingVisitor::visit(NodeMultiply* node) {
    evalBinary(node->left.get(), node->right.get(),
               [](double a, double b) { return a * b; });
}

void EvaluatingVisitor::visit(NodeDivide* node) {
    evalBinary(node->left.get(), node->right.get(),
               [](double a, double b) {
                   if (b == 0.0) throw std::runtime_error("Division by zero");
                   return a / b;
               });
}

void EvaluatingVisitor::visit(NodePower* node) {
    evalBinary(node->left.get(), node->right.get(),
               [](double a, double b) { return std::pow(a, b); });
}

// Assign: najpierw RHS -> pop -> store -> push (bo assignment “zwraca” wartość)
void EvaluatingVisitor::visit(NodeAssign* node) {
    if (!node->expression) {
        throw std::runtime_error("Null RHS in assignment");
    }

    node->expression->accept(this);
    double rhs = pop();

    symbols[node->variable] = rhs;
    push(rhs);
}
