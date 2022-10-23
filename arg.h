#ifndef Arg
#define Arg

#define printLogAnsw(b) \
    if(b){                                                                                  \
        FILE* logfile = NULL;                                                               \
        logfile = fopen(logFile, "a");                                                      \
        fprintf(logfile, "%s  %d sol:", __PRETTY_FUNCTION__, answ->numofSolutions);         \
        for (int i_d = 0; i_d < answ->numofSolutions; i_d++) {                              \
            fprintf(logfile, "\t%lg", answ->solutions[i_d]);                                \
        }                                                                                   \
        fprintf(logfile, "\n");                                                             \
        fclose(logfile);                                                                    \
    }                                                                                       \

typedef struct {
    char* f_name;
    char* m_name;
} arg_cmd;

extern bool isUnColored;
extern bool isLog;
extern bool isHelp;
extern bool isDebug;

void check_args (int argc, char* argv[]);

void Help ();
#endif// arg.h