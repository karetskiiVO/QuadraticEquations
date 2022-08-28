#ifndef Arg
#define Arg
typedef struct {
    char* f_name;
    char* m_name;
} arg_cmd;

extern bool isUnColored;
extern bool isLog;
extern bool isHelp;
extern bool isDebug;

void check_args(int argc, char* argv[]);

void Help ();
#endif