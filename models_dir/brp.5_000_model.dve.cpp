#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <setjmp.h>

#pragma clang diagnostic ignored "-Wparentheses-equality"

typedef uint64_t ulong_long_int_t;
typedef int64_t slong_long_int_t;
typedef uint32_t ulong_int_t;
typedef int32_t slong_int_t;
typedef union
{
    uint16_t var;
    uint32_t __padding__;
} ushort_int_t;
typedef union
{
    int16_t var;
    uint32_t __padding__;
} sshort_int_t;
typedef union
{
    uint8_t var;
    uint32_t __padding__;
} ubyte_t;
typedef ubyte_t byte_t;
typedef union
{
    int8_t var;
    uint32_t __padding__;
} sbyte_t;
typedef size_t size_int_t;

typedef struct transition_info
{
    int* label;
    int  group;
    int  por_proviso;
} transition_info_t;


struct state_struct_t
{
    byte_t prod_n;
    struct
    {
        ushort_int_t state;
        byte_t result;
        byte_t n;
    }
    __attribute__((__packed__)) Producer;
    struct
    {
        ushort_int_t state;
        byte_t m;
        byte_t n;
    }
    __attribute__((__packed__)) Consumer;
    struct
    {
        ushort_int_t state;
        byte_t ab;
        byte_t n;
        byte_t i;
        byte_t counter;
    }
    __attribute__((__packed__)) Sender;
    struct
    {
        ushort_int_t state;
        byte_t value;
        byte_t exp_ab;
    }
    __attribute__((__packed__)) Receiver;
    struct
    {
        ushort_int_t state;
        byte_t value;
    }
    __attribute__((__packed__)) K;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) L;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

state_struct_t initial_state = { 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0 };

extern "C" int get_state_size() {
    return state_size;
}

extern "C" void get_initial_state( void *to )
{
    memcpy(to, &initial_state, state_size);
}

extern "C" int have_property()
{
    return false;
}

