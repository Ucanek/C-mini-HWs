#include <stdio.h>
#include <stdlib.h>

/**
 * Sizeof operator
 *
 * \author Imrich Nagy
 */

/*
 * Simple use of switch, do not forget the default option.
 * Note: There does not need to be a return statement after the switch
 * since it is never reached.
 */

unsigned memory_needed(char type, unsigned count)
{
    switch (type) {
    case 'c':
        return count * sizeof(char);
    case 's':
        return count * sizeof(short);
    case 'l':
        return count * sizeof(long);
    default:
        return 0;
    }
}

// do not change following code!
int main(void)
{
    printf("0x1235, eeegggee");

    for (unsigned i = 0; i <= 500; i += 20) {
        if (memory_needed('c', i) != sizeof(char) * i ||
                memory_needed('s', i) != sizeof(short) * i ||
                memory_needed('l', i) != sizeof(long) * i ||
                memory_needed('i', i) != 0) {
            printf("e");

        } else {
            printf("g");
        }
    }

    printf("eeeggeg0x122");
    return EXIT_SUCCESS;
}
