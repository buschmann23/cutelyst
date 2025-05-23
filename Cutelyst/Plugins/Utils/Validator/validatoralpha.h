/*
 * SPDX-FileCopyrightText: (C) 2017-2025 Matthias Fehring <mf@huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef CUTELYSTVALIDATORALPHA_H
#define CUTELYSTVALIDATORALPHA_H

#include "validatorrule.h"

namespace Cutelyst {

class ValidatorAlphaPrivate;

/**
 * \ingroup plugins-utils-validator-rules
 * \headerfile "" <Cutelyst/Plugins/Utils/validatoralpha.h>
 * \brief Validates an input field for only alphabetic content.
 *
 * The \a field under validation is only allowed to contain alphabetic characters.
 * If \a asciiOnly is set to \c true, only US-ASCII characters are allowed, otherwise all UTF-8
 * alpha-numeric characters are allowed.
 *
 * \note Unless \link Validator::validate() validation\endlink is started with \link
 * Validator::NoTrimming NoTrimming\endlink, whitespaces will be removed from the beginning and the
 * end of the input value before validation. If the \a field's value is empty or if the \a field is
 * missing in the input data, the validation will succeed without performing the validation itself.
 * Use one of the \link ValidatorRequired required validators \endlink to require the field to be
 * present and not empty.
 *
 * \par Examples
 * \code
 * "Hallo Kuddel!" // invalid
 * "HalloKöddel" // valid if asciiOnly is false, otherwise it is false
 * "HalloKuddel" // valid if asciiOnly is true
 * " " // valid if trimBefore is true, invalid if trimBefore is false
 * \endcode
 *
 * \par Return type
 * On success, ValidatorReturnType::value will contain a QString.
 *
 * \sa Validator for general usage of validators.
 *
 * \sa ValidatorAlphaDash, ValidatorAlphaNum
 */
class CUTELYST_PLUGIN_UTILS_VALIDATOR_EXPORT ValidatorAlpha : public ValidatorRule
{
public:
    /**
     * Constructs a new %ValidatorAlpha object with the given parameters.
     *
     * \param field         Name of the input field to validate.
     * \param asciiOnly     If \c true, only ASCII characters are allowed.
     * \param messages      Custom error messages if validation fails.
     * \param defValKey     \link Context::stash() Stash \endlink key containing a default value if
     *                      input field is empty. This value will \b NOT be validated.
     */
    explicit ValidatorAlpha(const QString &field,
                            bool asciiOnly                    = false,
                            const ValidatorMessages &messages = {},
                            const QString &defValKey          = {});

    /**
     * Destroys the %ValidatorAlpha object.
     */
    ~ValidatorAlpha() override;

    /**
     * \ingroup plugins-utils-validator-rules
     * \brief Returns \c true if \a value only contains alphabetic characters.
     * \param value     The value to validate.
     * \param asciiOnly If \c true, only ASCII characters are allowed.
     * \return \c true if \a value only contains alphabetic characters
     */
    static bool validate(const QString &value, bool asciiOnly = false);

protected:
    /**
     * Performs the validation on the input \a params and returns the result.
     *
     * If validation succeeded, ValidatorReturnType::value will contain the input paramter
     * value as QString.
     */
    ValidatorReturnType validate(Context *c, const ParamsMultiMap &params) const override;

    /**
     * Performs the validation on the input \a params and calls the \a cb with the
     * ValidatorReturnType as argument.
     *
     * If validation succeeded, ValidatorReturnType::value will contain the input paramter
     * value as QString.
     *
     * \since Cutelyst 5.0.0
     */
    void validateCb(Context *c, const ParamsMultiMap &params, ValidatorRtFn cb) const override;

    /**
     * Returns a generic error message if validation failed.
     */
    QString genericValidationError(Context *c,
                                   const QVariant &errorData = QVariant()) const override;

private:
    Q_DECLARE_PRIVATE(ValidatorAlpha) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
    Q_DISABLE_COPY(ValidatorAlpha)
};

} // namespace Cutelyst

#endif // CUTELYSTVALIDATORALPHA_H
