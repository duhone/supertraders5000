#if !defined(enginetypes_h)
#define enginetypes_h

// *** WINDOW MODES ***
//#define MODE_FULLSCREEN   0
//#define MODE_WINDOWED	  1
//#define MODE_MULTI_WINDOW 2

// *** DISPLAY PARAMETERS ***
#define MODE_16_FS        0
#define MODE_24_FS        1
#define MODE_32_FS        2
#define MODE_WINDOWED     4

// *** RETURN ERRORS ***
#define MMDISPLAY_OK				0x00000000
#define MMDISPLAY_FAIL				0x80000001
#define MMDISPLAY_INVALID_PARAMETER 0x80000002

// *** SCREEN METRICS DEFINES ***
// Right Now Evertyingis using a conventional coordinate system
// (0, 0) bottom left, (width, height) top right
#define MIN_WIDTH  0.0
#define MIN_HEIGHT 0.0
#define MAX_WIDTH  1.0
#define MAX_HEIGHT 1.0

#define PROJ_MODE_DEFAULT		 0
#define PROJ_MODE_WINDOWXY		 1
#define PROJ_MODE_0_1_EVEN		 2
#define PROJ_MODE_SCREENXY		 3
#define PROJ_MODE_ASPECT_R		 4         
#define _PROJ_METRICS(loc,s_size) (loc*s_size - loc*(s_size/2)) // Project X Screen Coords

// *** TEXT OBJECT DEFINES ***//
#define LEFT_JUST   0
#define RIGHT_JUST  1
#define CENTER_JUST 2


// *** PARTICLE CLIPPING MODES
#define NO_CLIPPING 0
#define AUTO_WRAP	1
#define CLIP_STND	2

#endif