// PrintVisitor.cpp - Print AST Nodes
#include "PrintVisitor.h"

void PrintVisitor::visit(NodeNumber* node) {
    std::cout << node->value;
}

void PrintVisitor::visit(NodeVarRef* node) {
    std::cout << node->varName;  // Print the variable name
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

void PrintVisitor::visit(NodeMinus* node) {
    std::cout << "(";
    node->left->accept(this);
    std::cout << " - ";
    node->right->accept(this);
    std::cout << ")";
}

void PrintVisitor::visit(NodeMultiply* node) {
    std::cout << "(";
    node->left->accept(this);
    std::cout << " * ";
    node->right->accept(this);
    std::cout << ")";
}

void PrintVisitor::visit(NodeDivide* node) {
    std::cout << "(";
    node->left->accept(this);
    std::cout << " / ";
    node->right->accept(this);
    std::cout << ")";
}

void PrintVisitor::visit(NodePower* node) {
    std::cout << "(";
    node->left->accept(this);
    std::cout << " ^ ";
    node->right->accept(this);
    std::cout << ")";
}
