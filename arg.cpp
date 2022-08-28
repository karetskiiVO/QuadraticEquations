#include "arg.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

const int com_len = 4;

arg_cmd com[com_len];

void check_args (int argc, char* argv[]) {
    com[0].f_name = "--help";
    com[0].m_name = "-h";
    com[1].f_name = "--log";
    com[1].m_name = "-l";
    com[2].f_name = "--uncoloured";
    com[2].m_name = "-ucol";
    com[3].f_name = "--debug";
    com[3].m_name = "-d";

    assert(argc > 0 && "Err in start");
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], com[0].f_name) || !strcmp(argv[i], com[0].m_name))
            isHelp = true;
        else if (!strcmp(argv[i], com[1].f_name) || !strcmp(argv[i], com[1].m_name))
            isLog  = true;
        else if (!strcmp(argv[i], com[2].f_name) || !strcmp(argv[i], com[2].m_name))
            isUnColored = true;     
        else if (!strcmp(argv[i], com[3].f_name) || !strcmp(argv[i], com[3].m_name))
            isDebug = true;  

        else
            printf("%s has no difinition\n", argv[i]);
    }
}

void Help () {
    printf("te progrm support comads:\n");
    for (int i = 0; i < com_len; i++) {
        printf("\t%s", com[i].f_name);
    }
    printf("\n");
    for (int i = 0; i < com_len; i++) {
        printf("\t%s", com[i].m_name);
    }
    printf("\n");
}