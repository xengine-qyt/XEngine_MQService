﻿#pragma once
/********************************************************************
//    Created:     2021/07/01  15:45:45
//    File Name:   D:\XEngine_MQService\XEngine_Source\MQCore_ProtocolModule\Protocol_Define.h
//    File Path:   D:\XEngine_MQService\XEngine_Source\MQCore_ProtocolModule
//    File Base:   Protocol_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     导出的定义
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                        导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" XLONG Protocol_GetLastError(int* pInt_SysError = NULL);
/************************************************************************/
/*                        封装类函数                                    */
/************************************************************************/
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
extern "C" bool ProtocolModule_Packet_Common(int nNetType, XENGINE_PROTOCOLHDR* pSt_ProtocolHdr, XENGINE_PROTOCOL_XMQ* pSt_MQProtocol, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCXSTR lpszMsgBuffer = NULL, int nMsgLen = 0);
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
extern "C" bool ProtocolModule_Packet_MQNumber(XENGINE_PROTOCOLHDR* pSt_ProtocolHdr, XENGINE_MQNUMBER* pSt_MQNumber, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, int nNetType);
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
extern "C" bool ProtocolModule_Packet_PassAuth(XENGINE_PROTOCOL_USERAUTH* pSt_ProtocolAuth, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, int nCode);
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
  意思：输入要操作的协议
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ProtocolModule_Packet_PassUser(XENGINE_PROTOCOL_USERINFO* pSt_ProtocolUser, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, int nCode);
/********************************************************************
函数名称：ProtocolModule_Packet_Http
函数功能：HTTP封包类
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
 参数.三：nCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：返回的状态值
 参数.四：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：返回的消息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ProtocolModule_Packet_Http(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, int nCode = 0, LPCXSTR lpszMsgBuffer = NULL);
/********************************************************************
函数名称：ProtocolModule_Packet_UserList
函数功能：用户信息打包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的内容
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打包大小
 参数.三：pppSt_UserInfo
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要打包的数据
 参数.四：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要打包的数据的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ProtocolModule_Packet_UserList(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XENGINE_PROTOCOL_USERINFO*** pppSt_UserInfo, int nListCount);
/********************************************************************
函数名称：ProtocolModule_Packet_TopicList
函数功能：主题列表打包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的内容
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打包大小
 参数.三：pppszTableName
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要打包的数据
 参数.四：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要打包的数据的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ProtocolModule_Packet_TopicList(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XCHAR*** pppszTableName, int nListCount);
/********************************************************************
函数名称：ProtocolModule_Packet_OnlineList
函数功能：在线用户打包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打包的内容
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出打包大小
 参数.三：ppptszListUser
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要打包的数据
 参数.四：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要打包的数据的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ProtocolModule_Packet_OnlineList(XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XCHAR*** ppptszListUser, int nListCount);
/********************************************************************
函数名称：ProtocolModule_Packet_UNReadCreate
函数功能：未读消息打包创建函数
 参数.一：pSt_ProtocolHdr
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的协议头
 参数.二：enPayType
  In/Out：In
  类型：枚举型
  可空：N
  意思：输入打包的负载类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" XHANDLE ProtocolModule_Packet_UNReadCreate(XENGINE_PROTOCOLHDR* pSt_ProtocolHdr, ENUM_XENGINE_PROTOCOLHDR_PAYLOAD_TYPE enPayType);
/********************************************************************
函数名称：ProtocolModule_Packet_UNReadInsert
函数功能：维度消息打包数据插入
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pppSt_DBMessage
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要打包的数据
 参数.三：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要打包的数据个数
 参数.四：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要过滤的用户
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ProtocolModule_Packet_UNReadInsert(XHANDLE xhToken, XENGINE_DBMESSAGEQUEUE*** pppSt_DBMessage, int nListCount, LPCXSTR lpszUserName);
/********************************************************************
函数名称：ProtocolModule_Packet_UNReadDelete
函数功能：删除数据并且导出
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的数据
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ProtocolModule_Packet_UNReadDelete(XHANDLE xhToken, XCHAR* ptszMsgBuffer, int* pInt_MsgLen);
/************************************************************************/
/*                        解析类函数                                    */
/************************************************************************/
/********************************************************************
函数名称：ProtocolModule_Parse_Websocket
函数功能：websocket协议解析
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.三：pSt_ProtocolHdr
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出解析到的头协议
 参数.四：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出消息内容
 参数.五：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出内容大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool ProtocolModule_Parse_Websocket(LPCXSTR lpszMsgBuffer, int nMsgLen, XENGINE_PROTOCOLHDR * pSt_ProtocolHdr = NULL, XCHAR *ptszMsgBuffer = NULL, int* pInt_MsgLen = NULL);