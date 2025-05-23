# SPDX-FileCopyrightText: (C) 2017-2025 Matthias Fehring <mf@huessenbergnetz.de>
# SPDX-License-Identifier: BSD-3-Clause

set(plugin_validator_SRC
    validator.cpp
    validator_p.h
    validatorrule.cpp
    validatorrule_p.h
    validatoraccepted.cpp
    validatoraccepted_p.h
    validatorafter.cpp
    validatorafter_p.h
    validatoralpha.cpp
    validatoralpha_p.h
    validatoralphadash.cpp
    validatoralphadash_p.h
    validatoralphanum.cpp
    validatoralphanum_p.h
    validatorbefore.cpp
    validatorbefore_p.h
    validatorbetween.cpp
    validatorbetween_p.h
    validatorboolean.cpp
    validatorboolean_p.h
    validatorcharnotallowed.cpp
    validatorcharnotallowed_p.h
    validatorconfirmed.cpp
    validatorconfirmed_p.h
    validatordate.cpp
    validatordate_p.h
    validatordatetime.cpp
    validatordatetime_p.h
    validatordifferent.cpp
    validatordifferent_p.h
    validatordigits.cpp
    validatordigits_p.h
    validatordigitsbetween.cpp
    validatordigitsbetween_p.h
    validatordomain.cpp
    validatordomain_p.h
    validatoremail.cpp
    validatoremail_p.h
    validatorfilesize.cpp
    validatorfilesize_p.h
    validatorfilled.cpp
    validatorfilled_p.h
    validatorin.cpp
    validatorin_p.h
    validatorinteger.cpp
    validatorinteger_p.h
    validatorip.cpp
    validatorip_p.h
    validatorjson.cpp
    validatorjson_p.h
    validatormax.cpp
    validatormax_p.h
    validatormin.cpp
    validatormin_p.h
    validatornotin.cpp
    validatornotin_p.h
    validatornumeric.cpp
    validatornumeric_p.h
    validatorpresent.cpp
    validatorpresent_p.h
    validatorregularexpression.cpp
    validatorregularexpression_p.h
    validatorrequired.cpp
    validatorrequired_p.h
    validatorrequiredif.cpp
    validatorrequiredif_p.h
    validatorrequiredifstash.cpp
    validatorrequiredifstash_p.h
    validatorrequiredunless.cpp
    validatorrequiredunless_p.h
    validatorrequiredunlessstash.cpp
    validatorrequiredunlessstash_p.h
    validatorrequiredwith.cpp
    validatorrequiredwith_p.h
    validatorrequiredwithall.cpp
    validatorrequiredwithall_p.h
    validatorrequiredwithout.cpp
    validatorrequiredwithout_p.h
    validatorrequiredwithoutall.cpp
    validatorrequiredwithoutall_p.h
    validatorsame.cpp
    validatorsame_p.h
    validatorsize.cpp
    validatorsize_p.h
    validatortime.cpp
    validatortime_p.h
    validatorurl.cpp
    validatorurl_p.h
    validatorresult.cpp
    validatorresult_p.h
)


set(plugin_validator_HEADERS
    validator.h
    Validator
    validatorrule.h
    ValidatorRule
    validatoraccepted.h
    validatorafter.h
    validatoralpha.h
    validatoralphadash.h
    validatoralphanum.h
    validatorbefore.h
    validatorbetween.h
    validatorboolean.h
    validatorcharnotallowed.h
    validatorconfirmed.h
    validatordate.h
    validatordatetime.h
    validatordifferent.h
    validatordigits.h
    validatordigitsbetween.h
    validatordomain.h
    validatoremail.h
    validatorfilesize.h
    validatorfilled.h
    validatorin.h
    validatorinteger.h
    validatorip.h
    validatorjson.h
    validatormax.h
    validatormin.h
    validatornotin.h
    validatornumeric.h
    validatorpresent.h
    validatorregularexpression.h
    validatorrequired.h
    validatorrequiredif.h
    validatorrequiredifstash.h
    validatorrequiredunless.h
    validatorrequiredunlessstash.h
    validatorrequiredwith.h
    validatorrequiredwithall.h
    validatorrequiredwithout.h
    validatorrequiredwithoutall.h
    validatorsame.h
    validatorsize.h
    validatortime.h
    validatorurl.h
    Validators
    validatorresult.h
    ValidatorResult
)

