#include "pch.h"

using namespace winrt;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::Foundation;

void* __stdcall winrt_get_activation_factory([[maybe_unused]] std::wstring_view const& name);

struct Server : implements<Server, IGetActivationFactory> {
    IInspectable GetActivationFactory(const hstring& classId)
    {
        return IInspectable {winrt_get_activation_factory(classId), take_ownership_from_abi};
    }
};

int main()
{
    init_apartment();
    CoreApplication::RunWithActivationFactories(make<Server>());
}
