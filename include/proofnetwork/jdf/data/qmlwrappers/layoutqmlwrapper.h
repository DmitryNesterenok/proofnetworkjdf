/* Copyright 2018, OpenSoft Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright notice, this list of
 * conditions and the following disclaimer in the documentation and/or other materials provided
 * with the distribution.
 *     * Neither the name of OpenSoft Inc. nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef PROOF_JDF_LAYOUTQMLWRAPPER_H
#define PROOF_JDF_LAYOUTQMLWRAPPER_H

#include "proofnetwork/jdf/data/qmlwrappers/abstractresourceqmlwrapper.h"
#include "proofnetwork/jdf/proofnetworkjdf_global.h"
#include "proofnetwork/jdf/proofnetworkjdf_types.h"

#include <QtQml/QQmlListProperty>

namespace Proof {
namespace Jdf {
class MediaQmlWrapper;

class LayoutQmlWrapperPrivate;
class PROOF_NETWORK_JDF_EXPORT LayoutQmlWrapper : public AbstractResourceQmlWrapper
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Proof::Jdf::MediaQmlWrapper> media READ media NOTIFY mediaChanged)

    Q_DECLARE_PRIVATE(LayoutQmlWrapper)
public:
    explicit LayoutQmlWrapper(const LayoutSP &layout, QObject *parent = nullptr);
    ~LayoutQmlWrapper();
    PROOF_NDE_WRAPPER_TOOLS(Layout)

    QQmlListProperty<Proof::Jdf::MediaQmlWrapper> media() const;

signals:
    void mediaChanged(const QQmlListProperty<Proof::Jdf::MediaQmlWrapper> &media);

protected:
    void setupEntity(const QSharedPointer<NetworkDataEntity> &old = QSharedPointer<NetworkDataEntity>()) override;
};

} // namespace Jdf
} // namespace Proof

#endif // PROOF_JDF_LAYOUTQMLWRAPPER_H
