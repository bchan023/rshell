# rshell
Assignment 4 CS100


# Programmers
Bryant Chang


# Features

Extend your rshell program so that it properly handles input redirection &lt;, output
redirection &gt; and &gt;&gt;, and piping |. This will require using the Unix functions dup and
pipe. You can find help on how to use these functions in the man pages.


As an example, after this assignment, your program should be able to successfully
handle the following command:
$ cat &lt; existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z
A-Z &gt; newOutputFile2

Allows Input and Output Redirection (<, >, >>) and piping (|)


 
# Run the program by:
1) git clone https://github.com/bchan023/rshell.git

2) cd rshell

3) git checkout inputRedirection

4) make

5) bin/rshell


# bugs
1) some cases of output redirection won't work, like echo hi > file1 > file 2.

2) piping issues when in combination of output redirection