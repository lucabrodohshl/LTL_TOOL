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
    struct
    {
        ushort_int_t state;
        byte_t status;
        byte_t v;
    }
    __attribute__((__packed__)) P_0;
    struct
    {
        ushort_int_t state;
        byte_t status;
        byte_t v;
    }
    __attribute__((__packed__)) P_1;
    struct
    {
        ushort_int_t state;
        byte_t status;
        byte_t v;
    }
    __attribute__((__packed__)) P_2;
    struct
    {
        ushort_int_t state;
        byte_t status;
        byte_t v;
    }
    __attribute__((__packed__)) P_3;
    struct
    {
        ushort_int_t state;
        byte_t status;
        byte_t v;
    }
    __attribute__((__packed__)) P_4;
    struct
    {
        ushort_int_t state;
        byte_t v;
    }
    __attribute__((__packed__)) channel_link_0;
    struct
    {
        ushort_int_t state;
        byte_t v;
    }
    __attribute__((__packed__)) channel_link_1;
    struct
    {
        ushort_int_t state;
        byte_t v;
    }
    __attribute__((__packed__)) channel_link_2;
    struct
    {
        ushort_int_t state;
        byte_t v;
    }
    __attribute__((__packed__)) channel_link_3;
    struct
    {
        ushort_int_t state;
        byte_t v;
    }
    __attribute__((__packed__)) channel_link_4;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

