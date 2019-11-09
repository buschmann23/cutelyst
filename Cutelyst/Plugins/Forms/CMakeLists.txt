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

add_library(Cutelyst2Qt5Forms
    ${plugin_forms_SRC}
    ${plugin_forms_HEADERS}
)
add_library(Cutelyst2Qt5::Forms ALIAS Cutelyst2Qt5Forms)

set_target_properties(Cutelyst2Qt5Forms PROPERTIES
    EXPORT_NAME Forms
    VERSION ${PROJECT_VERSION}
    SOVERSION ${CUTELYST_API_LEVEL}
    PUBLIC_HEADER "${plugin_forms_HEADERS}"
)

target_link_libraries(Cutelyst2Qt5Forms
    PRIVATE Cutelyst2Qt5::Core
    PRIVATE Qt5::Core
    PRIVATE Qt5::Qml
)

if (PLUGIN_CSRFPROTECTION)
    target_link_libraries(Cutelyst2Qt5Forms
        PRIVATE Cutelyst2Qt5::CSRFProtection
    )
    target_compile_definitions(Cutelyst2Qt5Forms
        PRIVATE PLUGIN_CSRFPROTECTION_ENABLED
    )
endif (PLUGIN_CSRFPROTECTION)

install(TARGETS Cutelyst2Qt5Forms
    EXPORT CutelystTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION bin COMPONENT runtime
    ARCHIVE DESTINATION lib COMPONENT devel
    PUBLIC_HEADER DESTINATION include/cutelyst2-qt5/Cutelyst/Plugins COMPONENT devel
)

add_subdirectory("imports/org/cutelyst/forms")
