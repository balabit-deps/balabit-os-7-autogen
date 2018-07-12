/*   -*- buffer-read-only: t -*- vi: set ro:
 *
 *  DO NOT EDIT THIS FILE   (fork.c)
 *
 *  It has been AutoGen-ed
 *  From the definitions    ./xmlopts.def
 *  and the template file   fork.tpl
 *
 *  This module will fire up autogen and have it read definitions
 *  from its standard-in.
 */

static char const zFsError[] = "%s fs ERROR %d (%s) on %s\n";

static void
add_arg(char const * arg, int ix)
{
    char ** arg_vec = xml2agOptions.origArgVect;
    int      arg_ct = (int)xml2agOptions.origArgCt;

    if (ix >= (int)arg_ct) {
        arg_ct += 5;
        arg_vec = realloc(arg_vec, sizeof(void *) * (size_t)(arg_ct+1));
        if (arg_vec == NULL) {
            fprintf(stderr, "No memory for %d args\n", arg_ct);
            exit(EXIT_FAILURE);
        }
        xml2agOptions.origArgVect = arg_vec;
    }
    arg_vec[ ix ] = VOIDP(arg);
}

static int
become_child(int * fd, char const * pzInput)
{
    if (pipe(fd) != 0) {
        fprintf(stderr, zFsError, xml2agOptions.pzProgName,
                errno, strerror( errno ), "pipe(2)");
        exit(EXIT_FAILURE);
    }

    fflush(stdout);
    fflush(stdin);

    switch (fork()) {
    case -1:
        fprintf(stderr, zFsError, xml2agOptions.pzProgName,
                errno, strerror( errno ), "fork(2)");
        exit(EXIT_FAILURE);

    case 0:
        fclose(stdin);
        if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO) {
            fprintf(stderr, zFsError, xml2agOptions.pzProgName,
                    errno, strerror( errno ), "dup2(2) w/ STDIN_FILENO");
            exit(EXIT_FAILURE);
        }
        close(fd[1]);
        break;

    default:
        errno = 0;
        outFp = fdopen(fd[1], "w");
        if (outFp == NULL) {
            fprintf(stderr, zFsError, xml2agOptions.pzProgName,
                    errno, strerror( errno ), "fdopen(2) w/ pipe[1]");
            exit(EXIT_FAILURE);
        }
        close(fd[0]);
        return 0;
    }

    if (! HAVE_OPT( BASE_NAME )) {
        if (pzInput == NULL)
            pzInput = "stdin";
        else {
            char * pz = strrchr(pzInput, '.');
            if (pz != NULL) {
                pzInput = pz = strdup(pzInput);
                pz = strrchr(pz, '.');
                *pz = '\0';
            }
        }
        SET_OPT_BASE_NAME(pzInput);
    }

    return 1;
}

