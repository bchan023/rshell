#!/bin/sh
./bin/rshell
echo exit test1
test -e exit; ls -l
[ exit ]
test -e ./nofile && exit
ls && echo foobar || exit
echo foobar && exit && echo foobar
echo should not echo