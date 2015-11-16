/*
 * 
 *   example-1.c
 *
 *   XML config file parser example 2
 *
 *   Ron Croonenberg rocr@lanl.gov
 *   High Performance Computing (HPC-3)
 *   Los Alamos National Laboratory
 *
 *
 *   06-08-2015:        initial start rocr@lanl.gov
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "parse-inc/config-structs.h"

#include "confpars-structs.h"
#include "confpars.h"
#include "parse-types.h"
#include "parsedata.h"

int main(int argc, char *argv[])							// A simple example
{
struct config *config;									// this structure exist after the first parse step
char **name, my_name[] = "Ron Croonenberg", not_my_name[] = "Other Guy", vers[6] = "1.0";

config = (struct config *)malloc(sizeof(struct config));				// so let's create one

memset(config,      0x00, sizeof(struct config));

// Here is one way to do this:
name = (char **)getMemberPtr("config->version", config);
*name = vers;
printf("%s\n", config->version);

//name = (char **)getMemberPtr("config->namespace[0].name", config);				// get the pointer to char * in a structure
//*name = my_name;									// change it
//printf("%s\n", config->namespace[0].name);                                              // check to see it ended up in the actual 'super structure'

// and of course:
//config->namespace[0].name = not_my_name;						// I know what I am doing
//printf("%s\n", config->namespace[0].name);						// check to see it ended up in the actual 'super structure'

free(config);										// and we set it free again

return 0;										// done.
}											// yay, an example in less than 50 lines.
