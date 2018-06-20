/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/CAccessControlList.h
 *  PURPOSE:     Access control list class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

class CAccessControlList;

#pragma once

#include <list>
#include "CAccessControlListRight.h"
#include <xml/CXMLNode.h>

#define MAX_ACL_NAME_LENGTH 256

class CAccessControlList
{
public:
    CAccessControlList(const char* szACLName, class CAccessControlListManager* pACLManager);
    ~CAccessControlList(void);

    const char* GetName(void) { return m_strACLName; };

    CAccessControlListRight* AddRight(const char* szRightName, CAccessControlListRight::ERightType eRightType, bool bAccess);
    CAccessControlListRight* GetRight(const char* szRightName, CAccessControlListRight::ERightType eRightType);
    bool                     RemoveRight(const char* szRightName, CAccessControlListRight::ERightType eRightType);

    void WriteToXMLNode(CXMLNode* pNode);

    list<CAccessControlListRight*>::const_iterator IterBegin(void) { return m_Rights.begin(); };
    list<CAccessControlListRight*>::const_iterator IterEnd(void) { return m_Rights.end(); };

    bool CanBeModifiedByScript(void);
    uint GetScriptID(void) const { return m_uiScriptID; }

private:
    void OnChange(void);

    SString                        m_strACLName;
    list<CAccessControlListRight*> m_Rights;

    class CAccessControlListManager* m_pACLManager;
    uint                             m_uiScriptID;
};
