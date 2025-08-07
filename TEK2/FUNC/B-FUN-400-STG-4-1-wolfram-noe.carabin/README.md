Wolfram Elementary Cellular Automaton
This project is an implementation of Wolfram’s elementary cellular automaton in Haskell. The code supports user-defined rules and provides a simple terminal-based visualization of the automaton’s evolution over multiple generations.

Overview
A cellular automaton consists of an infinite row of cells, each of which can be in one of two possible states (commonly 0 or 1). On each iteration, every cell updates its state depending on itself and its two neighbors (left and right). Wolfram’s elementary cellular automata are defined by a rule number between 0 and 255 (binary representation of 8 bits).

In this project, you can specify:

Which rule (e.g. Rule 30, Rule 90, Rule 110, or any integer 0–255).
How many lines (generations) to display.
The generation at which to start displaying.
The width of the display window per line.
A horizontal shift (move) to center or offset the displayed region.
Features
Multiple rules: The code can interpret any rule from 0 up to 255 (8-bit wide).

Infinite space: The automaton theoretically extends infinitely in both directions and downward.

Configurable parameters:

--rule <int>: Rule number (0–255). Mandatory.
--start <int>: Start generation index (0 by default).
--lines <int>: Number of generations to display (unbounded if not provided).
--window <int>: Width (in cells) for each line (default is 80).
--move <int>: Shift the displayed window left (negative) or right (positive) around the center (default is 0).
Pure Haskell design:

All major computations are done in pure functions; the only side effects are in main for argument parsing and printing.
Fast skipping:

Large --start values can be handled quickly by generating only as many lines as needed, using Haskell’s laziness to avoid storing every generation in memory.
Installation & Compilation
This project uses Stack (version 2.1.3 or higher recommended) to manage dependencies and compilation.
A Makefile is provided for convenience.

Clone or download this repository.

Build using:

bash
Copier
Modifier
make
This will invoke Stack commands to build the executable.

Run the compiled binary. For example:

bash
Copier
Modifier
./wolfram --rule 30 --start 10 --lines 20 --window 100 --move 5
Or use stack run directly:

bash
Copier
Modifier
stack run wolfram -- --rule 110 --start 2000 --lines 50
(Note the -- separator after stack run wolfram to pass arguments correctly.)

Usage Examples
Rule 30, display from the very first generation (start=0), 20 lines in total, 80 cells width, no horizontal shift:

bash
Copier
Modifier
./wolfram --rule 30 --start 0 --lines 20 --window 80 --move 0
Rule 110, skip the first 2000 generations, display 100 lines, use a 120-character window, centered:

bash
Copier
Modifier
./wolfram --rule 110 --start 2000 --lines 100 --window 120
Rule 90, infinite display (no --lines) until user terminates with Ctrl+C:

bash
Copier
Modifier
./wolfram --rule 90 --start 0 --window 80
Error Handling
If no arguments or invalid arguments are provided, the program displays an error message and exits with code 84.
For correct usage, the program exits 0 upon completion.
File Structure
Main.hs (or equivalent module) contains main and the argument parsing logic.
Additional Haskell modules implement the pure logic for:
Generating new lines of the automaton.
Converting rules to bit patterns.
Centering and formatting lines for terminal output.
stack.yaml and package.yaml define the Stack project.
Makefile orchestrates the build via Stack.
Contributing
If you wish to modify or extend the code:

Clone the repository.
Make changes to the Haskell source files.
Rebuild with make or stack build.
Test by running the examples above.
Feel free to explore new rules, add additional visualization options, or implement bonus features (e.g. reading initial states from stdin, generating bitmap outputs, or real-time graphical modes).

License
This project is released under the terms specified by its authors (EPITECH project context). See the associated project guidelines or contact the maintainers for more information.
