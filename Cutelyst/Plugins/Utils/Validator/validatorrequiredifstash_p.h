/*
 * SPDX-FileCopyrightText: (C) 2018-2023 Matthias Fehring <mf@huessenbergnetz.de>
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef CUTELYSTVALIDATORREQUIREDIFSTASH_P_H
#define CUTELYSTVALIDATORREQUIREDIFSTASH_P_H

#include "validatorrequiredifstash.h"
#include "validatorrule_p.h"

namespace Cutelyst {

class ValidatorRequiredIfStashPrivate : public ValidatorRulePrivate
{
public:
    ValidatorRequiredIfStashPrivate(const QString &f,
                                    QString sk,
                                    QVariant sv,
                                    const ValidatorMessages &m)
        : ValidatorRulePrivate(f, m, {}, "ValidatorRequiredIfStash")
        , stashKey(std::move(sk))
        , stashValues(std::move(sv))
    {
    }

    QString stashKey;
    QVariant stashValues;
};

} // namespace Cutelyst

#endif // CUTELYSTVALIDATORREQUIREDIFSTASH_P_H
