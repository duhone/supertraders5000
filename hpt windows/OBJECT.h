#if !defined(OBJECT_H)
#define OBJECT_H

class __declspec (dllexport) OBJECT
{
public:

	OBJECT();
	~OBJECT();
	
	virtual void RRender();
	virtual void Render();
};

#endif