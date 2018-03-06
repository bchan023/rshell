#include "command.hh"

#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>


using namespace std;

void Command::execute () {
    struct stat buf;
    
    if(strcmp(argArr[0], "exit") == 0){
        exit(0);
    }
    
    if(testType == false){
        pass = false;
        pid_t pid = fork();
    
        if (pid < 0) {                                          
               perror("Fork() failed.");
           }
        else if (pid == 0) {
            if (execvp(argArr[0], argArr) == -1) {
              perror("Command Error.");
            }
            exit(0);
        }
        else {
            while(wait(0) != pid);
            pass = true;
        }
    } else {
    
        if(arguments.size() > 2) {
   
            string s = arguments.at(2);
            char* uI = new char[arguments.at(2).size() + 1];
            strcpy(uI, s.c_str());
      
            if(stat(uI, &buf) == -1){
	
                cout << "(FALSE)" << endl;
                cout << "Path not found" << endl;     
            } else {
		
                if((arguments.at(1) == "-f") && ((buf.st_mode & S_IFMT) == S_IFREG)){
                    cout << "(TRUE)" << endl;
                    pass = true;
                } else if((arguments.at(1) == "-d") && ((buf.st_mode & S_IFMT) == S_IFDIR)) {
                    cout << "(TRUE)" << endl;
                    pass = true;
                } else if((arguments.at(1) == "-e") && (((buf.st_mode & S_IFMT) == S_IFDIR) || ((buf.st_mode & S_IFMT) == S_IFREG))) {
                    cout << "(TRUE)" << endl;
                    pass = true;
                } else {
                    cout << "(FALSE)" << endl;
                }
            }
        } else {
            cout << "(FALSE)" << endl;
            cout << "Incorrect Syntax" << endl;
        }    
    }
}


void Command::setInput(string input) {
    userInput = input;
}


void Command::parse() {
    
    if (userInput.size() < 1) {
        return;
    }
    
    unsigned int itrArr = 0;
    
    size_t begin = userInput.find_first_not_of(" ");
    size_t end = userInput.find_last_not_of(" ");
    size_t size = end - begin + 1;
    
    userInput = userInput.substr(begin, size);
    
    char* cstrUserInput = new char [userInput.length() + 1];
    strcpy(cstrUserInput, userInput.c_str());
    char* token = strtok(cstrUserInput, " ");
    
    while (token != NULL) {
        arguments.push_back(token);
        argArr[itrArr] = token;
        token = strtok(NULL,  " ");
        itrArr++;
    }

    unsigned int i = 0;
    end = arguments.at(i).find('[');
    
    if(arguments.at(i) == "test"){
        testType = true;
  
    }
    else if(end != std::string::npos){
        i = arguments.size() - 1;
        end = arguments.at(i).find(']');
        
        if(end != std::string::npos){
            testType = true;
       
        }
        else {
            testType = false;
          
        }
    }
    else {
        testType = false;

    }

    return;
}


void Command::printInput() {
    cout << "Command::printInput(): " << userInput << endl;
}


void Command::printArgs() {
    for (unsigned int i = 0; i < arguments.size(); i++) {
        cout << "Command::printArgs(): " << arguments.at(i) << endl;
    }
    return;
}


string Command::getInput() {
    return userInput;
}


vector<string> Command::getArgs() {
    return arguments;
}


char ** Command::getArr() {
    return argArr;
}


void Command::passed() {
    pass = true;
    return;
}

void Command::failed() {
    pass = false;
    return;
}


bool Command::getPass() {
    return pass;
}

bool Command::isTest() {
    return testType;
}