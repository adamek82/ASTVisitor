// Visitor.h - Visitor Pattern Interface
#ifndef VISITOR_H
#define VISITOR_H

// Forward declarations for node types
class NodeNumber;
class NodeVarRef;
class NodePlus;
class NodeMinus;
class NodeMultiply;
class NodeDivide;
class NodeAssign;
class NodePower;

class Visitor {
public:
    virtual void visit(NodeNumber* node) = 0;
    virtual void visit(NodeVarRef* node) = 0;
    virtual void visit(NodePlus* node) = 0;
    virtual void visit(NodeMinus* node) = 0;
    virtual void visit(NodeMultiply* node) = 0;
    virtual void visit(NodeDivide* node) = 0;
    virtual void visit(NodePower* node) = 0;
    virtual void visit(NodeAssign* node) = 0;
    virtual ~Visitor() = default;
};

#endif // VISITOR_H
