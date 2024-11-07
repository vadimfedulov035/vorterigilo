// Copyright 2020 Joshua J Baker. All rights reserved.
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file.

#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif  // __cplusplus

struct map;

struct map *map_new(size_t elsize, size_t cap, uint64_t seed0, 
    uint64_t seed1, 
    uint64_t (*hash)(const void *item, uint64_t seed0, uint64_t seed1),
    int (*compare)(const void *a, const void *b, void *udata),
    void (*elfree)(void *item),
    void *udata);

struct map *map_new_with_allocator(void *(*malloc)(size_t), 
    void *(*realloc)(void *, size_t), void (*free)(void*), size_t elsize, 
    size_t cap, uint64_t seed0, uint64_t seed1,
    uint64_t (*hash)(const void *item, uint64_t seed0, uint64_t seed1),
    int (*compare)(const void *a, const void *b, void *udata),
    void (*elfree)(void *item),
    void *udata);

void map_free(struct map *map);
void map_clear(struct map *map, bool update_cap);
size_t map_count(struct map *map);
bool map_oom(struct map *map);
const void *map_get(struct map *map, const void *item);
const void *map_set(struct map *map, const void *item);
const void *map_delete(struct map *map, const void *item);
const void *map_probe(struct map *map, uint64_t position);
bool map_scan(struct map *map, bool (*iter)(const void *item, void *udata), void *udata);
bool map_iter(struct map *map, size_t *i, void **item);

uint64_t map_sip(const void *data, size_t len, uint64_t seed0, uint64_t seed1);
uint64_t map_murmur(const void *data, size_t len, uint64_t seed0, uint64_t seed1);
uint64_t map_xxhash3(const void *data, size_t len, uint64_t seed0, uint64_t seed1);

const void *map_get_with_hash(struct map *map, const void *key, uint64_t hash);
const void *map_delete_with_hash(struct map *map, const void *key, uint64_t hash);
const void *map_set_with_hash(struct map *map, const void *item, uint64_t hash);
void map_set_grow_by_power(struct map *map, size_t power);
void map_set_load_factor(struct map *map, double load_factor);


// DEPRECATED: use `map_new_with_allocator`
void map_set_allocator(void *(*malloc)(size_t), void (*free)(void*));

#if defined(__cplusplus)
}
#endif  // __cplusplus

#endif  // HASHMAP_H
