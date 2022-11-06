#ifndef I_ARGSPARSER
#define I_ARGSPARSER
#endif

typedef struct {
    char* input_path;  // path to input bf file
    char* output_path; // path to output binary
} Args;

// try parse args, return result code
int parse_args(Args* args, int argc, char *argv[]);