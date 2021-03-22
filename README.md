# Google Code Jam 2019

This repository contains my solutions to the problems from [Google Code Jam 2019][1] and Distributed Google Code Jam 2019. These solutions are provided "as is" - I give no guarantees that they will work as expected.

## Instructions

You can compile all Google Code Jam problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

Distributed Google Code Jam problems should be compiled and run using the local testing tool described in the [guide][2]. An example would be:

    $ dcj test --source <round_name>/<problem_id>.cpp --nodes <number_of_nodes>

You'll need to have an input header file with the name `<problem_id>.h` in the same directory as the source file. You can download sample inputs from each problem's page.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for the problem's limits.

### Qualification Round

* ✓ [A. Foregone Solution][qual1] (`foregone-solution`)
* ✓ [B. You Can Go Your Own Way][qual2] (`you-can-go-your-own-way`)
* ✓ [C. Cryptopangrams][qual3] (`cryptopangrams`)
* ✓ [D. Dat Bae][qual4] (`dat-bae`)

### Round 1A

* ✓ [B. Golf Gophers][round1a2] (`golf-gophers`)
* ✓ [C. Alien Rhyme][round1a3] (`alien-rhyme`)

### Round 1B

* ✓ [A. Manhattan Crepe Cart][round1b1] (`manhattan-crepe-cart`)
* ✗ [C. Fair Fight][round1b3] (`fair-fight`)

### Round 1C

* ✓ [A. Robot Programming Strategy][round1c1] (`robot-programming-strategy`)

[1]: https://codingcompetitions.withgoogle.com/codejam
[2]: https://code.google.com/codejam/resources/quickstart-guide#dcj
[qual1]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/0000000000088231
[qual2]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da
[qual3]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/000000000008830b
[qual4]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881de
[round1a2]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051635/0000000000104f1a
[round1a3]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051635/0000000000104e05
[round1b1]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051706/000000000012295c
[round1b3]: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051706/0000000000122838
[round1c1]: https://codingcompetitions.withgoogle.com/codejam/round/00000000000516b9/0000000000134c90
