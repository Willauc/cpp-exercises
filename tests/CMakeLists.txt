add_executable(tests
        test_my_array.cpp
        ../src/structure_donnee/My_Array.cpp
)

target_link_libraries(tests
        gtest
        gtest_main
        pthread
)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)


add_test(NAME MyArrayTest COMMAND tests)
