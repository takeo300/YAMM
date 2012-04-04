/* 
 * File:   VideoCallable.h
 * Author: Benjamin Rockel, Max Beikirch, Hendrik Sokolowski
 *
 * Created on 4. April 2012, 16:47
 */
/*
#ifndef VIDEOCALLABLE_H
#define	VIDEOCALLABLE_H

#include "Callable.h"

class VideoCallable : public Callable 
{
	Q_OBJECT
	public:
		virtual VideoCall createVideoCall(Contact *user) = 0;
		virtual VideoCall createVideoCall(QList<Contact*> users) = 0;
	signals:
		void vCallReceived(int VideoCallId) = 0;
};

#endif	/* VIDEOCALLABLE_H */

