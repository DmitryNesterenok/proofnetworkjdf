#ifndef ABSTRACTPHYSICALRESOURCELINK_H
#define ABSTRACTPHYSICALRESOURCELINK_H

#include "proofnetwork/jdf/data/abstractresourcelink.h"
#include "proofnetwork/jdf/proofnetworkjdf_types.h"
#include "proofnetwork/jdf/proofnetworkjdf_global.h"
#include "proofnetwork/jdf/apihelper.h"

#include <QXmlStreamReader>

namespace Proof {
namespace Jdf {

class AbstractPhysicalResourceLinkPrivate;
class PROOF_NETWORK_JDF_EXPORT AbstractPhysicalResourceLink : public AbstractResourceLink
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(AbstractPhysicalResourceLink)
public:
    ApiHelper::ResourceOrientation orientation() const;
    double amount() const;

    void setOrientation(ApiHelper::ResourceOrientation arg);
    void setAmount(double arg);

    static bool fromJdf(const QXmlStreamReader &xmlReader, const AbstractPhysicalResourceLinkSP &abstractResource);
    void toJdf(QXmlStreamWriter &jdfWriter) override;
signals:
    void orientationChanged(Proof::Jdf::ApiHelper::ResourceOrientation orientation);
    void amountChanged(double arg);
protected:
    explicit AbstractPhysicalResourceLink() = delete;
    AbstractPhysicalResourceLink(AbstractPhysicalResourceLinkPrivate &dd, QObject *parent = nullptr);
};

}
}

#endif // ABSTRACTPHYSICALRESOURCELINK_H
