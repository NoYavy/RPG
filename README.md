# RPG
This is a simple RPG to get into C++

## to install
1. Follow the instructions [here](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/intro.html#WHERETOGETIT)
2. build and compile with ```g++ main.cpp Player.cpp Room.cpp Interactable.cpp Text.cpp Item.cpp Portal.cpp -o main.out -lncurses```
3. run with ``./main.out``

## possible errors and fixes
| Problem | Solution |
| --- | --- |
| ```error opening terminal: xterm-256color``` | ```export TERMINFO=/lib/terminfo``` <br> ```export TERM=xterm``` |
