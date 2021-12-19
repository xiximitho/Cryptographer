set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h)

message(STATUS "----- GTKMM4_INCLUDE_DIRS: ${GTKMM_INCLUDE_DIRS}")
message(STATUS "----- GTKMM4_LIBRARIES: ${GTKMM_LIBRARIES}")
message(STATUS "----- GTKMM4_LINK_LIBRARIES: ${GTKMM_LINK_LIBRARIES}")

#install(FILES ${GTKMM_INCLUDE_DIRS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/gtkmm4)
add_executable(GTKMM_Cryptographer ${SOURCE_FILES})
link_directories(GTKMM_Cryptographer PRIVATE ${GTKMM_LIBRARY_DIRS})
include_directories(GTKMM_Cryptographer PRIVATE ${GTKMM_INCLUDE_DIRS})

target_link_libraries(GTKMM_Cryptographer PRIVATE ${GTKMM_LIBRARIES})
target_link_libraries(GTKMM_Cryptographer PRIVATE cryptopp-static)
install(TARGETS GTKMM_Cryptographer DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/gtkmm4)