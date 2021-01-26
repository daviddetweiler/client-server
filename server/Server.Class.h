#pragma once
#include "Server.Class.g.h"

namespace winrt::Server::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        hstring Property();
        void Property(hstring const& value);
    };
}
namespace winrt::Server::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
