#include "shell.h"
int main ()
{
        int err = 0;
        do
        {
                print_prompt();
                // read
                char *input = 0;
                err = read_line(&input);
                if(err < 0)
                {
                        free(input);
                        break;
                }
                // eval
                err = eval(input);
                // loop
        }
        while (!err);
	return 0;
}
