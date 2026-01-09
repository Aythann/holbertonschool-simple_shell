# Simple Shell Project

## Description

This project consists of building a **simple shell in C**, capable of executing commands similarly to a basic Unix shell.
The program works in both **interactive** and **non-interactive** modes, handles built-in commands (builtins), environment variables, and command execution using the PATH.

The goal of this project is to understand how a shell works internally: process creation, command parsing, environment handling, and execution with execve.


## Features

The shell supports the following features:

- Display of a prompt `($)` in interactive mode
- Reading user input using getline
- Parsing command lines into arguments
- Command execution:
  - using absolute or relative paths
  - using the PATH environment variable
- Built-in commands:
  - exit
  - env
  - cd
  - setenv
  - unsetenv
- Environment variable access and modification (environ)
- Proper memory management (Valgrind compliant)


## Compilation

Compile the project using the following command:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Run the shell with:

    ./hsh


## Usage Examples

### Interactive mode

    $ ./hsh
    ($) ls
    ($) pwd
    ($) cd ..
    ($) env
    ($) exit

### Non-interactive mode

    echo "ls -l" | ./hsh


## Built-in Commands

| Command | Description |
|--------|-------------|
| exit [status] | Exit the shell with an optional status code |
| env | Display the current environment |
| cd [directory] | Change the current directory |
| setenv NAME VALUE | Set or modify an environment variable |
| unsetenv NAME | Remove an environment variable |


## File Structure

| File | Description |
|------|------------|
| shell.h | Header file containing prototypes and structures |
| main.c | Main shell loop |
| execute.c | Command execution logic |
| builtins.c | Built-in command implementations |
| env.c | Environment variable management |
| parser.c | Command line parsing |
| path.c | PATH handling and command lookup |
| string_utils.c | String utility functions |
| utils.c | Basic utility functions (_puts, _strlen, etc.) |


## How It Works

1. The shell displays a prompt if running in interactive mode
2. It reads input from standard input using getline
3. The input line is parsed into arguments
4. The shell checks if the command is a built-in
5. If not:
   - it tries to execute the command directly
   - then searches for it in the PATH
6. A new process is created using fork
7. The command is executed with execve
8. The parent process waits for execution to finish


## Testing

The project was tested using:

- GCC
  - -Wall
  - -Werror
  - -Wextra
  - -pedantic
  - -std=gnu89
- Valgrind for memory leak detection
- Interactive and non-interactive execution tests


## Technical Constraints

- Code written in C
- Edited using vi, vim, or emacs
- Compiled on Ubuntu 20.04 LTS
- Strict compilation rules enforced

## Authors

Project created by:

- Aythan Cristovao
- Killian Le Boulzec
