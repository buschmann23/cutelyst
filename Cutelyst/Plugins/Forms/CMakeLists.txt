find_package(QT NAMES Qt6 Qt5 COMPONENTS Qml REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} 5.15.2 REQUIRED COMPONENTS Qml)

set(plugin_forms_SRC
    forms.cpp
    forms_p.h
    formhtmlelement.cpp
    formhtmlelement_p.h
    form.cpp
    form_p.h
    fieldset.cpp
    fieldset_p.h
    legend.cpp
    legend_p.h
    button.cpp
    button_p.h
    field.cpp
    field_p.h
    select.cpp
    select_p.h
    selectcontent.cpp
    selectcontent_p.h
    option.cpp
    option_p.h
    optgroup.cpp
    optgroup_p.h
)

set(plugin_forms_HEADERS
    forms.h
    formhtmlelement.h
    form.h
    fieldset.h
    legend.h
    button.h
    field.h
    select.h
    selectcontent.h
    option.h
    optgroup.h
)

add_library(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
    ${plugin_forms_SRC}
    ${plugin_forms_HEADERS}
)
add_library(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}::Forms ALIAS Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms)

set_target_properties(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms PROPERTIES
    EXPORT_NAME Forms
    VERSION ${PROJECT_VERSION}
    SOVERSION ${CUTELYST_API_LEVEL}
    PUBLIC_HEADER ${plugin_forms_HEADERS}
)

target_link_libraries(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
    PRIVATE Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}::Core
    PRIVATE Qt${QT_VERSION_MAJOR}::Core
    PRIVATE Qt${QT_VERSION_MAJOR}::Qml
)

set(PLUGIN_FORMS_PKGCONFIG_REQUIRES "Qt${QT_VERSION_MAJOR}Core Qt${QT_VERSION_MAJOR}Qml Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Core")

if (PLUGIN_CSRFPROTECTION)
    target_link_libraries(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
        PRIVATE Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}::CSRFProtection
    )
    target_compile_definitions(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
        PRIVATE PLUGIN_CSRFPROTECTION_ENABLED
    )
    set(PLUGIN_FORMS_PKGCONFIG_REQUIRES "${PLUGIN_FORMS_PKGCONFIG_REQUIRES} Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}CSRFProtection")
endif (PLUGIN_CSRFPROTECTION)

install(TARGETS Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms
    EXPORT CutelystTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT runtime
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT devel
    PUBLIC_HEADER DESTINATION include/cutelyst${PROJECT_VERSION_MAJOR}-qt${QT_VERSION_MAJOR}/Cutelyst/Plugins/Forms COMPONENT devel
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CutelystQtForms.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms.pc
    @ONLY
)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}Forms.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

add_subdirectory("imports/org/cutelyst/forms")
