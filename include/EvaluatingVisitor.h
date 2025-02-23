#ifndef EVALUATINGVISITOR_H
#define EVALUATINGVISITOR_H

#include "Visitor.h"
#include "AST.h"
#include <unordered_map>
#include <string>
#include <cmath>  // for std::pow
#include <stdexcept>

class EvaluatingVisitor : public Visitor {
private:
    // Symbol table: varName -> value
    std::unordered_map<std::string, double> symbols;

    // A temporary place to store the result of visiting a node
    double currentValue = 0.0;

public:
    // Visit each node type:
    void visit(NodeNumber* node) override;
    void visit(NodePlus* node) override;
    void visit(NodeMinus* node) override;
    void visit(NodeMultiply* node) override;
    void visit(NodeDivide* node) override;
    void visit(NodePower* node) override;
    void visit(NodeAssign* node) override;
    void visit(NodeVarRef* node) override;

    // Entry point: evaluate any node
    double evaluate(Node* node);
};

#endif // EVALUATINGVISITOR_H