void
forkAutogen(char const * pzInput)
{
    int fd[2];

    if (! become_child(fd, pzInput))
        return;

    {
        static char const zAg[] = "autogen";
        char * pzArg;
        int    ix    = 1;

        {
            char * pz = malloc(strlen( xml2agOptions.pzProgPath ) + 7);
            char * p  = strrchr(xml2agOptions.pzProgPath, '/');

            if (p == NULL) {
                strcpy(pz, zAg);
            } else {
                size_t len = (size_t)(p - xml2agOptions.pzProgPath) + 1;
                memcpy(pz, xml2agOptions.pzProgPath, len);
                strcpy(pz + len, zAg);
            }

            add_arg(pz, 0);
        }

        if (HAVE_OPT(TEMPL_DIRS)) {
            int  optCt = STACKCT_OPT(TEMPL_DIRS);
            char const ** ppOA  = STACKLST_OPT(TEMPL_DIRS);
            do  {
                char const * pA = *(ppOA++);
                pzArg = malloc(14 + strlen(pA));
                sprintf(pzArg, "--templ-dirs=%s", pA);
                add_arg(pzArg, ix++);
            } while (--optCt > 0);
        }

        if (HAVE_OPT(LIB_TEMPLATE)) {
            int  optCt = STACKCT_OPT(LIB_TEMPLATE);
            char const ** ppOA  = STACKLST_OPT(LIB_TEMPLATE);
            do  {
                char const * pA = *(ppOA++);
                pzArg = malloc(16 + strlen(pA));
                sprintf(pzArg, "--lib-template=%s", pA);
                add_arg(pzArg, ix++);
            } while (--optCt > 0);
        }

        if (HAVE_OPT(DEFINITIONS)) {
            pzArg = malloc(15 + strlen( OPT_ARG( DEFINITIONS )));
            sprintf(pzArg, "--definitions=%s", OPT_ARG( DEFINITIONS ));
            add_arg(pzArg, ix++);
        }

        if (HAVE_OPT(SHELL)) {
            pzArg = malloc(9 + strlen( OPT_ARG( SHELL )));
            sprintf(pzArg, "--shell=%s", OPT_ARG( SHELL ));
            add_arg(pzArg, ix++);
        }

        if (HAVE_OPT(NO_FMEMOPEN)) {
            add_arg("--no-fmemopen", ix++);
        }

        if (HAVE_OPT(EQUATE)) {
            pzArg = malloc(10 + strlen( OPT_ARG( EQUATE )));
            sprintf(pzArg, "--equate=%s", OPT_ARG( EQUATE ));
            add_arg(pzArg, ix++);
        }

        if (HAVE_OPT(BASE_NAME)) {
            pzArg = malloc(13 + strlen( OPT_ARG( BASE_NAME )));
            sprintf(pzArg, "--base-name=%s", OPT_ARG( BASE_NAME ));
            add_arg(pzArg, ix++);
        }

        if (HAVE_OPT(SOURCE_TIME)) {
            add_arg("--source-time", ix++);
        }

        if (HAVE_OPT(WRITABLE)) {
            add_arg("--writable", ix++);
        }

        if (HAVE_OPT(LOOP_LIMIT)) {
            pzArg = malloc((size_t)26);
            sprintf(pzArg, "--loop-limit=%d", (int)OPT_VALUE_LOOP_LIMIT);
            add_arg(pzArg, ix++);
        }

        if (HAVE_OPT(TIMEOUT)) {
            pzArg = malloc((size_t)23);
            sprintf(pzArg, "--timeout=%d", (int)OPT_VALUE_TIMEOUT);
            add_arg(pzArg, ix++);
        }

        if (HAVE_OPT(TRACE)) {
            static char const * kwlist[] = {
                "nothing",        "debug-message",  "server-shell",
                "templates",      "block-macros",   "expressions",
                "everything" };
            pzArg = malloc(9 + strlen( kwlist[ OPT_VALUE_TRACE ] ));
            sprintf(pzArg, "--trace=%s", kwlist[ OPT_VALUE_TRACE ]);
            add_arg(pzArg, ix++);
        }

        if (HAVE_OPT(TRACE_OUT)) {
            pzArg = malloc(13 + strlen( OPT_ARG( TRACE_OUT )));
            sprintf(pzArg, "--trace-out=%s", OPT_ARG( TRACE_OUT ));
            add_arg(pzArg, ix++);
        }

        if (HAVE_OPT(SHOW_DEFS)) {
            add_arg("--show-defs", ix++);
        }

        if (HAVE_OPT(USED_DEFINES)) {
            add_arg("--used-defines", ix++);
        }

        if (HAVE_OPT(CORE)) {
            add_arg("--core", ix++);
        }

        if (HAVE_OPT(SKIP_SUFFIX)) {
            int  optCt = STACKCT_OPT(SKIP_SUFFIX);
            char const ** ppOA  = STACKLST_OPT(SKIP_SUFFIX);
            do  {
                char const * pA = *(ppOA++);
                pzArg = malloc(15 + strlen(pA));
                sprintf(pzArg, "--skip-suffix=%s", pA);
                add_arg(pzArg, ix++);
            } while (--optCt > 0);
        }

        if (HAVE_OPT(SELECT_SUFFIX)) {
            int  optCt = STACKCT_OPT(SELECT_SUFFIX);
            char const ** ppOA  = STACKLST_OPT(SELECT_SUFFIX);
            do  {
                char const * pA = *(ppOA++);
                pzArg = malloc(17 + strlen(pA));
                sprintf(pzArg, "--select-suffix=%s", pA);
                add_arg(pzArg, ix++);
            } while (--optCt > 0);
        }

        if (HAVE_OPT(DEFINE)) {
            int  optCt = STACKCT_OPT(DEFINE);
            char const ** ppOA  = STACKLST_OPT(DEFINE);
            do  {
                char const * pA = *(ppOA++);
                pzArg = malloc(10 + strlen(pA));
                sprintf(pzArg, "--define=%s", pA);
                add_arg(pzArg, ix++);
            } while (--optCt > 0);
        }

        if (HAVE_OPT(UNDEFINE)) {
            int  optCt = STACKCT_OPT(UNDEFINE);
            char const ** ppOA  = STACKLST_OPT(UNDEFINE);
            do  {
                char const * pA = *(ppOA++);
                pzArg = malloc(12 + strlen(pA));
                sprintf(pzArg, "--undefine=%s", pA);
                add_arg(pzArg, ix++);
            } while (--optCt > 0);
        }

        if (HAVE_OPT(MAKE_DEP)) {
            int  optCt = STACKCT_OPT(MAKE_DEP);
            char const ** ppOA  = STACKLST_OPT(MAKE_DEP);
            do  {
                char const * pA = *(ppOA++);
                pzArg = malloc(12 + strlen(pA));
                sprintf(pzArg, "--make-dep=%s", pA);
                add_arg(pzArg, ix++);
            } while (--optCt > 0);
        }

        xml2agOptions.origArgVect[ix] = NULL;
        execvp(xml2agOptions.origArgVect[0], xml2agOptions.origArgVect);

        /*
         *  IF the first try fails, it may be because xml2ag and autogen have
         *  different paths.  Try again with just plain "autogen" and let
         *  the OS search "PATH" for the program.
         */
        execvp(zAg, xml2agOptions.origArgVect);
        fprintf(stderr, zFsError, xml2agOptions.pzProgName,
                errno, strerror(errno), "execvp(2)");
        exit(EXIT_FAILURE);
    }
}

/*
 * Local Variables:
 * c-file-style: "stroustrup"
 * indent-tabs-mode: nil
 * End:
 * end of fork.c */
