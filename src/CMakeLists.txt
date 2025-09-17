cmake_minimum_required(VERSION 3.10)
project(Mage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Find LLVM ---
set(LLVM_DIR "mage\\external\\llvm-project\\libc\\CMakeLists.txt") # Adjust this path

if (NOT DEFINED LLVM_DIR)
    find_package(LLVM REQUIRED CONFIG)
endif()

message(STATUS "Found LLVM ${LLVM_VERSION}")
message(STATUS "LLVM include directory: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM library directory: ${LLVM_LIBRARY_DIRS}")

# Add your source files
add_executable(mage
    ./main.cpp
    # src/ast.cpp
    # src/ir_generator.cpp
)

# Include LLVM headers
target_include_directories(mage PRIVATE
    ${LLVM_INCLUDE_DIRS}    
)

# Link LLVM libraries
target_link_libraries(mage PRIVATE
    LLVMIRReader
    LLVMIRWriter
    LLVMAsmParser
    LLVMCore
    LLVMTarget
    LLVMExecutionEngine
    LLVMLTO
    LLVMMCJIT
    LLVMOrcJIT
    LLVMTransformUtils
    LLVMAnalysis
    LLVMBitWriter
    LLVMSupport
    LLVMScalarOpts
    LLVMInstCombine
    LLVMPassBuilder
    LLVMLinker
    LLVMObject
    LLVMCodeGen
    LLVMX86CodeGen
    LLVMX86Desc
    LLVMX86Info
    LLVMX86AsmPrinter
    LLVMX86Disassembler
    # Add other LLVM libraries as needed for your specific features
    # (e.g., specific target code generators, analysis passes)
)