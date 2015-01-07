/*
 * Copyright (C) 2013-2014 Daniel Nicoletti <dantti12@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB. If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef CUTELYST_DISPATCHTYPEPATH_H
#define CUTELYST_DISPATCHTYPEPATH_H

#include <Cutelyst/DispatchType>
#include <Cutelyst/Action>

#include <QMap>

namespace Cutelyst {

class DispatchTypePathPrivate;
class DispatchTypePath : public DispatchType
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(DispatchTypePath)
public:
    explicit DispatchTypePath(QObject *parent = 0);
    virtual ~DispatchTypePath();

    virtual QByteArray list() const;

    virtual bool match(Context *ctx, const QString &path, const QStringList &args) const;

    virtual bool registerAction(Action *action);

    /**
     * Get a URI part for an action
     * Always returns NULL if captures is not empty since Path actions don't have captures
     */
    virtual QString uriForAction(Action *action, const QStringList &captures) const;

private:
    bool registerPath(const QString &path, Action *action);

    DispatchTypePathPrivate *d_ptr;
};

}

#endif // DispatchTypePath_H
