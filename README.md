# Car Board Game
My solution for RMIT Advanced Programming Techniques assignment 1. Written in ANSI C.

### Rules
- A car can move  around inside a board
- The player can move the car by entering a set of specific commands
- The car must stay within the board boundaries and must not hit the roadblocks

### How to run
- Make sure your machine has <code>gcc</code> installed and <var>configured</var> properly. Check gcc using <code>gcc --version</code>.
- <code>cd</code> to this folder.
- Compile <code>carboard.c</code> using <code>gcc -ansi -pedantic -Wall carboard.c -o carboard</code>.
- Run the compiled output using <code>.\carboard</code>
- One liner: &nbsp; <code>gcc -ansi -pedantic -Wall carboard.c -o carboard && .\carboard</code>
- Powershell: &nbsp; <code>gcc -ansi -pedantic -Wall carboard.c -o carboard ; .\carboard</code>

### VSCode CodeRunner
If you are using VSCode, you can use VSCode CodeRunner extension to run this project. 
CodeRunner settings lives inside <code>./.vscode/settings.json</code>
- Open <code>carboard.c</code>
- Right-click anywhere then choose <var>'Run code'</var>. 

### VSCode setup and Intellisense
- You will need the C/C++ and CodeRunner extensions.
- My VSCode setup will most likely to be different than yours.
- To fix intellisense issues, you have to tweak <code>./.vscode/c_cpp_properties.json</code>
- Make sure you are modifying the right JSON settings. 
    - If you are using Windows, modify the settings under <code>"name": "Win32"</code>
    - If you are using Mac, modify the settings under <code>"name": "Mac"</code>
    - If you are using Linux, modify the settings under <code>"name": "Linux"</code>
- Modify <var>includePath</var> and <var>browse.path</var> to point to your gcc's include paths.
- GCC Include paths can be retrieved using this command <code>gcc -v -E -x c -</code>. Look for folder names below this line: <pre>"#include <...> search starts here:"</pre>
