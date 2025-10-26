#cmake最低版本号
cmake_minimum_required(VERSION 3.10)

#项目名字
project(jiami)

#搜索源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
add_executable(CryptoTool ${SRC})

#帮助找到头文件
target_include_directories(CryptoTool PRIVATE ${PROJECT_SOURCE_DIR}/include)
