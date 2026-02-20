#pragma once

#include "Visitor.h"
#include "AST.h"

#include <cmath>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

class EvaluatingVisitor : public Visitor {
public:
    // Public API: evaluate the whole AST and return its final numeric value
    double evaluate(Node* node);

    // Visitor interface methods
    void visit(NodeNumber* node) override;
    void visit(NodeVarRef* node) override;
    void visit(NodePlus* node) override;
    void visit(NodeMinus* node) override;
    void visit(NodeMultiply* node) override;
    void visit(NodeDivide* node) override;
    void visit(NodePower* node) override;
    void visit(NodeAssign* node) override;

private:
    std::unordered_map<std::string, double> symbols;

    // Stack for partial evaluation results
    std::vector<double> valueStack;

private:
    // Push a value onto the evaluation stack
    void push(double v) { valueStack.push_back(v); }

    // Pop a value from the evaluation stack (with underflow check)
    double pop() {
        if (valueStack.empty()) {
            throw std::runtime_error("Evaluator bug: value stack underflow");
        }
        double v = valueStack.back();
        valueStack.pop_back();
        return v;
    }

    // Helper for binary operators:
    // evaluate left subtree, evaluate right subtree, pop rhs/lhs, compute, push result
    template <typename F>
    void evalBinary(Node* left, Node* right, F&& f) {
        if (!left || !right) {
            throw std::runtime_error("Null child node in binary expression");
        }
        left->accept(this);
        right->accept(this);
        double rhs = pop();
        double lhs = pop();
        push(f(lhs, rhs));
    }
};
