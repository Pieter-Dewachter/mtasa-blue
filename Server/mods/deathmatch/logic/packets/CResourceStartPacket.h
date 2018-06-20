/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/packets/CResourceStartPacket.h
 *  PURPOSE:     Resource start packet class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include <list>
#include "../packets/CPacket.h"
#include "../CResource.h"

class CResourceStartPacket : public CPacket
{
public:
    CResourceStartPacket(const char* szResourceName, class CResource* pResource);

    ePacketID     GetPacketID(void) const { return PACKET_ID_RESOURCE_START; };
    unsigned long GetFlags(void) const { return PACKET_HIGH_PRIORITY | PACKET_RELIABLE | PACKET_SEQUENCED; };

    bool Write(NetBitStreamInterface& BitStream) const;

private:
    std::string m_strResourceName;
    CResource*  m_pResource;
};

