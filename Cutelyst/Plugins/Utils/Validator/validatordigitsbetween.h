/*
 * SPDX-FileCopyrightText: (C) 2017-2025 Matthias Fehring <mf@huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef CUTELYSTVALIDATORDIGITSBETWEEN_H
#define CUTELYSTVALIDATORDIGITSBETWEEN_H

#include "validatorrule.h"

namespace Cutelyst {

class ValidatorDigitsBetweenPrivate;

/**
 * \ingroup plugins-utils-validator-rules
 * \headerfile "" <Cutelyst/Plugins/Utils/validatordigitsbetween.h>
 * \brief Checks for digits only with a length between min and max.
 *
 * The field under validation must only contain digits with a length between \a min and \a max. The
 * digits are not interpreteded as a numeric value but as a string, so the \a min and \a max values
 * are not a range for a numeric value but for the string length.
 *
 * \note Unless \link Validator::validate() validation\endlink is started with \link
 * Validator::NoTrimming NoTrimming\endlink, whitespaces will be removed from the beginning and the
 * end of the input value before validation. If the \a field's value is empty or if the \a field is
 * missing in the input data, the validation will succeed without performing the validation itself.
 * Use one of the \link ValidatorRequired required validators \endlink to require the field to be
 * present and not empty.
 *
 * \par Return type
 * On success, ValidatorReturnType::value will contain a QString.
 *
 * \sa Validator for general usage of validators.
 *
 * \sa ValidatorDigits
 */
class CUTELYST_PLUGIN_UTILS_VALIDATOR_EXPORT ValidatorDigitsBetween : public ValidatorRule
{
public:
    /**
     * Constructs a new %ValidatorDigitsBetween with the given parameters.
     *
     * \param field     Name of the input field to validate.
     * \param min       Minimum length of the digits. Should either be an integer value to directly
     *                  specify the length or the name of a \link Context::stash() Stash\endlink
     *                  key containing the length constraint.
     * \param max       Maximum length of the digits. Should either be an integer value to directly
     *                  specify the length or the name of a \link Context::stash() Stash\endlink
     *                  key containing the length constraint.
     * \param messages  Custom error messages if validation fails.
     * \param defValKey \link Context::stash() Stash \endlink key containing a default value if
     *                  input field is empty. This value will \b NOT be validated.
     */
    ValidatorDigitsBetween(const QString &field,
                           const QVariant &min,
                           const QVariant &max,
                           const ValidatorMessages &messages = ValidatorMessages(),
                           const QString &defValKey          = {});

    /**
     * Destroys the %ValidatorDigitsBetween object.
     */
    ~ValidatorDigitsBetween() override;

    /**
     * \ingroup plugins-utils-validator-rules
     * \brief Returns \c true if \a value only contains digits and has a length between \a min and
     * \a max.
     *
     * Nothe that this might return \c true for an empty value if 0 is between \a min and \a max.
     *
     * \param value The value to validate as it is.
     * \param min   Minimum length of the digits.
     * \param max   Maximum length of the digits.
     * \return \c true if \a value string only contains digits and has a length between \a min and
     * \a max, otherwise it returns \a false.
     */
    static bool validate(const QString &value, int min, int max);

protected:
    /**
     * Performs the validation on the input \a params and returns the result.
     *
     * If validation succeeded, ValidatorReturnType::value will contain the input parameter value as
     * QString.
     */
    ValidatorReturnType validate(Context *c, const ParamsMultiMap &params) const override;

    /**
     * Performs the validation on the input \a params and calls the \a cb with the
     * ValidatorReturnType as argument.
     *
     * If validation succeeded, ValidatorReturnType::value will contain the input parameter value as
     * QString.
     *
     * \since Cutelyst 5.0.0
     */
    void validateCb(Context *c, const ParamsMultiMap &params, ValidatorRtFn cb) const override;

    /**
     * Returns a generic error if validation failed.
     */
    QString genericValidationError(Context *c,
                                   const QVariant &errorData = QVariant()) const override;

private:
    Q_DECLARE_PRIVATE(ValidatorDigitsBetween) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
    Q_DISABLE_COPY(ValidatorDigitsBetween)
};

} // namespace Cutelyst

#endif // CUTELYSTVALIDATORDIGITSBETWEEN_H
