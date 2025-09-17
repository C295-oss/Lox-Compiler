
/* Prologue */
%require "3.2"
%language "c++"

%{
    #include <iostream>
    #include <vector>
    #include <string>
%}



%% /* Grammar rules and actions */






declaration ->          classDecl
                        | funDecl
                        | varDecl
                        | statement ;

classDecl ->            "class" identifier ( )
