cmake_minimum_required(VERSION 3.1...3.22)

project(
  TCPBBS
  VERSION 1.0
  LANGUAGES CXX)

  
  add_executable(tcpbbs main.cpp TcpServer.cpp TcpSession.cpp Screen.cpp TextElement.cpp)
  target_compile_features(tcpbbs PUBLIC cxx_std_17)
target_link_libraries( tcpbbs pthread )

