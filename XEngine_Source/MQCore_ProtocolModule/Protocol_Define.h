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
extern "C" DWORD Protocol_GetLastError(int* pInt_SysError = NULL);
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
extern "C" BOOL ProtocolModule_Packet_Common(int nNetType, XENGINE_PROTOCOLHDR* pSt_ProtocolHdr, XENGINE_PROTOCOL_XMQ* pSt_MQProtocol, TCHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCTSTR lpszMsgBuffer = NULL, int nMsgLen = 0);
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
extern "C" BOOL ProtocolModule_Packet_MQNumber(XENGINE_PROTOCOLHDR* pSt_ProtocolHdr, XENGINE_MQNUMBER* pSt_MQNumber, TCHAR* ptszMsgBuffer, int* pInt_MsgLen, int nNetType);
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
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProtocolModule_Packet_PassAuth(XENGINE_PROTOCOL_USERAUTH* pSt_ProtocolAuth, TCHAR* ptszMsgBuffer, int* pInt_MsgLen);
/********************************************************************
函数名称：ProtocolModule_Packet_DDSTopic
函数功能：DDS主题协议打包函数
 参数.一：pSt_DDSProtocol
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入要打包的DDS协议
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
 参数.四：dwOPeratorCode
  In/Out：In
  类型：整数型
  可空：N
  意思：输入操作码
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProtocolModule_Packet_DDSTopic(XENGINE_PROTOCOL_XDDS * pSt_DDSProtocol, TCHAR * ptszMsgBuffer, int* pInt_MsgLen, DWORD dwOPeratorCode);
/********************************************************************
函数名称：ProtocolModule_Packet_DDSQuery
函数功能：DDS查询回复协议
 参数.一：pppSt_DDSProtocol
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入DDS信息列表
 参数.二：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入列表个数
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
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProtocolModule_Packet_DDSQuery(XENGINE_PROTOCOL_XDDS*** pppSt_DDSProtocol, int nListCount, TCHAR* ptszMsgBuffer, int* pInt_MsgLen);
/************************************************************************/
/*                        解析类函数                                    */
/************************************************************************/
/********************************************************************
函数名称：ProtocolModule_Parse_Http
函数功能：HTTP协议解析
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
 参数.四：pptszMsgBuffer
  In/Out：Out
  类型：二级指针
  可空：Y
  意思：输出消息内容,需要释放内存
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
extern "C" BOOL ProtocolModule_Parse_Http(LPCTSTR lpszMsgBuffer, int nMsgLen, XENGINE_PROTOCOLHDR * pSt_ProtocolHdr = NULL, TCHAR * *pptszMsgBuffer = NULL, int* pInt_MsgLen = NULL);
/********************************************************************
函数名称：ProtocolModule_Parse_DDSQuery
函数功能：DDS查询解析协议
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的内容
 参数.二：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入解析的大小
 参数.三：pppSt_DDSProtocol
  In/Out：In/Out
  类型：三级指针
  可空：N
  意思：输出DDS信息列表,此内存需要释放
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProtocolModule_Parse_DDSQuery(LPCTSTR lpszMsgBuffer, int nMsgLen, XENGINE_PROTOCOL_XDDS*** pppSt_DDSProtocol, int* pInt_ListCount);