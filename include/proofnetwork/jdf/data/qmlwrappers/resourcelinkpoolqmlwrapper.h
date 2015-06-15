#ifndef RESOURCELINKPOOLQMLWRAPPER_H
#define RESOURCELINKPOOLQMLWRAPPER_H

#include "proofnetwork/qmlwrappers/networkdataentityqmlwrapper.h"
#include "proofnetwork/jdf/proofnetworkjdf_types.h"
#include "proofnetwork/jdf/proofnetworkjdf_global.h"

#include <QtQml/QQmlListProperty>

namespace Proof {
namespace Jdf {

class ComponentLinkQmlWrapper;
class CuttingParamsLinkQmlWrapper;
class MediaLinkQmlWrapper;
class FoldingParamsLinkQmlWrapper;
class LaminatingIntentLinkQmlWrapper;

class ResourceLinkPoolQmlWrapperPrivate;
class ResourceLinkPoolQmlWrapper : public NetworkDataEntityQmlWrapper
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Proof::Jdf::ComponentLinkQmlWrapper> componentLinks READ componentLinks NOTIFY componentLinksChanged)
    Q_PROPERTY(Proof::Jdf::CuttingParamsLinkQmlWrapper *cuttingParamsLink READ cuttingParamsLink NOTIFY cuttingParamsLinkChanged)
    Q_PROPERTY(Proof::Jdf::MediaLinkQmlWrapper *mediaLink READ mediaLink NOTIFY mediaLinkChanged)
    Q_PROPERTY(Proof::Jdf::FoldingParamsLinkQmlWrapper *foldingParamsLink READ foldingParamsLink NOTIFY foldingParamsLinkChanged)
    Q_PROPERTY(Proof::Jdf::LaminatingIntentLinkQmlWrapper *laminatingIntentLink READ laminatingIntentLink NOTIFY laminatingIntentLinkChanged)

    Q_DECLARE_PRIVATE(ResourceLinkPoolQmlWrapper)

public:
    explicit ResourceLinkPoolQmlWrapper(const ResourceLinkPoolSP &pool, QObject *parent = 0);
    ~ResourceLinkPoolQmlWrapper();
    PROOF_NDE_WRAPPER_TOOLS(ResourceLinkPool)

    QQmlListProperty<Proof::Jdf::ComponentLinkQmlWrapper> componentLinks() const;
    Proof::Jdf::CuttingParamsLinkQmlWrapper *cuttingParamsLink() const;
    Proof::Jdf::MediaLinkQmlWrapper *mediaLink() const;
    Proof::Jdf::FoldingParamsLinkQmlWrapper *foldingParamsLink() const;
    Proof::Jdf::LaminatingIntentLinkQmlWrapper *laminatingIntentLink() const;

signals:
    void componentLinksChanged(QQmlListProperty<Proof::Jdf::ComponentLinkQmlWrapper> arg);
    void cuttingParamsLinkChanged(Proof::Jdf::CuttingParamsLinkQmlWrapper *arg);
    void mediaLinkChanged(Proof::Jdf::MediaLinkQmlWrapper *arg);
    void foldingParamsLinkChanged(Proof::Jdf::FoldingParamsLinkQmlWrapper *arg);
    void laminatingIntentLinkChanged(Proof::Jdf::LaminatingIntentLinkQmlWrapper *arg);

protected:
    void setupEntity(const QSharedPointer<NetworkDataEntity> &old = QSharedPointer<NetworkDataEntity>()) override;

};

}
}
#endif // RESOURCELINKPOOLQMLWRAPPER_H