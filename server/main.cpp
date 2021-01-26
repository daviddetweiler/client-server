#include "pch.h"

#include <Windows.h>
#include <roapi.h>

using namespace winrt;

void* __stdcall winrt_get_activation_factory([[maybe_unused]] std::wstring_view const& name);

struct Server : implements<Server, winrt::Windows::Foundation::IGetActivationFactory> {
    IInspectable GetActivationFactory(const hstring& classId)
    {
        return IInspectable {winrt_get_activation_factory(classId), take_ownership_from_abi};
    }
};

HRESULT get_factory(HSTRING name, IActivationFactory** ptr)
{
    hstring tmp {};
    *put_abi(tmp) = name;
    const auto foo = static_cast<IUnknown*>(winrt_get_activation_factory(tmp));
    if (!foo)
        return REGDB_E_CLASSNOTREG;

    auto ret = foo->QueryInterface(ptr);
    foo->Release();
    return ret;
}

bool running {true};

int main()
{
    init_apartment();
    const hstring foo {L"Server.Class"};
    auto foo_ptr = static_cast<HSTRING>(get_abi(foo));
    auto serv_ptr = get_factory;
    RO_REGISTRATION_COOKIE cookie {};
    winrt::check_hresult(RoRegisterActivationFactories(&foo_ptr, &serv_ptr, 1, &cookie));
    while (running) {};
    RoRevokeActivationFactories(cookie);
    printf("Server closing");
    getchar();
    //CoreApplication::RunWithActivationFactories(make<Server>());
}
