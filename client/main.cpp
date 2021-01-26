#include "pch.h"

#include <winrt/Server.h>

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    init_apartment();
    Server::Class apple {};
    printf("%ls\n", apple.Property().c_str());
    getchar();
}
