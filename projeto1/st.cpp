#include "st.h"

extern void yyerror(const char*);

IdentifierNode* SymbolTable::newSymbol(std::string name, ValueType type, Node* value, ListNode *params){
  if(table.find(name) != table.end()){
    if(table[name]->params){ // function
      if(!table[name]->value && value){ // undefined function
        table[name]->value = value;
        table[name]->params = params;
      }else{
        yyerror("semantic error: re-declaration of function");
      }
    }else yyerror("semantic error: re-declaration of variable");
  }else{
    table[name] = new IdentifierNode(name,type,value,params);
  }
  return table[name];
}

IdentifierNode* SymbolTable::useSymbol(std::string name){
  if(!previous && table.find(name) == table.end()){
    yyerror("semantic error: undeclared variable");
    return nullptr;
  } else if(table.find(name) == table.end()){
    return previous->useSymbol(name);
  }else{
    return table[name];
  }
}

SymbolTable* SymbolTable::endScope(){
  for(auto pair : table){
    IdentifierNode* node = pair.second;
    if(node->params && !node->value){ // undefined function
      yyerror(("semantic error: function "+node->name+" is declared but never defined").c_str());
    }
  }
  return previous;
}
