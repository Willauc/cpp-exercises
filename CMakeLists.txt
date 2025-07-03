cmake_minimum_required(VERSION 3.10)
project(cpp_exercises)

set(CMAKE_CXX_STANDARD 17)


add_executable(main
        main.cpp
        src/affichage_matrice.cpp
        src/structure_donnee/array/My_Array.cpp
        src/structure_donnee/link_list/Link_List.cpp

)

enable_testing()
add_subdirectory(extern/googletest)
add_subdirectory(tests)
