﻿#pragma once
/********************************************************************
//    Created:     2021/07/02  10:12:38
//    File Name:   D:\XEngine_MQService\XEngine_Source\MQCore_SessionModule\SessionModule_Client\SessionModule_Client.h
//    File Path:   D:\XEngine_MQService\XEngine_Source\MQCore_SessionModule\SessionModule_Client
//    File Base:   SessionModule_Client
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     消息会话服务
//    History:
*********************************************************************/
typedef struct
{
    XENGINE_PROTOCOL_USERINFO st_UserInfo;                              //用户登录信息
    XCHAR tszUserAddr[128];                                             //用户地址
    time_t nTimeStart;                                                  //时间
    int nNetType;                                                       //网络类型
}XENGINE_SESSIONINFO, * LPXENGINE_SESSIONINFO;

class CSessionModule_Client
{
public:
    CSessionModule_Client();
    ~CSessionModule_Client();
public:
    bool SessionModule_Client_Init();
    bool SessionModule_Client_Destory();
    bool SessionModule_Client_Create(LPCXSTR lpszClientAddr, XENGINE_PROTOCOL_USERINFO *pSt_UserInfo, int nNetType);
    bool SessionModule_Client_Delete(LPCXSTR lpszClientAddr);
    bool SessionModule_Client_DeleteByUser(LPCXSTR lpszClientUser);
    bool SessionModule_Client_GetUser(LPCXSTR lpszSessionStr, XCHAR* ptszUserName = NULL);
    bool SessionModule_Client_GetAddr(LPCXSTR lpszUserName, XCHAR* ptszUserAddr = NULL);
    bool SessionModule_Client_GetInfoByUser(LPCXSTR lpszUserName, XENGINE_PROTOCOL_USERINFO* pSt_UserInfo);
    bool SessionModule_Client_GetType(LPCXSTR lpszSessionStr, int* pInt_NetType);
    bool SessionModule_Client_GetExist(LPCXSTR lpszClientAddr = NULL, LPCXSTR lpszClientUser = NULL);
    bool SessionModule_Client_GetListAddr(XCHAR*** ppptszClientList, int* pInt_ListCount, bool bAddr = true);
private:
    shared_mutex st_Locker;
private:
    unordered_map<xstring, XENGINE_SESSIONINFO> stl_MapSession;
};