if (PLUGIN_VALIDATOR_PWQUALITY)
    find_package(PkgConfig REQUIRED)
    pkg_search_module(PWQUALITY REQUIRED pwquality>=1.2.2)
    message(STATUS "PLUGIN: Validator, enable PwQuality, enabled.")
    list(APPEND plugin_validator_SRC validatorpwquality.cpp validatorpwquality_p.h)
    list(APPEND plugin_validator_HEADERS validatorpwquality.h)
else ()
    message(STATUS "PLUGIN: Validator, enable PwQuality, disabled.")
endif (PLUGIN_VALIDATOR_PWQUALITY)

set(target_name Cutelyst${PROJECT_VERSION_MAJOR}Qt${QT_VERSION_MAJOR}UtilsValidator)
add_library(${target_name}
    ${plugin_validator_SRC}
    ${plugin_validator_HEADERS}
)
add_library(Cutelyst::Utils::Validator ALIAS ${target_name})

generate_export_header(${target_name}
    BASE_NAME CUTELYST_PLUGIN_UTILS_VALIDATOR
    EXPORT_FILE_NAME ../validator_export.h
)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/../validator_export.h
    DESTINATION include/cutelyst${PROJECT_VERSION_MAJOR}-qt${QT_VERSION_MAJOR}/Cutelyst/Plugins/Utils
)

set_target_properties(${target_name} PROPERTIES
    EXPORT_NAME Utils::Validator
    VERSION ${PROJECT_VERSION}
    SOVERSION ${CUTELYST_API_LEVEL}
)

if(ENABLE_LTO)
    set_property(TARGET ${target_name} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

target_link_libraries(${target_name}
    PUBLIC
        Cutelyst::Core
    PRIVATE
        Qt::Network
)

# used to populate pkgconfig file
set(PLUGIN_VALIDATOR_PKGCONF_PRIV_REQ "Qt${QT_VERSION_MAJOR}Network >= ${QT_MINIMUM_VERSION}")
set(PLUGIN_VALIDATOR_PKGCONF_DEFINES "")

if (PLUGIN_VALIDATOR_PWQUALITY)
    target_link_libraries(${target_name}
        PRIVATE
            ${PWQUALITY_LIBRARIES}
    )
    target_compile_definitions(${target_name}
        PUBLIC
            CUTELYST_VALIDATOR_WITH_PWQUALITY
    )
    set(PLUGIN_VALIDATOR_PKGCONF_DEFINES "-DCUTELYST_VALIDATOR_WITH_PWQUALITY")
    set(PLUGIN_VALIDATOR_PKGCONF_PRIV_REQ "${PLUGIN_VALIDATOR_PKGCONF_PRIV_REQ} pwquality >= 1.2.2")
endif (PLUGIN_VALIDATOR_PWQUALITY)

set_property(TARGET ${target_name} PROPERTY PUBLIC_HEADER ${plugin_validator_HEADERS})
install(TARGETS ${target_name}
    EXPORT CutelystTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT runtime
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT devel
    PUBLIC_HEADER DESTINATION include/cutelyst${PROJECT_VERSION_MAJOR}-qt${QT_VERSION_MAJOR}/Cutelyst/Plugins/Utils COMPONENT devel
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CutelystQtUtilsValidator.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/${target_name}.pc
    @ONLY
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${target_name}.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

set(plugin_utils_validator_TS_FILES
    i18n/plugin_utils_validator.de.ts
    i18n/plugin_utils_validator.en.ts
)

qt_add_lupdate(${target_name}
    TS_FILES ${plugin_utils_validator_TS_FILES}
    OPTIONS -no-obsolete -locations none
)

qt_add_lrelease(${target_name}
    TS_FILES ${plugin_utils_validator_TS_FILES}
    QM_FILES_OUTPUT_VARIABLE plugin_utils_validator_QM_FILES
    OPTIONS -idbased
)

install(FILES ${plugin_utils_validator_QM_FILES} DESTINATION ${I18NDIR})
