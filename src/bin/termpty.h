typedef struct _Termpty   Termpty;
typedef struct _Termcell  Termcell;
typedef struct _Termatt   Termatt;
typedef struct _Termstate Termstate;
typedef struct _Termsave  Termsave;

#define COL_DEF        0
#define COL_BLACK      1
#define COL_RED        2
#define COL_GREEN      3
#define COL_YELLOW     4
#define COL_BLUE       5
#define COL_MAGENTA    6
#define COL_CYAN       7
#define COL_WHITE      8
#define COL_INVIS      9

#define COL_INVERSE   10
#define COL_INVERSEBG 11

struct _Termatt
{
   unsigned char fg, bg;
   unsigned short bold : 1;
   unsigned short faint : 1;
   unsigned short italic : 1;
   unsigned short underline : 1;
   unsigned short blink : 1;
   unsigned short blink2 : 1;
   unsigned short inverse : 1;
   unsigned short invisible : 1;
   unsigned short strike : 1;
   unsigned short fg256 : 1;
   unsigned short bg256 : 1;
   // below used for working out text from selections
   unsigned short autowrapped : 1;
   unsigned short newline : 1;
   unsigned short tab : 1;
   // 2 bits left
};

struct _Termstate
{
   int           cx, cy;
   Termatt       att;
   unsigned char charset;
   unsigned char charsetch;
   unsigned char chset[4];
   int           scroll_y1, scroll_y2;
   int           had_cr_x, had_cr_y;
   unsigned int  multibyte : 1;
   unsigned int  alt_kp : 1;
   unsigned int  insert : 1;
   unsigned int  appcursor : 1;
   unsigned int  wrap : 1;
   unsigned int  wrapnext : 1;
   unsigned int  hidecursor : 1;
   unsigned int  crlf : 1;
   unsigned int  had_cr : 1;
};

struct _Termpty
{
   Ecore_Event_Handler *hand_exe_exit;
   Ecore_Fd_Handler *hand_fd;
   struct {
      struct {
         void (*func) (void *data);
         void *data;
      } change, scroll, set_title, set_icon, cancel_sel;
   } cb;
   struct {
      const char *title;
      const char *icon;
   } prop;
   int w, h;
   int fd, slavefd;
   pid_t pid;
   Termcell *screen, *screen2;
   Termsave **back;
   int backmax, backpos;
   int backscroll_num;
   int *buf;
   int buflen;
   Termstate state, save, swap;
   unsigned int altbuf : 1;
};

struct _Termcell
{
   int      glyph;
   Termatt  att;
};

struct _Termsave
{
   int w;
   Termcell cell[1];
};

Termpty  *termpty_new(const char *cmd, int w, int h, int backscroll);
void      termpty_free(Termpty *ty);
Termcell *termpty_cellrow_get(Termpty *ty, int y, int *wret);
void      termpty_write(Termpty *ty, const char *input, int len);
void      termpty_resize(Termpty *ty, int w, int h);
void      termpty_backscroll_set(Termpty *ty, int size);
