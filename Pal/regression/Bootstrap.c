#include "pal.h"
#include "pal_regression.h"

int main(int argc, char** argv, char** envp) {
    /* check if the program is loaded */
    pal_printf("User Program Started\n");

    /* check control block */
    /* check arguments */
    pal_printf("# of Arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        pal_printf("argv[%d] = %s\n", i, argv[i]);
    }

    /* parent process */
    const struct pal_public_state* pal_public_state = DkGetPalPublicState();
    pal_printf("Parent Process: %p\n", pal_public_state->parent_process);

    /* test debug stream */
    const char* msg = "Written to Debug Stream\n";
    int ret = DkDebugLog((char*)msg, strlen(msg));
    if (ret < 0) {
        pal_printf("Failed to write the debug message.\n");
        return 1;
    }

    /* Allocation Alignment */
    pal_printf("Allocation Alignment: %ld\n", pal_public_state->alloc_align);

    /* user address range */
    pal_printf("User Address Range: %p - %p\n", pal_public_state->user_address.start,
               pal_public_state->user_address.end);

    if (pal_public_state->user_address.start && pal_public_state->user_address.end &&
        pal_public_state->user_address.start < pal_public_state->user_address.end)
        pal_printf("User Address Range OK\n");

    pal_printf("CPU num: %ld\n", pal_public_state->cpu_info.online_logical_cores);
    pal_printf("CPU vendor: %s\n", pal_public_state->cpu_info.cpu_vendor);
    pal_printf("CPU brand: %s\n", pal_public_state->cpu_info.cpu_brand);
    pal_printf("CPU family: %ld\n", pal_public_state->cpu_info.cpu_family);
    pal_printf("CPU model: %ld\n", pal_public_state->cpu_info.cpu_model);
    pal_printf("CPU stepping: %ld\n", pal_public_state->cpu_info.cpu_stepping);
    pal_printf("CPU flags: %s\n", pal_public_state->cpu_info.cpu_flags);

    return 0;
}
