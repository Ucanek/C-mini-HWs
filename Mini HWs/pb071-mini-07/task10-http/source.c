#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Minihomework 10: HTTP request
 * ---------------
 * Author: Matej Focko
 * Email:  485516@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ----------------------------------------------------------------------------
 *
 * Your task is to write a pair of functions for a simplified http request that
 * will consist of header and data. URL will be omitted.
 *
 * Write a `create_http_request` function, that allocates the memory needed for
 * the request. In case the allocation fails, you **cannot** modify the memory
 * of the request which you are supposed to set accordingly.
 *
 * To complement the creation, write a function `free_http_request` that will
 * deallocate the memory.
 *
 * Check the http_request struct and function documentations to determine
 * the exact behaviour of functions to implement.
 *
 * Do not change anything else except functions mentioned earlier.
 */

struct http_request
{
    size_t header_size;
    void *header;

    size_t data_size;
    void *data;
};

/**
 * Allocate needed memory for the request, set attributes and make sure header
 * of the request does not depend on the passed pointer.
 *
 * Do not modify the passed in a pointer in case of failure.
 *
 * @param request Pointer to the request that is to be initialized.
 * @param header_size Size of the header.
 * @param data_size Size of the data.
 * @param header Pointer to the memory holding header.
 * @returns true if created successfully, false otherwise.
 */
bool create_http_request(struct http_request *request, size_t header_size, size_t data_size, void *header)
{
    if (request == NULL || header == NULL){
        return false;
    }

    void *new_header = malloc(header_size);
    if (request->header == NULL){
        return false;
    }

    void *new_data = malloc(data_size);
    if (new_data == NULL){
        free(new_header);
        return false;
    }

    memcpy(new_header, header, header_size);
    request->header_size = header_size;
    request->header = new_header;
    request->data_size = data_size;
    request->data = new_data;

    return true;
}

/**
 * Free memory of the request and put the request in such state it cannot be double
 * freed.
 * @param request Pointer to the request.
 */
void free_http_request(struct http_request *request)
{
    if (request->header != NULL){
        free(request->header);
        request->header_size = 0;
        request->header = NULL;
    }

    if (request->data != NULL){
        free(request->data);
        request->data_size = 0;
        request-> data = NULL;
    }
}

static void print_data(size_t size, unsigned char *data)
{
    for (size_t i = 0; i < size; i++) {
        printf(" 0x%02hhX", *(data + i));
    }
}

static void print_request(struct http_request *request)
{
    printf("Request: size of header: %zu, size of data: %zu\n", request->header_size, request->data_size);

    printf("Header:");
    print_data(request->header_size, request->header);

    printf("\nData:");
    print_data(request->data_size, request->data);
}

int main(void)
{
    struct http_request request;

    // Basic test
    if (!create_http_request(&request, 13, 5, "Hello World!")) {
        printf("Failed to create http request!\n");
        return EXIT_FAILURE;
    }

    char *p = request.data;
    for (size_t i = 1; i <= 5; i++) {
        *p = i * 3;
        p++;
    }
    print_request(&request);
    printf("\n\nHeader as string: %s\n---\n", (char *) request.header);

    free_http_request(&request);

    // More mean test
    char mean[] = "Hello World!";
    if (!create_http_request(&request, 13, 5, mean)) {
        printf("Failed to create http request!\n");
        return EXIT_FAILURE;
    }
    mean[6] = 'w';

    p = request.data;
    for (size_t i = 1; i <= 5; i++) {
        *p = i * 5;
        p++;
    }
    print_request(&request);
    printf("\n\nHeader as string: %s\n", (char *) request.header);

    free_http_request(&request);

    return EXIT_SUCCESS;
}
