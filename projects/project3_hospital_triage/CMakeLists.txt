cmake_minimum_required(VERSION 3.16)
project(project3_hospital_triage CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Main executable simulation
add_executable(hospital_triage
    src/vitals_cpu.cpp
    src/er_queue.cpp
    src/action_stack.cpp
    src/triage_controller.cpp
    src/main.cpp
)

# Automated self-test runner
add_executable(triage_test
    src/vitals_cpu.cpp
    src/er_queue.cpp
    src/action_stack.cpp
    src/test_runner.cpp
)
