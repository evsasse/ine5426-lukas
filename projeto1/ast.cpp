#include <iostream>

#include "ast.h"

extern void yyerror(const char*);

void IntegerNode::print(){
  //std::cout << "IntegerNode{";
  std::cout << " " << value;
  //std::cout << "}";
}
void FloatNode::print(){
  std::cout << " " << as_declared;
}
void BoolNode::print(){
  std::cout << " ";
  if(value)
    std::cout << "true";
  else
    std::cout << "false";
}

BinaryOperationNode::BinaryOperationNode(Node *left, Operation operation, Node *right) :
Node(left->type), left(left), operation(operation), right(right) {
  if(operation == GREATER || operation == GREATEROREQUAL || operation == LESS || operation == LESSOREQUAL){
    //relational operation
    Node::type = BOOL;
    if((left->type != INT && left->type != FLOAT)||((right->type != INT && right->type != FLOAT))){
      yyerror("semantic error: relational operation expected int or float but received");
    }
  }
  else if(operation == EQUAL || operation == DIFFERENT){
    //comparison operation
    Node::type = BOOL;
    if(left->type != right->type){
      yyerror("semantic error: comparison operation expected but received");
    }
  }
  else if(operation == PLUS || operation == MINUS || operation == TIMES || operation == DIVIDE){
    //math operations
    if(left->type == FLOAT || right->type == FLOAT){
      Node::type = FLOAT;
    }
    if((left->type != INT && left->type != FLOAT)||((right->type != INT && right->type != FLOAT))){
      yyerror("semantic error: math operation expected int or float but received");
    }
  }
  else if(operation == ATTRIB){
    //attribution operation
    if(left->type != right->type){
      yyerror("semantic error: attribution operation expected but received");
    }
  }
  else if(operation == AND || operation == OR){
    //logical operations
    Node::type = BOOL;
    if(left->type != BOOL || right->type != BOOL){
      yyerror("semantic error: logical operation expected bool but received");
    }
  }
};
void BinaryOperationNode::print(){
  //std::cout << "BinaryOperationNode{";
  //left->print();
  switch(operation){
    case PLUS: std::cout << " +"; break;
    case MINUS: std::cout << " -"; break;
    case TIMES: std::cout << " *"; break;
    case DIVIDE: std::cout << " /"; break;
    case ATTRIB: std::cout << "="; break;
    case AND: std::cout << " &"; break;
    case OR: std::cout << " |"; break;
    case EQUAL: std::cout << " =="; break;
    case DIFFERENT: std::cout << " !="; break;
    case GREATER: std::cout << " >"; break;
    case GREATEROREQUAL: std::cout << " >="; break;
    case LESS: std::cout << " <"; break;
    case LESSOREQUAL: std::cout << " <="; break;
  }
  left->print();
  right->print();
  //std::cout << "}";
}

UnaryOperationNode::UnaryOperationNode(Operation operation, Node *right) :
Node(right->type), operation(operation), right(right){
  if(operation == NEGATIVE && type != INT && type != FLOAT){
    Node::type = INT;
    yyerror("semantic error: negative operation expected integer or float but received bool");
  }
  else if(operation == NOT && type != BOOL){
    Node::type = BOOL;
    yyerror("semantic error: not operation expected bool but received");
  }
};
void UnaryOperationNode::print(){
  //std::cout << " -u";
  switch(operation){
    case NEGATIVE: std::cout << " -u"; break;
    case NOT: std::cout << " !"; break;
  }
  right->print();
}

void IdentifierNode::print(){
  //std::cout << "IdentifierNode{";
  std::cout << " " << name;
  //std::cout << name;
  //std::cout << "}";
}

void MainDeclarationNode::print(){
  switch(type){
    case INT: std::cout << "int var:"; break;
    case FLOAT: std::cout << "float var:"; break;
    case BOOL: std::cout << "bool var:"; break;
  }
  first->print();
}

DeclarationNode::DeclarationNode(IdentifierNode* identifier, Node *value, DeclarationNode *next) :
identifier(identifier), value(value), next(next) {
  if(value && value->type != identifier->type)
    yyerror("semantic error: type expected at declaration different from received");
};
void DeclarationNode::print(){
  identifier->print();
  if(value){
    std::cout << " =";
    value->print();
  }
  if(next){
    std::cout << ",";
    next->print();
  }
}