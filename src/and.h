#ifndef AND_H
#define AND_H

#include "connector.h"
#include <stack>

class And : public Connector {
    public:
    And();
    And(Base *left);
    ~And();
    
    //functions
    void fetch_name();
 
    void execute(int &status,int pipes[],bool In,bool Out, int &size);
    void execute();
       void add_left(Base *left);
    void add_right(Base *right);
    void toStack(std::stack <Base*> &stacker);
};
#endif
