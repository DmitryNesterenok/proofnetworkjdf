#ifndef COMPONENTLINKQMLWRAPPER_H
#define COMPONENTLINKQMLWRAPPER_H

#include "proofnetwork/jdf/data/qmlwrappers/abstractphysicalresourcelinkqmlwrapper.h"
#include "proofnetwork/jdf/proofnetworkjdf_types.h"
#include "proofnetwork/jdf/proofnetworkjdf_global.h"

namespace Proof {
namespace Jdf {

class ComponentLinkQmlWrapperPrivate;
class ComponentLinkQmlWrapper : public AbstractPhysicalResourceLinkQmlWrapper
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(ComponentLinkQmlWrapper)
public:
    explicit ComponentLinkQmlWrapper(const ComponentLinkSP &component, QObject *parent = nullptr);
    PROOF_NDE_WRAPPER_TOOLS(ComponentLink)
};

}
}
#endif // COMPONENTLINKQMLWRAPPER_H
