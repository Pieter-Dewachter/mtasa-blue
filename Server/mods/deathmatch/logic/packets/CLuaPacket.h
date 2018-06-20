/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/packets/CLuaPacket.h
 *  PURPOSE:     Lua packet class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include "CPacket.h"

class CLuaPacket : public CPacket
{
public:
    CLuaPacket(unsigned char ucActionID, NetBitStreamInterface& BitStream) : m_ucActionID(ucActionID), m_BitStream(BitStream){};

    ePacketID     GetPacketID(void) const { return PACKET_ID_LUA; };
    unsigned long GetFlags(void) const { return PACKET_HIGH_PRIORITY | PACKET_RELIABLE | PACKET_SEQUENCED; };

    bool Write(NetBitStreamInterface& BitStream) const;

private:
    unsigned char          m_ucActionID;
    NetBitStreamInterface& m_BitStream;
};

