SET(SOURCE_FILES #设置变量，表示所有的源文件
main.cpp
FLTK.h
globalVal.cpp
globalVal.h
core/Mines.cpp
core/Mines.h
core/SweepInterface.cpp
core/SweepInterface.h
gui/GameObject.h
gui/gui.h
gui/GameObject.cpp
gui/gui.cpp

)

INCLUDE_DIRECTORIES( #相关头文件的目录
${PROJECT_SOURCE_DIR}/src/include
${PROJECT_SOURCE_DIR}/src/core
${PROJECT_SOURCE_DIR}/src/gui
${PROJECT_SOURCE_DIR}/src/test
)

MESSAGE(STATUS "Path: ${PROJECT_SOURCE_DIR}") #打印相关消息消息

LINK_DIRECTORIES( #相关库文件的目录
${PROJECT_SOURCE_DIR}/src/lib#FLTK库文件
)

ADD_EXECUTABLE(MineSweeping ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(MineSweeping
fltk
fltk_forms
fltk_images
fltk_jpeg
fltk_png
)
