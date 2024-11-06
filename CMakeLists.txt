cmake_minimum_required(VERSION 3.16)

project(student_linkedlist1 LANGUAGES C)

add_executable(student_linkedlist1 main.c)

include(GNUInstallDirs)
install(TARGETS student_linkedlist1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
