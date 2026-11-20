cmake_minimum_required(VERSION 3.16)
project(HighSchool_CPP_Systems_Curriculum CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

# ==============================================================================
# Lessons 01 - 20 (Direct CLion Run Configurations)
# ==============================================================================
add_executable(lesson01_lexer lessons/01_lexical_analysis_and_parsing/example.cpp)
add_executable(lesson02_terminal lessons/02_terminal_compilation_and_comments/example.cpp)
add_executable(lesson03_git lessons/03_git_and_github_for_cpp/example.cpp)
add_executable(lesson04_optimization lessons/04_compiler_optimization_and_object_files/example.cpp)
add_executable(lesson05_linker lessons/05_linker_and_symbol_tables/example.cpp)
add_executable(lesson06_stack_heap lessons/06_os_execution_model_stack_vs_heap/example.cpp)

add_executable(lesson07_threads lessons/07_concurrency_and_multithreading_mechanics/example.cpp)
target_link_libraries(lesson07_threads PRIVATE Threads::Threads)

add_executable(lesson08_mutex lessons/08_thread_synchronization_and_mutex_lock/example.cpp)
target_link_libraries(lesson08_mutex PRIVATE Threads::Threads)

add_executable(lesson09_preprocessor lessons/09_basic_preprocessor_directives/example.cpp)
add_executable(lesson10_header_guards lessons/10_conditional_compilation_and_header_guards/example.cpp)
add_executable(lesson11_namespaces lessons/11_namespaces/example.cpp)
add_executable(lesson12_namespace_conflicts lessons/12_resolving_namespace_conflicts/example.cpp)
add_executable(lesson13_multi_file lessons/13_multi_file_project_architecture/example.cpp)
add_executable(lesson14_declarations lessons/14_separating_declarations_and_definitions/example.cpp)
add_executable(lesson15_third_party lessons/15_third_party_library_integration/example.cpp)
add_executable(lesson16_include_paths lessons/16_configuring_include_paths_in_ide/example.cpp)
add_executable(lesson17_fifo_queue lessons/17_data_structures_fifo_queues/example.cpp)
add_executable(lesson18_lifo_stack lessons/18_data_structures_lifo_stacks/example.cpp)
add_executable(lesson19_assembly lessons/19_assembly_fundamentals_registers_and_instructions/example.cpp)
add_executable(lesson20_makefiles lessons/20_automated_builds_and_makefiles/example.cpp)

# ==============================================================================
# Capstone Team Projects
# ==============================================================================
add_subdirectory(projects/project1_transit_gate)
add_subdirectory(projects/project2_warehouse_robot)
add_subdirectory(projects/project3_hospital_triage)
