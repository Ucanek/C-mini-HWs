#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * http
 *
 * \author Matej Focko
 */

/*
 * Do not just assign the header pointer to request, modifying the value stored
 * in the pointer will then also affect the value in request.header (since
 * those two values are actually single one in memory).
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
    void *new_header = malloc(header_size);
    if (new_header == NULL) {
        fprintf(stderr, "Failed to allocate memory for header of request\n");
        return false;
    }

    void *new_data = malloc(data_size);
    if (new_data == NULL) {
        fprintf(stderr, "Failed to allocate memory for data of request\n");
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
    if (request->header != NULL) {
        free(request->header);

        request->header_size = 0;
        request->header = NULL;
    }

    if (request->data != NULL) {
        free(request->data);

        request->data_size = 0;
        request->data = NULL;
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
