/*
 * SPDX-FileCopyrightText: (C) 2017-2025 Matthias Fehring <mf@huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef CUTELYSTVALIDATORPRESENT_H
#define CUTELYSTVALIDATORPRESENT_H

#include "validatorrule.h"

namespace Cutelyst {

class ValidatorPresentPrivate;

/**
 * \ingroup plugins-utils-validator-rules
 * \headerfile "" <Cutelyst/Plugins/Utils/validatorpresent.h>
 * \brief The field under validation must be present in input data but can be empty.
 *
 * This validator checks if the \a field is present in the input data, but not if it contains any
 * content. If you want to check the fields presence and require it to have content, use one of the
 * \link ValidatorRequired required validators \endlink.
 *
 * \par Return type
 * On success, ValidatorReturnType::value will contain a QString.
 *
 * \sa Validator for general usage of validators.
 *
 * \sa ValidatorFilled, ValidatorRequired
 */
class CUTELYST_PLUGIN_UTILS_VALIDATOR_EXPORT ValidatorPresent : public ValidatorRule
{
public:
    /**
     * Constructs a new %ValidatorPresent object with the given parameters.
     *
     * \param field         Name of the input field to validate.
     * \param messages      Custom error message if validation fails.
     */
    explicit ValidatorPresent(const QString &field, const ValidatorMessages &messages = {});

    /**
     * Destroys the %ValidatorPresent object.
     */
    ~ValidatorPresent() override;

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
    Q_DECLARE_PRIVATE(ValidatorPresent) // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
    Q_DISABLE_COPY(ValidatorPresent)
};

} // namespace Cutelyst

#endif // CUTELYSTVALIDATORPRESENT_H
