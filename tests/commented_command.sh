#!/bin/sh
./bin/rshell
echo this should echo # and this should not
ls -l; ls # -l; ls -l
ls && echo foobar #asdf
ls && echo foobar#asdf
test -e /etc/#asdfas
# echo should not echo
 # echo should not echo
ls && echo foobar #asdf
test -e /etc/#adfadsf
exit #adsf