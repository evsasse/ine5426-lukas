#include "st.h"

extern void yyerror(const char*);

IdentifierNode* SymbolTable::newSymbol(std::string name, ValueType type, Node* value, ListNode *params){
  if(table.find(name) != table.end()){
    if(table[name]->params){ // existing function
      bool paramsAgree = table[name]->params->size() == params->size();
      if(paramsAgree){
        auto currentParam = table[name]->params->begin();
        auto newParam = params->begin();
        for(; newParam != params->end() && paramsAgree; currentParam++, newParam++)
          if(static_cast<IdentifierNode*>(*currentParam)->name != static_cast<IdentifierNode*>(*newParam)->name || (*currentParam)->type != (*newParam)->type)
            paramsAgree = !paramsAgree;
      }
      if(!table[name]->value && value && paramsAgree){ // undefined function
        table[name]->value = value;
        table[name]->params = params;
      }else{
        yyerror(("semantic error: re-definition of function "+name).c_str());
      }
    }else yyerror(("semantic error: re-declaration of variable "+name).c_str());
  }else{
    table[name] = new IdentifierNode(name,type,value,params);
  }
  return table[name];
}

IdentifierNode* SymbolTable::useSymbol(std::string name){
  if(!previous && table.find(name) == table.end()){
    yyerror(("semantic error: undeclared variable "+name).c_str());
    return new IdentifierNode(name, INT);
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
