
add_executable(tests
        test_my_array.cpp
        ../src/structure_donnee/array/My_Array.cpp
        ../src/structure_donnee/link_list/Link_List.h
        test_link_list.cpp
        test_stack.cpp
        ArrayQueueTest.cpp
        StackQueueTest.cpp
        PriorityQueueTest.cpp
        HashTableLLTest.cpp
        ../src/structure_donnee/hash_table/HashTableLL.cpp
        TreeTest.cpp
        ../src/structure_donnee/tree/Tree.cpp
        ../src/structure_donnee/tree/AVLTree.cpp
        ../src/structure_donnee/tree/AVLTree.h
        AVLTreeTest.cpp

)

target_link_libraries(tests
        gtest
        gtest_main
        pthread
)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)


add_test(NAME MyStructureDonneeTest COMMAND tests)
