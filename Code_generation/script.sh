#!/bin/bash

# Compile yacc file
yacc -d threeac.y

# Compile lex file
lex threeac.l

# Compile yacc and lex output files
cc y.tab.c lex.yy.c -o parser -ll

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Run './parser' to execute the parser."
else
    echo "Compilation failed."
fi