extern "C" int get_action( void* model, int t, const state_struct_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    transition_info_t transition_info = { NULL, t, 0 };
    (void)model; // ignore model
    int states_emitted = 0;
    state_struct_t tmp;
    state_struct_t *out = &tmp;
    goto switch_state;
    l0: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 1);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l1: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 2);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l2: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 3);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l3: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 4);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l4: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 5);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l5: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 6);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l6: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 7);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l7: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 8);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l8: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 9);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l9: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 10);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l10: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 11);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l11: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 12);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l12: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 13);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l13: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 14);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l14: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 15);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l15: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 16);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l16: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 17);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l17: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 18);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l18: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 19);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l19: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        ((*out).prod_n.var = 20);
        cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l20: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Producer.result.var) = (1);
        cpy[((int*)&((*out).Producer.result.var) - (int*)&(*out))] = 0;
        (*out).Producer.state.var = 3;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 6;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l21: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Producer.result.var) = (2);
        cpy[((int*)&((*out).Producer.result.var) - (int*)&(*out))] = 0;
        (*out).Producer.state.var = 3;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 6;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l22: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Producer.result.var) = (3);
        cpy[((int*)&((*out).Producer.result.var) - (int*)&(*out))] = 0;
        (*out).Producer.state.var = 3;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 6;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l23: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l24: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Consumer.m.var) = (1);
        cpy[((int*)&((*out).Consumer.m.var) - (int*)&(*out))] = 0;
        (*out).Consumer.state.var = 1;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        ((*out).Consumer.n.var = (*out).Consumer.n.var + 1);
        cpy[((int*)&((*out).Consumer.n.var) - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 3;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l25: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Consumer.m.var) = (5);
        cpy[((int*)&((*out).Consumer.m.var) - (int*)&(*out))] = 0;
        (*out).Consumer.state.var = 1;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        ((*out).Consumer.n.var = (*out).Consumer.n.var + 1);
        cpy[((int*)&((*out).Consumer.n.var) - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 3;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l26: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Consumer.m.var) = (4);
        cpy[((int*)&((*out).Consumer.m.var) - (int*)&(*out))] = 0;
        (*out).Consumer.state.var = 1;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        ((*out).Consumer.n.var = (*out).Consumer.n.var + 1);
        cpy[((int*)&((*out).Consumer.n.var) - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 3;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l27: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Consumer.m.var) = (2);
        cpy[((int*)&((*out).Consumer.m.var) - (int*)&(*out))] = 0;
        (*out).Consumer.state.var = 1;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        ((*out).Consumer.n.var = (*out).Consumer.n.var + 1);
        cpy[((int*)&((*out).Consumer.n.var) - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 5;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l28: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Consumer.state.var = 0;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l29: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Consumer.state.var = 0;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        ((*out).Consumer.n.var = 0);
        cpy[((int*)&((*out).Consumer.n.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l30: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Consumer.state.var = 2;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l31: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Consumer.state.var = 0;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        (*out).Producer.state.var = 0;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l32: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Consumer.state.var = 3;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l33: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Sender.n.var) = ((*in).prod_n.var);
        cpy[((int*)&((*out).Sender.n.var) - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 1;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        ((*out).Sender.i.var = 1);
        cpy[((int*)&((*out).Sender.i.var) - (int*)&(*out))] = 0;
        (*out).Producer.state.var = 2;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        // actions_read: 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
        // must-write:   0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l34: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Sender.state.var = 3;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        ((*out).Sender.counter.var = 0);
        cpy[((int*)&((*out).Sender.counter.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l35: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Sender.state.var = 4;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        ((*out).Sender.ab.var = 1 - (*out).Sender.ab.var);
        cpy[((int*)&((*out).Sender.ab.var) - (int*)&(*out))] = 0;
        (*out).L.state.var = 0;
        cpy[((int*)&(*out).L.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1
        // must-write:   0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l36: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Sender.state.var = 5;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        (*out).K.state.var = 0;
        cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l37: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Sender.state.var = 5;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        (*out).L.state.var = 0;
        cpy[((int*)&(*out).L.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l38: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Sender.state.var = 3;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        ((*out).Sender.counter.var = (*out).Sender.counter.var + 1);
        cpy[((int*)&((*out).Sender.counter.var) - (int*)&(*out))] = 0;
        (*out).K.state.var = 0;
        cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l39: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Sender.state.var = 3;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        ((*out).Sender.counter.var = (*out).Sender.counter.var + 1);
        cpy[((int*)&((*out).Sender.counter.var) - (int*)&(*out))] = 0;
        (*out).L.state.var = 0;
        cpy[((int*)&(*out).L.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l40: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Sender.state.var = 1;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        ((*out).Sender.i.var = (*out).Sender.i.var + 1);
        cpy[((int*)&((*out).Sender.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l41: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Receiver.value.var) = ((*in).K.value.var);
        cpy[((int*)&((*out).Receiver.value.var) - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 2;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        (*out).K.state.var = 0;
        cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l42: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Receiver.state.var = 5;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l43: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Receiver.value.var) = ((*in).K.value.var);
        cpy[((int*)&((*out).Receiver.value.var) - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 4;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        (*out).K.state.var = 0;
        cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l44: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Receiver.state.var = 1;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 0;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l45: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Receiver.state.var = 2;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        ((*out).Receiver.exp_ab.var = ((*out).Receiver.value.var & 1));
        cpy[((int*)&((*out).Receiver.exp_ab.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l46: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Receiver.state.var = 1;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 0;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l47: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).K.value.var) = ((4 + 2 + (*in).Sender.ab.var));
        cpy[((int*)&((*out).K.value.var) - (int*)&(*out))] = 0;
        (*out).K.state.var = 1;
        cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 2;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l48: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).K.value.var) = ((2 + (*in).Sender.ab.var));
        cpy[((int*)&((*out).K.value.var) - (int*)&(*out))] = 0;
        (*out).K.state.var = 1;
        cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 2;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l49: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).K.value.var) = ((4 + (*in).Sender.ab.var));
        cpy[((int*)&((*out).K.value.var) - (int*)&(*out))] = 0;
        (*out).K.state.var = 1;
        cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 2;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l50: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).K.value.var) = ((*in).Sender.ab.var);
        cpy[((int*)&((*out).K.value.var) - (int*)&(*out))] = 0;
        (*out).K.state.var = 1;
        cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 2;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l51: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).L.state.var = 1;
        cpy[((int*)&(*out).L.state.var - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 0;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l52: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).L.state.var = 1;
        cpy[((int*)&(*out).L.state.var - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 0;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        ((*out).Receiver.exp_ab.var = 1 - (*out).Receiver.exp_ab.var);
        cpy[((int*)&((*out).Receiver.exp_ab.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    switch_state: switch( t )
    {
        case 0: goto l0;
        case 1: goto l1;
        case 2: goto l2;
        case 3: goto l3;
        case 4: goto l4;
        case 5: goto l5;
        case 6: goto l6;
        case 7: goto l7;
        case 8: goto l8;
        case 9: goto l9;
        case 10: goto l10;
        case 11: goto l11;
        case 12: goto l12;
        case 13: goto l13;
        case 14: goto l14;
        case 15: goto l15;
        case 16: goto l16;
        case 17: goto l17;
        case 18: goto l18;
        case 19: goto l19;
        case 20: goto l20;
        case 21: goto l21;
        case 22: goto l22;
        case 23: goto l23;
        case 24: goto l24;
        case 25: goto l25;
        case 26: goto l26;
        case 27: goto l27;
        case 28: goto l28;
        case 29: goto l29;
        case 30: goto l30;
        case 31: goto l31;
        case 32: goto l32;
        case 33: goto l33;
        case 34: goto l34;
        case 35: goto l35;
        case 36: goto l36;
        case 37: goto l37;
        case 38: goto l38;
        case 39: goto l39;
        case 40: goto l40;
        case 41: goto l41;
        case 42: goto l42;
        case 43: goto l43;
        case 44: goto l44;
        case 45: goto l45;
        case 46: goto l46;
        case 47: goto l47;
        case 48: goto l48;
        case 49: goto l49;
        case 50: goto l50;
        case 51: goto l51;
        case 52: goto l52;
        default: printf ("Wrong group! Using greybox/long call + -l (DiVinE LTL semantics)? This combo is not implemented."); exit (-1);
    }
    return 0;
}

extern "C" int get_successor( void* model, int t, const state_struct_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    int states_emitted = 0;
    goto switch_state;
    l0: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l1: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l2: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l3: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l4: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l5: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l6: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l7: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l8: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l9: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l10: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l11: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l12: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l13: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l14: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l15: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l16: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l17: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l18: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l19: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l20: {
        
        // read:         0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 2) )  &&  ( ((*in).Sender.state.var == 4) )  &&  ( ((*in).Sender.i.var == (*in).Sender.n.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l21: {
        
        // read:         0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 2) )  &&  ( ((*in).Sender.state.var == 5) )  &&  ( ((*in).Sender.i.var < (*in).Sender.n.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l22: {
        
        // read:         0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 2) )  &&  ( ((*in).Sender.state.var == 5) )  &&  ( ((*in).Sender.i.var == (*in).Sender.n.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l23: {
        
        // read:         0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 3) )  &&  ( ((*in).Producer.result.var == 2 || (*in).Producer.result.var == 3) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l24: {
        
        // read:         0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 0) )  &&  ( ((*in).Receiver.state.var == 2) )  &&  ( (((*in).Receiver.value.var & 1) == (*in).Receiver.exp_ab.var && ((*in).Receiver.value.var & 2) == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l25: {
        
        // read:         0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 0) )  &&  ( ((*in).Receiver.state.var == 2) )  &&  ( ((((*in).Receiver.value.var & 1) == (*in).Receiver.exp_ab.var) && (((*in).Receiver.value.var & 2) == 0) && (((*in).Receiver.value.var & 4) == 0)) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l26: {
        
        // read:         0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 0) )  &&  ( ((*in).Receiver.state.var == 2) )  &&  ( ((((*in).Receiver.value.var & 1) == (*in).Receiver.exp_ab.var) && (((*in).Receiver.value.var & 2) == 0) && (((*in).Receiver.value.var & 4) == 4)) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l27: {
        
        // read:         0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 0) )  &&  ( ((*in).Receiver.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l28: {
        
        // read:         0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 1) )  &&  ( (((*in).Consumer.m.var == 4) || ((*in).Consumer.m.var == 5)) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l29: {
        
        // read:         0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 1) )  &&  ( ((*in).Consumer.m.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l30: {
        
        // read:         0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 1) )  &&  ( ((*in).Consumer.m.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l31: {
        
        // read:         1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 2) )  &&  ( ((*in).Consumer.n.var == (*in).prod_n.var) )  &&  ( ((*in).Producer.state.var == 3) )  &&  ( ((*in).Producer.result.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l32: {
        
        // read:         1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 2) )  &&  ( ((*in).Consumer.n.var != (*in).prod_n.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l33: {
        
        // read:         1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // actions_read: 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 0) )  &&  ( ((*in).Producer.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l34: {
        
        // read:         0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l35: {
        
        // read:         0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 2) )  &&  ( ((*in).L.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l36: {
        
        // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 2) )  &&  ( ((*in).Sender.counter.var == 30) )  &&  ( ((*in).K.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l37: {
        
        // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 2) )  &&  ( ((*in).Sender.counter.var == 30) )  &&  ( ((*in).L.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l38: {
        
        // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 2) )  &&  ( ((*in).Sender.counter.var < 30) )  &&  ( ((*in).K.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l39: {
        
        // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 2) )  &&  ( ((*in).Sender.counter.var < 30) )  &&  ( ((*in).L.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l40: {
        
        // read:         0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 4) )  &&  ( ((*in).Sender.i.var < (*in).Sender.n.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l41: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        if (  ( ((*in).Receiver.state.var == 0) )  &&  ( ((*in).K.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l42: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Receiver.state.var == 0) )  &&  ( (((*in).Receiver.value.var & 2) == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l43: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        if (  ( ((*in).Receiver.state.var == 1) )  &&  ( ((*in).K.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l44: {
        
        // read:         0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Receiver.state.var == 1) )  &&  ( ((*in).Sender.state.var == 6) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l45: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).Receiver.state.var == 4) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l46: {
        
        // read:         0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Receiver.state.var == 5) )  &&  ( ((*in).Sender.state.var == 6) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l47: {
        
        // read:         0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).K.state.var == 0) )  &&  ( ((*in).Sender.state.var == 3) )  &&  ( ((*in).Sender.i.var == 1 && (*in).Sender.i.var == (*in).Sender.n.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l48: {
        
        // read:         0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).K.state.var == 0) )  &&  ( ((*in).Sender.state.var == 3) )  &&  ( ((*in).Sender.i.var > 1 && (*in).Sender.i.var == (*in).Sender.n.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l49: {
        
        // read:         0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).K.state.var == 0) )  &&  ( ((*in).Sender.state.var == 3) )  &&  ( ((*in).Sender.i.var == 1 && (*in).Sender.i.var < (*in).Sender.n.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l50: {
        
        // read:         0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).K.state.var == 0) )  &&  ( ((*in).Sender.state.var == 3) )  &&  ( ((*in).Sender.i.var > 1 && (*in).Sender.i.var < (*in).Sender.n.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l51: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).L.state.var == 0) )  &&  ( ((*in).Receiver.state.var == 2) )  &&  ( ((*in).Receiver.exp_ab.var != ((*in).Receiver.value.var & 1)) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l52: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        if (  ( ((*in).L.state.var == 0) )  &&  ( ((*in).Receiver.state.var == 3) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    switch_state: switch( t )
    {
        case 0: goto l0;
        case 1: goto l1;
        case 2: goto l2;
        case 3: goto l3;
        case 4: goto l4;
        case 5: goto l5;
        case 6: goto l6;
        case 7: goto l7;
        case 8: goto l8;
        case 9: goto l9;
        case 10: goto l10;
        case 11: goto l11;
        case 12: goto l12;
        case 13: goto l13;
        case 14: goto l14;
        case 15: goto l15;
        case 16: goto l16;
        case 17: goto l17;
        case 18: goto l18;
        case 19: goto l19;
        case 20: goto l20;
        case 21: goto l21;
        case 22: goto l22;
        case 23: goto l23;
        case 24: goto l24;
        case 25: goto l25;
        case 26: goto l26;
        case 27: goto l27;
        case 28: goto l28;
        case 29: goto l29;
        case 30: goto l30;
        case 31: goto l31;
        case 32: goto l32;
        case 33: goto l33;
        case 34: goto l34;
        case 35: goto l35;
        case 36: goto l36;
        case 37: goto l37;
        case 38: goto l38;
        case 39: goto l39;
        case 40: goto l40;
        case 41: goto l41;
        case 42: goto l42;
        case 43: goto l43;
        case 44: goto l44;
        case 45: goto l45;
        case 46: goto l46;
        case 47: goto l47;
        case 48: goto l48;
        case 49: goto l49;
        case 50: goto l50;
        case 51: goto l51;
        case 52: goto l52;
        default: printf ("Wrong group! Using greybox/long call + -l (DiVinE LTL semantics)? This combo is not implemented."); exit (-1);
    }
    return 0;
}

extern "C" int get_successors( void *model, const state_struct_t *in, void (*callback)(void *arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    (void)model; // ignore model
    bool system_in_deadlock = true;
    transition_info_t transition_info = { NULL, -1, 0 };
    int states_emitted = 0;
    state_struct_t tmp;
    state_struct_t *out = &tmp;
    int cpy[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    if ( false )
    {
        ;
    }
    else
    {
        if (  ( ((*in).Producer.state.var == 0) ) )
        {
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 1);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 0;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 2);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 1;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 3);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 2;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 4);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 3;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 5);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 4;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 6);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 5;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 7);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 6;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 8);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 7;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 9);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 8;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 10);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 9;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 11);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 10;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 12);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 11;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 13);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 12;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 14);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 13;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 15);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 14;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 16);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 15;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 17);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 16;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 18);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 17;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 19);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 18;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                ((*out).prod_n.var = 20);
                cpy[((int*)&((*out).prod_n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 19;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Producer.state.var == 2) ) )
        {
            
            // read:         0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.state.var == 4) )  &&  ( ((*in).Sender.i.var == (*in).Sender.n.var) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Producer.result.var) = (1);
                cpy[((int*)&((*out).Producer.result.var) - (int*)&(*out))] = 0;
                (*out).Producer.state.var = 3;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 6;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 20;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.state.var == 5) )  &&  ( ((*in).Sender.i.var < (*in).Sender.n.var) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Producer.result.var) = (2);
                cpy[((int*)&((*out).Producer.result.var) - (int*)&(*out))] = 0;
                (*out).Producer.state.var = 3;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 6;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 21;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.state.var == 5) )  &&  ( ((*in).Sender.i.var == (*in).Sender.n.var) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Producer.result.var) = (3);
                cpy[((int*)&((*out).Producer.result.var) - (int*)&(*out))] = 0;
                (*out).Producer.state.var = 3;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 6;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 22;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Producer.state.var == 3) ) )
        {
            
            // read:         0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Producer.result.var == 2 || (*in).Producer.result.var == 3) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 23;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Consumer.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Receiver.state.var == 2) )  &&  ( (((*in).Receiver.value.var & 1) == (*in).Receiver.exp_ab.var && ((*in).Receiver.value.var & 2) == 2) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Consumer.m.var) = (1);
                cpy[((int*)&((*out).Consumer.m.var) - (int*)&(*out))] = 0;
                (*out).Consumer.state.var = 1;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                ((*out).Consumer.n.var = (*out).Consumer.n.var + 1);
                cpy[((int*)&((*out).Consumer.n.var) - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 3;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 24;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Receiver.state.var == 2) )  &&  ( ((((*in).Receiver.value.var & 1) == (*in).Receiver.exp_ab.var) && (((*in).Receiver.value.var & 2) == 0) && (((*in).Receiver.value.var & 4) == 0)) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Consumer.m.var) = (5);
                cpy[((int*)&((*out).Consumer.m.var) - (int*)&(*out))] = 0;
                (*out).Consumer.state.var = 1;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                ((*out).Consumer.n.var = (*out).Consumer.n.var + 1);
                cpy[((int*)&((*out).Consumer.n.var) - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 3;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 25;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Receiver.state.var == 2) )  &&  ( ((((*in).Receiver.value.var & 1) == (*in).Receiver.exp_ab.var) && (((*in).Receiver.value.var & 2) == 0) && (((*in).Receiver.value.var & 4) == 4)) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Consumer.m.var) = (4);
                cpy[((int*)&((*out).Consumer.m.var) - (int*)&(*out))] = 0;
                (*out).Consumer.state.var = 1;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                ((*out).Consumer.n.var = (*out).Consumer.n.var + 1);
                cpy[((int*)&((*out).Consumer.n.var) - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 3;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 26;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Receiver.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Consumer.m.var) = (2);
                cpy[((int*)&((*out).Consumer.m.var) - (int*)&(*out))] = 0;
                (*out).Consumer.state.var = 1;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                ((*out).Consumer.n.var = (*out).Consumer.n.var + 1);
                cpy[((int*)&((*out).Consumer.n.var) - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 5;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 27;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Consumer.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( (((*in).Consumer.m.var == 4) || ((*in).Consumer.m.var == 5)) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Consumer.state.var = 0;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 28;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Consumer.m.var == 2) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Consumer.state.var = 0;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                ((*out).Consumer.n.var = 0);
                cpy[((int*)&((*out).Consumer.n.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 29;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Consumer.m.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Consumer.state.var = 2;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 30;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Consumer.state.var == 2) ) )
        {
            
            // read:         1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Consumer.n.var == (*in).prod_n.var) )  &&  ( ((*in).Producer.state.var == 3) )  &&  ( ((*in).Producer.result.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Consumer.state.var = 0;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                (*out).Producer.state.var = 0;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 31;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Consumer.n.var != (*in).prod_n.var) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Consumer.state.var = 3;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 32;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Sender.state.var == 0) ) )
        {
            
            // read:         1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            // actions_read: 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Producer.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Sender.n.var) = ((*in).prod_n.var);
                cpy[((int*)&((*out).Sender.n.var) - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 1;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                ((*out).Sender.i.var = 1);
                cpy[((int*)&((*out).Sender.i.var) - (int*)&(*out))] = 0;
                (*out).Producer.state.var = 2;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                // actions_read: 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
                // must-write:   0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 33;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Sender.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Sender.state.var = 3;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                ((*out).Sender.counter.var = 0);
                cpy[((int*)&((*out).Sender.counter.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 34;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Sender.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).L.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Sender.state.var = 4;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                ((*out).Sender.ab.var = 1 - (*out).Sender.ab.var);
                cpy[((int*)&((*out).Sender.ab.var) - (int*)&(*out))] = 0;
                (*out).L.state.var = 0;
                cpy[((int*)&(*out).L.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1
                // must-write:   0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 35;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.counter.var == 30) )  &&  ( ((*in).K.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Sender.state.var = 5;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                (*out).K.state.var = 0;
                cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 36;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.counter.var == 30) )  &&  ( ((*in).L.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Sender.state.var = 5;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                (*out).L.state.var = 0;
                cpy[((int*)&(*out).L.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 37;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).Sender.counter.var < 30) )  &&  ( ((*in).K.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Sender.state.var = 3;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                ((*out).Sender.counter.var = (*out).Sender.counter.var + 1);
                cpy[((int*)&((*out).Sender.counter.var) - (int*)&(*out))] = 0;
                (*out).K.state.var = 0;
                cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 38;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).Sender.counter.var < 30) )  &&  ( ((*in).L.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Sender.state.var = 3;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                ((*out).Sender.counter.var = (*out).Sender.counter.var + 1);
                cpy[((int*)&((*out).Sender.counter.var) - (int*)&(*out))] = 0;
                (*out).L.state.var = 0;
                cpy[((int*)&(*out).L.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 39;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Sender.state.var == 4) ) )
        {
            
            // read:         0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.i.var < (*in).Sender.n.var) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Sender.state.var = 1;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                ((*out).Sender.i.var = (*out).Sender.i.var + 1);
                cpy[((int*)&((*out).Sender.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 40;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Receiver.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
            if (  ( ((*in).K.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Receiver.value.var) = ((*in).K.value.var);
                cpy[((int*)&((*out).Receiver.value.var) - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 2;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                (*out).K.state.var = 0;
                cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 41;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( (((*in).Receiver.value.var & 2) == 2) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Receiver.state.var = 5;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 42;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Receiver.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
            if (  ( ((*in).K.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Receiver.value.var) = ((*in).K.value.var);
                cpy[((int*)&((*out).Receiver.value.var) - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 4;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                (*out).K.state.var = 0;
                cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 43;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.state.var == 6) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Receiver.state.var = 1;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 0;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 44;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Receiver.state.var == 4) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Receiver.state.var = 2;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                ((*out).Receiver.exp_ab.var = ((*out).Receiver.value.var & 1));
                cpy[((int*)&((*out).Receiver.exp_ab.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 45;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Receiver.state.var == 5) ) )
        {
            
            // read:         0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.state.var == 6) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Receiver.state.var = 1;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 0;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 46;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).K.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.state.var == 3) )  &&  ( ((*in).Sender.i.var == 1 && (*in).Sender.i.var == (*in).Sender.n.var) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).K.value.var) = ((4 + 2 + (*in).Sender.ab.var));
                cpy[((int*)&((*out).K.value.var) - (int*)&(*out))] = 0;
                (*out).K.state.var = 1;
                cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 2;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
                system_in_deadlock = false;
                transition_info.group = 47;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.state.var == 3) )  &&  ( ((*in).Sender.i.var > 1 && (*in).Sender.i.var == (*in).Sender.n.var) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).K.value.var) = ((2 + (*in).Sender.ab.var));
                cpy[((int*)&((*out).K.value.var) - (int*)&(*out))] = 0;
                (*out).K.state.var = 1;
                cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 2;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
                system_in_deadlock = false;
                transition_info.group = 48;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.state.var == 3) )  &&  ( ((*in).Sender.i.var == 1 && (*in).Sender.i.var < (*in).Sender.n.var) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).K.value.var) = ((4 + (*in).Sender.ab.var));
                cpy[((int*)&((*out).K.value.var) - (int*)&(*out))] = 0;
                (*out).K.state.var = 1;
                cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 2;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
                system_in_deadlock = false;
                transition_info.group = 49;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.state.var == 3) )  &&  ( ((*in).Sender.i.var > 1 && (*in).Sender.i.var < (*in).Sender.n.var) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).K.value.var) = ((*in).Sender.ab.var);
                cpy[((int*)&((*out).K.value.var) - (int*)&(*out))] = 0;
                (*out).K.state.var = 1;
                cpy[((int*)&(*out).K.state.var - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 2;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0
                system_in_deadlock = false;
                transition_info.group = 50;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).L.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Receiver.state.var == 2) )  &&  ( ((*in).Receiver.exp_ab.var != ((*in).Receiver.value.var & 1)) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).L.state.var = 1;
                cpy[((int*)&(*out).L.state.var - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 0;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 51;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
            if (  ( ((*in).Receiver.state.var == 3) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).L.state.var = 1;
                cpy[((int*)&(*out).L.state.var - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 0;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                ((*out).Receiver.exp_ab.var = 1 - (*out).Receiver.exp_ab.var);
                cpy[((int*)&((*out).Receiver.exp_ab.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1
                system_in_deadlock = false;
                transition_info.group = 52;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
    }
    if (  ( system_in_deadlock ) )
    {
    }
    return states_emitted;
}

extern "C" int get_state_variable_count() 
{
    return 18;
}

extern "C" const char* get_state_variable_name(int var)
{
    switch (var)
    {
        case 0:
            return "prod_n";
        case 1:
            return "Producer";
        case 2:
            return "Producer.result";
        case 3:
            return "Producer.n";
        case 4:
            return "Consumer";
        case 5:
            return "Consumer.m";
        case 6:
            return "Consumer.n";
        case 7:
            return "Sender";
        case 8:
            return "Sender.ab";
        case 9:
            return "Sender.n";
        case 10:
            return "Sender.i";
        case 11:
            return "Sender.counter";
        case 12:
            return "Receiver";
        case 13:
            return "Receiver.value";
        case 14:
            return "Receiver.exp_ab";
        case 15:
            return "K";
        case 16:
            return "K.value";
        case 17:
            return "L";
        default:
            return NULL;
    }
}

extern "C" int get_state_variable_type(int var)
{
    switch (var)
    {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 4;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 5;
        case 16:
            return 0;
        case 17:
            return 6;
        default:
            return -1;
    }
}

extern "C" int get_state_variable_type_count() 
{
    return 7;
}

extern "C" const char* get_state_variable_type_name(int type) 
{
    switch (type)
    {
        case 2:
            return "Consumer";
        case 5:
            return "K";
        case 6:
            return "L";
        case 1:
            return "Producer";
        case 4:
            return "Receiver";
        case 3:
            return "Sender";
        case 0:
            return "byte";
        default:
            return NULL;
    }
}

extern "C" int get_state_variable_type_value_count(int type)
{
    switch (type)
    {
        case 2: // Consumer
            return 4;
        case 5: // K
            return 2;
        case 6: // L
            return 2;
        case 1: // Producer
            return 4;
        case 4: // Receiver
            return 6;
        case 3: // Sender
            return 7;
        case 0: // byte
            return 0;
        default:
            return -1;
    }
}

extern "C" const char* get_state_variable_type_value(int type, int value) 
{
    switch (type)
    {
        case 2:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "get_msg";
                case 2:
                    return "check";
                case 3:
                    return "st_error";
            }
        }
        case 5:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "got_msg";
            }
        }
        case 6:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "got_msg";
            }
        }
        case 1:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "start_send";
                case 2:
                    return "wait_result";
                case 3:
                    return "check";
            }
        }
        case 4:
        {
            switch (value)
            {
                case 0:
                    return "idle";
                case 1:
                    return "new_file";
                case 2:
                    return "frame_received";
                case 3:
                    return "frame_reported";
                case 4:
                    return "first_safe";
                case 5:
                    return "ret";
            }
        }
        case 3:
        {
            switch (value)
            {
                case 0:
                    return "idle";
                case 1:
                    return "next_frame";
                case 2:
                    return "wait_ack";
                case 3:
                    return "send";
                case 4:
                    return "success";
                case 5:
                    return "q_error";
                case 6:
                    return "ret";
            }
        }
    }
    return NULL;
}

int transition_dependency[][3][18] = 
{
    // { ... read ...}, { ... may-write ...}, { ... must-write ...}
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0},{0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},{0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0},{0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},{0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0},{0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},{0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}},
    {{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1}},
    {{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1}},
    {{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1}},
    {{0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0}},
    {{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0}},
    {{0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0}},
    {{0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0}},
    {{0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1}}
}
;

int actions_read[][18] = 
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0}
}
;

extern "C" int get_transition_count() 
{
    return 53;
}

extern "C" const int* get_transition_read_dependencies(int t) 
{
    if (t>=0 && t < 53) return transition_dependency[t][0];
    return NULL;
}

extern "C" const int* get_transition_actions_read_dependencies(int t) 
{
    if (t>=0 && t < 53) return actions_read[t];
    return NULL;
}

extern "C" const int* get_transition_may_write_dependencies(int t) 
{
    if (t>=0 && t < 53) return transition_dependency[t][1];
    return NULL;
}

extern "C" const int* get_transition_write_dependencies(int t) 
{
    return get_transition_may_write_dependencies(t);
}

extern "C" const int* get_transition_must_write_dependencies(int t) 
{
    if (t>=0 && t < 53) return transition_dependency[t][2];
    return NULL;
}

static int wrapped_div(int denom, jmp_buf* jbuf)
{
    if(denom == 0) longjmp(*jbuf, 1);
    return denom;
}

static int wrapped_index(int index, int size, jmp_buf* jbuf)
{
    if(index < 0 || index >= size) longjmp(*jbuf, 1);
    return index;
}

extern "C" int get_guard(void* model, int g, state_struct_t* src) 
{
    (void)model;
    jmp_buf jbuf;
    if(!setjmp(jbuf))
    {
        switch(g)
        {
            case 0: return (((*src).Producer.state.var == 0));
            case 1: return (((*src).Producer.state.var == 2));
            case 2: return (((*src).Sender.state.var == 4));
            case 3: return (((*src).Sender.i.var == (*src).Sender.n.var));
            case 4: return (((*src).Sender.state.var == 5));
            case 5: return (((*src).Sender.i.var < (*src).Sender.n.var));
            case 6: return (((*src).Producer.state.var == 3));
            case 7: return (((*src).Producer.result.var == 2 || (*src).Producer.result.var == 3));
            case 8: return (((*src).Consumer.state.var == 0));
            case 9: return (((*src).Receiver.state.var == 2));
            case 10: return ((((*src).Receiver.value.var & 1) == (*src).Receiver.exp_ab.var));
            case 11: return ((((*src).Receiver.value.var & 2) == 2));
            case 12: return (((((*src).Receiver.value.var & 1) == (*src).Receiver.exp_ab.var)));
            case 13: return (((((*src).Receiver.value.var & 2) == 0)));
            case 14: return (((((*src).Receiver.value.var & 4) == 0)));
            case 15: return (((((*src).Receiver.value.var & 4) == 4)));
            case 16: return (((*src).Receiver.state.var == 0));
            case 17: return (((*src).Consumer.state.var == 1));
            case 18: return ((((*src).Consumer.m.var == 4) || ((*src).Consumer.m.var == 5)));
            case 19: return (((*src).Consumer.m.var == 2));
            case 20: return (((*src).Consumer.m.var == 1));
            case 21: return (((*src).Consumer.state.var == 2));
            case 22: return (((*src).Consumer.n.var == (*src).prod_n.var));
            case 23: return (((*src).Producer.result.var == 1));
            case 24: return (((*src).Consumer.n.var != (*src).prod_n.var));
            case 25: return (((*src).Sender.state.var == 0));
            case 26: return (((*src).Producer.state.var == 1));
            case 27: return (((*src).Sender.state.var == 1));
            case 28: return (((*src).Sender.state.var == 2));
            case 29: return (((*src).L.state.var == 1));
            case 30: return (((*src).Sender.counter.var == 30));
            case 31: return (((*src).K.state.var == 1));
            case 32: return (((*src).Sender.counter.var < 30));
            case 33: return (((*src).Receiver.state.var == 1));
            case 34: return (((*src).Sender.state.var == 6));
            case 35: return (((*src).Receiver.state.var == 4));
            case 36: return (((*src).Receiver.state.var == 5));
            case 37: return (((*src).K.state.var == 0));
            case 38: return (((*src).Sender.state.var == 3));
            case 39: return (((*src).Sender.i.var == 1));
            case 40: return (((*src).Sender.i.var > 1));
            case 41: return (((*src).L.state.var == 0));
            case 42: return (((*src).Receiver.exp_ab.var != ((*src).Receiver.value.var & 1)));
            case 43: return (((*src).Receiver.state.var == 3));
        }
    }
    else return 2;
    return false;
}

extern "C" void get_guard_all(void* model, state_struct_t* src, int* guard) 
{
    guard[0] = get_guard(model, 0, src);
    guard[1] = get_guard(model, 1, src);
    guard[2] = get_guard(model, 2, src);
    guard[3] = get_guard(model, 3, src);
    guard[4] = get_guard(model, 4, src);
    guard[5] = get_guard(model, 5, src);
    guard[6] = get_guard(model, 6, src);
    guard[7] = get_guard(model, 7, src);
    guard[8] = get_guard(model, 8, src);
    guard[9] = get_guard(model, 9, src);
    guard[10] = get_guard(model, 10, src);
    guard[11] = get_guard(model, 11, src);
    guard[12] = get_guard(model, 12, src);
    guard[13] = get_guard(model, 13, src);
    guard[14] = get_guard(model, 14, src);
    guard[15] = get_guard(model, 15, src);
    guard[16] = get_guard(model, 16, src);
    guard[17] = get_guard(model, 17, src);
    guard[18] = get_guard(model, 18, src);
    guard[19] = get_guard(model, 19, src);
    guard[20] = get_guard(model, 20, src);
    guard[21] = get_guard(model, 21, src);
    guard[22] = get_guard(model, 22, src);
    guard[23] = get_guard(model, 23, src);
    guard[24] = get_guard(model, 24, src);
    guard[25] = get_guard(model, 25, src);
    guard[26] = get_guard(model, 26, src);
    guard[27] = get_guard(model, 27, src);
    guard[28] = get_guard(model, 28, src);
    guard[29] = get_guard(model, 29, src);
    guard[30] = get_guard(model, 30, src);
    guard[31] = get_guard(model, 31, src);
    guard[32] = get_guard(model, 32, src);
    guard[33] = get_guard(model, 33, src);
    guard[34] = get_guard(model, 34, src);
    guard[35] = get_guard(model, 35, src);
    guard[36] = get_guard(model, 36, src);
    guard[37] = get_guard(model, 37, src);
    guard[38] = get_guard(model, 38, src);
    guard[39] = get_guard(model, 39, src);
    guard[40] = get_guard(model, 40, src);
    guard[41] = get_guard(model, 41, src);
    guard[42] = get_guard(model, 42, src);
    guard[43] = get_guard(model, 43, src);
}

extern "C" const int get_guard_count() 
{
    return 44;
}

#pragma clang diagnostic push
int* guards_per_transition[53] = 
{
    ((int[]){1, 0}), // 0
    ((int[]){1, 0}), // 1
    ((int[]){1, 0}), // 2
    ((int[]){1, 0}), // 3
    ((int[]){1, 0}), // 4
    ((int[]){1, 0}), // 5
    ((int[]){1, 0}), // 6
    ((int[]){1, 0}), // 7
    ((int[]){1, 0}), // 8
    ((int[]){1, 0}), // 9
    ((int[]){1, 0}), // 10
    ((int[]){1, 0}), // 11
    ((int[]){1, 0}), // 12
    ((int[]){1, 0}), // 13
    ((int[]){1, 0}), // 14
    ((int[]){1, 0}), // 15
    ((int[]){1, 0}), // 16
    ((int[]){1, 0}), // 17
    ((int[]){1, 0}), // 18
    ((int[]){1, 0}), // 19
    ((int[]){3, 1, 2, 3}), // 20
    ((int[]){3, 1, 4, 5}), // 21
    ((int[]){3, 1, 4, 3}), // 22
    ((int[]){2, 6, 7}), // 23
    ((int[]){4, 8, 9, 10, 11}), // 24
    ((int[]){5, 8, 9, 12, 13, 14}), // 25
    ((int[]){5, 8, 9, 12, 13, 15}), // 26
    ((int[]){2, 8, 16}), // 27
    ((int[]){2, 17, 18}), // 28
    ((int[]){2, 17, 19}), // 29
    ((int[]){2, 17, 20}), // 30
    ((int[]){4, 21, 22, 6, 23}), // 31
    ((int[]){2, 21, 24}), // 32
    ((int[]){2, 25, 26}), // 33
    ((int[]){1, 27}), // 34
    ((int[]){2, 28, 29}), // 35
    ((int[]){3, 28, 30, 31}), // 36
    ((int[]){3, 28, 30, 29}), // 37
    ((int[]){3, 28, 32, 31}), // 38
    ((int[]){3, 28, 32, 29}), // 39
    ((int[]){2, 2, 5}), // 40
    ((int[]){2, 16, 31}), // 41
    ((int[]){2, 16, 11}), // 42
    ((int[]){2, 33, 31}), // 43
    ((int[]){2, 33, 34}), // 44
    ((int[]){1, 35}), // 45
    ((int[]){2, 36, 34}), // 46
    ((int[]){4, 37, 38, 39, 3}), // 47
    ((int[]){4, 37, 38, 40, 3}), // 48
    ((int[]){4, 37, 38, 39, 5}), // 49
    ((int[]){4, 37, 38, 40, 5}), // 50
    ((int[]){3, 41, 9, 42}), // 51
    ((int[]){2, 41, 43}), // 52
}
;
#pragma clang diagnostic pop

extern "C" const int* get_guards(int t) 
{
    if (t>=0 && t < 53) return guards_per_transition[t];
    return NULL;
}

extern "C" const int** get_all_guards() 
{
    return (const int**)&guards_per_transition;
}

int guard[][18] = 
{
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}
}
;

extern "C" const int* get_guard_matrix(int g) 
{
    if (g>=0 && g < 44) return guard[g];
    return NULL;
}

int guardmaybecoenabled[44][44] = 
{
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_may_be_coenabled_matrix(int g) 
{
    if (g>=0 && g < 44) return guardmaybecoenabled[g];
    return NULL;
}

int guard_nes[44][53] = 
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
}
;

extern "C" const int* get_guard_nes_matrix(int g) 
{
    if (g>=0 && g < 44) return guard_nes[g];
    return NULL;
}

int guard_nds[44][53] = 
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_guard_nds_matrix(int g) 
{
    if (g>=0 && g < 44) return guard_nds[g];
    return NULL;
}

int dna[53][53] = 
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1}
}
;

extern "C" const int* get_dna_matrix(int t) 
{
    if (t >= 0 && t < 53) return dna[t];
    return NULL;
}

