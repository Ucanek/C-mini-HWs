#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fnmatch.h>

/*
 * Minihomework 11: Pattern matching
 * ---------------
 * Author: Vojtech Jelinek
 * Email:  vojtechjelinek@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task here is to count files that correspond to some pattern.
 *
 * Imagine the filenames you receive are names for images withthis structure:
 * "<theme>_<id>_<year>-<month>-<day>.<ext>"
 * <theme> is theme of the image
 * <id> is identificator of the image, 
 * <year>, <month> and <day> specify when the image was created
 * <ext> is the file extension. 
 * So for example "dog_11_2018-11-12.jpg", "cat_1_2011-01-01.png".
 *
 * You need to count the number of filenames with "dog" theme (exactly), were
 * created in year 2018 and have ".jpg" extension.
 * 
 * For example, satisfying filenames, that should be counted, are:
 * "dog_11_2018-11-11.jpg",
 * "dog_11215_2018-01-05.jpg",
 * "dog_0_2018-99-99.jpg".
 *  
 * Images not satisfying the condition:
 * "cat_20_2018-01-01.jpg",
 * "doggo_1231_2018-05-21.jpg", 
 * "dog_1_2017-01-30.jpg",
 * "dog_222_2018-01-01.png".
 * 
 * You do not need to test the validity of the data (if the dates are real
 * or not etc.).
 *
 * Cases that have different structure than specified in previous paragraph
 * will not be tested.
 *
 * The function returns the number of files matched.
 *
 * Use fnmatch function from fnmatch.h, for the flags argument of fnmatch use
 * FNM_PATHNAME.
 *
 * Useful links:
 * - fnmatch:
 *   https://pubs.opengroup.org/onlinepubs/009695399/functions/fnmatch.html
 * - pattern matching:
 *   https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_13_01
 */

int count_matching_files(int filenames_count, char **filenames)
{
    /* TODO your code here instead of returning -1 */
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s files\n", argv[0]);
        return EXIT_FAILURE;
    }

    int count = count_matching_files(argc - 1, argv + 1);
    printf("%d\n", count);
    return EXIT_SUCCESS;
}
