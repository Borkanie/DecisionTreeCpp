cmake_minimum_required(VERSION 3.22) # version can be different

project(DecisionTree) #name of your project
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0) #for g++ 5.1.0

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(main 
    main.cpp
    DecisionTree.h
    DecisionTree.cpp
    Node.h)

