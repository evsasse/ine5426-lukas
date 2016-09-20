#pragma once

#include <string>

enum Operation { NEGATIVE, NOT,
                 ATTRIB, PLUS, MINUS, TIMES, DIVIDE,
                 AND, OR, EQUAL, DIFFERENT, GREATER, GREATEROREQUAL,
                 LESS, LESSOREQUAL };
enum ValueType { INT, FLOAT, BOOL };

class Node {
public:
  ValueType type;
  virtual void print(){};
  Node(){};
protected:
  Node(ValueType type) :
    type(type) {};
};

class IntegerNode : public Node {
public:
  int value;
  IntegerNode(int value) :
    Node(INT), value(value) {};
  void print();
};
class FloatNode : public Node {
public:
  std::string as_declared;
  float value;
  FloatNode(std::string value) :
    Node(FLOAT), as_declared(value), value(std::stof(value)) {};
  void print();
};
class BoolNode : public Node {
public:
  bool value;
  BoolNode(bool value) :
    Node(BOOL), value(value) {};
  void print();
};

class BinaryOperationNode : public Node {
public:
  Operation operation;
  Node *left, *right;
  BinaryOperationNode(Node *left, Operation operation, Node *right);
  void print();
};
class UnaryOperationNode : public Node {
public:
  Operation operation;
  Node *right;
  UnaryOperationNode(Operation operation, Node *right);
  void print();
};

class IdentifierNode : public Node {
public:
  std::string name;
  IdentifierNode(std::string name, ValueType type) :
    Node(type), name(name) {};
  void print();
};

class DeclarationNode : public Node {
public:
  IdentifierNode *identifier;
  DeclarationNode *next;
  Node *value;
  DeclarationNode(IdentifierNode* identifier, Node* value = nullptr, DeclarationNode *next = nullptr);
  void print();
};
class MainDeclarationNode : public Node {
public:
  DeclarationNode *first;
  MainDeclarationNode(DeclarationNode *first, ValueType type) :
    Node(type), first(first) {};
  void print();
};