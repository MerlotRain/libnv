/**
 * Copyright (c) 2023-present Merlot.Rain
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef SDA_H
#define SDA_H

#include <stddef.h>
#include "nv-common.h"

struct nv__sda {
    char *data;
    size_t len;
};

struct nv__sda *nv__sda_new(size_t element_size);
char *nv__sda_free(struct nv__sda *sda, NV_BOOLEAN free_segment);
struct nv__sda *nv__sda_append_vals(struct nv__sda *a, void *data, size_t len);
struct nv__sda *nv__sda_prepend_vals(struct nv__sda *a, void *data, size_t len);
struct nv__sda *nv__sda_insert_vals(struct nv__sda *a, size_t index_,
                                    void *data, size_t len);
struct nv__sda *nv__sda_set_size(struct nv__sda *a, size_t length);
struct nv__sda *nv__sda_remove_range(struct nv__sda *a, size_t index_,
                                     size_t length);
void nv__sda_set_clear_func(struct nv__sda *a, DestoryFunc func);

#define nv__sda_index(a, t, i)      (((t *) (void *) (a)->data)[(i)])
#define nv__sda_append_val(a, v)    nv__sda_append_vals(a, &(v), 1)
#define nv__sda_prepend_val(a, v)   nv__sda_prepend_vals(a, &(v), 1)
#define nv__sda_insert_val(a, i, v) nv__sda_insert_vals(a, i, &(v), 1)
#endif