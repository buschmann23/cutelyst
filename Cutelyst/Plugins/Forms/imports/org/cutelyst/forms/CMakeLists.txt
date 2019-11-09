find_program(QMAKE_CMD_PATH NAMES qmake-qt5 qmake)
set(QMAKE_CMD ${QMAKE_CMD_PATH})

### Finds where to qmlplugindump binary is installed
### Requires that 'qmake' directory is in PATH
function(FindQmlPluginDump)
    execute_process(
        COMMAND ${QMAKE_CMD} -query QT_INSTALL_BINS
        OUTPUT_VARIABLE QT_BIN_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(QMLPLUGINDUMP_BIN ${QT_BIN_DIR}/qmlplugindump PARENT_SCOPE)
endfunction()

### Sets QT_INSTALL_QML to the directory where QML Plugins should be installed
function(FindQtInstallQml)
    execute_process(
        COMMAND ${QMAKE_CMD} -query QT_INSTALL_QML
        OUTPUT_VARIABLE PROC_RESULT
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(QT_INSTALL_QML ${PROC_RESULT} PARENT_SCOPE)
endfunction()

set(qml_plugin_forms_SRC
    qmlcutelystformsplugin.cpp
)

add_library(Cutelyst2Qt5FormsQml
    ${qml_plugin_forms_SRC}
)

add_library(Cutelyst2Qt5::FormsQml ALIAS Cutelyst2Qt5FormsQml)

set_target_properties(Cutelyst2Qt5FormsQml PROPERTIES
    AUTOMOC ON
    AUTORCC ON
)

target_link_libraries(Cutelyst2Qt5FormsQml
    PRIVATE Cutelyst2Qt5::Forms
    PRIVATE Qt5::Core
    PRIVATE Qt5::Qml
)

### Find location of qmlplugindump (stored in QMLPLUGINDUMP_BIN)
FindQmlPluginDump()
### Find where to install QML Plugins (stored in QT_INSTALL_QML)
FindQtInstallQml()

set(QMLPLUGIN_URI org.cutelyst.forms)
set(QMLPLUGIN_VERSION 1.0)

set(COPY_QMLDIR_COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/qmldir $<TARGET_FILE_DIR:Cutelyst2Qt5FormsQml>/qmldir)
#set(COPY_QMLFILES_COMMAND ${CMAKE_COMMAND} -E copy ${QMLPLUGIN_QMLFILES} $<TARGET_FILE_DIR:${TARGET}>)
set(GENERATE_QMLTYPES_COMMAND ${QMLPLUGINDUMP_BIN} -nonrelocatable ${QMLPLUGIN_URI} ${QMLPLUGIN_VERSION} ${CMAKE_BINARY_DIR}/Cutelyst/Plugins/Forms/imports > ${CMAKE_CURRENT_BINARY_DIR}/plugin.qmltypes)

### Copy qmldir from project source to binary dir
add_custom_command(
    TARGET Cutelyst2Qt5FormsQml
    POST_BUILD
    COMMAND ${COPY_QMLDIR_COMMAND}
    COMMENT "Copying qmldir to binary directory"
)

## Create command to generate plugin.qmltypes after build
add_custom_command(
    TARGET Cutelyst2Qt5FormsQml
    POST_BUILD
    COMMAND ${GENERATE_QMLTYPES_COMMAND}
    COMMENT "Generating plugin.qmltypes"
)

string(REPLACE "." "/" QMLPLUGIN_INSTALL_URI ${QMLPLUGIN_URI})

### Install library
install(TARGETS ${TARGET}
    DESTINATION ${QT_INSTALL_QML}/${QMLPLUGIN_INSTALL_URI}
)

### Install aditional files
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/qmldir
    ${CMAKE_CURRENT_BINARY_DIR}/plugin.qmltypes
    DESTINATION ${QT_INSTALL_QML}/${QMLPLUGIN_INSTALL_URI}
)
