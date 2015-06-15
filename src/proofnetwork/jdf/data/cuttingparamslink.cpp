#include "cuttingparamslink.h"

#include "proofnetwork/jdf/data/abstractresourcelink_p.h"

namespace Proof {
namespace Jdf {

class CuttingParamsLinkPrivate : public AbstractResourceLinkPrivate
{
    Q_DECLARE_PUBLIC(CuttingParamsLink)
};

CuttingParamsLink::CuttingParamsLink(QObject *parent)
    : AbstractResourceLink(*new CuttingParamsLinkPrivate, parent)
{
}

CuttingParamsLinkQmlWrapper *CuttingParamsLink::toQmlWrapper(QObject *parent) const
{
    Q_D(const CuttingParamsLink);
    CuttingParamsLinkSP castedSelf = qSharedPointerCast<CuttingParamsLink>(d->weakSelf);
    Q_ASSERT(castedSelf);
    return new CuttingParamsLinkQmlWrapper(castedSelf, parent);

}

CuttingParamsLinkSP CuttingParamsLink::create()
{
    CuttingParamsLinkSP result(new CuttingParamsLink());
    result->d_func()->weakSelf = result.toWeakRef();
    return result;
}

CuttingParamsLinkSP CuttingParamsLink::fromJdf(const QXmlStreamReader &xmlReader)
{
    CuttingParamsLinkSP cuttingParams = create();
    AbstractResourceLink::fromJdf(xmlReader, cuttingParams);
    return cuttingParams;
}

CuttingParamsLinkSP CuttingParamsLink::defaultObject()
{
    static CuttingParamsLinkSP entity = create();
    return entity;
}

}
}
