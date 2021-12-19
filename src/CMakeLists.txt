set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h)

add_executable(GTKMM_Cryptographer ${SOURCE_FILES})
link_directories(GTKMM_Cryptographer PRIVATE ${GTKMM_LIBRARY_DIRS})
include_directories(GTKMM_Cryptographer PRIVATE ${GTKMM_INCLUDE_DIRS})

target_link_libraries(GTKMM_Cryptographer PRIVATE ${GTKMM_LIBRARIES})
target_link_libraries(GTKMM_Cryptographer PRIVATE cryptopp-shared)