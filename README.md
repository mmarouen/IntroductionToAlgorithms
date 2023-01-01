# Introduction to algorithms implementations and solutions
This book is a review and implementation of the famous book.\
All the content of the book is shared for educational purposes for the benefit of the readers.\
Please feel free to share or use :)
## Scope
The book is overreaching into several programming branches or disciplines: Complexity theory, runtime, algorithmic aspect..\
In this implementation, Im mainly focused on the "data science" aspect of the book.\
By this is meant solving the problem using different algorithms where each implementation  exploits a different paradigm but not necessarily focusing on the "optimal" runtime or complexity.
> For example, chapter 4 adresses matrix multiplication algorithms using mainly a direct method and several recursive methods.\
In the current implementation, one algorithms from each method is written.\
Additionally, the chapter also dives into the runtime and complexity of each method in detail. These aspect are skipped from the implementation.


## Content
Each chapter is associated with a `runnable` calling the algorithmic implementations.\
The user is of course free to add additional runnables.\
The repository is broken down into chapters where each contains the algorithms that were presented within.\
Whenever relevant a chapter exercice solutions are included as pdfs under the `exercices`folder.\
The table of content below links the `header` files associated with each chapter along with the relevant `runnable` and a brief description of the algorithms implemented.
Chapter | Runnable | Algorithms
--- | --- | --- |
[Chapter2](lib/include/algorithms/chap2.hpp) | [sorter](src/sort_algs.cpp) | - Insert sort algorithm<br>- Merge sort algorithm
[Chapter4](lib/include/algorithms/chap4.hpp) | [multiplier](src/multiply_matrices.cpp) | - Classical matrix multiplication<br>- Recursive matrix multiplication

## Prerequisites
- `c++`
- `CMake`

> **WARNING**: Implementation was tested on a Ubuntu 20 machine