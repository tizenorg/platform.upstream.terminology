typedef struct _Config Config;

struct _Config
{
   struct {
      const char    *name;
      int            size;
      unsigned char  bitmap;
   } font;
   int               scrollback;
   const char       *theme;
   const char       *background;
   unsigned char     jump_on_change;
   unsigned char     translucent;
   const char       *wordsep;
   int               vidmod;
   unsigned char     mute;
};

extern Config *config;
extern Eina_Bool config_tmp;

void config_init(void);
void config_shutdown(void);
void config_save(void);
