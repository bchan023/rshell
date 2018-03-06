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


void RShellContainer::getInput(string input) {
    userInput = input;
    return;
}


void RShellContainer::addCommand(Command * command) {
    Commands.push_back(command);
    return;
}


void RShellContainer::addConnector(Connector * connect) {
    Connectors.push_back(connect);
    return;
}



void RShellContainer::parse() {
    string tempStr;                                                            
    
    if (userInput.length() == 0) {                                            
        return;
    }
    
    char* cstrUserInput = new char [userInput.length() + 1];                   
    strcpy(cstrUserInput, userInput.c_str());                                   
    
    char* token = strtok(cstrUserInput, ";|&#");                               
    
    while (token != NULL) {                                                    
        addCommand(new Command(token));                                        
        token = strtok(NULL, ";|&#");
    }
    
    unsigned itr = 0;
    bool mult = false;                                                         
    while (itr < userInput.length()) {
        if ((itr + 1) >= userInput.length()) {}
        else if (userInput[itr] == ';' && !mult) {
            addConnector(new Connector(";"));
            mult = true;
        }
        else if (userInput[itr] == '#' && !mult) {
            addConnector(new Connector("#"));
            mult = true;
        }
        else if (userInput[itr] == '|' && userInput[itr + 1] == '|' && !mult) {
            addConnector(new Connector("||"));
            mult = true;
        }
        else if (userInput[itr] == '&' && userInput[itr + 1] == '&' && !mult) {
            addConnector(new Connector("&&"));
            mult = true;
        }
        else if (userInput[itr] != ' ' && userInput[itr] != ';' && 
                 userInput[itr] != '#' && userInput[itr] != '|' && 
                 userInput[itr] != '&') {
            mult = false;
        }
        else {}
        
        itr++;
    }
    
    if ((Commands.size() - Connectors.size()) != 1) {                           
        perror("Error: Incorrect number of commands to connects.\n");
    }
    
    for (unsigned int i = 0; i < Commands.size(); i++) {                       
        Commands.at(i)->parse();
    }
    
    return;
}

void RShellContainer::execute() {                                               
    if (Commands.size() == 0) {                                                 
        return;                                                                
    }
    
    pass = true;                                                       
    
    for (unsigned i = 0; i < Commands.size(); i++) {
        
        
        if (pass) {
            Commands.at(i)->execute();
            
        }
        
        
        if (Connectors.size() > i) {
            if (Connectors.at(i)->getType() == ";") {
                pass = true;
            }
            else if (Connectors.at(i)->getType() == "#") {
                return;
            }
            else if (Connectors.at(i)->getType() == "&&") {
                if (Commands.at(i)->getPass()) {
                    pass = true;
                }
                else {
                    pass = false;
                }
            }
            else if (Connectors.at(i)->getType() == "&&") {
                if (Commands.at(i)->getPass()) {
                    pass = false;
                }
                else {
                    pass = true;
                }
            }
        }
    }
}


void RShellContainer::clear() {
    Commands.clear();
    Connectors.clear();
    return;
}


void RShellContainer::printInput() {
    cout << "RShellContainer::PrintInput(): " << userInput << endl;
}


void RShellContainer::printCommandsInput() {
    cout << "RShellContainer::PrintCommandsInput(): " << endl;
    
    if (Commands.size() < 1) {
        return;
    }
    
    for (unsigned int i = 0; i < Commands.size(); i++) {
        Commands.at(i)->printInput();
    }
    return;
}


void RShellContainer::printConnectors() {
    cout << "RShellContainer::PrintConnectors(): " << endl;
    
    if (Connectors.size() < 1) {
        return;
    }
    
    for (unsigned int i = 0; i < Connectors.size(); i++) {
        Connectors.at(i)->printInput();
    }
}


void RShellContainer::printCommandsArgs() {
    cout << "RShellContainer::PrintCommandsArgs(): " << endl;
    
    if (Commands.size() < 1) {
        return;
    }
    
    for (unsigned int i = 0; i < Commands.size(); i++) {
        Commands.at(i)->printArgs();
    }
    return;
}

bool RShellContainer::getPass() {
    return pass;
}