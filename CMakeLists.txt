cmake_minimum_required(VERSION 3.10)
project(cpp_exercises)

set(CMAKE_CXX_STANDARD 17)


add_executable(main
        main.cpp
        src/affichage_matrice.cpp
        src/structure_donnee/My_Array.cpp
        src/structure_donnee/My_Array.h

)

enable_testing()
add_subdirectory(extern/googletest)
add_subdirectory(tests)
