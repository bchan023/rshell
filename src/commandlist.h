#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include <boost/tokenizer.hpp>
#include <vector>
#include <stack>

#include "command.h"
#include "or.h"
#include "and.h"
#include "pipein.h"
#include "pipeout.h"
#include "redirect.h"

using namespace boost;

class CommandList: public Base{
    private:
        Base* build(Base*, Base*);
        Base* splitBuild(std::vector<Base*> &userInputs);
        std::vector<Base*> Actions;
        std::string colonget(std::string input,bool &endPar);
        std::string paranthesesget(std::string input);
    public:
        CommandList(std::vector<std::string>& inputSplit, unsigned &cur,int layer, int &flag);
        ~CommandList();
        void execute(int &flag,int pipes[],bool In,bool Out,int &size);
        void execute();
        void add_left(Base*);
        void add_right(Base*);
        void fetch_name ();
        void toStack(std::stack <Base*> &stacker);
};
#endif

