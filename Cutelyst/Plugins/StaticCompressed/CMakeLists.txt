# SPDX-FileCopyrightText: (C) 2017-2022 Matthias Fehring <mf@huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

cmake_dependent_option(PLUGIN_STATICCOMPRESSED_ZOPFLI "Enables the use of zofpli instead of zlib for gzip compression" OFF "PLUGIN_STATICCOMPRESSED" OFF)
cmake_dependent_option(PLUGIN_STATICCOMPRESSED_BROTLI "Enables the support of the brotli compression format" OFF "PLUGIN_STATICCOMPRESSED" OFF)
cmake_dependent_option(PLUGIN_STATICCOMPRESSED_ZSTD "Enables the support of the Zstandard compression format" OFF "PLUGIN_STATICCOMPRESSED" OFF)

set(plugin_staticcompressed_SRC
    staticcompressed.cpp
    staticcompressed_p.h
)

set(plugin_staticcompressed_HEADERS
    staticcompressed.h
    StaticCompressed
)

add_library(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed
    ${plugin_staticcompressed_SRC}
    ${plugin_staticcompressed_HEADERS}
)
add_library(Cutelyst::StaticCompressed ALIAS Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed)

set_target_properties(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed PROPERTIES
    EXPORT_NAME StaticCompressed
    VERSION ${PROJECT_VERSION}
    SOVERSION ${CUTELYST_API_LEVEL}
)

target_link_libraries(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed
    PUBLIC
        Cutelyst::Core
)

# used in the pkg-config file
set(PLUGIN_STATICCOMPRESSED_PKGCONF_PRIV_REQ "")
set(PLUGIN_STATICCOMPRESSED_PKGCONF_DEFINES "")
set(PLUGIN_STATICCOMPRESSED_PKGCONF_PRIV_LIB "")

if (PLUGIN_STATICCOMPRESSED_ZOPFLI)
    find_package(Zopfli REQUIRED)
    message(STATUS "PLUGIN: StaticCompressed, enable zopfli")
    target_link_libraries(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed
        PRIVATE
            ${ZOPFLI_LIBRARIES}
    )
    target_compile_definitions(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed
        PUBLIC
            CUTELYST_STATICCOMPRESSED_WITH_ZOPFLI
    )
    target_include_directories(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed
        PRIVATE
            ${ZOPFLI_INCLUDE_DIRS}
    )
    set(PLUGIN_STATICCOMPRESSED_PKGCONF_DEFINES "${PLUGIN_STATICCOMPRESSED_PKGCONF_DEFINES} -DCUTELYST_STATICCOMPRESSED_WITH_ZOPFLI")
    set(PLUGIN_STATICCOMPRESSED_PKGCONF_PRIV_LIB "${PLUGIN_STATICCOMPRESSED_PKGCONF_PRIV_LIB} -lzopfli")
endif (PLUGIN_STATICCOMPRESSED_ZOPFLI)

if (PLUGIN_STATICCOMPRESSED_BROTLI)
    find_package(PkgConfig REQUIRED)
    pkg_search_module(Brotli REQUIRED IMPORTED_TARGET libbrotlienc)
    message(STATUS "PLUGIN: StaticCompressed, enable brotli")
    target_link_libraries(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed
        PRIVATE
            PkgConfig::Brotli
    )
    target_compile_definitions(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed
        PUBLIC
            CUTELYST_STATICCOMPRESSED_WITH_BROTLI
    )
    set(PLUGIN_STATICCOMPRESSED_PKGCONF_DEFINES "${PLUGIN_STATICCOMPRESSED_PKGCONF_DEFINES} -DCUTELYST_STATICCOMPRESSED_WITH_BROTLI")
    set(PLUGIN_STATICCOMPRESSED_PKGCONF_PRIV_REQ "${PLUGIN_STATICCOMPRESSED_PKGCONF_PRIV_REQ} libbrotlienc")
endif (PLUGIN_STATICCOMPRESSED_BROTLI)

if (PLUGIN_STATICCOMPRESSED_ZSTD)
    find_package(PkgConfig REQUIRED)
    pkg_search_module(Zstd REQUIRED IMPORTED_TARGET libzstd>=1.4.0)
    message(STATUS "PLUGIN: StaticCompressed, enable Zstandard")
    target_link_libraries(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed
        PRIVATE
            PkgConfig::Zstd
    )
    target_compile_definitions(Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed
        PUBLIC
            CUTELYST_STATICCOMPRESSED_WITH_ZSTD
    )
    set(PLUGIN_STATICCOMPRESSED_PKGCONF_DEFINES "${PLUGIN_STATICCOMPRESSED_PKGCONF_DEFINES} -DCUTELYST_STATICCOMPRESSED_WITH_ZSTD")
    set(PLUGIN_STATICCOMPRESSED_PKGCONF_PRIV_REQ "${PLUGIN_STATICCOMPRESSED_PKGCONF_PRIV_REQ} libzstd")
endif (PLUGIN_STATICCOMPRESSED_ZSTD)

set_property(TARGET Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed PROPERTY PUBLIC_HEADER ${plugin_staticcompressed_HEADERS})
install(TARGETS Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed
    EXPORT CutelystTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT runtime
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT devel
    PUBLIC_HEADER DESTINATION include/cutelyst${PROJECT_VERSION_MAJOR}-qt${QT_VERSION_MAJOR}/Cutelyst/Plugins/StaticCompressed COMPONENT devel
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CutelystQtStaticCompressed.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed.pc
    @ONLY
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}StaticCompressed.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
