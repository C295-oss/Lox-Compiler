This is a long term project that I wish to work on. The goal of it is to get familiar with the tools commonly used 
to build compilers, gain a deeper understanding of how languages work under the hood, and to have fun with the project. 

I started project in early August. Wrote a Scanner and then was in the middle of writting a handwritten recursive descent parser.

Now, I am now using GNU Bison -- a parser generator. The AST will then be translated into LLVM IR. This is both to learn 
industry standard tools and due to time constraints from both school and a previous internship. 

The reason for the switch up is because of time, and because I am learning about parser generators in a compiler design class and
really wanted to try learning a bit ahead of time and because it sounded interesting to use.

When deciding to learn LLVM, what piqued my interest initially was its prevalence and because
rust is compiled using LLVM IR. There are other reasons as well, such as it's modularity and optimizations that
it preforms before the toy language is translated into machine code. I'm learning LLVM on my own.
