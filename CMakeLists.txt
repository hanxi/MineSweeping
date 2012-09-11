CMAKE_MINIMUM_REQUIRED(VERSION 2.5.0) #cmake 最低版本要求，低于2.6 构建过程会被终止。

PROJECT(MineSweeping) #定义工程名称
MESSAGE(STATUS "Project: MineSweeping") #打印相关消息消息
MESSAGE(STATUS "Project Directory: ${PROJECT_SOURCE_DIR}")

ADD_SUBDIRECTORY(src bin) #添加子目录
ADD_SUBDIRECTORY(src/core bin) #添加子目录
ADD_SUBDIRECTORY(src/gui bin) #添加子目录
ADD_SUBDIRECTORY(src/test bin) #添加子目录

