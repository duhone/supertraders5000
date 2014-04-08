//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "onewindow.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

one_window::one_window()
{
  message_arg = 0;
  message_number = 0;
  pallette_number = 0;
  parent_window = 0;
  xoffset = 0;
  yoffset = 0;
  xscale = .1;
  yscale = .1;
  
}

one_window::~one_window()
{

}

void one_window::setparent_window(int arg)
{
  parent_window = arg;
}

void one_window::setpallette_number(int arg)
{
  pallette_number = arg;
}

void one_window::setxoffset(float arg)
{
  xoffset = arg;
}

void one_window::setyoffset(float arg)
{
  yoffset = arg;
}

void one_window::setxscale(float arg)
{
  xscale = arg;
}

void one_window::setyscale(float arg)
{
  yscale = arg;
}

void one_window::setmessage_number(int arg)
{
  message_number = arg;
}

void one_window::setmessage_arg(int arg)
{
  message_arg = arg;
}

int one_window::getparent_window()
{
  return parent_window;

}

int one_window::getpallette_number()
{
  return pallette_number;
}

float one_window::getxoffset()
{
  return xoffset;
}

float one_window::getyoffset()
{
  return yoffset;
}

float one_window::getxscale()
{
  return xscale;
}

float one_window::getyscale()
{
  return yscale;
}

int one_window::getmessage_number()
{
  return message_number;
}

int one_window::getmessage_arg()
{
  return message_arg;
}
