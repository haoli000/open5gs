/**
 * @file main.c
 */

/* Core library */
#define TRACE_MODULE _main_
#include "core_debug.h"
#include "core_signal.h"

/* Server */
#include "cellwire.h"

static char *compile_time = __DATE__ " " __TIME__;

static void show_version()
{
    printf("CellWire daemon v%s - %s\n", PACKAGE_VERSION, compile_time);
}

static void show_help()
{
    show_version();

    printf("\n"
           "Usage: cellwired [arguments]\n"
           "\n"
           "Arguments:\n"
           "   -v                   Show version\n"
           "   -h                   Show help\n"
           "   -d                   Start as daemon\n"
           "   -f                   Set configuration file name\n"
           "   -l log_path          Fork log daemon with file path to be logged to\n"
           "\n"
           );
}

static int check_signal(int signum)
{
    switch (signum)
    {
        case SIGTERM:
        case SIGINT:
        {
            d_info("%s received", 
                    signum == SIGTERM ? "SIGTERM" : "SIGINT");

            return 1;
        }
        case SIGUSR1:
        {
            break;
        }
        default:
        {
            d_error("Unknown signal number = %d\n", signum);
            break;
        }
            
    }
    return 0;
}


int main(int argc, char *argv[])
{
    /**************************************************************************
     * Starting up process.
     *
     * Keep the order of starting-up
     */
    char *config_path = NULL;
    char *log_path = NULL;

    while (1)
    {
        int opt = getopt (argc, argv, "vhdf:l:");
        if (opt == -1)
            break;

        switch (opt)
        {
            case 'v':
                show_version();
                return EXIT_SUCCESS;
            case 'h':
                show_help();
                return EXIT_SUCCESS;
            case 'd':
            {
                pid_t pid;
                pid = fork();

                d_assert(pid >= 0, return EXIT_FAILURE, "fork() failed");

                if (pid != 0)
                {
                    /* Parent */
                    return EXIT_SUCCESS;
                }
                /* Child */

                setsid();
                umask(027);
                break;
            }
            case 'f':
                config_path = optarg;
                break;
            case 'l':
                log_path = optarg;
                break;
            default:
                show_help();
                return EXIT_FAILURE;
        }
    }

    {
#if 0
        extern int _gtp_xact;
        d_trace_level(&_gtp_xact, 100);
        extern int _mme_sm;
        d_trace_level(&_mme_sm, 100);
        extern int _s1ap_sm;
        d_trace_level(&_s1ap_sm, 100);
        extern int _emm_sm;
        d_trace_level(&_emm_sm, 100);
        extern int _esm_sm;
        d_trace_level(&_esm_sm, 100);

        extern int _s1ap_recv;
        d_trace_level(&_s1ap_recv, 100);
        extern int _s1ap_send;
        d_trace_level(&_s1ap_send, 100);
        extern int _s6a;
        d_trace_level(&_s6a, 100);
        extern int _tlv_msg;
        d_trace_level(&_tlv_msg, 1);
#endif
    }

    if (cellwire_initialize(config_path, log_path) != CORE_OK)
    {
        d_fatal("CellWire initialization failed. Aborted");
        return EXIT_FAILURE;
    }

    show_version();
    d_info("CellWire daemon start");
    signal_thread(check_signal);

    d_info("CellWire daemon terminating...");

    cellwire_terminate();

    return EXIT_SUCCESS;
}
