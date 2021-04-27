# competition_cpp
The workspace on VSCode for the C++ user coding in a programming competition

## directories
### [.vscode/](./.vscode/)
snippets  
### [archive/](./.vscode/)
written code
### [lib/](./lib/)
library for the programming competition
### [src/](./src/)
source files
### shell scripts
- [b.sh](./b.sh)
    build
- [br.sh](./br.sh)
    build and run
- [r.sh](./r.sh)
    run

## usage
1. code program in  
    - `src/{run1.cpp, ..., run6.cpp}`  

2. and use  
    - `./br.sh {$1: 1, ..., 6}`  
    to build and run program  
    - `./b.sh {$1: 1, ..., 6}`   
    to build program  
    - `./r.sh {$1: 1, ..., 6}`  
    to run compiled program  
