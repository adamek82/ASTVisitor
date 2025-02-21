// Visitor.h - Visitor Pattern Interface
#ifndef VISITOR_H
#define VISITOR_H

class NodeNumber;
class NodePlus;
class NodeAssign;

class Visitor {
public:
    virtual void visit(NodeNumber* node) = 0;
    virtual void visit(NodePlus* node) = 0;
    virtual void visit(NodeAssign* node) = 0;
    virtual ~Visitor() = default;
};

#endif // VISITOR_H