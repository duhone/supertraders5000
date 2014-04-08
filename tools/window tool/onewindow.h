//---------------------------------------------------------------------------

#ifndef onewindowH
#define onewindowH
//---------------------------------------------------------------------------

class one_window
{
public:
        one_window();
        ~one_window();
        void setparent_window(int arg);
        void setpallette_number(int arg);
        void setxoffset(float arg);
        void setyoffset(float arg);
        void setxscale(float arg);
        void setyscale(float arg);
        void setmessage_number(int arg);
        void setmessage_arg(int arg);
        int getparent_window();
        int getpallette_number();
        float getxoffset();
        float getyoffset();
        float getxscale();
        float getyscale();
        int getmessage_number();
        int getmessage_arg();


private:
        int parent_window;
        int pallette_number;
        float xoffset;
        float yoffset;
        float xscale;
        float yscale;
        int message_number;
        int message_arg;

};



#endif
