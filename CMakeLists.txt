cmake_minimum_required(VERSION 3.25)

project(MultiplicativePersistence)

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")

set(PROJECT_NAME MultiplicativePersistence)

set(IMGUI_FILES
        imgui/imconfig.h
        imgui/imgui.cpp
        imgui/imgui.h
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_internal.h
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imstb_rectpack.h
        imgui/imstb_textedit.h
        imgui/imstb_truetype.h
        imgui/backends/imgui_impl_glfw.cpp
        imgui/backends/imgui_impl_glfw.h
        imgui/backends/imgui_impl_opengl3.cpp
        imgui/backends/imgui_impl_opengl3.h
)

add_executable(${PROJECT_NAME}
        src/main.cpp
        ${IMGUI_FILES}
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

include_directories( ${OPENGL_INCLUDE_DIRS} )

add_subdirectory( glfw )

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/imgui
        ${PROJECT_SOURCE_DIR}/imgui/backends
        ${PROJECT_SOURCE_DIR}/glfw/include/GLFW
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        opengl32
        glfw
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