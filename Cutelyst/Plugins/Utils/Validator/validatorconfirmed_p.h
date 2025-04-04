/*
 * SPDX-FileCopyrightText: (C) 2017-2023 Matthias Fehring <mf@huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef CUTELYSTVALIDATORCONFIRMED_P_H
#define CUTELYSTVALIDATORCONFIRMED_P_H

#include "validatorconfirmed.h"
#include "validatorrule_p.h"

namespace Cutelyst {

class ValidatorConfirmedPrivate : public ValidatorRulePrivate
{
public:
    ValidatorConfirmedPrivate(const QString &f, const ValidatorMessages &m)
        : ValidatorRulePrivate(f, m, {}, "ValidatorConfirmed")
    {
    }
};

} // namespace Cutelyst

#endif // CUTELYSTVALIDATORCONFIRMED_P_H
