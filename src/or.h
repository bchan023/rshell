#ifndef OR_H
#define OR_H
#include <stack>
#include "connector.h"

class Or: public Connector{
    public:
        Or();
        Or(Base *left);
        ~Or();
        
        //from and and assn3
        
        void fetch_name ();
        void add_right(Base *right);
        void add_left(Base *left);
        void execute();
        void execute(int &status,int pipes[],bool In,bool Out, int &size);
        void toStack(std::stack <Base*> &stacker);
};

#endif
