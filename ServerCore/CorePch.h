#pragma once

#include "Types.h"
#include "CoreMacro.h"
#include "CoreTLS.h"
#include "CoreGlobal.h"
#include "Container.h"

#include <iostream>
#include <winsock2.h>
#include <mswsock.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <assert.h>
using namespace std;

#include "SocketUtils.h"
#include "SendBuffer.h"
#include "Session.h"
#include "LockQueue.h"