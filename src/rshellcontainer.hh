#ifndef rshellcontainer_hh
#define rshellcontainer_hh

#include "rshellcontainer.hh"
#include "command.hh"
#include "connector.hh"
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

class RShellContainer: public RShellBase {
	protected:
	    	string userInput;
		vector<Command*> Commands;
		vector<Connector*> Connectors;
		bool pass;
	public:
	    	RShellContainer() {
	    	    
	    	};
	    	void parse();
	    	void getInput(string input);
		void execute();
		void addCommand(Command * command);
		void addConnector(Connector * connect);
		void clear();
		void printInput();
		void printCommandsInput();
		void printConnectors();
		void printCommandsArgs();
		bool getPass();
};

#endif