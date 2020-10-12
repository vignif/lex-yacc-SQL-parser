# SQL parser with LEX / YACC
Simple parser for sql standard language, project made for Language Processing Technologies @diism University of Siena.
This project presents a really simple parser for SQL language, with limited use cases and tokens supported.
It's made for academic purposes and learning purposes, feel free to dig into the details of the **rules** and **definitions** in the source code.
The compiled version of the program is also provided.

![logo](https://foss.unh.edu/projects/images/c/c8/Lex_Yacc.JPG)


An exensive description of the project is presented in: **lex_yacc_project.pdf**

## Statement of the problem

```
Using lex/yacc implement a parser for the select SQL statement.
The syntax of the command is

select col1, col2,… from tab1, tab2,.. where cond

where the column (col1, col2,…) and table (tab1, tab2,..) names
have the usual structure of identifiers (alphanumeric strings
beginning with a letter) and cond is the condition that
is written by combining terms

col op col
col op const

using the connectors and, or. col is a name of a column, const is a constant
and op is a comparison operator among <, >, =. For instance

select serial, name, salary from employees, salaries where serial = code and
name = john and salary > 1000

In the code just print the matched terms.

```

# How to use
There are two steps in compiling a Lex source program. First, the Lex source must be turned into a generated program in the host general purpose language. Then this program must be compiled and loaded, usually with a library of Lex subroutines.



## Compile the executable in your machine

I've been using a linux distribution for this project, so make sure you have **yacc** and **lex** installed.

```
sudo apt-get update
sudo apt-get install bison
sudo apt-get install flex
```


Now you can build the executable for your own SQL parser with:

```
yacc -d --verbose sql.y
lex sql.l
gcc lex.yy.c y.tab.c utils.c -o sql -ll -ly -w
```
The executable is created in **./sql**. Make sure the file can be executed with `chmod +x ./sql`.

The file `text.txt` defines line per line some dumb sql queries to be tested with your brand new parser.

```
./sql <test.txt
```

## Use directly the executable

Alternatively you can also try directly the executable without compiling it on your machine.

The file `text.txt` defines line per line some dumb sql queries to be tested with your brand new parser.

```
./sql <test.txt
```

