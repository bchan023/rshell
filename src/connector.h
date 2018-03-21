#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <stack>
#include "base.h"

class Connector: public Base{
    public:
        ~Connector(){}
        //abstract connector class
        virtual void fetch_name () = 0;
        virtual void execute(int &status,int pipes[],bool In,bool Out ,int &size) = 0;
        virtual void execute() = 0;
        virtual void add_left(Base*)= 0;
        virtual void add_right(Base*) = 0;
        virtual void toStack(std::stack <Base*> &stacker) = 0;
};
#endif
