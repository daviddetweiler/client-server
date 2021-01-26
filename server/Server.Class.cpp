#include "pch.h"
#include "Server.Class.h"
#include "Server.Class.g.cpp"

namespace winrt::Server::implementation
{
    hstring Class::Property()
    {
        printf("Client bought an apple\n");
        return L"I am an apple!";
    }

    void Class::Property(hstring const& value)
    {
        throw hresult_not_implemented();
    }
}
