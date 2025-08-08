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
        byte_t x;
        byte_t v;
    }
    __attribute__((__packed__)) NonatomicVar_0;
    struct
    {
        ushort_int_t state;
        byte_t x;
        byte_t v;
    }
    __attribute__((__packed__)) NonatomicVar_1;
    struct
    {
        ushort_int_t state;
        byte_t x;
        byte_t v;
    }
    __attribute__((__packed__)) NonatomicVar_2;
    struct
    {
        ushort_int_t state;
        byte_t i;
        byte_t v;
    }
    __attribute__((__packed__)) P_0;
    struct
    {
        ushort_int_t state;
        byte_t i;
        byte_t v;
    }
    __attribute__((__packed__)) P_1;
    struct
    {
        ushort_int_t state;
        byte_t i;
        byte_t v;
    }
    __attribute__((__packed__)) P_2;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

state_struct_t initial_state = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

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
        ((*out).NonatomicVar_0.v.var) = (1);
        cpy[((int*)&((*out).NonatomicVar_0.v.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 1;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l1: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).NonatomicVar_0.v.var) = (0);
        cpy[((int*)&((*out).NonatomicVar_0.v.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 8;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l2: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).NonatomicVar_0.v.var) = (0);
        cpy[((int*)&((*out).NonatomicVar_0.v.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 11;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l3: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).NonatomicVar_1.v.var) = (1);
        cpy[((int*)&((*out).NonatomicVar_1.v.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 1;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l4: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).NonatomicVar_1.v.var) = (0);
        cpy[((int*)&((*out).NonatomicVar_1.v.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 8;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l5: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).NonatomicVar_1.v.var) = (0);
        cpy[((int*)&((*out).NonatomicVar_1.v.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 11;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l6: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).NonatomicVar_2.v.var) = (1);
        cpy[((int*)&((*out).NonatomicVar_2.v.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 1;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l7: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).NonatomicVar_2.v.var) = (0);
        cpy[((int*)&((*out).NonatomicVar_2.v.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 8;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l8: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).NonatomicVar_2.v.var) = (0);
        cpy[((int*)&((*out).NonatomicVar_2.v.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 11;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l9: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 2;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).P_0.i.var = 0);
        cpy[((int*)&((*out).P_0.i.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        ((*out).NonatomicVar_0.x.var = (*out).NonatomicVar_0.v.var);
        cpy[((int*)&((*out).NonatomicVar_0.x.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l10: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 3;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).P_0.i.var = 0 + 1);
        cpy[((int*)&((*out).P_0.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l11: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 4;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l12: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 4;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l13: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 4;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l14: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 4;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l15: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 4;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l16: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 4;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l17: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 4;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l18: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 4;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l19: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 4;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l20: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l21: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l22: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l23: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l24: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l25: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l26: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l27: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l28: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l29: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 10;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l30: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 2;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).P_0.i.var = (*out).P_0.i.var + 1);
        cpy[((int*)&((*out).P_0.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l31: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 5;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l32: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 6;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l33: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 0;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l34: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 5;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l35: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 5;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l36: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 5;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l37: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 5;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l38: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 5;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l39: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 5;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l40: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 5;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l41: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 5;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l42: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 5;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l43: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 7;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        ((*out).NonatomicVar_0.x.var = (*out).NonatomicVar_0.v.var);
        cpy[((int*)&((*out).NonatomicVar_0.x.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l44: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l45: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l46: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l47: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l48: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l49: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l50: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l51: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (0);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l52: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_0.v.var) = (1);
        cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
        (*out).P_0.state.var = 9;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l53: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 3;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).P_0.i.var = (*out).P_0.i.var + 1);
        cpy[((int*)&((*out).P_0.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l54: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 0;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        ((*out).NonatomicVar_0.x.var = (*out).NonatomicVar_0.v.var);
        cpy[((int*)&((*out).NonatomicVar_0.x.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l55: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 2;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).P_1.i.var = 0);
        cpy[((int*)&((*out).P_1.i.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        ((*out).NonatomicVar_1.x.var = (*out).NonatomicVar_1.v.var);
        cpy[((int*)&((*out).NonatomicVar_1.x.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l56: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 3;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).P_1.i.var = 1 + 1);
        cpy[((int*)&((*out).P_1.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l57: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 4;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l58: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 4;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l59: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 4;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l60: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 4;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l61: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 4;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l62: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 4;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l63: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 4;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l64: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 4;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l65: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 4;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l66: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l67: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l68: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l69: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l70: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l71: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l72: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l73: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l74: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l75: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 10;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l76: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 2;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).P_1.i.var = (*out).P_1.i.var + 1);
        cpy[((int*)&((*out).P_1.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l77: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 5;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l78: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 6;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l79: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 0;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l80: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 5;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l81: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 5;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l82: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 5;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l83: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 5;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l84: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 5;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l85: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 5;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l86: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 5;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l87: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 5;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l88: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 5;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l89: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 7;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        ((*out).NonatomicVar_1.x.var = (*out).NonatomicVar_1.v.var);
        cpy[((int*)&((*out).NonatomicVar_1.x.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l90: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l91: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l92: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l93: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l94: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l95: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l96: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l97: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (0);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l98: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_1.v.var) = (1);
        cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
        (*out).P_1.state.var = 9;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l99: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 3;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).P_1.i.var = (*out).P_1.i.var + 1);
        cpy[((int*)&((*out).P_1.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l100: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 0;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        ((*out).NonatomicVar_1.x.var = (*out).NonatomicVar_1.v.var);
        cpy[((int*)&((*out).NonatomicVar_1.x.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l101: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 2;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).P_2.i.var = 0);
        cpy[((int*)&((*out).P_2.i.var) - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        ((*out).NonatomicVar_2.x.var = (*out).NonatomicVar_2.v.var);
        cpy[((int*)&((*out).NonatomicVar_2.x.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0
        // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l102: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 3;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).P_2.i.var = 2 + 1);
        cpy[((int*)&((*out).P_2.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l103: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 4;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l104: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 4;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l105: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 4;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l106: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 4;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l107: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 4;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l108: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 4;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l109: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 4;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l110: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 4;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l111: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 4;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l112: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l113: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l114: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l115: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l116: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l117: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l118: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l119: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l120: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l121: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 10;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l122: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 2;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).P_2.i.var = (*out).P_2.i.var + 1);
        cpy[((int*)&((*out).P_2.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l123: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 5;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l124: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 6;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l125: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 0;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l126: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 5;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l127: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 5;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l128: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 5;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l129: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 5;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l130: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 5;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l131: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 5;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l132: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 5;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l133: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 5;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l134: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 5;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l135: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 7;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        ((*out).NonatomicVar_2.x.var = (*out).NonatomicVar_2.v.var);
        cpy[((int*)&((*out).NonatomicVar_2.x.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l136: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_0.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l137: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l138: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_0.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l139: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_1.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l140: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l141: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_1.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l142: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = ((*in).NonatomicVar_2.x.var);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l143: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (0);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l144: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).P_2.v.var) = (1);
        cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
        (*out).P_2.state.var = 9;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 1;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l145: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 3;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).P_2.i.var = (*out).P_2.i.var + 1);
        cpy[((int*)&((*out).P_2.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l146: {
        *out = *in;
        int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 0;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        (*out).NonatomicVar_2.state.var = 0;
        cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
        ((*out).NonatomicVar_2.x.var = (*out).NonatomicVar_2.v.var);
        cpy[((int*)&((*out).NonatomicVar_2.x.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0
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
        case 53: goto l53;
        case 54: goto l54;
        case 55: goto l55;
        case 56: goto l56;
        case 57: goto l57;
        case 58: goto l58;
        case 59: goto l59;
        case 60: goto l60;
        case 61: goto l61;
        case 62: goto l62;
        case 63: goto l63;
        case 64: goto l64;
        case 65: goto l65;
        case 66: goto l66;
        case 67: goto l67;
        case 68: goto l68;
        case 69: goto l69;
        case 70: goto l70;
        case 71: goto l71;
        case 72: goto l72;
        case 73: goto l73;
        case 74: goto l74;
        case 75: goto l75;
        case 76: goto l76;
        case 77: goto l77;
        case 78: goto l78;
        case 79: goto l79;
        case 80: goto l80;
        case 81: goto l81;
        case 82: goto l82;
        case 83: goto l83;
        case 84: goto l84;
        case 85: goto l85;
        case 86: goto l86;
        case 87: goto l87;
        case 88: goto l88;
        case 89: goto l89;
        case 90: goto l90;
        case 91: goto l91;
        case 92: goto l92;
        case 93: goto l93;
        case 94: goto l94;
        case 95: goto l95;
        case 96: goto l96;
        case 97: goto l97;
        case 98: goto l98;
        case 99: goto l99;
        case 100: goto l100;
        case 101: goto l101;
        case 102: goto l102;
        case 103: goto l103;
        case 104: goto l104;
        case 105: goto l105;
        case 106: goto l106;
        case 107: goto l107;
        case 108: goto l108;
        case 109: goto l109;
        case 110: goto l110;
        case 111: goto l111;
        case 112: goto l112;
        case 113: goto l113;
        case 114: goto l114;
        case 115: goto l115;
        case 116: goto l116;
        case 117: goto l117;
        case 118: goto l118;
        case 119: goto l119;
        case 120: goto l120;
        case 121: goto l121;
        case 122: goto l122;
        case 123: goto l123;
        case 124: goto l124;
        case 125: goto l125;
        case 126: goto l126;
        case 127: goto l127;
        case 128: goto l128;
        case 129: goto l129;
        case 130: goto l130;
        case 131: goto l131;
        case 132: goto l132;
        case 133: goto l133;
        case 134: goto l134;
        case 135: goto l135;
        case 136: goto l136;
        case 137: goto l137;
        case 138: goto l138;
        case 139: goto l139;
        case 140: goto l140;
        case 141: goto l141;
        case 142: goto l142;
        case 143: goto l143;
        case 144: goto l144;
        case 145: goto l145;
        case 146: goto l146;
        default: printf ("Wrong group! Using greybox/long call + -l (DiVinE LTL semantics)? This combo is not implemented."); exit (-1);
    }
    return 0;
}

extern "C" int get_successor( void* model, int t, const state_struct_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    int states_emitted = 0;
    goto switch_state;
    l0: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).NonatomicVar_0.state.var == 0) )  &&  ( ((*in).P_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l1: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).NonatomicVar_0.state.var == 0) )  &&  ( ((*in).P_0.state.var == 6) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l2: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).NonatomicVar_0.state.var == 0) )  &&  ( ((*in).P_0.state.var == 10) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l3: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).NonatomicVar_1.state.var == 0) )  &&  ( ((*in).P_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l4: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).NonatomicVar_1.state.var == 0) )  &&  ( ((*in).P_1.state.var == 6) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l5: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).NonatomicVar_1.state.var == 0) )  &&  ( ((*in).P_1.state.var == 10) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l6: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).NonatomicVar_2.state.var == 0) )  &&  ( ((*in).P_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l7: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).NonatomicVar_2.state.var == 0) )  &&  ( ((*in).P_2.state.var == 6) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l8: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).NonatomicVar_2.state.var == 0) )  &&  ( ((*in).P_2.state.var == 10) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l9: {
        
        // read:         1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 1) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l10: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.i.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l11: {
        
        // read:         1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l12: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l13: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l14: {
        
        // read:         0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l15: {
        
        // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l16: {
        
        // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l17: {
        
        // read:         0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l18: {
        
        // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l19: {
        
        // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l20: {
        
        // read:         1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) )  &&  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l21: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) )  &&  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l22: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) )  &&  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l23: {
        
        // read:         0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) )  &&  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l24: {
        
        // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) )  &&  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l25: {
        
        // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) )  &&  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l26: {
        
        // read:         0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) )  &&  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l27: {
        
        // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) )  &&  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l28: {
        
        // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) )  &&  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l29: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) )  &&  ( ((*in).P_0.i.var == 3) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l30: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 4) )  &&  ( ((*in).P_0.v.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l31: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 4) )  &&  ( ((*in).P_0.v.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l32: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 5) )  &&  ( ((*in).P_0.v.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l33: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 5) )  &&  ( ((*in).P_0.v.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l34: {
        
        // read:         1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 7) )  &&  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l35: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 7) )  &&  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l36: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 7) )  &&  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l37: {
        
        // read:         0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 7) )  &&  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l38: {
        
        // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 7) )  &&  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l39: {
        
        // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 7) )  &&  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l40: {
        
        // read:         0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 7) )  &&  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l41: {
        
        // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 7) )  &&  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l42: {
        
        // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 7) )  &&  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l43: {
        
        // read:         1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 8) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l44: {
        
        // read:         1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 9) )  &&  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l45: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 9) )  &&  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l46: {
        
        // read:         1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 9) )  &&  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l47: {
        
        // read:         0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 9) )  &&  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l48: {
        
        // read:         0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 9) )  &&  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l49: {
        
        // read:         0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 9) )  &&  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l50: {
        
        // read:         0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 9) )  &&  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l51: {
        
        // read:         0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 9) )  &&  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l52: {
        
        // read:         0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 9) )  &&  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l53: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 9) )  &&  ( ((*in).P_0.v.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l54: {
        
        // read:         1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 11) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l55: {
        
        // read:         0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l56: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.i.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l57: {
        
        // read:         1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l58: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l59: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l60: {
        
        // read:         0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l61: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l62: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l63: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l64: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l65: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l66: {
        
        // read:         1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) )  &&  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l67: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) )  &&  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l68: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) )  &&  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l69: {
        
        // read:         0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) )  &&  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l70: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) )  &&  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l71: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) )  &&  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l72: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) )  &&  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l73: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) )  &&  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l74: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) )  &&  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l75: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) )  &&  ( ((*in).P_1.i.var == 3) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l76: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).P_1.state.var == 4) )  &&  ( ((*in).P_1.v.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l77: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 4) )  &&  ( ((*in).P_1.v.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l78: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 5) )  &&  ( ((*in).P_1.v.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l79: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 5) )  &&  ( ((*in).P_1.v.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l80: {
        
        // read:         1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 7) )  &&  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l81: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 7) )  &&  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l82: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 7) )  &&  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l83: {
        
        // read:         0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 7) )  &&  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l84: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 7) )  &&  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l85: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 7) )  &&  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l86: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 7) )  &&  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l87: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 7) )  &&  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l88: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 7) )  &&  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l89: {
        
        // read:         0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 8) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l90: {
        
        // read:         1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 9) )  &&  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l91: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 9) )  &&  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l92: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 9) )  &&  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l93: {
        
        // read:         0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 9) )  &&  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l94: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 9) )  &&  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l95: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 9) )  &&  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l96: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 9) )  &&  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l97: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 9) )  &&  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l98: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 9) )  &&  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l99: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).P_1.state.var == 9) )  &&  ( ((*in).P_1.v.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l100: {
        
        // read:         0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 11) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l101: {
        
        // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 1) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l102: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.i.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l103: {
        
        // read:         1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l104: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l105: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l106: {
        
        // read:         0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l107: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l108: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l109: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l110: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l111: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l112: {
        
        // read:         1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) )  &&  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l113: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) )  &&  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l114: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) )  &&  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l115: {
        
        // read:         0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) )  &&  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l116: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) )  &&  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l117: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) )  &&  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l118: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) )  &&  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l119: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) )  &&  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l120: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) )  &&  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l121: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) )  &&  ( ((*in).P_2.i.var == 3) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l122: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        if (  ( ((*in).P_2.state.var == 4) )  &&  ( ((*in).P_2.v.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l123: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 4) )  &&  ( ((*in).P_2.v.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l124: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 5) )  &&  ( ((*in).P_2.v.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l125: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 5) )  &&  ( ((*in).P_2.v.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l126: {
        
        // read:         1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 7) )  &&  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l127: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 7) )  &&  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l128: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 7) )  &&  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l129: {
        
        // read:         0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 7) )  &&  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l130: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 7) )  &&  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l131: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 7) )  &&  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l132: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 7) )  &&  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l133: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 7) )  &&  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l134: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 7) )  &&  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l135: {
        
        // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 8) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l136: {
        
        // read:         1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 9) )  &&  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l137: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 9) )  &&  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l138: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 9) )  &&  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l139: {
        
        // read:         0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 9) )  &&  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l140: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 9) )  &&  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l141: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 9) )  &&  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l142: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 9) )  &&  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l143: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 9) )  &&  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l144: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 9) )  &&  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l145: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        if (  ( ((*in).P_2.state.var == 9) )  &&  ( ((*in).P_2.v.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l146: {
        
        // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 11) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
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
        case 53: goto l53;
        case 54: goto l54;
        case 55: goto l55;
        case 56: goto l56;
        case 57: goto l57;
        case 58: goto l58;
        case 59: goto l59;
        case 60: goto l60;
        case 61: goto l61;
        case 62: goto l62;
        case 63: goto l63;
        case 64: goto l64;
        case 65: goto l65;
        case 66: goto l66;
        case 67: goto l67;
        case 68: goto l68;
        case 69: goto l69;
        case 70: goto l70;
        case 71: goto l71;
        case 72: goto l72;
        case 73: goto l73;
        case 74: goto l74;
        case 75: goto l75;
        case 76: goto l76;
        case 77: goto l77;
        case 78: goto l78;
        case 79: goto l79;
        case 80: goto l80;
        case 81: goto l81;
        case 82: goto l82;
        case 83: goto l83;
        case 84: goto l84;
        case 85: goto l85;
        case 86: goto l86;
        case 87: goto l87;
        case 88: goto l88;
        case 89: goto l89;
        case 90: goto l90;
        case 91: goto l91;
        case 92: goto l92;
        case 93: goto l93;
        case 94: goto l94;
        case 95: goto l95;
        case 96: goto l96;
        case 97: goto l97;
        case 98: goto l98;
        case 99: goto l99;
        case 100: goto l100;
        case 101: goto l101;
        case 102: goto l102;
        case 103: goto l103;
        case 104: goto l104;
        case 105: goto l105;
        case 106: goto l106;
        case 107: goto l107;
        case 108: goto l108;
        case 109: goto l109;
        case 110: goto l110;
        case 111: goto l111;
        case 112: goto l112;
        case 113: goto l113;
        case 114: goto l114;
        case 115: goto l115;
        case 116: goto l116;
        case 117: goto l117;
        case 118: goto l118;
        case 119: goto l119;
        case 120: goto l120;
        case 121: goto l121;
        case 122: goto l122;
        case 123: goto l123;
        case 124: goto l124;
        case 125: goto l125;
        case 126: goto l126;
        case 127: goto l127;
        case 128: goto l128;
        case 129: goto l129;
        case 130: goto l130;
        case 131: goto l131;
        case 132: goto l132;
        case 133: goto l133;
        case 134: goto l134;
        case 135: goto l135;
        case 136: goto l136;
        case 137: goto l137;
        case 138: goto l138;
        case 139: goto l139;
        case 140: goto l140;
        case 141: goto l141;
        case 142: goto l142;
        case 143: goto l143;
        case 144: goto l144;
        case 145: goto l145;
        case 146: goto l146;
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
        if (  ( ((*in).NonatomicVar_0.state.var == 0) ) )
        {
            
            // read:         1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).NonatomicVar_0.v.var) = (1);
                cpy[((int*)&((*out).NonatomicVar_0.v.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 1;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 0;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.state.var == 6) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).NonatomicVar_0.v.var) = (0);
                cpy[((int*)&((*out).NonatomicVar_0.v.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 8;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 1;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.state.var == 10) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).NonatomicVar_0.v.var) = (0);
                cpy[((int*)&((*out).NonatomicVar_0.v.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 11;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 2;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).NonatomicVar_1.state.var == 0) ) )
        {
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).NonatomicVar_1.v.var) = (1);
                cpy[((int*)&((*out).NonatomicVar_1.v.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 1;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 3;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.state.var == 6) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).NonatomicVar_1.v.var) = (0);
                cpy[((int*)&((*out).NonatomicVar_1.v.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 8;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 4;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.state.var == 10) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).NonatomicVar_1.v.var) = (0);
                cpy[((int*)&((*out).NonatomicVar_1.v.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 11;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 5;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).NonatomicVar_2.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).NonatomicVar_2.v.var) = (1);
                cpy[((int*)&((*out).NonatomicVar_2.v.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 1;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 6;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.state.var == 6) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).NonatomicVar_2.v.var) = (0);
                cpy[((int*)&((*out).NonatomicVar_2.v.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 8;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 7;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.state.var == 10) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).NonatomicVar_2.v.var) = (0);
                cpy[((int*)&((*out).NonatomicVar_2.v.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 11;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 8;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 1) ) )
        {
            
            // read:         1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 2;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).P_0.i.var = 0);
                cpy[((int*)&((*out).P_0.i.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                ((*out).NonatomicVar_0.x.var = (*out).NonatomicVar_0.v.var);
                cpy[((int*)&((*out).NonatomicVar_0.x.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 9;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 3;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).P_0.i.var = 0 + 1);
                cpy[((int*)&((*out).P_0.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 10;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 4;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 11;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 4;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 12;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 4;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 13;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 4;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 14;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 4;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 15;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 4;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 16;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 4;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 17;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 4;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 18;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 4;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 19;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 3) ) )
        {
            
            // read:         1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 20;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 21;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 22;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 23;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 24;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 25;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 26;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 27;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 28;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 3) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 10;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 29;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 4) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 2;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).P_0.i.var = (*out).P_0.i.var + 1);
                cpy[((int*)&((*out).P_0.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 30;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 5;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 31;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 5) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 6;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 32;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 0;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 33;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 7) ) )
        {
            
            // read:         1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 5;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 34;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 5;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 35;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 5;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 36;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 5;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 37;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 5;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 38;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 5;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 39;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 5;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 40;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 5;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 41;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 5;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 42;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 8) ) )
        {
            
            // read:         1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 7;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                ((*out).NonatomicVar_0.x.var = (*out).NonatomicVar_0.v.var);
                cpy[((int*)&((*out).NonatomicVar_0.x.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 43;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 9) ) )
        {
            
            // read:         1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 44;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 45;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 46;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 47;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 48;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 49;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 50;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (0);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 51;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 1 && (*in).P_0.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_0.v.var) = (1);
                cpy[((int*)&((*out).P_0.v.var) - (int*)&(*out))] = 0;
                (*out).P_0.state.var = 9;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 52;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
            if (  ( ((*in).P_0.v.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 3;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).P_0.i.var = (*out).P_0.i.var + 1);
                cpy[((int*)&((*out).P_0.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 53;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 11) ) )
        {
            
            // read:         1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 0;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                ((*out).NonatomicVar_0.x.var = (*out).NonatomicVar_0.v.var);
                cpy[((int*)&((*out).NonatomicVar_0.x.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 54;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 1) ) )
        {
            
            // read:         0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 2;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).P_1.i.var = 0);
                cpy[((int*)&((*out).P_1.i.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                ((*out).NonatomicVar_1.x.var = (*out).NonatomicVar_1.v.var);
                cpy[((int*)&((*out).NonatomicVar_1.x.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 55;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 3;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).P_1.i.var = 1 + 1);
                cpy[((int*)&((*out).P_1.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 56;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 4;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 57;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 4;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 58;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 4;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 59;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 4;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 60;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 4;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 61;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 4;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 62;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 4;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 63;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 4;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 64;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 4;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 65;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 3) ) )
        {
            
            // read:         1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 66;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 67;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 68;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 69;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 70;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 71;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 72;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 73;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 74;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 3) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 10;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 75;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 4) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).P_1.v.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 2;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).P_1.i.var = (*out).P_1.i.var + 1);
                cpy[((int*)&((*out).P_1.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 76;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 5;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 77;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 5) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 6;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 78;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 0;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 79;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 7) ) )
        {
            
            // read:         1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 5;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 80;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 5;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 81;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 5;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 82;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 5;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 83;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 5;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 84;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 5;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 85;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 5;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 86;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 5;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 87;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 5;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 88;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 8) ) )
        {
            
            // read:         0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 7;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                ((*out).NonatomicVar_1.x.var = (*out).NonatomicVar_1.v.var);
                cpy[((int*)&((*out).NonatomicVar_1.x.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 89;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 9) ) )
        {
            
            // read:         1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 90;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 91;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 92;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 93;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 94;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 95;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 96;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (0);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 97;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_1.v.var == 1 && (*in).P_1.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_1.v.var) = (1);
                cpy[((int*)&((*out).P_1.v.var) - (int*)&(*out))] = 0;
                (*out).P_1.state.var = 9;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 98;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).P_1.v.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 3;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).P_1.i.var = (*out).P_1.i.var + 1);
                cpy[((int*)&((*out).P_1.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 99;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 11) ) )
        {
            
            // read:         0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 0;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                ((*out).NonatomicVar_1.x.var = (*out).NonatomicVar_1.v.var);
                cpy[((int*)&((*out).NonatomicVar_1.x.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 100;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 2;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).P_2.i.var = 0);
                cpy[((int*)&((*out).P_2.i.var) - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                ((*out).NonatomicVar_2.x.var = (*out).NonatomicVar_2.v.var);
                cpy[((int*)&((*out).NonatomicVar_2.x.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0
                // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0
                system_in_deadlock = false;
                transition_info.group = 101;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 2) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 3;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).P_2.i.var = 2 + 1);
                cpy[((int*)&((*out).P_2.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
                system_in_deadlock = false;
                transition_info.group = 102;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 4;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 103;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 4;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 104;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 4;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 105;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 4;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 106;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 4;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 107;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 4;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 108;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 4;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 109;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 4;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 110;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 4;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 111;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 3) ) )
        {
            
            // read:         1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 112;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 113;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 114;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 115;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 116;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 117;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 118;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 119;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 120;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 3) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 10;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 121;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 4) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
            if (  ( ((*in).P_2.v.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 2;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).P_2.i.var = (*out).P_2.i.var + 1);
                cpy[((int*)&((*out).P_2.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
                system_in_deadlock = false;
                transition_info.group = 122;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 5;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 123;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 5) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 6;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 124;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 0;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 125;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 7) ) )
        {
            
            // read:         1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 5;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 126;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 5;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 127;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 5;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 128;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 5;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 129;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 5;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 130;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 5;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 131;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 5;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 132;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 5;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 133;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 5;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 134;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 8) ) )
        {
            
            // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 7;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                ((*out).NonatomicVar_2.x.var = (*out).NonatomicVar_2.v.var);
                cpy[((int*)&((*out).NonatomicVar_2.x.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 135;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 9) ) )
        {
            
            // read:         1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_0.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 136;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 137;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 0) )  &&  ( ((*in).NonatomicVar_0.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_0.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 138;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_1.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 139;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 140;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 1) )  &&  ( ((*in).NonatomicVar_1.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_1.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 141;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = ((*in).NonatomicVar_2.x.var);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 142;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (0);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 143;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).P_2.v.var == 1 && (*in).P_2.i.var == 2) )  &&  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).P_2.v.var) = (1);
                cpy[((int*)&((*out).P_2.v.var) - (int*)&(*out))] = 0;
                (*out).P_2.state.var = 9;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 1;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 144;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
            if (  ( ((*in).P_2.v.var == 0) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 3;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).P_2.i.var = (*out).P_2.i.var + 1);
                cpy[((int*)&((*out).P_2.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
                system_in_deadlock = false;
                transition_info.group = 145;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 11) ) )
        {
            
            // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).NonatomicVar_2.state.var == 1) ) )
            {
                *out = *in;
                int cpy[18] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 0;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                (*out).NonatomicVar_2.state.var = 0;
                cpy[((int*)&(*out).NonatomicVar_2.state.var - (int*)&(*out))] = 0;
                ((*out).NonatomicVar_2.x.var = (*out).NonatomicVar_2.v.var);
                cpy[((int*)&((*out).NonatomicVar_2.x.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 146;
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
            return "NonatomicVar_0";
        case 1:
            return "NonatomicVar_0.x";
        case 2:
            return "NonatomicVar_0.v";
        case 3:
            return "NonatomicVar_1";
        case 4:
            return "NonatomicVar_1.x";
        case 5:
            return "NonatomicVar_1.v";
        case 6:
            return "NonatomicVar_2";
        case 7:
            return "NonatomicVar_2.x";
        case 8:
            return "NonatomicVar_2.v";
        case 9:
            return "P_0";
        case 10:
            return "P_0.i";
        case 11:
            return "P_0.v";
        case 12:
            return "P_1";
        case 13:
            return "P_1.i";
        case 14:
            return "P_1.v";
        case 15:
            return "P_2";
        case 16:
            return "P_2.i";
        case 17:
            return "P_2.v";
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
            return 1;
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
        case 0:
            return "NonatomicVar_0";
        case 2:
            return "NonatomicVar_1";
        case 3:
            return "NonatomicVar_2";
        case 4:
            return "P_0";
        case 5:
            return "P_1";
        case 6:
            return "P_2";
        case 1:
            return "byte";
        default:
            return NULL;
    }
}

extern "C" int get_state_variable_type_value_count(int type)
{
    switch (type)
    {
        case 0: // NonatomicVar_0
            return 2;
        case 2: // NonatomicVar_1
            return 2;
        case 3: // NonatomicVar_2
            return 2;
        case 4: // P_0
            return 12;
        case 5: // P_1
            return 12;
        case 6: // P_2
            return 12;
        case 1: // byte
            return 0;
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
                    return "q";
                case 1:
                    return "r";
            }
        }
        case 2:
        {
            switch (value)
            {
                case 0:
                    return "q";
                case 1:
                    return "r";
            }
        }
        case 3:
        {
            switch (value)
            {
                case 0:
                    return "q";
                case 1:
                    return "r";
            }
        }
        case 4:
        {
            switch (value)
            {
                case 0:
                    return "NCS";
                case 1:
                    return "w1";
                case 2:
                    return "p3";
                case 3:
                    return "p8";
                case 4:
                    return "p4";
                case 5:
                    return "p5";
                case 6:
                    return "p6";
                case 7:
                    return "p61";
                case 8:
                    return "w2";
                case 9:
                    return "p9";
                case 10:
                    return "CS";
                case 11:
                    return "w3";
            }
        }
        case 5:
        {
            switch (value)
            {
                case 0:
                    return "NCS";
                case 1:
                    return "w1";
                case 2:
                    return "p3";
                case 3:
                    return "p8";
                case 4:
                    return "p4";
                case 5:
                    return "p5";
                case 6:
                    return "p6";
                case 7:
                    return "p61";
                case 8:
                    return "w2";
                case 9:
                    return "p9";
                case 10:
                    return "CS";
                case 11:
                    return "w3";
            }
        }
        case 6:
        {
            switch (value)
            {
                case 0:
                    return "NCS";
                case 1:
                    return "w1";
                case 2:
                    return "p3";
                case 3:
                    return "p8";
                case 4:
                    return "p4";
                case 5:
                    return "p5";
                case 6:
                    return "p6";
                case 7:
                    return "p61";
                case 8:
                    return "w2";
                case 9:
                    return "p9";
                case 10:
                    return "CS";
                case 11:
                    return "w3";
            }
        }
    }
    return NULL;
}

int transition_dependency[][3][18] = 
{
    // { ... read ...}, { ... may-write ...}, { ... must-write ...}
    {{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0}},
    {{1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0}},
    {{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0}},
    {{1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0}},
    {{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0}},
    {{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0}},
    {{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0}}
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
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0}
}
;

extern "C" int get_transition_count() 
{
    return 147;
}

extern "C" const int* get_transition_read_dependencies(int t) 
{
    if (t>=0 && t < 147) return transition_dependency[t][0];
    return NULL;
}

extern "C" const int* get_transition_actions_read_dependencies(int t) 
{
    if (t>=0 && t < 147) return actions_read[t];
    return NULL;
}

extern "C" const int* get_transition_may_write_dependencies(int t) 
{
    if (t>=0 && t < 147) return transition_dependency[t][1];
    return NULL;
}

extern "C" const int* get_transition_write_dependencies(int t) 
{
    return get_transition_may_write_dependencies(t);
}

extern "C" const int* get_transition_must_write_dependencies(int t) 
{
    if (t>=0 && t < 147) return transition_dependency[t][2];
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
            case 0: return (((*src).NonatomicVar_0.state.var == 0));
            case 1: return (((*src).P_0.state.var == 0));
            case 2: return (((*src).P_0.state.var == 6));
            case 3: return (((*src).P_0.state.var == 10));
            case 4: return (((*src).NonatomicVar_1.state.var == 0));
            case 5: return (((*src).P_1.state.var == 0));
            case 6: return (((*src).P_1.state.var == 6));
            case 7: return (((*src).P_1.state.var == 10));
            case 8: return (((*src).NonatomicVar_2.state.var == 0));
            case 9: return (((*src).P_2.state.var == 0));
            case 10: return (((*src).P_2.state.var == 6));
            case 11: return (((*src).P_2.state.var == 10));
            case 12: return (((*src).P_0.state.var == 1));
            case 13: return (((*src).NonatomicVar_0.state.var == 1));
            case 14: return (((*src).P_0.state.var == 2));
            case 15: return (((*src).P_0.i.var == 0));
            case 16: return (((*src).P_0.i.var == 1));
            case 17: return (((*src).NonatomicVar_1.state.var == 1));
            case 18: return (((*src).P_0.i.var == 2));
            case 19: return (((*src).NonatomicVar_2.state.var == 1));
            case 20: return (((*src).P_0.state.var == 3));
            case 21: return (((*src).P_0.i.var == 3));
            case 22: return (((*src).P_0.state.var == 4));
            case 23: return (((*src).P_0.v.var == 0));
            case 24: return (((*src).P_0.v.var == 1));
            case 25: return (((*src).P_0.state.var == 5));
            case 26: return (((*src).P_0.state.var == 7));
            case 27: return (((*src).P_0.state.var == 8));
            case 28: return (((*src).P_0.state.var == 9));
            case 29: return (((*src).P_0.state.var == 11));
            case 30: return (((*src).P_1.state.var == 1));
            case 31: return (((*src).P_1.state.var == 2));
            case 32: return (((*src).P_1.i.var == 1));
            case 33: return (((*src).P_1.i.var == 0));
            case 34: return (((*src).P_1.i.var == 2));
            case 35: return (((*src).P_1.state.var == 3));
            case 36: return (((*src).P_1.i.var == 3));
            case 37: return (((*src).P_1.state.var == 4));
            case 38: return (((*src).P_1.v.var == 0));
            case 39: return (((*src).P_1.v.var == 1));
            case 40: return (((*src).P_1.state.var == 5));
            case 41: return (((*src).P_1.state.var == 7));
            case 42: return (((*src).P_1.state.var == 8));
            case 43: return (((*src).P_1.state.var == 9));
            case 44: return (((*src).P_1.state.var == 11));
            case 45: return (((*src).P_2.state.var == 1));
            case 46: return (((*src).P_2.state.var == 2));
            case 47: return (((*src).P_2.i.var == 2));
            case 48: return (((*src).P_2.i.var == 0));
            case 49: return (((*src).P_2.i.var == 1));
            case 50: return (((*src).P_2.state.var == 3));
            case 51: return (((*src).P_2.i.var == 3));
            case 52: return (((*src).P_2.state.var == 4));
            case 53: return (((*src).P_2.v.var == 0));
            case 54: return (((*src).P_2.v.var == 1));
            case 55: return (((*src).P_2.state.var == 5));
            case 56: return (((*src).P_2.state.var == 7));
            case 57: return (((*src).P_2.state.var == 8));
            case 58: return (((*src).P_2.state.var == 9));
            case 59: return (((*src).P_2.state.var == 11));
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
}

extern "C" const int get_guard_count() 
{
    return 60;
}

#pragma clang diagnostic push
int* guards_per_transition[147] = 
{
    ((int[]){2, 0, 1}), // 0
    ((int[]){2, 0, 2}), // 1
    ((int[]){2, 0, 3}), // 2
    ((int[]){2, 4, 5}), // 3
    ((int[]){2, 4, 6}), // 4
    ((int[]){2, 4, 7}), // 5
    ((int[]){2, 8, 9}), // 6
    ((int[]){2, 8, 10}), // 7
    ((int[]){2, 8, 11}), // 8
    ((int[]){2, 12, 13}), // 9
    ((int[]){2, 14, 15}), // 10
    ((int[]){3, 14, 15, 0}), // 11
    ((int[]){3, 14, 15, 13}), // 12
    ((int[]){3, 14, 15, 13}), // 13
    ((int[]){3, 14, 16, 4}), // 14
    ((int[]){3, 14, 16, 17}), // 15
    ((int[]){3, 14, 16, 17}), // 16
    ((int[]){3, 14, 18, 8}), // 17
    ((int[]){3, 14, 18, 19}), // 18
    ((int[]){3, 14, 18, 19}), // 19
    ((int[]){3, 20, 15, 0}), // 20
    ((int[]){3, 20, 15, 13}), // 21
    ((int[]){3, 20, 15, 13}), // 22
    ((int[]){3, 20, 16, 4}), // 23
    ((int[]){3, 20, 16, 17}), // 24
    ((int[]){3, 20, 16, 17}), // 25
    ((int[]){3, 20, 18, 8}), // 26
    ((int[]){3, 20, 18, 19}), // 27
    ((int[]){3, 20, 18, 19}), // 28
    ((int[]){2, 20, 21}), // 29
    ((int[]){2, 22, 23}), // 30
    ((int[]){2, 22, 24}), // 31
    ((int[]){2, 25, 24}), // 32
    ((int[]){2, 25, 23}), // 33
    ((int[]){3, 26, 15, 0}), // 34
    ((int[]){3, 26, 15, 13}), // 35
    ((int[]){3, 26, 15, 13}), // 36
    ((int[]){3, 26, 16, 4}), // 37
    ((int[]){3, 26, 16, 17}), // 38
    ((int[]){3, 26, 16, 17}), // 39
    ((int[]){3, 26, 18, 8}), // 40
    ((int[]){3, 26, 18, 19}), // 41
    ((int[]){3, 26, 18, 19}), // 42
    ((int[]){2, 27, 13}), // 43
    ((int[]){4, 28, 24, 15, 0}), // 44
    ((int[]){4, 28, 24, 15, 13}), // 45
    ((int[]){4, 28, 24, 15, 13}), // 46
    ((int[]){4, 28, 24, 16, 4}), // 47
    ((int[]){4, 28, 24, 16, 17}), // 48
    ((int[]){4, 28, 24, 16, 17}), // 49
    ((int[]){4, 28, 24, 18, 8}), // 50
    ((int[]){4, 28, 24, 18, 19}), // 51
    ((int[]){4, 28, 24, 18, 19}), // 52
    ((int[]){2, 28, 23}), // 53
    ((int[]){2, 29, 13}), // 54
    ((int[]){2, 30, 17}), // 55
    ((int[]){2, 31, 32}), // 56
    ((int[]){3, 31, 33, 0}), // 57
    ((int[]){3, 31, 33, 13}), // 58
    ((int[]){3, 31, 33, 13}), // 59
    ((int[]){3, 31, 32, 4}), // 60
    ((int[]){3, 31, 32, 17}), // 61
    ((int[]){3, 31, 32, 17}), // 62
    ((int[]){3, 31, 34, 8}), // 63
    ((int[]){3, 31, 34, 19}), // 64
    ((int[]){3, 31, 34, 19}), // 65
    ((int[]){3, 35, 33, 0}), // 66
    ((int[]){3, 35, 33, 13}), // 67
    ((int[]){3, 35, 33, 13}), // 68
    ((int[]){3, 35, 32, 4}), // 69
    ((int[]){3, 35, 32, 17}), // 70
    ((int[]){3, 35, 32, 17}), // 71
    ((int[]){3, 35, 34, 8}), // 72
    ((int[]){3, 35, 34, 19}), // 73
    ((int[]){3, 35, 34, 19}), // 74
    ((int[]){2, 35, 36}), // 75
    ((int[]){2, 37, 38}), // 76
    ((int[]){2, 37, 39}), // 77
    ((int[]){2, 40, 39}), // 78
    ((int[]){2, 40, 38}), // 79
    ((int[]){3, 41, 33, 0}), // 80
    ((int[]){3, 41, 33, 13}), // 81
    ((int[]){3, 41, 33, 13}), // 82
    ((int[]){3, 41, 32, 4}), // 83
    ((int[]){3, 41, 32, 17}), // 84
    ((int[]){3, 41, 32, 17}), // 85
    ((int[]){3, 41, 34, 8}), // 86
    ((int[]){3, 41, 34, 19}), // 87
    ((int[]){3, 41, 34, 19}), // 88
    ((int[]){2, 42, 17}), // 89
    ((int[]){4, 43, 39, 33, 0}), // 90
    ((int[]){4, 43, 39, 33, 13}), // 91
    ((int[]){4, 43, 39, 33, 13}), // 92
    ((int[]){4, 43, 39, 32, 4}), // 93
    ((int[]){4, 43, 39, 32, 17}), // 94
    ((int[]){4, 43, 39, 32, 17}), // 95
    ((int[]){4, 43, 39, 34, 8}), // 96
    ((int[]){4, 43, 39, 34, 19}), // 97
    ((int[]){4, 43, 39, 34, 19}), // 98
    ((int[]){2, 43, 38}), // 99
    ((int[]){2, 44, 17}), // 100
    ((int[]){2, 45, 19}), // 101
    ((int[]){2, 46, 47}), // 102
    ((int[]){3, 46, 48, 0}), // 103
    ((int[]){3, 46, 48, 13}), // 104
    ((int[]){3, 46, 48, 13}), // 105
    ((int[]){3, 46, 49, 4}), // 106
    ((int[]){3, 46, 49, 17}), // 107
    ((int[]){3, 46, 49, 17}), // 108
    ((int[]){3, 46, 47, 8}), // 109
    ((int[]){3, 46, 47, 19}), // 110
    ((int[]){3, 46, 47, 19}), // 111
    ((int[]){3, 50, 48, 0}), // 112
    ((int[]){3, 50, 48, 13}), // 113
    ((int[]){3, 50, 48, 13}), // 114
    ((int[]){3, 50, 49, 4}), // 115
    ((int[]){3, 50, 49, 17}), // 116
    ((int[]){3, 50, 49, 17}), // 117
    ((int[]){3, 50, 47, 8}), // 118
    ((int[]){3, 50, 47, 19}), // 119
    ((int[]){3, 50, 47, 19}), // 120
    ((int[]){2, 50, 51}), // 121
    ((int[]){2, 52, 53}), // 122
    ((int[]){2, 52, 54}), // 123
    ((int[]){2, 55, 54}), // 124
    ((int[]){2, 55, 53}), // 125
    ((int[]){3, 56, 48, 0}), // 126
    ((int[]){3, 56, 48, 13}), // 127
    ((int[]){3, 56, 48, 13}), // 128
    ((int[]){3, 56, 49, 4}), // 129
    ((int[]){3, 56, 49, 17}), // 130
    ((int[]){3, 56, 49, 17}), // 131
    ((int[]){3, 56, 47, 8}), // 132
    ((int[]){3, 56, 47, 19}), // 133
    ((int[]){3, 56, 47, 19}), // 134
    ((int[]){2, 57, 19}), // 135
    ((int[]){4, 58, 54, 48, 0}), // 136
    ((int[]){4, 58, 54, 48, 13}), // 137
    ((int[]){4, 58, 54, 48, 13}), // 138
    ((int[]){4, 58, 54, 49, 4}), // 139
    ((int[]){4, 58, 54, 49, 17}), // 140
    ((int[]){4, 58, 54, 49, 17}), // 141
    ((int[]){4, 58, 54, 47, 8}), // 142
    ((int[]){4, 58, 54, 47, 19}), // 143
    ((int[]){4, 58, 54, 47, 19}), // 144
    ((int[]){2, 58, 53}), // 145
    ((int[]){2, 59, 19}), // 146
}
;
#pragma clang diagnostic pop

extern "C" const int* get_guards(int t) 
{
    if (t>=0 && t < 147) return guards_per_transition[t];
    return NULL;
}

extern "C" const int** get_all_guards() 
{
    return (const int**)&guards_per_transition;
}

int guard[][18] = 
{
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}
}
;

extern "C" const int* get_guard_matrix(int g) 
{
    if (g>=0 && g < 60) return guard[g];
    return NULL;
}

int guardmaybecoenabled[60][60] = 
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_guard_may_be_coenabled_matrix(int g) 
{
    if (g>=0 && g < 60) return guardmaybecoenabled[g];
    return NULL;
}

int guard_nes[60][147] = 
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
}
;

extern "C" const int* get_guard_nes_matrix(int g) 
{
    if (g>=0 && g < 60) return guard_nes[g];
    return NULL;
}

int guard_nds[60][147] = 
{
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_guard_nds_matrix(int g) 
{
    if (g>=0 && g < 60) return guard_nds[g];
    return NULL;
}

int dna[147][147] = 
{
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_dna_matrix(int t) 
{
    if (t >= 0 && t < 147) return dna[t];
    return NULL;
}

