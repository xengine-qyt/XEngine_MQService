﻿#include "pch.h"
#include "ProtocolModule_Packet.h"
/********************************************************************
//    Created:     2020/12/23  20:55:17
//    File Name:   H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_XMQCore\MQCore_XMQService\XMQService_Protocol\XMQService_Protocol.cpp
//    File Path:   H:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_XMQCore\MQCore_XMQService\XMQService_Protocol
//    File Base:   XMQService_Protocol
//    File Ext:    cpp
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     消息队列协议组包器
//    History:
*********************************************************************/
CProtocolModule_Packet::CProtocolModule_Packet()
{
}
CProtocolModule_Packet::~CProtocolModule_Packet()
{
}
///////////////////////////////////////////////////////////////////////////////
//                      公有函数
///////////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：ProtocolModule_Packet_TCPCommon
函数功能：通用封包类
 参数.一：nNetType
  In/Out：In
  类型：整数型
  可空：N
  意思：输入网络类型
 参数.二：pSt_ProtocolHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：协议头
 参数.三：pSt_MQProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：消息头
 参数.四：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出封装号的协议
 参数.五：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出封装的协议的长度
 参数.六：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要封装的数据
 参数.七：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：要封装数据的长度
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CProtocolModule_Packet::ProtocolModule_Packet_Common(int nNetType, XENGINE_PROTOCOLHDR* pSt_ProtocolHdr, XENGINE_PROTOCOL_XMQ* pSt_MQProtocol, TCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCTSTR lpszMsgBuffer /* = NULL */, int nMsgLen /* = 0 */)
{
	Protocol_IsErrorOccur = FALSE;

	if (XENGINE_MQAPP_NETTYPE_TCP == nNetType)
	{
		ProtocolModule_Packet_TCPCommon(pSt_ProtocolHdr, pSt_MQProtocol, ptszMsgBuffer, pInt_MsgLen, lpszMsgBuffer, nMsgLen);
	}
	else
	{
		ProtocolModule_Packet_HttpCommon(pSt_ProtocolHdr, pSt_MQProtocol, ptszMsgBuffer, pInt_MsgLen, lpszMsgBuffer, nMsgLen);
	}
	return TRUE;
}
/********************************************************************
函数名称：ProtocolModule_Packet_TCPCommon
函数功能：通用封包类
 参数.一：pSt_ProtocolHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：协议头
 参数.二：pSt_MQProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：消息头
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出封装号的协议
 参数.四：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出封装的协议的长度
 参数.五：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要封装的数据
 参数.六：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：要封装数据的长度
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CProtocolModule_Packet::ProtocolModule_Packet_TCPCommon(XENGINE_PROTOCOLHDR* pSt_ProtocolHdr, XENGINE_PROTOCOL_XMQ* pSt_MQProtocol, TCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCTSTR lpszMsgBuffer /* = NULL */, int nMsgLen /* = 0 */)
{
    Protocol_IsErrorOccur = FALSE;

    if ((NULL == pSt_ProtocolHdr) || (NULL == ptszMsgBuffer) || (NULL == pInt_MsgLen))
    {
        Protocol_IsErrorOccur = TRUE;
        Protocol_dwErrorCode = ERROR_MQ_MODULE_PROTOCOL_PARAMENT;
        return FALSE;
    }
	
	if (NULL == pSt_MQProtocol)
	{
		pSt_ProtocolHdr->unPacketSize = nMsgLen;
		memcpy(ptszMsgBuffer, pSt_ProtocolHdr, sizeof(XENGINE_PROTOCOLHDR));

		*pInt_MsgLen = sizeof(XENGINE_PROTOCOLHDR) + nMsgLen;
	}
	else
	{
		pSt_ProtocolHdr->unPacketSize = sizeof(XENGINE_PROTOCOL_XMQ) + nMsgLen;
		memcpy(ptszMsgBuffer, pSt_ProtocolHdr, sizeof(XENGINE_PROTOCOLHDR));

		memcpy(ptszMsgBuffer + sizeof(XENGINE_PROTOCOLHDR), pSt_MQProtocol, sizeof(XENGINE_PROTOCOL_XMQ));
		if (NULL != lpszMsgBuffer)
		{
			memcpy(ptszMsgBuffer + sizeof(XENGINE_PROTOCOLHDR) + sizeof(XENGINE_PROTOCOL_XMQ), lpszMsgBuffer, nMsgLen);
		}
		*pInt_MsgLen = sizeof(XENGINE_PROTOCOLHDR) + sizeof(XENGINE_PROTOCOL_XMQ) + nMsgLen;
	}
   
    return TRUE;
}
/********************************************************************
函数名称：ProtocolModule_Packet_HttpCommon
函数功能：HTTP通用封包类
 参数.一：pSt_ProtocolHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：协议头
 参数.二：pSt_MQProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：消息头
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出封装号的协议
 参数.四：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出封装的协议的长度
 参数.五：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：要封装的数据
 参数.六：nMsgLen
  In/Out：In
  类型：整数型
  可空：Y
  意思：要封装数据的长度
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CProtocolModule_Packet::ProtocolModule_Packet_HttpCommon(XENGINE_PROTOCOLHDR* pSt_ProtocolHdr, XENGINE_PROTOCOL_XMQ* pSt_MQProtocol, TCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCTSTR lpszMsgBuffer /* = NULL */, int nMsgLen /* = 0 */)
{
    Json::Value st_JsonRoot;
    Json::Value st_JsonMQProtocol;
    Json::Value st_JsonPayload;
	Json::StreamWriterBuilder st_JsonBuilder;

	st_JsonRoot["unOperatorType"] = pSt_ProtocolHdr->unOperatorType;
	st_JsonRoot["unOperatorCode"] = pSt_ProtocolHdr->unOperatorCode;
	st_JsonRoot["xhToken"] = (Json::Value::UInt64)pSt_ProtocolHdr->xhToken;
	st_JsonRoot["wReserve"] = pSt_ProtocolHdr->wReserve;
	st_JsonRoot["byVersion"] = pSt_ProtocolHdr->byVersion;

	if (NULL != pSt_MQProtocol)
	{
		st_JsonMQProtocol["tszMQKey"] = pSt_MQProtocol->tszMQKey;
		st_JsonMQProtocol["nSerial"] = (Json::Value::Int64)pSt_MQProtocol->nSerial;
		st_JsonMQProtocol["nGetTimer"] = pSt_MQProtocol->nGetTimer;
		st_JsonMQProtocol["nKeepTime"] = pSt_MQProtocol->nKeepTime;
		st_JsonMQProtocol["nPubTime"] = (Json::Value::Int64)pSt_MQProtocol->nPubTime;
		st_JsonRoot["st_MQProtocol"] = st_JsonMQProtocol;
	}
	
    if (nMsgLen > 0)
    {
        st_JsonPayload["nPayType"] = (ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE)pSt_ProtocolHdr->byVersion;
        st_JsonPayload["nPayLen"] = nMsgLen;
        st_JsonPayload["tszPayData"] = lpszMsgBuffer;

        st_JsonRoot["st_Payload"] = st_JsonPayload;
    }
    st_JsonBuilder["emitUTF8"] = true;

    *pInt_MsgLen = Json::writeString(st_JsonBuilder, st_JsonRoot).length();
    memcpy(ptszMsgBuffer, Json::writeString(st_JsonBuilder, st_JsonRoot).c_str(), *pInt_MsgLen);

    return TRUE;
}
/********************************************************************
函数名称：ProtocolModule_Packet_MQNumber
函数功能：获取序列打包函数
 参数.一：pSt_ProtocolHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入协议头
 参数.二：pSt_MQNumber
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的序列号信息
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.四：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.五：nNetType
  In/Out：Out
  类型：整数型
  可空：N
  意思：输入网络类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CProtocolModule_Packet::ProtocolModule_Packet_MQNumber(XENGINE_PROTOCOLHDR* pSt_ProtocolHdr, XENGINE_MQNUMBER* pSt_MQNumber, TCHAR* ptszMsgBuffer, int* pInt_MsgLen, int nNetType)
{
	Protocol_IsErrorOccur = FALSE;

	if ((NULL == pSt_ProtocolHdr) || (NULL == ptszMsgBuffer) || (NULL == pInt_MsgLen))
	{
		Protocol_IsErrorOccur = TRUE;
		Protocol_dwErrorCode = ERROR_MQ_MODULE_PROTOCOL_PARAMENT;
		return FALSE;
	}

	if (XENGINE_MQAPP_NETTYPE_TCP == nNetType)
	{
		pSt_ProtocolHdr->unPacketSize = sizeof(XENGINE_MQNUMBER);
		memcpy(ptszMsgBuffer, pSt_ProtocolHdr, sizeof(XENGINE_PROTOCOLHDR));
		memcpy(ptszMsgBuffer + sizeof(XENGINE_PROTOCOLHDR), pSt_MQNumber, sizeof(XENGINE_MQNUMBER));
		*pInt_MsgLen = sizeof(XENGINE_PROTOCOLHDR) + sizeof(XENGINE_MQNUMBER);
	}
	else
	{
		Json::Value st_JsonRoot;
		Json::Value st_JsonObject;
		Json::StreamWriterBuilder st_JsonBuilder;

		st_JsonRoot["unOperatorType"] = pSt_ProtocolHdr->unOperatorType;
		st_JsonRoot["unOperatorCode"] = pSt_ProtocolHdr->unOperatorCode;
		st_JsonRoot["wReserve"] = pSt_ProtocolHdr->wReserve;

		st_JsonObject["tszMQKey"] = pSt_MQNumber->tszMQKey;
		st_JsonObject["nCount"] = (Json::Value::Int64)pSt_MQNumber->nCount;
		st_JsonObject["nFirstNumber"] = (Json::Value::Int64)pSt_MQNumber->nFirstNumber;
		st_JsonObject["nLastNumber"] = (Json::Value::Int64)pSt_MQNumber->nLastNumber;
		
		st_JsonRoot["st_MQNumber"] = st_JsonObject;

		st_JsonBuilder["emitUTF8"] = true;

		*pInt_MsgLen = Json::writeString(st_JsonBuilder, st_JsonRoot).length();
		memcpy(ptszMsgBuffer, Json::writeString(st_JsonBuilder, st_JsonRoot).c_str(), *pInt_MsgLen);
	}
	return TRUE;
}
/********************************************************************
函数名称：ProtocolModule_Packet_PassAuth
函数功能：HTTP代理打包函数
 参数.一：pSt_ProtocolAuth
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的内容
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：nCode
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操作的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CProtocolModule_Packet::ProtocolModule_Packet_PassAuth(XENGINE_PROTOCOL_USERAUTH* pSt_ProtocolAuth, TCHAR* ptszMsgBuffer, int* pInt_MsgLen, int nCode)
{
	Protocol_IsErrorOccur = FALSE;

	if ((NULL == pSt_ProtocolAuth) || (NULL == ptszMsgBuffer) || (NULL == pInt_MsgLen))
	{
		Protocol_IsErrorOccur = TRUE;
		Protocol_dwErrorCode = ERROR_MQ_MODULE_PROTOCOL_PARAMENT;
		return FALSE;
	}
	Json::Value st_JsonRoot;
	Json::Value st_JsonAuth;
	Json::StreamWriterBuilder st_JsonBuilder;

	st_JsonAuth["tszUserName"] = pSt_ProtocolAuth->tszUserName;
	st_JsonAuth["tszUserPass"] = pSt_ProtocolAuth->tszUserPass;
	st_JsonAuth["enClientType"] = pSt_ProtocolAuth->enClientType;
	st_JsonAuth["enDeviceType"] = pSt_ProtocolAuth->enDeviceType;

	st_JsonRoot["unOperatorType"] = ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_XMQ;
	st_JsonRoot["unOperatorCode"] = nCode;
	st_JsonRoot["wReserve"] = 0;
	st_JsonRoot["byVersion"] = 2;
	st_JsonRoot["st_Auth"] = st_JsonAuth;

	st_JsonBuilder["emitUTF8"] = true;

	*pInt_MsgLen = Json::writeString(st_JsonBuilder, st_JsonRoot).length();
	memcpy(ptszMsgBuffer, Json::writeString(st_JsonBuilder, st_JsonRoot).c_str(), *pInt_MsgLen);
	return TRUE;
}
/********************************************************************
函数名称：ProtocolModule_Packet_PassUser
函数功能：HTTP用户信息打包函数
 参数.一：pSt_ProtocolUser
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的内容
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的缓冲区
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出缓冲区大小
 参数.四：nCode
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要操纵的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CProtocolModule_Packet::ProtocolModule_Packet_PassUser(XENGINE_PROTOCOL_USERINFO* pSt_ProtocolUser, TCHAR* ptszMsgBuffer, int* pInt_MsgLen, int nCode)
{
	Protocol_IsErrorOccur = FALSE;

	if ((NULL == pSt_ProtocolUser) || (NULL == ptszMsgBuffer) || (NULL == pInt_MsgLen))
	{
		Protocol_IsErrorOccur = TRUE;
		Protocol_dwErrorCode = ERROR_MQ_MODULE_PROTOCOL_PARAMENT;
		return FALSE;
	}
	Json::Value st_JsonRoot;
	Json::Value st_JsonUser;
	Json::StreamWriterBuilder st_JsonBuilder;

	st_JsonUser["nIDNumber"] = pSt_ProtocolUser->nIDNumber;
	st_JsonUser["nPhoneNumber"] = pSt_ProtocolUser->nPhoneNumber;
	st_JsonUser["nUserLevel"] = pSt_ProtocolUser->nUserLevel;
	st_JsonUser["nUserState"] = pSt_ProtocolUser->nUserState;
	st_JsonUser["tszCreateTime"] = pSt_ProtocolUser->tszCreateTime;
	st_JsonUser["tszEMailAddr"] = pSt_ProtocolUser->tszEMailAddr;
	st_JsonUser["tszLoginTime"] = pSt_ProtocolUser->tszLoginTime;
	st_JsonUser["tszUserName"] = pSt_ProtocolUser->tszUserName;
	st_JsonUser["tszUserPass"] = pSt_ProtocolUser->tszUserPass;

	st_JsonRoot["unOperatorType"] = ENUM_XENGINE_COMMUNICATION_PROTOCOL_TYPE_XMQ;
	st_JsonRoot["unOperatorCode"] = nCode;
	st_JsonRoot["wReserve"] = 0;
	st_JsonRoot["byVersion"] = 2;
	st_JsonRoot["st_User"] = st_JsonUser;

	st_JsonBuilder["emitUTF8"] = true;

	*pInt_MsgLen = Json::writeString(st_JsonBuilder, st_JsonRoot).length();
	memcpy(ptszMsgBuffer, Json::writeString(st_JsonBuilder, st_JsonRoot).c_str(), *pInt_MsgLen);
	return TRUE;
}