/*
 * SPDX-FileCopyrightText: (C) 2017-2025 Matthias Fehring <mf@huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef CUTELYSTVALIDATORMIN_H
#define CUTELYSTVALIDATORMIN_H

#include "validatorrule.h"

namespace Cutelyst {

class ValidatorMinPrivate;

/**
 * \ingroup plugins-utils-validator-rules
 * \class ValidatorMin validatormin.h <Cutelyst/Plugins/Utils/validatormin.h>
 * \brief Checks if a value is not smaller or shorter than a maximum value.
 *
 * This works for floating point, integer and QString types, where for numeric types it will check
 * the value itself while for QString it will check the string length. Use \a min to define the
 * minimum value and \a type to set the type to check against. \a min will internally converted into
 * a comparative value (qlonglong for QMetaType::Int, qulonglong for QMetaType::UInt and int for
 * QMetaType::QString. Allowed types for the \a type specifier are all numeric types and
 * QMetaType::QString. Any other type will result in a validation data error.
 *
 * If you set a string to the \a min value, this will neither be interpreted as a number nor as
 * string length, but will be used to get the comparison number value from the \link
 * Context::stash() stash\endlink.
 *
 * \note Conversion of numeric input values is performed in the \c 'C' locale.
 *
 * \note Unless \link Validator::validate() validation\endlink is started with \link
 * Validator::NoTrimming NoTrimming\endlink, whitespaces will be removed from the beginning and the
 * end of the input value before validation. If the \a field's value is empty or if the \a field is
 * missing in the input data, the validation will succeed without performing the validation itself.
 * Use one of the \link ValidatorRequired required validators \endlink to require the field to be
 * present and not empty.
 *
 * \par Return type
 * On success, ValidatorReturnType::value will contain the \a type specified in the constructor.
 *
 * \sa Validator for general usage of validators.
 *
 * \sa ValidatorMax, ValidatorBetween, ValidatorSize
 */
class CUTELYST_PLUGIN_UTILS_VALIDATOR_EXPORT ValidatorMin : public ValidatorRule
{
public:
    /**
     * Constructs a new %ValidatorMin with the given parameters.
     *
     * \param field         Name of the input field to validate.
     * \param type          The type to compare.
     * \param min           Minimum value. Will be converted into comparable value. If it is a
     *                      QString, it will try to get the comparison value from the stash.
     * \param messages      Custom error message if validation fails.
     * \param defValKey     \link Context::stash() Stash \endlink key containing a default value
     *                      if input field is empty. This value will \b NOT be validated.
     */
    ValidatorMin(const QString &field,
                 QMetaType::Type type,
                 const QVariant &min,
                 const ValidatorMessages &messages = ValidatorMessages(),
                 const QString &defValKey          = {});

    /**
     * Destroys the %ValidatorMin object.
     */
    ~ValidatorMin() override;

protected:
    /**
     * Performs the validation on the input \a params and returns the result.
     *
     * If validation succeeded, ValidatorReturnType::value will contain the input parameter value
     * converted into the \a type specified in the constructor.
     */
    ValidatorReturnType validate(Context *c, const ParamsMultiMap &params) const override;

    /**
     * Performs the validation on the input \a params and calls the \a cb with the
     * ValidatorReturnType as argument.
     *
     * If validation succeeded, ValidatorReturnType::value will contain the input parameter value
     * converted into the \a type specified in the constructor.
     *
     * \since Cutelyst 5.0.0
     */
    void validateCb(Context *c, const ParamsMultiMap &params, ValidatorRtFn cb) const override;

    /**
     * Returns a generic error message.
     */
    QString genericValidationError(Context *c,
                                   const QVariant &errorData = QVariant()) const override;

    /**
     * Returns a generic error message for validation data errors.
     */
    QString genericValidationDataError(Context *c, const QVariant &errorData) const override;

    /**
     * Returns a generic error message for input value parsing errors.
     */
    QString genericParsingError(Context *c, const QVariant &errorData) const override;

private:
    Q_DECLARE_PRIVATE(ValidatorMin) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
    Q_DISABLE_COPY(ValidatorMin)
};

} // namespace Cutelyst

#endif // CUTELYSTVALIDATORMIN_H
