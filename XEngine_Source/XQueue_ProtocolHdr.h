﻿#pragma once
/********************************************************************
//    Created:     2021/07/09  16:37:59
//    File Name:   D:\XEngine_MQService\XEngine_Source\XQueue_ProtocolHdr.h
//    File Path:   D:\XEngine_MQService\XEngine_Source
//    File Base:   XQueue_ProtocolHdr
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     消息队列协议
//    History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////
//                          导出的数据定义
///////////////////////////////////////////////////////////////////////////
//消息队列协议
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REQPOST 0x7000           //投递包请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REPPOST 0x7001           //投递包回复
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REQGET 0x7002            //获取包请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REPGET 0x7003            //获取包回复
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REQDEL 0x7004            //删除包请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REPDEL 0x7005            //删除包回复
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REQCREATE 0x7006         //主题创建请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REPCREATE 0x7007         //主题创建回复
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REQDELETE 0x7008         //主题删除请求
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REPDELETE 0x7009         //主题删除回复
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REQNOTIFY 0x7010         //请求订阅
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_REPNOTIFY 0x7011         //订阅回复
#define XENGINE_COMMUNICATION_PROTOCOL_OPERATOR_CODE_MQ_MSGNOTIFY 0x70A0
///////////////////////////////////////////////////////////////////////////
//                          导出的数据结构
///////////////////////////////////////////////////////////////////////////
#pragma pack(push)
#pragma pack(1)
//消息队列服务协议
typedef struct tag_XEngine_ProtocolXmq
{
	CHAR tszMQKey[256];                                                   //此消息的KEY，不能为空
	__int64x nSerial;                                                     //包序列号
	int nKeepTime;                                                        //保存时间，单位秒，如果为0，获取一次后被抛弃。-1 永久存在，如果有多个永久存在的包nSerial必须有值
	int nGetTimer;                                                        //可以获取的次数
}XENGINE_PROTOCOL_XMQ, * LPXENGINE_PROTOCOL_XMQ;
#pragma pack(pop)