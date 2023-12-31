## S7CS1_CDLab

This repository contains programs done as part of Compiler Design Lab [CS1U48A].



###### Experiment 01 - Lexical Analyzer using DFA
Write a C program that works as a Lexical Analyzer. Run the below terminal commands from main repository location to run the code. Provide input C program in /Exp_01/inputFile.txt

```
cd Exp_01
gcc lexicalAnalyzer.c -o lexicalAnalyzer.out
./lexicalAnalyzer.out
```

<br>

###### Experiment 02 - Lexical Analyzer using LEX Tool
Use LEX tool to implement a lexical analyzer
2.1 - Lexical Analyzer using LEX tool
2.2 - Count number of words from a set of strings
2.3 - Get number of vovels in a string

Navigate to the folder where your program is, and use the following commands to use LEX tool.
```
lex <filename>.l
gcc lex.yy.c -ll
./a.out
```

<br>

###### Experiment 03 - Recursive Descend Parser
Write a C program to implement a recursive descend parser for the given language.

<br>

###### Experiment 04 - Shift Reduce Parser
Write a C program to implement a shift reduce parser for any given set of productions.

<br>

###### Experiment 05 - YACC
Use LEX and YACC tools to check if an expression is valid or not.
Use the following commands to run tools
```
yacc -d filename.y
lex filename.l
cc lex.yy.c y.tab.c -ll
./a.out
```

<br>

###### Experiment 06 - YACC
Use LEX and YACC tools to create a calculator

<br>

###### Experiment 07 - Intermediate Code Generation
Program to create intermediate 3 address code from given expression

<br>

###### Experiment 08 - First and Follow
Program to find First and Follow of a grammar