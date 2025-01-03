cmake_minimum_required(VERSION 3.1...3.14)

project(tempfile VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(TEMPFILE_TARGET_NAME ${PROJECT_NAME})

include(GNUInstallDirs)

set(TEMPFILE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/")
set(TEMPFILE_CONFIG_INSTALL_DIR "${CMAKE_INSTALL_DATADIR}/cmake/${PROJECT_NAME}/" CACHE INTERNAL "")
set(TEMPFILE_INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_INCLUDEDIR}/")
set(TEMPFILE_TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(TEMPFILE_CMAKE_CONFIG_DIR "${PROJECT_SOURCE_DIR}/cmake")
set(TEMPFILE_CMAKE_PROJECT_CONFIG_FILE "${TEMPFILE_CMAKE_CONFIG_DIR}/${PROJECT_NAME}Config.cmake")
set(TEMPFILE_CMAKE_PROJECT_TARGETS_FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")


add_library(${TEMPFILE_TARGET_NAME} INTERFACE)
target_include_directories(${TEMPFILE_TARGET_NAME} INTERFACE
    $<BUILD_INTERFACE:${TEMPFILE_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${TEMPFILE_INCLUDE_INSTALL_DIR}>
)

install(
    DIRECTORY ${TEMPFILE_INCLUDE_DIR}
    DESTINATION ${TEMPFILE_INCLUDE_INSTALL_DIR}
)

install(FILES ${TEMPFILE_CMAKE_PROJECT_CONFIG_FILE}
    DESTINATION ${TEMPFILE_CONFIG_INSTALL_DIR})

export(
    TARGETS ${TEMPFILE_TARGET_NAME}
    NAMESPACE ${PROJECT_NAME}::
    FILE ${TEMPFILE_CMAKE_PROJECT_TARGETS_FILE}
)

install(
    TARGETS ${TEMPFILE_TARGET_NAME}
    EXPORT ${TEMPFILE_TARGETS_EXPORT_NAME}
    INCLUDES DESTINATION ${TEMPFILE_INCLUDE_INSTALL_DIR}
)
install(
    EXPORT ${TEMPFILE_TARGETS_EXPORT_NAME}
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${TEMPFILE_CONFIG_INSTALL_DIR}
)