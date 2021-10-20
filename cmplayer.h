#ifndef CMPLAYER_H
#define CMPLAYER_H

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QHBoxLayout>
#include <QWidget>
#include "state.h"
#include "log.h"
#include <sys/sysinfo.h>
#include <QFile>

//#ifdef __cplusplus
//extern "C"{
//#endif /* End of #ifdef __cplusplus */

typedef void* CMPHandle;

enum STREAM_TYPE
{
    CMP_TCP = 0,
    CMP_UDP
};

enum SHOW_HIDE
{
    HIDE_VIDEO = 0,
    SHOW_VIDEO
};

enum CMPPLAY_STATE
{
    CMP_STATE_IDLE = 0,        // 空闲
    CMP_STATE_PLAY,            // 播放
    CMP_STATE_FAST_FORWARD,    // 快进
    CMP_STATE_SLOW_FORWARD,    // 慢放
    CMP_STATE_PAUSE,           // 暂停
    CMP_STATE_STOP             // 停止状态
};

/*************************************************
  函数功能:     CMP_Init
  函数描述:     模块初使化
  输入参数:     无
  输出参数:     无
  返回值:       0-成功，否则失败
*************************************************/
int CMP_Init(void);


/*************************************************
  函数功能:     CMP_UnInit
  函数描述:     模块反初使化
  输入参数:     无
  输出参数:     无
  返回值:       0：成功， <0:失败
*************************************************/
int CMP_UnInit(void);


/*************************************************
  函数功能:     CMP_CreateMedia
  函数描述:     创建媒体句柄
  输入参数:     tWinInfo：媒体显示窗口位置信息
  返回值:       媒体句柄
*************************************************/
CMPHandle CMP_CreateMedia(QWidget *palywidget);



/*************************************************
  函数功能:     CMP_SetWnd
  函数描述:     改变播放窗口
  输入参数:     hPlay：媒体句柄 tWnd 改变后的目标窗口
  输出参数:     无
  返回值:
*************************************************/
int CMP_ChangeWnd(CMPHandle hPlay,QWidget *palywidget);



/*************************************************
  函数功能:     CMP_DestroyMedia
  函数描述:     销毁媒体句柄
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:       0：成功， <0:失败
*************************************************/
int CMP_DestroyMedia(CMPHandle hPlay);


/*************************************************
  函数功能:     CMP_OpenMediaPreview
  函数描述:     打开预览媒体
  输入参数:     hPlay：媒体句柄， pcRtspUrl：rtsp地址 ,iTcpFlag：CMP_TCP or CMP_UDP
  输出参数:     无
  返回值:       0：成功， -1:未找到相应媒体句柄
*************************************************/
int CMP_OpenMediaPreview(CMPHandle hPlay,const char *pcRtspFile,int iTcpFlag);

/*************************************************
  函数功能:     CMP_OpenMediaFile
  函数描述:     打开点播媒体
  输入参数:     hPlay：媒体句柄， pcRtspFile:rtsp文件地址 ,iTcpFlag：CMP_TCP or CMP_UDP
  输出参数:     无
  返回值:       0：成功， -1:未找到相应媒体句柄
  *************************************************/
int CMP_OpenMediaFile(CMPHandle hPlay, const char *pcRtspFile,int iTcpFlag);


/*************************************************
  函数功能:     CMP_CloseMedia
  函数描述:     关闭媒体
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:       0：成功， -1:未找到相应媒体句柄
*************************************************/
int CMP_CloseMedia(CMPHandle hPlay);


/*************************************************
  函数功能:     CMP_SetWndDisplayEnable
  函数描述:     设置播放窗口显示使能
  输入参数:     hPlay：媒体句柄
                iEnable: 使能标志，1-使能，0-不使能
  输出参数:     无
  返回值:
*************************************************/
int CMP_SetWndDisplayEnable(CMPHandle hPlay, int iEnable,QWidget *palywidget);


/*************************************************
  函数功能:     CMP_PlayMedia
  函数描述:     开始播放媒体流
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:
*************************************************/
int CMP_PlayMedia(CMPHandle hPlay);



/*************************************************
  函数功能:     CMP_PauseMedia
  函数描述:     暂停播放媒体流
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:
*************************************************/
int CMP_PauseMedia(CMPHandle hPlay);


/*************************************************
  函数功能:     CMP_PauseMedia
  函数描述:     获取媒体播放状态
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:
*************************************************/

int CMP_GetPlayStatus(CMPHandle hPlay);


/*************************************************
  函数功能:     CMP_SetPosition
  函数描述:     设置播放位置（秒）
  输入参数:     hPlay：媒体句柄
                nPosTime: 跳转时间(单位S)
  输出参数:     无
*************************************************/
int CMP_SetPosition(CMPHandle hPlay, int nPosTime);


/*************************************************
  函数功能:     CMP_GetPlayRange
  函数描述:     获取播放时长
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:       文件播放总时长，以秒为单位
*************************************************/
int CMP_GetPlayRange(CMPHandle hPlay);

/*************************************************
  函数功能:     CMP_GetPlayRange
  函数描述:     获取当前播放时间
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:       文件播当前播放时间，以秒为单位
*************************************************/
int CMP_GetCurrentPlayTime(CMPHandle hPlay);


/*************************************************
  函数功能:     CMP_GetPlayRange
  函数描述:     获取当前播放速度
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:       0
*************************************************/

int CMP_SetPlayRate(CMPHandle hPlay,qreal rate);

/*************************************************
  函数功能:     CMP_GetPlayRange
  函数描述:     获取当前媒体状态
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:       0
*************************************************/
int  CMP_GetStreamState(CMPHandle hPlay);



/*************************************************
  函数功能:     CMP_GetPlayRange
  函数描述:     获取当前播放状态
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:       0
*************************************************/
int CMP_GetPlayState(CMPHandle hPlay);


/*************************************************
  函数功能:     CMP_GetPlayRange
  函数描述:     获取当前播放错误状态
  输入参数:     hPlay：媒体句柄
  输出参数:     无
  返回值:       0
*************************************************/

int CMP_GetStreamError(CMPHandle hPlay);


//#endif

//#ifdef __cplusplus
//}
#endif /* End of #ifdef __cplusplus */