state_struct_t initial_state = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

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
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).channel_link_0.v.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 2;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).channel_link_0.state.var = 0;
        cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // must-write:   1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l1: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 1;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l2: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 0;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l3: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 0;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).P_0.status.var = 0);
        cpy[((int*)&((*out).P_0.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l4: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 1;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l5: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).channel_link_1.v.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 2;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).channel_link_1.state.var = 0;
        cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l6: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 1;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l7: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 0;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l8: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 0;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).P_1.status.var = 0);
        cpy[((int*)&((*out).P_1.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l9: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 1;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l10: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).channel_link_2.v.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 2;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).channel_link_2.state.var = 0;
        cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l11: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 1;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l12: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 0;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l13: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 0;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).P_2.status.var = 0);
        cpy[((int*)&((*out).P_2.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l14: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 1;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l15: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_3.v.var) = ((*in).channel_link_3.v.var);
        cpy[((int*)&((*out).P_3.v.var) - (int*)&(*out))] = 0;
        (*out).P_3.state.var = 2;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        (*out).channel_link_3.state.var = 0;
        cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l16: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_3.state.var = 1;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l17: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_3.state.var = 0;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l18: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_3.state.var = 0;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        ((*out).P_3.status.var = 0);
        cpy[((int*)&((*out).P_3.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l19: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_3.state.var = 1;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l20: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_4.v.var) = ((*in).channel_link_4.v.var);
        cpy[((int*)&((*out).P_4.v.var) - (int*)&(*out))] = 0;
        (*out).P_4.state.var = 2;
        cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
        (*out).channel_link_4.state.var = 0;
        cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l21: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_4.state.var = 1;
        cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l22: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_4.state.var = 0;
        cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l23: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_4.state.var = 0;
        cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
        ((*out).P_4.status.var = 0);
        cpy[((int*)&((*out).P_4.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l24: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_4.state.var = 1;
        cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l25: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_0.v.var) = (255);
        cpy[((int*)&((*out).channel_link_0.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_0.state.var = 1;
        cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
        (*out).P_4.state.var = 0;
        cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
        ((*out).P_4.status.var = 0);
        cpy[((int*)&((*out).P_4.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l26: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_0.v.var) = (23);
        cpy[((int*)&((*out).channel_link_0.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_0.state.var = 1;
        cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
        (*out).P_4.state.var = 0;
        cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
        ((*out).P_4.status.var = 1);
        cpy[((int*)&((*out).P_4.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l27: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_0.v.var) = ((*in).P_4.v.var);
        cpy[((int*)&((*out).channel_link_0.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_0.state.var = 1;
        cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
        (*out).P_4.state.var = 0;
        cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
        ((*out).P_4.status.var = 2);
        cpy[((int*)&((*out).P_4.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l28: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_0.v.var) = ((*in).P_4.v.var);
        cpy[((int*)&((*out).channel_link_0.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_0.state.var = 1;
        cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
        (*out).P_4.state.var = 0;
        cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l29: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).channel_link_0.state.var = 0;
        cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l30: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_1.v.var) = (255);
        cpy[((int*)&((*out).channel_link_1.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_1.state.var = 1;
        cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 0;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).P_0.status.var = 0);
        cpy[((int*)&((*out).P_0.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l31: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_1.v.var) = (24);
        cpy[((int*)&((*out).channel_link_1.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_1.state.var = 1;
        cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 0;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).P_0.status.var = 1);
        cpy[((int*)&((*out).P_0.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l32: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_1.v.var) = ((*in).P_0.v.var);
        cpy[((int*)&((*out).channel_link_1.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_1.state.var = 1;
        cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 0;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).P_0.status.var = 2);
        cpy[((int*)&((*out).P_0.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l33: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_1.v.var) = ((*in).P_0.v.var);
        cpy[((int*)&((*out).channel_link_1.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_1.state.var = 1;
        cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 0;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l34: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).channel_link_1.state.var = 0;
        cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l35: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_2.v.var) = (255);
        cpy[((int*)&((*out).channel_link_2.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_2.state.var = 1;
        cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 0;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).P_1.status.var = 0);
        cpy[((int*)&((*out).P_1.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l36: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_2.v.var) = (14);
        cpy[((int*)&((*out).channel_link_2.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_2.state.var = 1;
        cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 0;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).P_1.status.var = 1);
        cpy[((int*)&((*out).P_1.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l37: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_2.v.var) = ((*in).P_1.v.var);
        cpy[((int*)&((*out).channel_link_2.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_2.state.var = 1;
        cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 0;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).P_1.status.var = 2);
        cpy[((int*)&((*out).P_1.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l38: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_2.v.var) = ((*in).P_1.v.var);
        cpy[((int*)&((*out).channel_link_2.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_2.state.var = 1;
        cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 0;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l39: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).channel_link_2.state.var = 0;
        cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l40: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_3.v.var) = (255);
        cpy[((int*)&((*out).channel_link_3.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_3.state.var = 1;
        cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 0;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).P_2.status.var = 0);
        cpy[((int*)&((*out).P_2.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l41: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_3.v.var) = (6);
        cpy[((int*)&((*out).channel_link_3.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_3.state.var = 1;
        cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 0;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).P_2.status.var = 1);
        cpy[((int*)&((*out).P_2.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l42: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_3.v.var) = ((*in).P_2.v.var);
        cpy[((int*)&((*out).channel_link_3.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_3.state.var = 1;
        cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 0;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).P_2.status.var = 2);
        cpy[((int*)&((*out).P_2.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l43: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_3.v.var) = ((*in).P_2.v.var);
        cpy[((int*)&((*out).channel_link_3.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_3.state.var = 1;
        cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 0;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l44: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).channel_link_3.state.var = 0;
        cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l45: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_4.v.var) = (255);
        cpy[((int*)&((*out).channel_link_4.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_4.state.var = 1;
        cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
        (*out).P_3.state.var = 0;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        ((*out).P_3.status.var = 0);
        cpy[((int*)&((*out).P_3.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l46: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_4.v.var) = (0);
        cpy[((int*)&((*out).channel_link_4.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_4.state.var = 1;
        cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
        (*out).P_3.state.var = 0;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        ((*out).P_3.status.var = 1);
        cpy[((int*)&((*out).P_3.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l47: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_4.v.var) = ((*in).P_3.v.var);
        cpy[((int*)&((*out).channel_link_4.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_4.state.var = 1;
        cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
        (*out).P_3.state.var = 0;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        ((*out).P_3.status.var = 2);
        cpy[((int*)&((*out).P_3.status.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l48: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_link_4.v.var) = ((*in).P_3.v.var);
        cpy[((int*)&((*out).channel_link_4.v.var) - (int*)&(*out))] = 0;
        (*out).channel_link_4.state.var = 1;
        cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
        (*out).P_3.state.var = 0;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l49: {
        *out = *in;
        int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).channel_link_4.state.var = 0;
        cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
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
        default: printf ("Wrong group! Using greybox/long call + -l (DiVinE LTL semantics)? This combo is not implemented."); exit (-1);
    }
    return 0;
}

extern "C" int get_successor( void* model, int t, const state_struct_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    int states_emitted = 0;
    goto switch_state;
    l0: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 0) )  &&  ( ((*in).channel_link_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l1: {
        
        // read:         1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.v.var == 255) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l2: {
        
        // read:         1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.v.var != 255 && (*in).P_0.v.var > 24) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l3: {
        
        // read:         1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.v.var != 255 && (*in).P_0.v.var == 24 && (*in).P_0.status.var != 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l4: {
        
        // read:         1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.v.var != 255 && (*in).P_0.v.var == 24 && (*in).P_0.status.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l5: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 0) )  &&  ( ((*in).channel_link_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l6: {
        
        // read:         0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.v.var == 255) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l7: {
        
        // read:         0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.v.var != 255 && (*in).P_1.v.var > 14) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l8: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.v.var != 255 && (*in).P_1.v.var == 14 && (*in).P_1.status.var != 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l9: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.v.var != 255 && (*in).P_1.v.var == 14 && (*in).P_1.status.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l10: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).P_2.state.var == 0) )  &&  ( ((*in).channel_link_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l11: {
        
        // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.v.var == 255) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l12: {
        
        // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.v.var != 255 && (*in).P_2.v.var > 6) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l13: {
        
        // read:         0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.v.var != 255 && (*in).P_2.v.var == 6 && (*in).P_2.status.var != 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l14: {
        
        // read:         0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.v.var != 255 && (*in).P_2.v.var == 6 && (*in).P_2.status.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l15: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        if (  ( ((*in).P_3.state.var == 0) )  &&  ( ((*in).channel_link_3.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l16: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).P_3.v.var == 255) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l17: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).P_3.v.var != 255 && (*in).P_3.v.var > 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l18: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).P_3.v.var != 255 && (*in).P_3.v.var == 0 && (*in).P_3.status.var != 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l19: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).P_3.v.var != 255 && (*in).P_3.v.var == 0 && (*in).P_3.status.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l20: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        if (  ( ((*in).P_4.state.var == 0) )  &&  ( ((*in).channel_link_4.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l21: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_4.state.var == 2) )  &&  ( ((*in).P_4.v.var == 255) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l22: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_4.state.var == 2) )  &&  ( ((*in).P_4.v.var != 255 && (*in).P_4.v.var > 23) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l23: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_4.state.var == 2) )  &&  ( ((*in).P_4.v.var != 255 && (*in).P_4.v.var == 23 && (*in).P_4.status.var != 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l24: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_4.state.var == 2) )  &&  ( ((*in).P_4.v.var != 255 && (*in).P_4.v.var == 23 && (*in).P_4.status.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l25: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_0.state.var == 0) )  &&  ( ((*in).P_4.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l26: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_0.state.var == 0) )  &&  ( ((*in).P_4.state.var == 0) )  &&  ( ((*in).P_4.status.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l27: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_0.state.var == 0) )  &&  ( ((*in).P_4.state.var == 2) )  &&  ( ((*in).P_4.v.var != 255 && (*in).P_4.status.var == 1 && (*in).P_4.v.var < 23) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l28: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_0.state.var == 0) )  &&  ( ((*in).P_4.state.var == 2) )  &&  ( ((*in).P_4.v.var != 255 && (*in).P_4.status.var == 0 && (*in).P_4.v.var < 23) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l29: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l30: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_1.state.var == 0) )  &&  ( ((*in).P_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l31: {
        
        // read:         1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_1.state.var == 0) )  &&  ( ((*in).P_0.state.var == 0) )  &&  ( ((*in).P_0.status.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l32: {
        
        // read:         1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_1.state.var == 0) )  &&  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.v.var != 255 && (*in).P_0.status.var == 1 && (*in).P_0.v.var < 24) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l33: {
        
        // read:         1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_1.state.var == 0) )  &&  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.v.var != 255 && (*in).P_0.status.var == 0 && (*in).P_0.v.var < 24) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l34: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l35: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_2.state.var == 0) )  &&  ( ((*in).P_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l36: {
        
        // read:         0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_2.state.var == 0) )  &&  ( ((*in).P_1.state.var == 0) )  &&  ( ((*in).P_1.status.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l37: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_2.state.var == 0) )  &&  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.v.var != 255 && (*in).P_1.status.var == 1 && (*in).P_1.v.var < 14) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l38: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_2.state.var == 0) )  &&  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.v.var != 255 && (*in).P_1.status.var == 0 && (*in).P_1.v.var < 14) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l39: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l40: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_3.state.var == 0) )  &&  ( ((*in).P_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l41: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_3.state.var == 0) )  &&  ( ((*in).P_2.state.var == 0) )  &&  ( ((*in).P_2.status.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l42: {
        
        // read:         0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_3.state.var == 0) )  &&  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.v.var != 255 && (*in).P_2.status.var == 1 && (*in).P_2.v.var < 6) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l43: {
        
        // read:         0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_3.state.var == 0) )  &&  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.v.var != 255 && (*in).P_2.status.var == 0 && (*in).P_2.v.var < 6) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l44: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_3.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l45: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_4.state.var == 0) )  &&  ( ((*in).P_3.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l46: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_4.state.var == 0) )  &&  ( ((*in).P_3.state.var == 0) )  &&  ( ((*in).P_3.status.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l47: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_4.state.var == 0) )  &&  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).P_3.v.var != 255 && (*in).P_3.status.var == 1 && (*in).P_3.v.var < 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l48: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_4.state.var == 0) )  &&  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).P_3.v.var != 255 && (*in).P_3.status.var == 0 && (*in).P_3.v.var < 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l49: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_link_4.state.var == 1) ) )
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
    int cpy[25] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    if ( false )
    {
        ;
    }
    else
    {
        if (  ( ((*in).P_0.state.var == 0) ) )
        {
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).channel_link_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).channel_link_0.v.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 2;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).channel_link_0.state.var = 0;
                cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // must-write:   1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 0;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 2) ) )
        {
            
            // read:         1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 255) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 1;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 1;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var != 255 && (*in).P_0.v.var > 24) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 0;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 2;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var != 255 && (*in).P_0.v.var == 24 && (*in).P_0.status.var != 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 0;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).P_0.status.var = 0);
                cpy[((int*)&((*out).P_0.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 3;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var != 255 && (*in).P_0.v.var == 24 && (*in).P_0.status.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 1;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 4;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 0) ) )
        {
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).channel_link_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).channel_link_1.v.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 2;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).channel_link_1.state.var = 0;
                cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 5;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 2) ) )
        {
            
            // read:         0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 255) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 1;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 6;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var != 255 && (*in).P_1.v.var > 14) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 0;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 7;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var != 255 && (*in).P_1.v.var == 14 && (*in).P_1.status.var != 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 0;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).P_1.status.var = 0);
                cpy[((int*)&((*out).P_1.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 8;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var != 255 && (*in).P_1.v.var == 14 && (*in).P_1.status.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 1;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 9;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).channel_link_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).channel_link_2.v.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 2;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).channel_link_2.state.var = 0;
                cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 10;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 255) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 1;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 11;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var != 255 && (*in).P_2.v.var > 6) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 0;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 12;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var != 255 && (*in).P_2.v.var == 6 && (*in).P_2.status.var != 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 0;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).P_2.status.var = 0);
                cpy[((int*)&((*out).P_2.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 13;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var != 255 && (*in).P_2.v.var == 6 && (*in).P_2.status.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 1;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 14;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_3.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
            if (  ( ((*in).channel_link_3.state.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_3.v.var) = ((*in).channel_link_3.v.var);
                cpy[((int*)&((*out).P_3.v.var) - (int*)&(*out))] = 0;
                (*out).P_3.state.var = 2;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                (*out).channel_link_3.state.var = 0;
                cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 15;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_3.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_3.v.var == 255) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_3.state.var = 1;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 16;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_3.v.var != 255 && (*in).P_3.v.var > 0) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_3.state.var = 0;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 17;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_3.v.var != 255 && (*in).P_3.v.var == 0 && (*in).P_3.status.var != 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_3.state.var = 0;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                ((*out).P_3.status.var = 0);
                cpy[((int*)&((*out).P_3.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 18;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_3.v.var != 255 && (*in).P_3.v.var == 0 && (*in).P_3.status.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_3.state.var = 1;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 19;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_4.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
            if (  ( ((*in).channel_link_4.state.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_4.v.var) = ((*in).channel_link_4.v.var);
                cpy[((int*)&((*out).P_4.v.var) - (int*)&(*out))] = 0;
                (*out).P_4.state.var = 2;
                cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
                (*out).channel_link_4.state.var = 0;
                cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 20;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_4.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_4.v.var == 255) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_4.state.var = 1;
                cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 21;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_4.v.var != 255 && (*in).P_4.v.var > 23) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_4.state.var = 0;
                cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 22;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_4.v.var != 255 && (*in).P_4.v.var == 23 && (*in).P_4.status.var != 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_4.state.var = 0;
                cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
                ((*out).P_4.status.var = 0);
                cpy[((int*)&((*out).P_4.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 23;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_4.v.var != 255 && (*in).P_4.v.var == 23 && (*in).P_4.status.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_4.state.var = 1;
                cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 24;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_link_0.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_4.state.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_0.v.var) = (255);
                cpy[((int*)&((*out).channel_link_0.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_0.state.var = 1;
                cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
                (*out).P_4.state.var = 0;
                cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
                ((*out).P_4.status.var = 0);
                cpy[((int*)&((*out).P_4.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 25;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_4.state.var == 0) )  &&  ( ((*in).P_4.status.var == 0) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_0.v.var) = (23);
                cpy[((int*)&((*out).channel_link_0.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_0.state.var = 1;
                cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
                (*out).P_4.state.var = 0;
                cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
                ((*out).P_4.status.var = 1);
                cpy[((int*)&((*out).P_4.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 26;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_4.state.var == 2) )  &&  ( ((*in).P_4.v.var != 255 && (*in).P_4.status.var == 1 && (*in).P_4.v.var < 23) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_0.v.var) = ((*in).P_4.v.var);
                cpy[((int*)&((*out).channel_link_0.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_0.state.var = 1;
                cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
                (*out).P_4.state.var = 0;
                cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
                ((*out).P_4.status.var = 2);
                cpy[((int*)&((*out).P_4.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 27;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_4.state.var == 2) )  &&  ( ((*in).P_4.v.var != 255 && (*in).P_4.status.var == 0 && (*in).P_4.v.var < 23) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_0.v.var) = ((*in).P_4.v.var);
                cpy[((int*)&((*out).channel_link_0.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_0.state.var = 1;
                cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
                (*out).P_4.state.var = 0;
                cpy[((int*)&(*out).P_4.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 28;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_link_0.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).channel_link_0.state.var = 0;
                cpy[((int*)&(*out).channel_link_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 29;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_link_1.state.var == 0) ) )
        {
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_1.v.var) = (255);
                cpy[((int*)&((*out).channel_link_1.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_1.state.var = 1;
                cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 0;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).P_0.status.var = 0);
                cpy[((int*)&((*out).P_0.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 30;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.state.var == 0) )  &&  ( ((*in).P_0.status.var == 0) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_1.v.var) = (24);
                cpy[((int*)&((*out).channel_link_1.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_1.state.var = 1;
                cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 0;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).P_0.status.var = 1);
                cpy[((int*)&((*out).P_0.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 31;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.v.var != 255 && (*in).P_0.status.var == 1 && (*in).P_0.v.var < 24) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_1.v.var) = ((*in).P_0.v.var);
                cpy[((int*)&((*out).channel_link_1.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_1.state.var = 1;
                cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 0;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).P_0.status.var = 2);
                cpy[((int*)&((*out).P_0.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 32;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.v.var != 255 && (*in).P_0.status.var == 0 && (*in).P_0.v.var < 24) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_1.v.var) = ((*in).P_0.v.var);
                cpy[((int*)&((*out).channel_link_1.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_1.state.var = 1;
                cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 0;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 33;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_link_1.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).channel_link_1.state.var = 0;
                cpy[((int*)&(*out).channel_link_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 34;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_link_2.state.var == 0) ) )
        {
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_2.v.var) = (255);
                cpy[((int*)&((*out).channel_link_2.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_2.state.var = 1;
                cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 0;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).P_1.status.var = 0);
                cpy[((int*)&((*out).P_1.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 35;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.state.var == 0) )  &&  ( ((*in).P_1.status.var == 0) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_2.v.var) = (14);
                cpy[((int*)&((*out).channel_link_2.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_2.state.var = 1;
                cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 0;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).P_1.status.var = 1);
                cpy[((int*)&((*out).P_1.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 36;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.v.var != 255 && (*in).P_1.status.var == 1 && (*in).P_1.v.var < 14) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_2.v.var) = ((*in).P_1.v.var);
                cpy[((int*)&((*out).channel_link_2.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_2.state.var = 1;
                cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 0;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).P_1.status.var = 2);
                cpy[((int*)&((*out).P_1.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 37;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.v.var != 255 && (*in).P_1.status.var == 0 && (*in).P_1.v.var < 14) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_2.v.var) = ((*in).P_1.v.var);
                cpy[((int*)&((*out).channel_link_2.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_2.state.var = 1;
                cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 0;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 38;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_link_2.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).channel_link_2.state.var = 0;
                cpy[((int*)&(*out).channel_link_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 39;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_link_3.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_3.v.var) = (255);
                cpy[((int*)&((*out).channel_link_3.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_3.state.var = 1;
                cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 0;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).P_2.status.var = 0);
                cpy[((int*)&((*out).P_2.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
                // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
                system_in_deadlock = false;
                transition_info.group = 40;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.state.var == 0) )  &&  ( ((*in).P_2.status.var == 0) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_3.v.var) = (6);
                cpy[((int*)&((*out).channel_link_3.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_3.state.var = 1;
                cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 0;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).P_2.status.var = 1);
                cpy[((int*)&((*out).P_2.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
                // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
                system_in_deadlock = false;
                transition_info.group = 41;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.v.var != 255 && (*in).P_2.status.var == 1 && (*in).P_2.v.var < 6) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_3.v.var) = ((*in).P_2.v.var);
                cpy[((int*)&((*out).channel_link_3.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_3.state.var = 1;
                cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 0;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).P_2.status.var = 2);
                cpy[((int*)&((*out).P_2.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
                // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
                system_in_deadlock = false;
                transition_info.group = 42;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.v.var != 255 && (*in).P_2.status.var == 0 && (*in).P_2.v.var < 6) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_3.v.var) = ((*in).P_2.v.var);
                cpy[((int*)&((*out).channel_link_3.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_3.state.var = 1;
                cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 0;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
                system_in_deadlock = false;
                transition_info.group = 43;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_link_3.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).channel_link_3.state.var = 0;
                cpy[((int*)&(*out).channel_link_3.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 44;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_link_4.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_3.state.var == 1) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_4.v.var) = (255);
                cpy[((int*)&((*out).channel_link_4.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_4.state.var = 1;
                cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
                (*out).P_3.state.var = 0;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                ((*out).P_3.status.var = 0);
                cpy[((int*)&((*out).P_3.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                system_in_deadlock = false;
                transition_info.group = 45;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_3.state.var == 0) )  &&  ( ((*in).P_3.status.var == 0) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_4.v.var) = (0);
                cpy[((int*)&((*out).channel_link_4.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_4.state.var = 1;
                cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
                (*out).P_3.state.var = 0;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                ((*out).P_3.status.var = 1);
                cpy[((int*)&((*out).P_3.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                system_in_deadlock = false;
                transition_info.group = 46;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).P_3.v.var != 255 && (*in).P_3.status.var == 1 && (*in).P_3.v.var < 0) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_4.v.var) = ((*in).P_3.v.var);
                cpy[((int*)&((*out).channel_link_4.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_4.state.var = 1;
                cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
                (*out).P_3.state.var = 0;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                ((*out).P_3.status.var = 2);
                cpy[((int*)&((*out).P_3.status.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                system_in_deadlock = false;
                transition_info.group = 47;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).P_3.v.var != 255 && (*in).P_3.status.var == 0 && (*in).P_3.v.var < 0) ) )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_link_4.v.var) = ((*in).P_3.v.var);
                cpy[((int*)&((*out).channel_link_4.v.var) - (int*)&(*out))] = 0;
                (*out).channel_link_4.state.var = 1;
                cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
                (*out).P_3.state.var = 0;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                system_in_deadlock = false;
                transition_info.group = 48;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_link_4.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).channel_link_4.state.var = 0;
                cpy[((int*)&(*out).channel_link_4.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 49;
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
    return 25;
}

extern "C" const char* get_state_variable_name(int var)
{
    switch (var)
    {
        case 0:
            return "P_0";
        case 1:
            return "P_0.status";
        case 2:
            return "P_0.v";
        case 3:
            return "P_1";
        case 4:
            return "P_1.status";
        case 5:
            return "P_1.v";
        case 6:
            return "P_2";
        case 7:
            return "P_2.status";
        case 8:
            return "P_2.v";
        case 9:
            return "P_3";
        case 10:
            return "P_3.status";
        case 11:
            return "P_3.v";
        case 12:
            return "P_4";
        case 13:
            return "P_4.status";
        case 14:
            return "P_4.v";
        case 15:
            return "channel_link_0";
        case 16:
            return "channel_link_0.v";
        case 17:
            return "channel_link_1";
        case 18:
            return "channel_link_1.v";
        case 19:
            return "channel_link_2";
        case 20:
            return "channel_link_2.v";
        case 21:
            return "channel_link_3";
        case 22:
            return "channel_link_3.v";
        case 23:
            return "channel_link_4";
        case 24:
            return "channel_link_4.v";
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
            return 1;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 5;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 6;
        case 16:
            return 1;
        case 17:
            return 7;
        case 18:
            return 1;
        case 19:
            return 8;
        case 20:
            return 1;
        case 21:
            return 9;
        case 22:
            return 1;
        case 23:
            return 10;
        case 24:
            return 1;
        default:
            return -1;
    }
}

extern "C" int get_state_variable_type_count() 
{
    return 11;
}

extern "C" const char* get_state_variable_type_name(int type) 
{
    switch (type)
    {
        case 0:
            return "P_0";
        case 2:
            return "P_1";
        case 3:
            return "P_2";
        case 4:
            return "P_3";
        case 5:
            return "P_4";
        case 1:
            return "byte";
        case 6:
            return "channel_link_0";
        case 7:
            return "channel_link_1";
        case 8:
            return "channel_link_2";
        case 9:
            return "channel_link_3";
        case 10:
            return "channel_link_4";
        default:
            return NULL;
    }
}

extern "C" int get_state_variable_type_value_count(int type)
{
    switch (type)
    {
        case 0: // P_0
            return 3;
        case 2: // P_1
            return 3;
        case 3: // P_2
            return 3;
        case 4: // P_3
            return 3;
        case 5: // P_4
            return 3;
        case 1: // byte
            return 0;
        case 6: // channel_link_0
            return 2;
        case 7: // channel_link_1
            return 2;
        case 8: // channel_link_2
            return 2;
        case 9: // channel_link_3
            return 2;
        case 10: // channel_link_4
            return 2;
        default:
            return -1;
    }
}

extern "C" const char* get_state_variable_type_value(int type, int value) 
{
    switch (type)
    {
        case 0:
        {
            switch (value)
            {
                case 0:
                    return "wait";
                case 1:
                    return "CS";
                case 2:
                    return "got_msg";
            }
        }
        case 2:
        {
            switch (value)
            {
                case 0:
                    return "wait";
                case 1:
                    return "CS";
                case 2:
                    return "got_msg";
            }
        }
        case 3:
        {
            switch (value)
            {
                case 0:
                    return "wait";
                case 1:
                    return "CS";
                case 2:
                    return "got_msg";
            }
        }
        case 4:
        {
            switch (value)
            {
                case 0:
                    return "wait";
                case 1:
                    return "CS";
                case 2:
                    return "got_msg";
            }
        }
        case 5:
        {
            switch (value)
            {
                case 0:
                    return "wait";
                case 1:
                    return "CS";
                case 2:
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
                    return "tr";
            }
        }
        case 7:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "tr";
            }
        }
        case 8:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "tr";
            }
        }
        case 9:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "tr";
            }
        }
        case 10:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "tr";
            }
        }
    }
    return NULL;
}

int transition_dependency[][3][25] = 
{
    // { ... read ...}, { ... may-write ...}, { ... must-write ...}
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0}},
    {{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}},
    {{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0}},
    {{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0}},
    {{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0}},
    {{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0}},
    {{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0}},
    {{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1}},
    {{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1}},
    {{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1}},
    {{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}}
}
;

int actions_read[][25] = 
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
}
;

extern "C" int get_transition_count() 
{
    return 50;
}

extern "C" const int* get_transition_read_dependencies(int t) 
{
    if (t>=0 && t < 50) return transition_dependency[t][0];
    return NULL;
}

extern "C" const int* get_transition_actions_read_dependencies(int t) 
{
    if (t>=0 && t < 50) return actions_read[t];
    return NULL;
}

extern "C" const int* get_transition_may_write_dependencies(int t) 
{
    if (t>=0 && t < 50) return transition_dependency[t][1];
    return NULL;
}

extern "C" const int* get_transition_write_dependencies(int t) 
{
    return get_transition_may_write_dependencies(t);
}

extern "C" const int* get_transition_must_write_dependencies(int t) 
{
    if (t>=0 && t < 50) return transition_dependency[t][2];
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
            case 0: return (((*src).P_0.state.var == 0));
            case 1: return (((*src).channel_link_0.state.var == 1));
            case 2: return (((*src).P_0.state.var == 2));
            case 3: return (((*src).P_0.v.var == 255));
            case 4: return (((*src).P_0.v.var != 255));
            case 5: return (((*src).P_0.v.var > 24));
            case 6: return (((*src).P_0.v.var == 24));
            case 7: return (((*src).P_0.status.var != 1));
            case 8: return (((*src).P_0.status.var == 1));
            case 9: return (((*src).P_1.state.var == 0));
            case 10: return (((*src).channel_link_1.state.var == 1));
            case 11: return (((*src).P_1.state.var == 2));
            case 12: return (((*src).P_1.v.var == 255));
            case 13: return (((*src).P_1.v.var != 255));
            case 14: return (((*src).P_1.v.var > 14));
            case 15: return (((*src).P_1.v.var == 14));
            case 16: return (((*src).P_1.status.var != 1));
            case 17: return (((*src).P_1.status.var == 1));
            case 18: return (((*src).P_2.state.var == 0));
            case 19: return (((*src).channel_link_2.state.var == 1));
            case 20: return (((*src).P_2.state.var == 2));
            case 21: return (((*src).P_2.v.var == 255));
            case 22: return (((*src).P_2.v.var != 255));
            case 23: return (((*src).P_2.v.var > 6));
            case 24: return (((*src).P_2.v.var == 6));
            case 25: return (((*src).P_2.status.var != 1));
            case 26: return (((*src).P_2.status.var == 1));
            case 27: return (((*src).P_3.state.var == 0));
            case 28: return (((*src).channel_link_3.state.var == 1));
            case 29: return (((*src).P_3.state.var == 2));
            case 30: return (((*src).P_3.v.var == 255));
            case 31: return (((*src).P_3.v.var != 255));
            case 32: return (((*src).P_3.v.var > 0));
            case 33: return (((*src).P_3.v.var == 0));
            case 34: return (((*src).P_3.status.var != 1));
            case 35: return (((*src).P_3.status.var == 1));
            case 36: return (((*src).P_4.state.var == 0));
            case 37: return (((*src).channel_link_4.state.var == 1));
            case 38: return (((*src).P_4.state.var == 2));
            case 39: return (((*src).P_4.v.var == 255));
            case 40: return (((*src).P_4.v.var != 255));
            case 41: return (((*src).P_4.v.var > 23));
            case 42: return (((*src).P_4.v.var == 23));
            case 43: return (((*src).P_4.status.var != 1));
            case 44: return (((*src).P_4.status.var == 1));
            case 45: return (((*src).channel_link_0.state.var == 0));
            case 46: return (((*src).P_4.state.var == 1));
            case 47: return (((*src).P_4.status.var == 0));
            case 48: return (((*src).P_4.v.var < 23));
            case 49: return (((*src).channel_link_1.state.var == 0));
            case 50: return (((*src).P_0.state.var == 1));
            case 51: return (((*src).P_0.status.var == 0));
            case 52: return (((*src).P_0.v.var < 24));
            case 53: return (((*src).channel_link_2.state.var == 0));
            case 54: return (((*src).P_1.state.var == 1));
            case 55: return (((*src).P_1.status.var == 0));
            case 56: return (((*src).P_1.v.var < 14));
            case 57: return (((*src).channel_link_3.state.var == 0));
            case 58: return (((*src).P_2.state.var == 1));
            case 59: return (((*src).P_2.status.var == 0));
            case 60: return (((*src).P_2.v.var < 6));
            case 61: return (((*src).channel_link_4.state.var == 0));
            case 62: return (((*src).P_3.state.var == 1));
            case 63: return (((*src).P_3.status.var == 0));
            case 64: return (((*src).P_3.v.var < 0));
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
    guard[44] = get_guard(model, 44, src);
    guard[45] = get_guard(model, 45, src);
    guard[46] = get_guard(model, 46, src);
    guard[47] = get_guard(model, 47, src);
    guard[48] = get_guard(model, 48, src);
    guard[49] = get_guard(model, 49, src);
    guard[50] = get_guard(model, 50, src);
    guard[51] = get_guard(model, 51, src);
    guard[52] = get_guard(model, 52, src);
    guard[53] = get_guard(model, 53, src);
    guard[54] = get_guard(model, 54, src);
    guard[55] = get_guard(model, 55, src);
    guard[56] = get_guard(model, 56, src);
    guard[57] = get_guard(model, 57, src);
    guard[58] = get_guard(model, 58, src);
    guard[59] = get_guard(model, 59, src);
    guard[60] = get_guard(model, 60, src);
    guard[61] = get_guard(model, 61, src);
    guard[62] = get_guard(model, 62, src);
    guard[63] = get_guard(model, 63, src);
    guard[64] = get_guard(model, 64, src);
}

extern "C" const int get_guard_count() 
{
    return 65;
}

#pragma clang diagnostic push
int* guards_per_transition[50] = 
{
    ((int[]){2, 0, 1}), // 0
    ((int[]){2, 2, 3}), // 1
    ((int[]){3, 2, 4, 5}), // 2
    ((int[]){4, 2, 4, 6, 7}), // 3
    ((int[]){4, 2, 4, 6, 8}), // 4
    ((int[]){2, 9, 10}), // 5
    ((int[]){2, 11, 12}), // 6
    ((int[]){3, 11, 13, 14}), // 7
    ((int[]){4, 11, 13, 15, 16}), // 8
    ((int[]){4, 11, 13, 15, 17}), // 9
    ((int[]){2, 18, 19}), // 10
    ((int[]){2, 20, 21}), // 11
    ((int[]){3, 20, 22, 23}), // 12
    ((int[]){4, 20, 22, 24, 25}), // 13
    ((int[]){4, 20, 22, 24, 26}), // 14
    ((int[]){2, 27, 28}), // 15
    ((int[]){2, 29, 30}), // 16
    ((int[]){3, 29, 31, 32}), // 17
    ((int[]){4, 29, 31, 33, 34}), // 18
    ((int[]){4, 29, 31, 33, 35}), // 19
    ((int[]){2, 36, 37}), // 20
    ((int[]){2, 38, 39}), // 21
    ((int[]){3, 38, 40, 41}), // 22
    ((int[]){4, 38, 40, 42, 43}), // 23
    ((int[]){4, 38, 40, 42, 44}), // 24
    ((int[]){2, 45, 46}), // 25
    ((int[]){3, 45, 36, 47}), // 26
    ((int[]){5, 45, 38, 40, 44, 48}), // 27
    ((int[]){5, 45, 38, 40, 47, 48}), // 28
    ((int[]){1, 1}), // 29
    ((int[]){2, 49, 50}), // 30
    ((int[]){3, 49, 0, 51}), // 31
    ((int[]){5, 49, 2, 4, 8, 52}), // 32
    ((int[]){5, 49, 2, 4, 51, 52}), // 33
    ((int[]){1, 10}), // 34
    ((int[]){2, 53, 54}), // 35
    ((int[]){3, 53, 9, 55}), // 36
    ((int[]){5, 53, 11, 13, 17, 56}), // 37
    ((int[]){5, 53, 11, 13, 55, 56}), // 38
    ((int[]){1, 19}), // 39
    ((int[]){2, 57, 58}), // 40
    ((int[]){3, 57, 18, 59}), // 41
    ((int[]){5, 57, 20, 22, 26, 60}), // 42
    ((int[]){5, 57, 20, 22, 59, 60}), // 43
    ((int[]){1, 28}), // 44
    ((int[]){2, 61, 62}), // 45
    ((int[]){3, 61, 27, 63}), // 46
    ((int[]){5, 61, 29, 31, 35, 64}), // 47
    ((int[]){5, 61, 29, 31, 63, 64}), // 48
    ((int[]){1, 37}), // 49
}
;
#pragma clang diagnostic pop

extern "C" const int* get_guards(int t) 
{
    if (t>=0 && t < 50) return guards_per_transition[t];
    return NULL;
}

extern "C" const int** get_all_guards() 
{
    return (const int**)&guards_per_transition;
}

int guard[][25] = 
{
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0}
}
;

extern "C" const int* get_guard_matrix(int g) 
{
    if (g>=0 && g < 65) return guard[g];
    return NULL;
}

int guardmaybecoenabled[65][65] = 
{
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_may_be_coenabled_matrix(int g) 
{
    if (g>=0 && g < 65) return guardmaybecoenabled[g];
    return NULL;
}

int guard_nes[65][50] = 
{
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_nes_matrix(int g) 
{
    if (g>=0 && g < 65) return guard_nes[g];
    return NULL;
}

int guard_nds[65][50] = 
{
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_nds_matrix(int g) 
{
    if (g>=0 && g < 65) return guard_nds[g];
    return NULL;
}

int dna[50][50] = 
{
    {1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_dna_matrix(int t) 
{
    if (t >= 0 && t < 50) return dna[t];
    return NULL;
}

