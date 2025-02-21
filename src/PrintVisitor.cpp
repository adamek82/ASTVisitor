// PrintVisitor.cpp - Print AST Nodes
#include "PrintVisitor.h"

void PrintVisitor::visit(NodeNumber* node) {
    std::cout << node->value;
}

void PrintVisitor::visit(NodePlus* node) {
    std::cout << "(";
    node->left->accept(this);
    std::cout << " + ";
    node->right->accept(this);
    std::cout << ")";
}

void PrintVisitor::visit(NodeAssign* node) {
    std::cout << node->variable << " = ";
    node->expression->accept(this);
}