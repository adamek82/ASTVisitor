// PrintVisitor.h - Concrete visitor for printing
#ifndef PRINTVISITOR_H
#define PRINTVISITOR_H

#include "Visitor.h"
#include "AST.h"
#include <iostream>

class PrintVisitor : public Visitor {
public:
    void visit(NodeNumber* node) override;
    void visit(NodeVarRef* node) override;
    void visit(NodePlus* node) override;
    void visit(NodeMinus* node) override;
    void visit(NodeMultiply* node) override;
    void visit(NodeDivide* node) override;
    void visit(NodePower* node) override;
    void visit(NodeAssign* node) override;
};

#endif // PRINTVISITOR_H
