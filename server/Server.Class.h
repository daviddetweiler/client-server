#pragma once
#include "Server.Class.g.h"

extern bool running;

namespace winrt::Server::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        hstring Property();
        void Property(hstring const& value);

        static void final_release(std::unique_ptr<Class> foo)
        {
            printf("Client ate their apple\n");
            foo.reset();
            running = false;
        }
    };
}
namespace winrt::Server::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
