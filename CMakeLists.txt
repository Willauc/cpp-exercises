cmake_minimum_required(VERSION 3.10)
project(cpp_exercises)

set(CMAKE_CXX_STANDARD 17)


add_executable(main
        main.cpp
        src/affichage_matrice.cpp
        src/structure_donnee/array/My_Array.cpp
        src/affichage_matrice.h
        src/structure_donnee/stack/Stack.h
        src/structure_donnee/stack/Expression.cpp
        src/structure_donnee/stack/Expression.h

)

enable_testing()
add_subdirectory(extern/googletest)
add_subdirectory(tests)
