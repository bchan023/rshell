#include <unistd.h>
#include <iostream>
#include "rshell.hh"
#include "rshellcontainer.hh"
#include "command.hh"
#include "connector.hh"

using namespace std;

int main() {
    string userInput;
    RShellContainer rshell;
    
    while (userInput != "exit") {
        cout << "rshell script $ ";                                             // rshell script
        getline(cin, userInput);                                                // get input
        
        if (userInput == "exit") {}                                             
        else {                                                                  
            rshell.getInput(userInput);
            rshell.parse();                                                     // parse input
            //rshell.execute();
            //rshell.printInput();
            //rshell.printCommandsInput();
            //rshell.printCommandsArgs();
            //rshell.printConnectors();
            rshell.execute();                                                   // evaluate based on input
            rshell.clear();                                                     // resets shell after executing
        }
    }
}