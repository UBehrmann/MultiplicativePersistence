cmake_minimum_required(VERSION 3.25)

project(MultiplicativePersistence)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(PROJECT_NAME MultiplicativePersistence)

# ImGui backend files (still need to compile these)
set(IMGUI_BACKEND_FILES
        imgui_backends/imgui_impl_glfw.cpp
        imgui_backends/imgui_impl_opengl3.cpp
)

add_executable(${PROJECT_NAME}
        src/main.cpp
        ${IMGUI_BACKEND_FILES}
        src/MP/MultiplicativePersistence.cpp
        src/MP/MultiplicativePersistence.h
        src/UI/ConsoleOuput/ConsoleOutput.cpp
        src/UI/ConsoleOuput/ConsoleOutput.h
        src/MP/MPType.h
        src/Data/DataManagement.cpp
        src/Data/DataManagement.h
        src/UI/UI.cpp
        src/UI/UI.h
        src/Libs/json/json.hpp
        src/Libs/json/json_util.h
        src/UI/UI.cpp
        src/UI/UI.h
        src/UI/Windows/ImguiWindow.h
        src/UI/Windows/MainWindow.cpp
        src/UI/Windows/MainWindow.h
        src/UI/Windows/MP_Window.cpp
        src/UI/Windows/MP_Window.h
)

#ImGui and GLFW integration
find_package( OpenGL REQUIRED )
find_package( glfw3 REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )

# ImGui library (manually installed)
find_library(IMGUI_LIBRARY imgui PATHS /usr/local/lib REQUIRED)
find_path(IMGUI_INCLUDE_DIR imgui.h PATHS /usr/local/include REQUIRED)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        ${IMGUI_INCLUDE_DIR}
        ${IMGUI_INCLUDE_DIR}/backends
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        OpenGL::GL
        glfw
        ${IMGUI_LIBRARY}
)

add_executable(
        MultiplicativePersistenceConsole
        src/cmdMain.cpp
        src/MP/MultiplicativePersistence.cpp
        src/MP/MultiplicativePersistence.h
        src/UI/ConsoleOuput/ConsoleOutput.cpp
        src/UI/ConsoleOuput/ConsoleOutput.h
        src/MP/MPType.h
        src/Data/DataManagement.cpp
        src/Data/DataManagement.h
)