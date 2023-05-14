###############################BASE INFORMATION###################################
cmake_minimum_required(VERSION 3.17.0)
project("raytracer" VERSION 0.1.0 LANGUAGES CXX)

###############################COMPILATION VARIABLES##############################
set(CMAKE_CXX_STANDARD 20)
set(NAME "raytracer")
set(TEST_NAME "unit_tests")
set(CXX_FLAGS -Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system)
###############################DIRECTORIES SRC####################################
set(SRC
    src/Math/Vector3D/Vector3D.cpp
    src/Math/Point3D/Point3D.cpp
    src/Math/Rectangle3D/Rectangle3D.cpp
    src/Math/Light/LightCalculation.cpp
    src/RayTracer/Ray/Ray.cpp
    src/RayTracer/Objects/AObjects.cpp
    src/RayTracer/Objects/Sphere/Sphere.cpp
    src/RayTracer/Objects/Plane/Plane.cpp
    src/RayTracer/Objects/Cone/Cone.cpp
    src/RayTracer/Light/AmbiantLight/AmbiantLight.cpp
    src/RayTracer/Light/DirectionalLight/DirectionalLight.cpp
    src/RayTracer/Light/PointLight/PointLight.cpp
    src/RayTracer/Camera/Camera.cpp
    src/RayTracer/Renderer/Renderer.cpp
    src/RayTracer/Viewer/Viewer.cpp
    src/Parser/Parser.cpp
    src/Parser/Parser.cpp
    src/Factory/Factory.cpp
)

set(MAIN
    src/main.cpp
)

set(TESTS
)

###############################COMPILATION MAIN PROGRAM###########################
add_compile_options(${CXX_FLAGS})
include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(${NAME} ${SRC} ${MAIN})
target_link_libraries(${NAME} config++ sfml-graphics sfml-window sfml-system)
add_custom_target(core
    COMMAND make ${NAME}
)

###############################COMPILATION TESTS##################################
find_library(CRITERION criterion)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
#create the tests executable
add_executable(${TEST_NAME} ${SRC} ${TESTS})
target_link_libraries(${TEST_NAME} sfml-graphics sfml-window sfml-system)
#link the tests with the criterion library
target_link_libraries(${TEST_NAME} ${CRITERION} config++)

###############################CUSTOM TARGETS#####################################
add_custom_target(fclean
    COMMAND make clean
    COMMAND find . -name "*~" -delete
    COMMAND find . -name "*.gcno" -delete
    COMMAND find . -name "*.gcda" -delete
    COMMAND find . -name "unit_test" -delete
    COMMAND find . -name "*.o" -delete
    COMMAND find . -name "*.so" -delete
    COMMAND find . -name "CMakeCache.txt" -delete
    COMMAND rm -rf CMakeFiles
    COMMAND find . -name "cmake_install.cmake" -delete
    COMMAND find . -name "Makefile" -delete
    COMMAND find . -name ${NAME} -delete
    COMMAND find . -name "*.a" -delete
    COMMAND find . -name "lib" -delete
    COMMENT "Clean the project and the binary"
)

#set the target to recompile the project
add_custom_target(re
    COMMAND make clean
    COMMAND make
    COMMENT "Recompiling the project"
)

#set the target to run the tests
add_custom_target(tests_run
    COMMAND make ${TEST_NAME}
    COMMAND ./${TEST_NAME}
    COMMENT "Running unit tests"
)
