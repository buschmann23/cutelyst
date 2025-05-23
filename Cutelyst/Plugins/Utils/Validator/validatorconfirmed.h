/*
 * SPDX-FileCopyrightText: (C) 2017-2025 Matthias Fehring <mf@huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef CUTELYSTVALIDATORCONFIRMED_H
#define CUTELYSTVALIDATORCONFIRMED_H

#include "validatorrule.h"

namespace Cutelyst {

class ValidatorConfirmedPrivate;

/**
 * \ingroup plugins-utils-validator-rules
 * \headerfile "" <Cutelyst/Plugins/Utils/validatorconfirmed.h>
 * \brief Checks for a confirmation input field.
 *
 * The \a field under validation must have a matching field of \c foo_confirmation. For example, if
 * the field under validation is \c password, a matching \c password_confirmation field must be
 * present in the input with the same value.
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
 * \sa ValidatorSame
 */
class CUTELYST_PLUGIN_UTILS_VALIDATOR_EXPORT ValidatorConfirmed : public ValidatorRule
{
public:
    /**
     * Constructs a new %ValidatorConfirmed object with the given parameters.
     *
     * \param field         Name of the input field to validate.
     * \param messages      Custom error message if validation fails.
     */
    explicit ValidatorConfirmed(const QString &field, const ValidatorMessages &messages = {});

    /**
     * Destroys the %ValidatorConfirmed object.
     */
    ~ValidatorConfirmed() override;

protected:
    /**
     * Performs the validation on the input \a params and returns the result.
     *
     * If validation succeeded, ValidatorReturnType::value will contain the input paramater values
     * as QString.
     */
    ValidatorReturnType validate(Context *c, const ParamsMultiMap &params) const override;

    /**
     * Performs the validation on the input \a params and calls the \a cb with the
     * ValidatorReturnType as argument.
     *
     * If validation succeeded, ValidatorReturnType::value will contain the input paramater values
     * as QString.
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
    Q_DECLARE_PRIVATE(ValidatorConfirmed) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
    Q_DISABLE_COPY(ValidatorConfirmed)
};

} // namespace Cutelyst

#endif // CUTELYSTVALIDATORCONFIRMED_H
