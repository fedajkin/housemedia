/******************************************************************* 
* File    : JSFX_ImageZoom.js  © JavaScript-FX.com
* Created : 2001/08/31 
* Author  : Roy Whittle  (Roy@Whittle.com) www.Roy.Whittle.com 
* Purpose : To create a zooming effect for images
* History 
* Date         Version        Description 
* 2001-08-09	1.0		First version
* 2001-08-31	1.1		Code split - others became JSFX_FadingRollovers,
*                             JSFX_ImageFader and JSFX_ImageZoom.
* 2002-01-27	1.2		Completed development by converting to JSFX namespace
* 2002-04-25	1.3		Added the functions stretchIn & expandIn
* 2004-01-06	1.4		Allowed for the image (tag) being forcibly sized
***********************************************************************/ 
/*** Create some global variables ***/
if(!window.JSFX)
	JSFX=new Object();
JSFX.ImageZoomRunning = false;
/*******************************************************************
*
* Function    : zoomIn
*
* Description : This function is based on the turn_on() function
*		      of animate2.js (animated rollovers from www.roy.whittle.com).
*		      Each zoom object is given a state. 
*			OnMouseOver the state is switched depending on the current state.
*			Current state -> Switch to
*			===========================
*			null		->	OFF.
*			OFF		->	ZOOM_IN + start timer
*			ZOOM_OUT	->	ZOOM_IN
*			ZOOM_IN_OUT	->	ZOOM_IN
*****************************************************************/
JSFX.zoomOn = function(img, zoomStep, maxZoom)
{
	if(img)
	{
		if(!zoomStep)
		{
			if(img.mode == "EXPAND")
				zoomStep = img.height/10;
			else
				zoomStep = img.width/10;
		}

		if(!maxZoom)
		{
			if(img.mode == "EXPAND")
				maxZoom = img.height/2;
			else
				maxZoom = img.width/2;
		}


		if(img.state == null)
		{
			img.state = "OFF";
			img.index = 0;
			img.orgWidth =  img.width;
			img.orgHeight = img.height;
			img.zoomStep = zoomStep;
			img.maxZoom  = maxZoom;
		}

		if(img.state == "OFF")
		{
			img.state = "ZOOM_IN";
			start_zooming();
		}
		else if( img.state == "ZOOM_IN_OUT"
			|| img.state == "ZOOM_OUT")
		{
			img.state = "ZOOM_IN";
		}
	}
}
JSFX.zoomIn = function(img, zoomStep, maxZoom)
{
	img.mode = "ZOOM";
	JSFX.zoomOn(img, zoomStep, maxZoom);
}
JSFX.stretchIn = function(img, zoomStep, maxZoom)
{
	img.mode = "STRETCH";
	JSFX.zoomOn(img, zoomStep, maxZoom);
}
JSFX.expandIn = function(img, zoomStep, maxZoom)
{
	img.mode = "EXPAND";
	JSFX.zoomOn(img, zoomStep, maxZoom);
}
/*******************************************************************
*
* Function    : zoomOut
*
* Description : This function is based on the turn_off function
*		      of animate2.js (animated rollovers from www.roy.whittle.com).
*		      Each zoom object is given a state. 
*			OnMouseOut the state is switched depending on the current state.
*			Current state -> Switch to
*			===========================
*			ON		->	ZOOM_OUT + start timer
*			ZOOM_IN	->	ZOOM_IN_OUT.
*****************************************************************/
JSFX.zoomOut = function(img)
{
	if(img)
	{
		if(img.state=="ON")
		{
			img.state="ZOOM_OUT";
			start_zooming();
		}
		else if(img.state == "ZOOM_IN")
		{
			img.state="ZOOM_IN_OUT";
		}
	}
}
/*******************************************************************
*
* Function    : start_zooming
*
* Description : This function is based on the start_animating() function
*	        	of animate2.js (animated rollovers from www.roy.whittle.com).
*			If the timer is not currently running, it is started.
*			Only 1 timer is used for all objects
*****************************************************************/
function start_zooming()
{
	if(!JSFX.ImageZoomRunning)
		ImageZoomAnimation();
}

JSFX.setZoom = function(img)
{
	if(img.mode == "STRETCH")
	{
		img.width  = img.orgWidth  + img.index;
		img.height = img.orgHeight;
	}
	else if(img.mode == "EXPAND")
	{
		img.width  = img.orgWidth;
		img.height = img.orgHeight + img.index;
	}
	else
	{
		img.width  = img.orgWidth   + img.index;
		img.height = img.orgHeight  + (img.index * (img.orgHeight/img.orgWidth));
	}
}
/*******************************************************************
*
* Function    : ImageZoomAnimation
*
* Description : This function is based on the Animate function
*		    of animate2.js (animated rollovers from www.roy.whittle.com).
*		    Each zoom object has a state. This function
*		    modifies each object and (possibly) changes its state.
*****************************************************************/
function ImageZoomAnimation()
{
	JSFX.ImageZoomRunning = false;
	for(i=0 ; i<document.images.length ; i++)
	{
		var img = document.images[i];
		if(img.state)
		{
			if(img.state == "ZOOM_IN")
			{
				img.index+=img.zoomStep;
				if(img.index > img.maxZoom)
					img.index = img.maxZoom;

				JSFX.setZoom(img);

				if(img.index == img.maxZoom)
					img.state="ON";
				else
					JSFX.ImageZoomRunning = true;
			}
			else if(img.state == "ZOOM_IN_OUT")
			{
				img.index+=img.zoomStep;
				if(img.index > img.maxZoom)
					img.index = img.maxZoom;

				JSFX.setZoom(img);
	
				if(img.index == img.maxZoom)
					img.state="ZOOM_OUT";
				JSFX.ImageZoomRunning = true;
			}
			else if(img.state == "ZOOM_OUT")
			{
				img.index-=img.zoomStep;
				if(img.index < 0)
					img.index = 0;

				JSFX.setZoom(img);

				if(img.index == 0)
					img.state="OFF";
				else
					JSFX.ImageZoomRunning = true;
			}
		}
	}
	/*** Check to see if we need to animate any more frames. ***/
	if(JSFX.ImageZoomRunning)
		setTimeout("ImageZoomAnimation()", 40);
}
