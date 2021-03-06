/***************************************************************************
    copyright            : (C) 2007 by mean
    email                : fixounet@free.fr
    
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "ADM_default.h"
#include "ADM_muxerInternal.h"
#include "muxerMP4.h"
#define ADM_MINIMAL_UI_INTERFACE
#include "DIA_factory.h"
#include "fourcc.h"
bool mp4Configure(void)
{
        uint32_t fmt=(uint32_t)muxerConfig.muxerType;
        uint32_t dar=(uint32_t)muxerConfig.aspectRatio;
        bool alt=muxerConfig.useAlternateMp3Tag;
        bool force=muxerConfig.forceAspectRatio;
        diaMenuEntry format[]={{MP4_MUXER_MP4,"MP4"},{MP4_MUXER_PSP,"PSP"}};
        diaElemMenu  menuFormat(&fmt,QT_TRANSLATE_NOOP("mp4muxer","Muxing Format"),2,format,"");
        diaElemToggle alternate(&alt,QT_TRANSLATE_NOOP("mp4muxer","Use alternate MP3 tag"));
        diaElemToggle forceAR(&force,QT_TRANSLATE_NOOP("mp4muxer","Force aspect ratio"));
        diaMenuEntry aspect[]={{STANDARD,"4:3"},{WIDE,"16:9"},{UNI,"18:9"},{CINEMA,"64:27"}};
        diaElemMenu  menuAspect(&dar,QT_TRANSLATE_NOOP("mp4muxer","Aspect Ratio (DAR)"),4,aspect,"");

        diaElem *tabs[]={&menuFormat,&alternate,&forceAR,&menuAspect};
        if( diaFactoryRun(QT_TRANSLATE_NOOP("mp4muxer","MP4 Muxer"),4,tabs))
        {
            muxerConfig.muxerType=(MP4_MUXER_TYPE)fmt;
            muxerConfig.useAlternateMp3Tag=alt;
            muxerConfig.forceAspectRatio=force;
            muxerConfig.aspectRatio=(MP4_MUXER_DAR)dar;
            return true;
        }
        return false;
}


