cmake_minimum_required(VERSION 3.5)

project(ponyKA_pick_and_throw)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(behaviortree_cpp_v3)

add_executable(${PROJECT_NAME} 
    "main.cpp"
    "moveTo.cpp"
    "graspObject.cpp"
    "openDoor.cpp"
    "switchHands.cpp"
    "throwObject.cpp"
    "isDoorOpen.cpp"
    "isObjectAtHand.cpp"
    "simpleMotion.cpp"
)
target_link_libraries(${PROJECT_NAME} BT::behaviortree_cpp_v3)

add_executable(hello_BT "example.cpp")
target_link_libraries(hello_BT BT::behaviortree_cpp_v3)