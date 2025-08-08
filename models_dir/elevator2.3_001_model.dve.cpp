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
    byte_t req[13];
    sshort_int_t t;
    sshort_int_t p;
    byte_t v;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) cabin;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) environment;
    struct
    {
        ushort_int_t state;
        byte_t ldir;
    }
    __attribute__((__packed__)) controller;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

state_struct_t initial_state = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

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
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).cabin.state.var = 1;
        cpy[((int*)&(*out).cabin.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l1: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).cabin.state.var = 2;
        cpy[((int*)&(*out).cabin.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l2: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).cabin.state.var = 1;
        cpy[((int*)&(*out).cabin.state.var - (int*)&(*out))] = 0;
        ((*out).p.var = (*out).p.var - 1);
        cpy[((int*)&((*out).p.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l3: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).cabin.state.var = 1;
        cpy[((int*)&(*out).cabin.state.var - (int*)&(*out))] = 0;
        ((*out).p.var = (*out).p.var + 1);
        cpy[((int*)&((*out).p.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l4: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).cabin.state.var = 0;
        cpy[((int*)&(*out).cabin.state.var - (int*)&(*out))] = 0;
        ((*out).req[(*out).p.var].var = 0);
        cpy[((int*)&((*out).req[(*out).p.var].var) - (int*)&(*out))] = 0;
        ((*out).v.var = 0);
        cpy[((int*)&((*out).v.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // may-write:    1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l5: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[0].var = 1);
        cpy[((int*)&((*out).req[0].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l6: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[1].var = 1);
        cpy[((int*)&((*out).req[1].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l7: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[2].var = 1);
        cpy[((int*)&((*out).req[2].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l8: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[3].var = 1);
        cpy[((int*)&((*out).req[3].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l9: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[4].var = 1);
        cpy[((int*)&((*out).req[4].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l10: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[5].var = 1);
        cpy[((int*)&((*out).req[5].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l11: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[6].var = 1);
        cpy[((int*)&((*out).req[6].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l12: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[7].var = 1);
        cpy[((int*)&((*out).req[7].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l13: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[8].var = 1);
        cpy[((int*)&((*out).req[8].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l14: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[9].var = 1);
        cpy[((int*)&((*out).req[9].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l15: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[10].var = 1);
        cpy[((int*)&((*out).req[10].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l16: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[11].var = 1);
        cpy[((int*)&((*out).req[11].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l17: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).environment.state.var = 0;
        cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
        ((*out).req[12].var = 1);
        cpy[((int*)&((*out).req[12].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l18: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).controller.state.var = 1;
        cpy[((int*)&(*out).controller.state.var - (int*)&(*out))] = 0;
        ((*out).t.var = (*out).t.var + (2 * (*out).controller.ldir.var) - 1);
        cpy[((int*)&((*out).t.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l19: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).controller.state.var = 0;
        cpy[((int*)&(*out).controller.state.var - (int*)&(*out))] = 0;
        ((*out).controller.ldir.var = 1 - (*out).controller.ldir.var);
        cpy[((int*)&((*out).controller.ldir.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l20: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).controller.state.var = 2;
        cpy[((int*)&(*out).controller.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l21: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).controller.state.var = 1;
        cpy[((int*)&(*out).controller.state.var - (int*)&(*out))] = 0;
        ((*out).t.var = (*out).t.var + (2 * (*out).controller.ldir.var) - 1);
        cpy[((int*)&((*out).t.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l22: {
        *out = *in;
        int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).controller.state.var = 0;
        cpy[((int*)&(*out).controller.state.var - (int*)&(*out))] = 0;
        ((*out).v.var = 1);
        cpy[((int*)&((*out).v.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0
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
        default: printf ("Wrong group! Using greybox/long call + -l (DiVinE LTL semantics)? This combo is not implemented."); exit (-1);
    }
    return 0;
}

extern "C" int get_successor( void* model, int t, const state_struct_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    int states_emitted = 0;
    goto switch_state;
    l0: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).cabin.state.var == 0) )  &&  ( ((*in).v.var > 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l1: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).cabin.state.var == 1) )  &&  ( ((*in).t.var == (*in).p.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l2: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        if (  ( ((*in).cabin.state.var == 1) )  &&  ( ((*in).t.var < (*in).p.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l3: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        if (  ( ((*in).cabin.state.var == 1) )  &&  ( ((*in).t.var > (*in).p.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l4: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
        if (  ( ((*in).cabin.state.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l5: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[0].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l6: {
        
        // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[1].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l7: {
        
        // read:         0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[2].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l8: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[3].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l9: {
        
        // read:         0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[4].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l10: {
        
        // read:         0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[5].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l11: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[6].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l12: {
        
        // read:         0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[7].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l13: {
        
        // read:         0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[8].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l14: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[9].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l15: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[10].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l16: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[11].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l17: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).environment.state.var == 0) )  &&  ( ((*in).req[12].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l18: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
        if (  ( ((*in).controller.state.var == 0) )  &&  ( ((*in).v.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l19: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        if (  ( ((*in).controller.state.var == 1) )  &&  ( ((*in).t.var < 0 || (*in).t.var == 13) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l20: {
        
        // read:         1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).controller.state.var == 1) )  &&  ( ((*in).t.var >= 0 && (*in).t.var < 13 && (*in).req[(*in).t.var].var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l21: {
        
        // read:         1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
        if (  ( ((*in).controller.state.var == 1) )  &&  ( ((*in).t.var >= 0 && (*in).t.var < 13 && (*in).req[(*in).t.var].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l22: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).controller.state.var == 2) ) )
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
    int cpy[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    if ( false )
    {
        ;
    }
    else
    {
        if (  ( ((*in).cabin.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).v.var > 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).cabin.state.var = 1;
                cpy[((int*)&(*out).cabin.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 0;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).cabin.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).t.var == (*in).p.var) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).cabin.state.var = 2;
                cpy[((int*)&(*out).cabin.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 1;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            if (  ( ((*in).t.var < (*in).p.var) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).cabin.state.var = 1;
                cpy[((int*)&(*out).cabin.state.var - (int*)&(*out))] = 0;
                ((*out).p.var = (*out).p.var - 1);
                cpy[((int*)&((*out).p.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 2;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            if (  ( ((*in).t.var > (*in).p.var) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).cabin.state.var = 1;
                cpy[((int*)&(*out).cabin.state.var - (int*)&(*out))] = 0;
                ((*out).p.var = (*out).p.var + 1);
                cpy[((int*)&((*out).p.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 3;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).cabin.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).cabin.state.var = 0;
                cpy[((int*)&(*out).cabin.state.var - (int*)&(*out))] = 0;
                ((*out).req[(*out).p.var].var = 0);
                cpy[((int*)&((*out).req[(*out).p.var].var) - (int*)&(*out))] = 0;
                ((*out).v.var = 0);
                cpy[((int*)&((*out).v.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // may-write:    1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 4;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).environment.state.var == 0) ) )
        {
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[0].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[0].var = 1);
                cpy[((int*)&((*out).req[0].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 5;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[1].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[1].var = 1);
                cpy[((int*)&((*out).req[1].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 6;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[2].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[2].var = 1);
                cpy[((int*)&((*out).req[2].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 7;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[3].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[3].var = 1);
                cpy[((int*)&((*out).req[3].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 8;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[4].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[4].var = 1);
                cpy[((int*)&((*out).req[4].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 9;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[5].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[5].var = 1);
                cpy[((int*)&((*out).req[5].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 10;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[6].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[6].var = 1);
                cpy[((int*)&((*out).req[6].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 11;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[7].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[7].var = 1);
                cpy[((int*)&((*out).req[7].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 12;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[8].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[8].var = 1);
                cpy[((int*)&((*out).req[8].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 13;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[9].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[9].var = 1);
                cpy[((int*)&((*out).req[9].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 14;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[10].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[10].var = 1);
                cpy[((int*)&((*out).req[10].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 15;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[11].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[11].var = 1);
                cpy[((int*)&((*out).req[11].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 16;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).req[12].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).environment.state.var = 0;
                cpy[((int*)&(*out).environment.state.var - (int*)&(*out))] = 0;
                ((*out).req[12].var = 1);
                cpy[((int*)&((*out).req[12].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 17;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).controller.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
            if (  ( ((*in).v.var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).controller.state.var = 1;
                cpy[((int*)&(*out).controller.state.var - (int*)&(*out))] = 0;
                ((*out).t.var = (*out).t.var + (2 * (*out).controller.ldir.var) - 1);
                cpy[((int*)&((*out).t.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 18;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).controller.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
            if (  ( ((*in).t.var < 0 || (*in).t.var == 13) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).controller.state.var = 0;
                cpy[((int*)&(*out).controller.state.var - (int*)&(*out))] = 0;
                ((*out).controller.ldir.var = 1 - (*out).controller.ldir.var);
                cpy[((int*)&((*out).controller.ldir.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                system_in_deadlock = false;
                transition_info.group = 19;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).t.var >= 0 && (*in).t.var < 13 && (*in).req[(*in).t.var].var == 1) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).controller.state.var = 2;
                cpy[((int*)&(*out).controller.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 20;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
            if (  ( ((*in).t.var >= 0 && (*in).t.var < 13 && (*in).req[(*in).t.var].var == 0) ) )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).controller.state.var = 1;
                cpy[((int*)&(*out).controller.state.var - (int*)&(*out))] = 0;
                ((*out).t.var = (*out).t.var + (2 * (*out).controller.ldir.var) - 1);
                cpy[((int*)&((*out).t.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 21;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).controller.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).controller.state.var = 0;
                cpy[((int*)&(*out).controller.state.var - (int*)&(*out))] = 0;
                ((*out).v.var = 1);
                cpy[((int*)&((*out).v.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 22;
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
    return 20;
}

extern "C" const char* get_state_variable_name(int var)
{
    switch (var)
    {
        case 0:
            return "req[0]";
        case 1:
            return "req[1]";
        case 2:
            return "req[2]";
        case 3:
            return "req[3]";
        case 4:
            return "req[4]";
        case 5:
            return "req[5]";
        case 6:
            return "req[6]";
        case 7:
            return "req[7]";
        case 8:
            return "req[8]";
        case 9:
            return "req[9]";
        case 10:
            return "req[10]";
        case 11:
            return "req[11]";
        case 12:
            return "req[12]";
        case 13:
            return "t";
        case 14:
            return "p";
        case 15:
            return "v";
        case 16:
            return "cabin";
        case 17:
            return "environment";
        case 18:
            return "controller";
        case 19:
            return "controller.ldir";
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
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 0;
        default:
            return -1;
    }
}

extern "C" int get_state_variable_type_count() 
{
    return 5;
}

extern "C" const char* get_state_variable_type_name(int type) 
{
    switch (type)
    {
        case 0:
            return "byte";
        case 2:
            return "cabin";
        case 4:
            return "controller";
        case 3:
            return "environment";
        case 1:
            return "int";
        default:
            return NULL;
    }
}

extern "C" int get_state_variable_type_value_count(int type)
{
    switch (type)
    {
        case 0: // byte
            return 0;
        case 2: // cabin
            return 3;
        case 4: // controller
            return 3;
        case 3: // environment
            return 1;
        case 1: // int
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
                    return "idle";
                case 1:
                    return "mov";
                case 2:
                    return "open";
            }
        }
        case 4:
        {
            switch (value)
            {
                case 0:
                    return "wait";
                case 1:
                    return "work";
                case 2:
                    return "done";
            }
        }
        case 3:
        {
            switch (value)
            {
                case 0:
                    return "read";
            }
        }
    }
    return NULL;
}

int transition_dependency[][3][20] = 
{
    // { ... read ...}, { ... may-write ...}, { ... must-write ...}
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1}},
    {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}},
    {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0}}
}
;

int actions_read[][20] = 
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
}
;

extern "C" int get_transition_count() 
{
    return 23;
}

extern "C" const int* get_transition_read_dependencies(int t) 
{
    if (t>=0 && t < 23) return transition_dependency[t][0];
    return NULL;
}

extern "C" const int* get_transition_actions_read_dependencies(int t) 
{
    if (t>=0 && t < 23) return actions_read[t];
    return NULL;
}

extern "C" const int* get_transition_may_write_dependencies(int t) 
{
    if (t>=0 && t < 23) return transition_dependency[t][1];
    return NULL;
}

extern "C" const int* get_transition_write_dependencies(int t) 
{
    return get_transition_may_write_dependencies(t);
}

extern "C" const int* get_transition_must_write_dependencies(int t) 
{
    if (t>=0 && t < 23) return transition_dependency[t][2];
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
            case 0: return (((*src).cabin.state.var == 0));
            case 1: return (((*src).v.var > 0));
            case 2: return (((*src).cabin.state.var == 1));
            case 3: return (((*src).t.var == (*src).p.var));
            case 4: return (((*src).t.var < (*src).p.var));
            case 5: return (((*src).t.var > (*src).p.var));
            case 6: return (((*src).cabin.state.var == 2));
            case 7: return (((*src).environment.state.var == 0));
            case 8: return (((*src).req[wrapped_index(0, 13, &jbuf)].var == 0));
            case 9: return (((*src).req[wrapped_index(1, 13, &jbuf)].var == 0));
            case 10: return (((*src).req[wrapped_index(2, 13, &jbuf)].var == 0));
            case 11: return (((*src).req[wrapped_index(3, 13, &jbuf)].var == 0));
            case 12: return (((*src).req[wrapped_index(4, 13, &jbuf)].var == 0));
            case 13: return (((*src).req[wrapped_index(5, 13, &jbuf)].var == 0));
            case 14: return (((*src).req[wrapped_index(6, 13, &jbuf)].var == 0));
            case 15: return (((*src).req[wrapped_index(7, 13, &jbuf)].var == 0));
            case 16: return (((*src).req[wrapped_index(8, 13, &jbuf)].var == 0));
            case 17: return (((*src).req[wrapped_index(9, 13, &jbuf)].var == 0));
            case 18: return (((*src).req[wrapped_index(10, 13, &jbuf)].var == 0));
            case 19: return (((*src).req[wrapped_index(11, 13, &jbuf)].var == 0));
            case 20: return (((*src).req[wrapped_index(12, 13, &jbuf)].var == 0));
            case 21: return (((*src).controller.state.var == 0));
            case 22: return (((*src).v.var == 0));
            case 23: return (((*src).controller.state.var == 1));
            case 24: return (((*src).t.var < 0 || (*src).t.var == 13));
            case 25: return (((*src).t.var >= 0));
            case 26: return (((*src).t.var < 13));
            case 27: return (((*src).req[wrapped_index((*src).t.var, 13, &jbuf)].var == 1));
            case 28: return (((*src).req[wrapped_index((*src).t.var, 13, &jbuf)].var == 0));
            case 29: return (((*src).controller.state.var == 2));
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
}

extern "C" const int get_guard_count() 
{
    return 30;
}

#pragma clang diagnostic push
int* guards_per_transition[23] = 
{
    ((int[]){2, 0, 1}), // 0
    ((int[]){2, 2, 3}), // 1
    ((int[]){2, 2, 4}), // 2
    ((int[]){2, 2, 5}), // 3
    ((int[]){1, 6}), // 4
    ((int[]){2, 7, 8}), // 5
    ((int[]){2, 7, 9}), // 6
    ((int[]){2, 7, 10}), // 7
    ((int[]){2, 7, 11}), // 8
    ((int[]){2, 7, 12}), // 9
    ((int[]){2, 7, 13}), // 10
    ((int[]){2, 7, 14}), // 11
    ((int[]){2, 7, 15}), // 12
    ((int[]){2, 7, 16}), // 13
    ((int[]){2, 7, 17}), // 14
    ((int[]){2, 7, 18}), // 15
    ((int[]){2, 7, 19}), // 16
    ((int[]){2, 7, 20}), // 17
    ((int[]){2, 21, 22}), // 18
    ((int[]){2, 23, 24}), // 19
    ((int[]){4, 23, 25, 26, 27}), // 20
    ((int[]){4, 23, 25, 26, 28}), // 21
    ((int[]){1, 29}), // 22
}
;
#pragma clang diagnostic pop

extern "C" const int* get_guards(int t) 
{
    if (t>=0 && t < 23) return guards_per_transition[t];
    return NULL;
}

extern "C" const int** get_all_guards() 
{
    return (const int**)&guards_per_transition;
}

int guard[][20] = 
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}
}
;

extern "C" const int* get_guard_matrix(int g) 
{
    if (g>=0 && g < 30) return guard[g];
    return NULL;
}

int guardmaybecoenabled[30][30] = 
{
    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_may_be_coenabled_matrix(int g) 
{
    if (g>=0 && g < 30) return guardmaybecoenabled[g];
    return NULL;
}

int guard_nes[30][23] = 
{
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}
}
;

extern "C" const int* get_guard_nes_matrix(int g) 
{
    if (g>=0 && g < 30) return guard_nes[g];
    return NULL;
}

int guard_nds[30][23] = 
{
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_guard_nds_matrix(int g) 
{
    if (g>=0 && g < 30) return guard_nds[g];
    return NULL;
}

int dna[23][23] = 
{
    {1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_dna_matrix(int t) 
{
    if (t >= 0 && t < 23) return dna[t];
    return NULL;
}

