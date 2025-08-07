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
    byte_t request[2];
    byte_t starvers[2];
    byte_t resources[2];
    sshort_int_t res0[2];
    sshort_int_t res1[2];
    sshort_int_t acquiring[2];
    sshort_int_t entryRound;
    byte_t phase;
    byte_t fire;
    struct
    {
        ushort_int_t state;
        sshort_int_t i;
    }
    __attribute__((__packed__)) round_about;
    struct
    {
        ushort_int_t state;
        sshort_int_t i;
    }
    __attribute__((__packed__)) phil_0;
    struct
    {
        ushort_int_t state;
        sshort_int_t i;
    }
    __attribute__((__packed__)) phil_1;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

state_struct_t initial_state = { 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 };

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
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 0;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).res0[(*out).round_about.i.var].var = -1);
        cpy[((int*)&((*out).res0[(*out).round_about.i.var].var) - (int*)&(*out))] = 0;
        ((*out).res1[(*out).round_about.i.var].var = -1);
        cpy[((int*)&((*out).res1[(*out).round_about.i.var].var) - (int*)&(*out))] = 0;
        ((*out).acquiring[(*out).round_about.i.var].var = -1);
        cpy[((int*)&((*out).acquiring[(*out).round_about.i.var].var) - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = (*out).round_about.i.var + 1);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l1: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 1;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = 0);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        ((*out).phase.var = 0);
        cpy[((int*)&((*out).phase.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l2: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 1;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).resources[(*out).round_about.i.var].var = 0);
        cpy[((int*)&((*out).resources[(*out).round_about.i.var].var) - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = (*out).round_about.i.var + 1);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l3: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 2;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = 0);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l4: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 2;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).resources[(*out).res0[(*out).round_about.i.var].var * 2].var = (*out).entryRound.var);
        cpy[((int*)&((*out).resources[(*out).res0[(*out).round_about.i.var].var * 2].var) - (int*)&(*out))] = 0;
        ((*out).resources[(*out).res0[(*out).round_about.i.var].var * 2 + 1].var = (*out).round_about.i.var);
        cpy[((int*)&((*out).resources[(*out).res0[(*out).round_about.i.var].var * 2 + 1].var) - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = (*out).round_about.i.var + 1);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l5: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 2;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = (*out).round_about.i.var + 1);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l6: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 3;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = 0);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l7: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 3;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).resources[(*out).res1[(*out).round_about.i.var].var * 2].var = (*out).entryRound.var);
        cpy[((int*)&((*out).resources[(*out).res1[(*out).round_about.i.var].var * 2].var) - (int*)&(*out))] = 0;
        ((*out).resources[(*out).res1[(*out).round_about.i.var].var * 2 + 1].var = (*out).round_about.i.var);
        cpy[((int*)&((*out).resources[(*out).res1[(*out).round_about.i.var].var * 2 + 1].var) - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = (*out).round_about.i.var + 1);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l8: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 3;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = (*out).round_about.i.var + 1);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l9: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 5;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = 0);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        ((*out).phase.var = 1);
        cpy[((int*)&((*out).phase.var) - (int*)&(*out))] = 0;
        ((*out).fire.var = 0);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l10: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 6;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).fire.var = 0);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        ((*out).phase.var = 2);
        cpy[((int*)&((*out).phase.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l11: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 6;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).request[1 * (*out).resources[2 * (*out).round_about.i.var + 1].var + (*out).round_about.i.var].var = 0);
        cpy[((int*)&((*out).request[1 * (*out).resources[2 * (*out).round_about.i.var + 1].var + (*out).round_about.i.var].var) - (int*)&(*out))] = 0;
        ((*out).starvers[1 * (*out).resources[2 * (*out).round_about.i.var + 1].var + (*out).round_about.i.var].var = 0);
        cpy[((int*)&((*out).starvers[1 * (*out).resources[2 * (*out).round_about.i.var + 1].var + (*out).round_about.i.var].var) - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = (*out).round_about.i.var + 1);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l12: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 6;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = (*out).round_about.i.var + 1);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l13: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 7;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = 0);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l14: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 7;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = (*out).round_about.i.var + 1);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l15: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).round_about.state.var = 1;
        cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
        ((*out).phase.var = 0);
        cpy[((int*)&((*out).phase.var) - (int*)&(*out))] = 0;
        ((*out).round_about.i.var = 0);
        cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l16: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_0.state.var = 1;
        cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
        ((*out).resources[(*out).res0[0].var].var = 0);
        cpy[((int*)&((*out).resources[(*out).res0[0].var].var) - (int*)&(*out))] = 0;
        ((*out).resources[(*out).res0[0].var + 1].var = 0);
        cpy[((int*)&((*out).resources[(*out).res0[0].var + 1].var) - (int*)&(*out))] = 0;
        ((*out).res0[0].var = (*out).res1[0].var);
        cpy[((int*)&((*out).res0[0].var) - (int*)&(*out))] = 0;
        ((*out).res1[0].var = -1);
        cpy[((int*)&((*out).res1[0].var) - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,1,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l17: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_0.state.var = 1;
        cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
        ((*out).acquiring[0].var = 0);
        cpy[((int*)&((*out).acquiring[0].var) - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        ((*out).request[0 * 1 + 0].var = (*out).entryRound.var);
        cpy[((int*)&((*out).request[0 * 1 + 0].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l18: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_0.state.var = 1;
        cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l19: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_0.state.var = 0;
        cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l20: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_0.state.var = 2;
        cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l21: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_0.state.var = 0;
        cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l22: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_0.state.var = 2;
        cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
        ((*out).phil_0.i.var = (*out).phil_0.i.var + 1);
        cpy[((int*)&((*out).phil_0.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l23: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_0.state.var = 0;
        cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        ((*out).phil_0.i.var = (*out).phil_0.i.var + 1);
        cpy[((int*)&((*out).phil_0.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l24: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_0.state.var = 0;
        cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
        ((*out).res0[0].var = (*out).acquiring[0].var);
        cpy[((int*)&((*out).res0[0].var) - (int*)&(*out))] = 0;
        ((*out).acquiring[0].var = -1);
        cpy[((int*)&((*out).acquiring[0].var) - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        ((*out).phil_0.i.var = 0);
        cpy[((int*)&((*out).phil_0.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l25: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_0.state.var = 0;
        cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
        ((*out).res1[0].var = (*out).acquiring[0].var);
        cpy[((int*)&((*out).res1[0].var) - (int*)&(*out))] = 0;
        ((*out).acquiring[0].var = -1);
        cpy[((int*)&((*out).acquiring[0].var) - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        ((*out).phil_0.i.var = 0);
        cpy[((int*)&((*out).phil_0.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0
        // must-write:   0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l26: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_1.state.var = 1;
        cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
        ((*out).resources[(*out).res0[1].var].var = 0);
        cpy[((int*)&((*out).resources[(*out).res0[1].var].var) - (int*)&(*out))] = 0;
        ((*out).resources[(*out).res0[1].var + 1].var = 0);
        cpy[((int*)&((*out).resources[(*out).res0[1].var + 1].var) - (int*)&(*out))] = 0;
        ((*out).res0[1].var = (*out).res1[1].var);
        cpy[((int*)&((*out).res0[1].var) - (int*)&(*out))] = 0;
        ((*out).res1[1].var = -1);
        cpy[((int*)&((*out).res1[1].var) - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l27: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_1.state.var = 1;
        cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
        ((*out).acquiring[1].var = 0);
        cpy[((int*)&((*out).acquiring[1].var) - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        ((*out).request[1 * 1 + 0].var = (*out).entryRound.var);
        cpy[((int*)&((*out).request[1 * 1 + 0].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l28: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_1.state.var = 1;
        cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l29: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_1.state.var = 0;
        cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l30: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_1.state.var = 2;
        cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l31: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_1.state.var = 0;
        cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l32: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_1.state.var = 2;
        cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
        ((*out).phil_1.i.var = (*out).phil_1.i.var + 1);
        cpy[((int*)&((*out).phil_1.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l33: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_1.state.var = 0;
        cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        ((*out).phil_1.i.var = (*out).phil_1.i.var + 1);
        cpy[((int*)&((*out).phil_1.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
        // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1
        // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l34: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_1.state.var = 0;
        cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
        ((*out).res0[1].var = (*out).acquiring[1].var);
        cpy[((int*)&((*out).res0[1].var) - (int*)&(*out))] = 0;
        ((*out).acquiring[1].var = -1);
        cpy[((int*)&((*out).acquiring[1].var) - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        ((*out).phil_1.i.var = 0);
        cpy[((int*)&((*out).phil_1.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l35: {
        *out = *in;
        int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).phil_1.state.var = 0;
        cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
        ((*out).res1[1].var = (*out).acquiring[1].var);
        cpy[((int*)&((*out).res1[1].var) - (int*)&(*out))] = 0;
        ((*out).acquiring[1].var = -1);
        cpy[((int*)&((*out).acquiring[1].var) - (int*)&(*out))] = 0;
        ((*out).fire.var = (*out).fire.var + 1);
        cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
        ((*out).phil_1.i.var = 0);
        cpy[((int*)&((*out).phil_1.i.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,1
        // must-write:   0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,1
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
        default: printf ("Wrong group! Using greybox/long call + -l (DiVinE LTL semantics)? This combo is not implemented."); exit (-1);
    }
    return 0;
}

extern "C" int get_successor( void* model, int t, const state_struct_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    int states_emitted = 0;
    goto switch_state;
    l0: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).round_about.state.var == 0) )  &&  ( ((*in).round_about.i.var < 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l1: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).round_about.state.var == 0) )  &&  ( ((*in).round_about.i.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l2: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).round_about.state.var == 1) )  &&  ( ((*in).round_about.i.var < 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l3: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).round_about.state.var == 1) )  &&  ( ((*in).round_about.i.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l4: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0
        if (  ( ((*in).round_about.state.var == 2) )  &&  ( ((*in).round_about.i.var < 2 && (*in).res0[(*in).round_about.i.var].var != -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l5: {
        
        // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).round_about.state.var == 2) )  &&  ( ((*in).round_about.i.var < 2 && (*in).res0[(*in).round_about.i.var].var == -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l6: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).round_about.state.var == 2) )  &&  ( ((*in).round_about.i.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l7: {
        
        // read:         0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0
        if (  ( ((*in).round_about.state.var == 3) )  &&  ( ((*in).round_about.i.var < 2 && (*in).res1[(*in).round_about.i.var].var != -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l8: {
        
        // read:         0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).round_about.state.var == 3) )  &&  ( ((*in).round_about.i.var < 2 && (*in).res1[(*in).round_about.i.var].var == -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l9: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).round_about.state.var == 3) )  &&  ( ((*in).round_about.i.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l10: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).round_about.state.var == 5) )  &&  ( ((*in).fire.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l11: {
        
        // read:         0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).round_about.state.var == 6) )  &&  ( ((*in).round_about.i.var < 1 && (*in).resources[2 * (*in).round_about.i.var].var != 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l12: {
        
        // read:         0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).round_about.state.var == 6) )  &&  ( ((*in).round_about.i.var < 1 && (*in).resources[2 * (*in).round_about.i.var].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l13: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).round_about.state.var == 6) )  &&  ( ((*in).round_about.i.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l14: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).round_about.state.var == 7) )  &&  ( ((*in).round_about.i.var < 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l15: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).round_about.state.var == 7) )  &&  ( ((*in).round_about.i.var == 2 && (*in).fire.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l16: {
        
        // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_0.state.var == 0) )  &&  ( ((*in).phase.var == 1 && (*in).res0[0].var != -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l17: {
        
        // read:         0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_0.state.var == 0) )  &&  ( ((*in).phase.var == 1 && (*in).res1[0].var == -1 && (*in).acquiring[0].var == -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l18: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_0.state.var == 0) )  &&  ( ((*in).phase.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l19: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_0.state.var == 1) )  &&  ( ((*in).phase.var == 2 && (*in).acquiring[0].var == -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l20: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).phil_0.state.var == 1) )  &&  ( ((*in).phase.var == 2 && (*in).acquiring[0].var != -1 && (*in).fire.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l21: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_0.state.var == 1) )  &&  ( ((*in).phase.var == 2 && (*in).acquiring[0].var != -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l22: {
        
        // read:         0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
        if (  ( ((*in).phil_0.state.var == 2) )  &&  ( ((*in).phil_0.i.var < 2 && (*in).res0[(*in).phil_0.i.var].var != (*in).acquiring[0].var && (*in).res1[(*in).phil_0.i.var].var != (*in).acquiring[0].var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l23: {
        
        // read:         0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0
        if (  ( ((*in).phil_0.state.var == 2) )  &&  ( ((*in).phil_0.i.var < 2 && ((*in).res0[(*in).phil_0.i.var].var == (*in).acquiring[0].var || (*in).res1[(*in).phil_0.i.var].var == (*in).acquiring[0].var)) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l24: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_0.state.var == 2) )  &&  ( ((*in).phil_0.i.var == 2 && (*in).res0[0].var == -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l25: {
        
        // read:         0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_0.state.var == 2) )  &&  ( ((*in).phil_0.i.var == 2 && (*in).res0[0].var != -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l26: {
        
        // read:         0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_1.state.var == 0) )  &&  ( ((*in).phase.var == 1 && (*in).res0[1].var != -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l27: {
        
        // read:         0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_1.state.var == 0) )  &&  ( ((*in).phase.var == 1 && (*in).res1[1].var == -1 && (*in).acquiring[1].var == -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l28: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_1.state.var == 0) )  &&  ( ((*in).phase.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l29: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_1.state.var == 1) )  &&  ( ((*in).phase.var == 2 && (*in).acquiring[1].var == -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l30: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).phil_1.state.var == 1) )  &&  ( ((*in).phase.var == 2 && (*in).acquiring[1].var != -1 && (*in).fire.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l31: {
        
        // read:         0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_1.state.var == 1) )  &&  ( ((*in).phase.var == 2 && (*in).acquiring[1].var != -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l32: {
        
        // read:         0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
        if (  ( ((*in).phil_1.state.var == 2) )  &&  ( ((*in).phil_1.i.var < 2 && (*in).res0[(*in).phil_1.i.var].var != (*in).acquiring[1].var && (*in).res1[(*in).phil_1.i.var].var != (*in).acquiring[1].var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l33: {
        
        // read:         0,0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,0,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
        if (  ( ((*in).phil_1.state.var == 2) )  &&  ( ((*in).phil_1.i.var < 2 && ((*in).res0[(*in).phil_1.i.var].var == (*in).acquiring[1].var || (*in).res1[(*in).phil_1.i.var].var == (*in).acquiring[1].var)) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l34: {
        
        // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_1.state.var == 2) )  &&  ( ((*in).phil_1.i.var == 2 && (*in).res0[1].var == -1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l35: {
        
        // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0
        if (  ( ((*in).phil_1.state.var == 2) )  &&  ( ((*in).phil_1.i.var == 2 && (*in).res0[1].var != -1) ) )
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
    int cpy[21] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    if ( false )
    {
        ;
    }
    else
    {
        if (  ( ((*in).round_about.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).round_about.i.var < 2) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 0;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).res0[(*out).round_about.i.var].var = -1);
                cpy[((int*)&((*out).res0[(*out).round_about.i.var].var) - (int*)&(*out))] = 0;
                ((*out).res1[(*out).round_about.i.var].var = -1);
                cpy[((int*)&((*out).res1[(*out).round_about.i.var].var) - (int*)&(*out))] = 0;
                ((*out).acquiring[(*out).round_about.i.var].var = -1);
                cpy[((int*)&((*out).acquiring[(*out).round_about.i.var].var) - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = (*out).round_about.i.var + 1);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 0;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).round_about.i.var == 2) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 1;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = 0);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                ((*out).phase.var = 0);
                cpy[((int*)&((*out).phase.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 1;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).round_about.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).round_about.i.var < 2) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 1;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).resources[(*out).round_about.i.var].var = 0);
                cpy[((int*)&((*out).resources[(*out).round_about.i.var].var) - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = (*out).round_about.i.var + 1);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 2;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).round_about.i.var == 2) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 2;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = 0);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 3;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).round_about.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0
            if (  ( ((*in).round_about.i.var < 2 && (*in).res0[(*in).round_about.i.var].var != -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 2;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).resources[(*out).res0[(*out).round_about.i.var].var * 2].var = (*out).entryRound.var);
                cpy[((int*)&((*out).resources[(*out).res0[(*out).round_about.i.var].var * 2].var) - (int*)&(*out))] = 0;
                ((*out).resources[(*out).res0[(*out).round_about.i.var].var * 2 + 1].var = (*out).round_about.i.var);
                cpy[((int*)&((*out).resources[(*out).res0[(*out).round_about.i.var].var * 2 + 1].var) - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = (*out).round_about.i.var + 1);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 4;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).round_about.i.var < 2 && (*in).res0[(*in).round_about.i.var].var == -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 2;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = (*out).round_about.i.var + 1);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 5;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).round_about.i.var == 2) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 3;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = 0);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 6;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).round_about.state.var == 3) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0
            if (  ( ((*in).round_about.i.var < 2 && (*in).res1[(*in).round_about.i.var].var != -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 3;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).resources[(*out).res1[(*out).round_about.i.var].var * 2].var = (*out).entryRound.var);
                cpy[((int*)&((*out).resources[(*out).res1[(*out).round_about.i.var].var * 2].var) - (int*)&(*out))] = 0;
                ((*out).resources[(*out).res1[(*out).round_about.i.var].var * 2 + 1].var = (*out).round_about.i.var);
                cpy[((int*)&((*out).resources[(*out).res1[(*out).round_about.i.var].var * 2 + 1].var) - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = (*out).round_about.i.var + 1);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 7;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).round_about.i.var < 2 && (*in).res1[(*in).round_about.i.var].var == -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 3;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = (*out).round_about.i.var + 1);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 8;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).round_about.i.var == 2) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 5;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = 0);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                ((*out).phase.var = 1);
                cpy[((int*)&((*out).phase.var) - (int*)&(*out))] = 0;
                ((*out).fire.var = 0);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 9;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).round_about.state.var == 5) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).fire.var == 2) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 6;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).fire.var = 0);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                ((*out).phase.var = 2);
                cpy[((int*)&((*out).phase.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 10;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).round_about.state.var == 6) ) )
        {
            
            // read:         0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).round_about.i.var < 1 && (*in).resources[2 * (*in).round_about.i.var].var != 0) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 6;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).request[1 * (*out).resources[2 * (*out).round_about.i.var + 1].var + (*out).round_about.i.var].var = 0);
                cpy[((int*)&((*out).request[1 * (*out).resources[2 * (*out).round_about.i.var + 1].var + (*out).round_about.i.var].var) - (int*)&(*out))] = 0;
                ((*out).starvers[1 * (*out).resources[2 * (*out).round_about.i.var + 1].var + (*out).round_about.i.var].var = 0);
                cpy[((int*)&((*out).starvers[1 * (*out).resources[2 * (*out).round_about.i.var + 1].var + (*out).round_about.i.var].var) - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = (*out).round_about.i.var + 1);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 11;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).round_about.i.var < 1 && (*in).resources[2 * (*in).round_about.i.var].var == 0) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 6;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = (*out).round_about.i.var + 1);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 12;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).round_about.i.var == 1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 7;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = 0);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 13;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).round_about.state.var == 7) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).round_about.i.var < 2) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 7;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = (*out).round_about.i.var + 1);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 14;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).round_about.i.var == 2 && (*in).fire.var == 2) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).round_about.state.var = 1;
                cpy[((int*)&(*out).round_about.state.var - (int*)&(*out))] = 0;
                ((*out).phase.var = 0);
                cpy[((int*)&((*out).phase.var) - (int*)&(*out))] = 0;
                ((*out).round_about.i.var = 0);
                cpy[((int*)&((*out).round_about.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 15;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).phil_0.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 1 && (*in).res0[0].var != -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_0.state.var = 1;
                cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
                ((*out).resources[(*out).res0[0].var].var = 0);
                cpy[((int*)&((*out).resources[(*out).res0[0].var].var) - (int*)&(*out))] = 0;
                ((*out).resources[(*out).res0[0].var + 1].var = 0);
                cpy[((int*)&((*out).resources[(*out).res0[0].var + 1].var) - (int*)&(*out))] = 0;
                ((*out).res0[0].var = (*out).res1[0].var);
                cpy[((int*)&((*out).res0[0].var) - (int*)&(*out))] = 0;
                ((*out).res1[0].var = -1);
                cpy[((int*)&((*out).res1[0].var) - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,1,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 16;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 1 && (*in).res1[0].var == -1 && (*in).acquiring[0].var == -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_0.state.var = 1;
                cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
                ((*out).acquiring[0].var = 0);
                cpy[((int*)&((*out).acquiring[0].var) - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                ((*out).request[0 * 1 + 0].var = (*out).entryRound.var);
                cpy[((int*)&((*out).request[0 * 1 + 0].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 17;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_0.state.var = 1;
                cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 18;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).phil_0.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 2 && (*in).acquiring[0].var == -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_0.state.var = 0;
                cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 19;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 2 && (*in).acquiring[0].var != -1 && (*in).fire.var == 0) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_0.state.var = 2;
                cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 20;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 2 && (*in).acquiring[0].var != -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_0.state.var = 0;
                cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 21;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).phil_0.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
            if (  ( ((*in).phil_0.i.var < 2 && (*in).res0[(*in).phil_0.i.var].var != (*in).acquiring[0].var && (*in).res1[(*in).phil_0.i.var].var != (*in).acquiring[0].var) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_0.state.var = 2;
                cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
                ((*out).phil_0.i.var = (*out).phil_0.i.var + 1);
                cpy[((int*)&((*out).phil_0.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0
                system_in_deadlock = false;
                transition_info.group = 22;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0
            if (  ( ((*in).phil_0.i.var < 2 && ((*in).res0[(*in).phil_0.i.var].var == (*in).acquiring[0].var || (*in).res1[(*in).phil_0.i.var].var == (*in).acquiring[0].var)) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_0.state.var = 0;
                cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                ((*out).phil_0.i.var = (*out).phil_0.i.var + 1);
                cpy[((int*)&((*out).phil_0.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0
                system_in_deadlock = false;
                transition_info.group = 23;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phil_0.i.var == 2 && (*in).res0[0].var == -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_0.state.var = 0;
                cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
                ((*out).res0[0].var = (*out).acquiring[0].var);
                cpy[((int*)&((*out).res0[0].var) - (int*)&(*out))] = 0;
                ((*out).acquiring[0].var = -1);
                cpy[((int*)&((*out).acquiring[0].var) - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                ((*out).phil_0.i.var = 0);
                cpy[((int*)&((*out).phil_0.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0
                system_in_deadlock = false;
                transition_info.group = 24;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phil_0.i.var == 2 && (*in).res0[0].var != -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_0.state.var = 0;
                cpy[((int*)&(*out).phil_0.state.var - (int*)&(*out))] = 0;
                ((*out).res1[0].var = (*out).acquiring[0].var);
                cpy[((int*)&((*out).res1[0].var) - (int*)&(*out))] = 0;
                ((*out).acquiring[0].var = -1);
                cpy[((int*)&((*out).acquiring[0].var) - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                ((*out).phil_0.i.var = 0);
                cpy[((int*)&((*out).phil_0.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0
                // must-write:   0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0
                system_in_deadlock = false;
                transition_info.group = 25;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).phil_1.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 1 && (*in).res0[1].var != -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_1.state.var = 1;
                cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
                ((*out).resources[(*out).res0[1].var].var = 0);
                cpy[((int*)&((*out).resources[(*out).res0[1].var].var) - (int*)&(*out))] = 0;
                ((*out).resources[(*out).res0[1].var + 1].var = 0);
                cpy[((int*)&((*out).resources[(*out).res0[1].var + 1].var) - (int*)&(*out))] = 0;
                ((*out).res0[1].var = (*out).res1[1].var);
                cpy[((int*)&((*out).res0[1].var) - (int*)&(*out))] = 0;
                ((*out).res1[1].var = -1);
                cpy[((int*)&((*out).res1[1].var) - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 26;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 1 && (*in).res1[1].var == -1 && (*in).acquiring[1].var == -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_1.state.var = 1;
                cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
                ((*out).acquiring[1].var = 0);
                cpy[((int*)&((*out).acquiring[1].var) - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                ((*out).request[1 * 1 + 0].var = (*out).entryRound.var);
                cpy[((int*)&((*out).request[1 * 1 + 0].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 27;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_1.state.var = 1;
                cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 28;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).phil_1.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 2 && (*in).acquiring[1].var == -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_1.state.var = 0;
                cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 29;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 2 && (*in).acquiring[1].var != -1 && (*in).fire.var == 1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_1.state.var = 2;
                cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 30;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phase.var == 2 && (*in).acquiring[1].var != -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_1.state.var = 0;
                cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 31;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).phil_1.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
            if (  ( ((*in).phil_1.i.var < 2 && (*in).res0[(*in).phil_1.i.var].var != (*in).acquiring[1].var && (*in).res1[(*in).phil_1.i.var].var != (*in).acquiring[1].var) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_1.state.var = 2;
                cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
                ((*out).phil_1.i.var = (*out).phil_1.i.var + 1);
                cpy[((int*)&((*out).phil_1.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1
                system_in_deadlock = false;
                transition_info.group = 32;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,0,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
            if (  ( ((*in).phil_1.i.var < 2 && ((*in).res0[(*in).phil_1.i.var].var == (*in).acquiring[1].var || (*in).res1[(*in).phil_1.i.var].var == (*in).acquiring[1].var)) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_1.state.var = 0;
                cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                ((*out).phil_1.i.var = (*out).phil_1.i.var + 1);
                cpy[((int*)&((*out).phil_1.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1
                // may-write:    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1
                // must-write:   0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1
                system_in_deadlock = false;
                transition_info.group = 33;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phil_1.i.var == 2 && (*in).res0[1].var == -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_1.state.var = 0;
                cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
                ((*out).res0[1].var = (*out).acquiring[1].var);
                cpy[((int*)&((*out).res0[1].var) - (int*)&(*out))] = 0;
                ((*out).acquiring[1].var = -1);
                cpy[((int*)&((*out).acquiring[1].var) - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                ((*out).phil_1.i.var = 0);
                cpy[((int*)&((*out).phil_1.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1
                system_in_deadlock = false;
                transition_info.group = 34;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0
            if (  ( ((*in).phil_1.i.var == 2 && (*in).res0[1].var != -1) ) )
            {
                *out = *in;
                int cpy[21] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).phil_1.state.var = 0;
                cpy[((int*)&(*out).phil_1.state.var - (int*)&(*out))] = 0;
                ((*out).res1[1].var = (*out).acquiring[1].var);
                cpy[((int*)&((*out).res1[1].var) - (int*)&(*out))] = 0;
                ((*out).acquiring[1].var = -1);
                cpy[((int*)&((*out).acquiring[1].var) - (int*)&(*out))] = 0;
                ((*out).fire.var = (*out).fire.var + 1);
                cpy[((int*)&((*out).fire.var) - (int*)&(*out))] = 0;
                ((*out).phil_1.i.var = 0);
                cpy[((int*)&((*out).phil_1.i.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,1
                // must-write:   0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,1
                system_in_deadlock = false;
                transition_info.group = 35;
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
    return 21;
}

extern "C" const char* get_state_variable_name(int var)
{
    switch (var)
    {
        case 0:
            return "request[0]";
        case 1:
            return "request[1]";
        case 2:
            return "starvers[0]";
        case 3:
            return "starvers[1]";
        case 4:
            return "resources[0]";
        case 5:
            return "resources[1]";
        case 6:
            return "res0[0]";
        case 7:
            return "res0[1]";
        case 8:
            return "res1[0]";
        case 9:
            return "res1[1]";
        case 10:
            return "acquiring[0]";
        case 11:
            return "acquiring[1]";
        case 12:
            return "entryRound";
        case 13:
            return "phase";
        case 14:
            return "fire";
        case 15:
            return "round_about";
        case 16:
            return "round_about.i";
        case 17:
            return "phil_0";
        case 18:
            return "phil_0.i";
        case 19:
            return "phil_1";
        case 20:
            return "phil_1.i";
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
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 2;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 1;
        case 19:
            return 4;
        case 20:
            return 1;
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
        case 1:
            return "int";
        case 3:
            return "phil_0";
        case 4:
            return "phil_1";
        case 2:
            return "round_about";
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
        case 1: // int
            return 0;
        case 3: // phil_0
            return 3;
        case 4: // phil_1
            return 3;
        case 2: // round_about
            return 9;
        default:
            return -1;
    }
}

extern "C" const char* get_state_variable_type_value(int type, int value) 
{
    switch (type)
    {
        case 3:
        {
            switch (value)
            {
                case 0:
                    return "action";
                case 1:
                    return "end";
                case 2:
                    return "mutex";
            }
        }
        case 4:
        {
            switch (value)
            {
                case 0:
                    return "action";
                case 1:
                    return "end";
                case 2:
                    return "mutex";
            }
        }
        case 2:
        {
            switch (value)
            {
                case 0:
                    return "reset";
                case 1:
                    return "begin0";
                case 2:
                    return "begin1";
                case 3:
                    return "begin2";
                case 4:
                    return "begin3";
                case 5:
                    return "action";
                case 6:
                    return "end0";
                case 7:
                    return "end1";
                case 8:
                    return "end2";
            }
        }
    }
    return NULL;
}

int transition_dependency[][3][21] = 
{
    // { ... read ...}, { ... may-write ...}, { ... must-write ...}
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0}},
    {{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0}},
    {{0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,0},{0,0,0,0,1,1,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0,0,1,0,0,0},{1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0}},
    {{0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0},{0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0},{0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0}},
    {{0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0},{0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0}},
    {{0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,1,0},{0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,0,0,1,0},{1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1}},
    {{0,0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1}},
    {{0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1},{0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1},{0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1}},
    {{0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,1},{0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,1}}
}
;

int actions_read[][21] = 
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0}
}
;

extern "C" int get_transition_count() 
{
    return 36;
}

extern "C" const int* get_transition_read_dependencies(int t) 
{
    if (t>=0 && t < 36) return transition_dependency[t][0];
    return NULL;
}

extern "C" const int* get_transition_actions_read_dependencies(int t) 
{
    if (t>=0 && t < 36) return actions_read[t];
    return NULL;
}

extern "C" const int* get_transition_may_write_dependencies(int t) 
{
    if (t>=0 && t < 36) return transition_dependency[t][1];
    return NULL;
}

extern "C" const int* get_transition_write_dependencies(int t) 
{
    return get_transition_may_write_dependencies(t);
}

extern "C" const int* get_transition_must_write_dependencies(int t) 
{
    if (t>=0 && t < 36) return transition_dependency[t][2];
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
            case 0: return (((*src).round_about.state.var == 0));
            case 1: return (((*src).round_about.i.var < 2));
            case 2: return (((*src).round_about.i.var == 2));
            case 3: return (((*src).round_about.state.var == 1));
            case 4: return (((*src).round_about.state.var == 2));
            case 5: return (((*src).res0[wrapped_index((*src).round_about.i.var, 2, &jbuf)].var != -1));
            case 6: return (((*src).res0[wrapped_index((*src).round_about.i.var, 2, &jbuf)].var == -1));
            case 7: return (((*src).round_about.state.var == 3));
            case 8: return (((*src).res1[wrapped_index((*src).round_about.i.var, 2, &jbuf)].var != -1));
            case 9: return (((*src).res1[wrapped_index((*src).round_about.i.var, 2, &jbuf)].var == -1));
            case 10: return (((*src).round_about.state.var == 5));
            case 11: return (((*src).fire.var == 2));
            case 12: return (((*src).round_about.state.var == 6));
            case 13: return (((*src).round_about.i.var < 1));
            case 14: return (((*src).resources[wrapped_index(2 * (*src).round_about.i.var, 2, &jbuf)].var != 0));
            case 15: return (((*src).resources[wrapped_index(2 * (*src).round_about.i.var, 2, &jbuf)].var == 0));
            case 16: return (((*src).round_about.i.var == 1));
            case 17: return (((*src).round_about.state.var == 7));
            case 18: return (((*src).phil_0.state.var == 0));
            case 19: return (((*src).phase.var == 1));
            case 20: return (((*src).res0[wrapped_index(0, 2, &jbuf)].var != -1));
            case 21: return (((*src).res1[wrapped_index(0, 2, &jbuf)].var == -1));
            case 22: return (((*src).acquiring[wrapped_index(0, 2, &jbuf)].var == -1));
            case 23: return (((*src).phil_0.state.var == 1));
            case 24: return (((*src).phase.var == 2));
            case 25: return (((*src).acquiring[wrapped_index(0, 2, &jbuf)].var != -1));
            case 26: return (((*src).fire.var == 0));
            case 27: return (((*src).phil_0.state.var == 2));
            case 28: return (((*src).phil_0.i.var < 2));
            case 29: return (((*src).res0[wrapped_index((*src).phil_0.i.var, 2, &jbuf)].var != (*src).acquiring[wrapped_index(0, 2, &jbuf)].var));
            case 30: return (((*src).res1[wrapped_index((*src).phil_0.i.var, 2, &jbuf)].var != (*src).acquiring[wrapped_index(0, 2, &jbuf)].var));
            case 31: return ((((*src).res0[wrapped_index((*src).phil_0.i.var, 2, &jbuf)].var == (*src).acquiring[wrapped_index(0, 2, &jbuf)].var || (*src).res1[wrapped_index((*src).phil_0.i.var, 2, &jbuf)].var == (*src).acquiring[wrapped_index(0, 2, &jbuf)].var)));
            case 32: return (((*src).phil_0.i.var == 2));
            case 33: return (((*src).res0[wrapped_index(0, 2, &jbuf)].var == -1));
            case 34: return (((*src).phil_1.state.var == 0));
            case 35: return (((*src).res0[wrapped_index(1, 2, &jbuf)].var != -1));
            case 36: return (((*src).res1[wrapped_index(1, 2, &jbuf)].var == -1));
            case 37: return (((*src).acquiring[wrapped_index(1, 2, &jbuf)].var == -1));
            case 38: return (((*src).phil_1.state.var == 1));
            case 39: return (((*src).acquiring[wrapped_index(1, 2, &jbuf)].var != -1));
            case 40: return (((*src).fire.var == 1));
            case 41: return (((*src).phil_1.state.var == 2));
            case 42: return (((*src).phil_1.i.var < 2));
            case 43: return (((*src).res0[wrapped_index((*src).phil_1.i.var, 2, &jbuf)].var != (*src).acquiring[wrapped_index(1, 2, &jbuf)].var));
            case 44: return (((*src).res1[wrapped_index((*src).phil_1.i.var, 2, &jbuf)].var != (*src).acquiring[wrapped_index(1, 2, &jbuf)].var));
            case 45: return ((((*src).res0[wrapped_index((*src).phil_1.i.var, 2, &jbuf)].var == (*src).acquiring[wrapped_index(1, 2, &jbuf)].var || (*src).res1[wrapped_index((*src).phil_1.i.var, 2, &jbuf)].var == (*src).acquiring[wrapped_index(1, 2, &jbuf)].var)));
            case 46: return (((*src).phil_1.i.var == 2));
            case 47: return (((*src).res0[wrapped_index(1, 2, &jbuf)].var == -1));
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
}

extern "C" const int get_guard_count() 
{
    return 48;
}

#pragma clang diagnostic push
int* guards_per_transition[36] = 
{
    ((int[]){2, 0, 1}), // 0
    ((int[]){2, 0, 2}), // 1
    ((int[]){2, 3, 1}), // 2
    ((int[]){2, 3, 2}), // 3
    ((int[]){3, 4, 1, 5}), // 4
    ((int[]){3, 4, 1, 6}), // 5
    ((int[]){2, 4, 2}), // 6
    ((int[]){3, 7, 1, 8}), // 7
    ((int[]){3, 7, 1, 9}), // 8
    ((int[]){2, 7, 2}), // 9
    ((int[]){2, 10, 11}), // 10
    ((int[]){3, 12, 13, 14}), // 11
    ((int[]){3, 12, 13, 15}), // 12
    ((int[]){2, 12, 16}), // 13
    ((int[]){2, 17, 1}), // 14
    ((int[]){3, 17, 2, 11}), // 15
    ((int[]){3, 18, 19, 20}), // 16
    ((int[]){4, 18, 19, 21, 22}), // 17
    ((int[]){2, 18, 19}), // 18
    ((int[]){3, 23, 24, 22}), // 19
    ((int[]){4, 23, 24, 25, 26}), // 20
    ((int[]){3, 23, 24, 25}), // 21
    ((int[]){4, 27, 28, 29, 30}), // 22
    ((int[]){3, 27, 28, 31}), // 23
    ((int[]){3, 27, 32, 33}), // 24
    ((int[]){3, 27, 32, 20}), // 25
    ((int[]){3, 34, 19, 35}), // 26
    ((int[]){4, 34, 19, 36, 37}), // 27
    ((int[]){2, 34, 19}), // 28
    ((int[]){3, 38, 24, 37}), // 29
    ((int[]){4, 38, 24, 39, 40}), // 30
    ((int[]){3, 38, 24, 39}), // 31
    ((int[]){4, 41, 42, 43, 44}), // 32
    ((int[]){3, 41, 42, 45}), // 33
    ((int[]){3, 41, 46, 47}), // 34
    ((int[]){3, 41, 46, 35}), // 35
}
;
#pragma clang diagnostic pop

extern "C" const int* get_guards(int t) 
{
    if (t>=0 && t < 36) return guards_per_transition[t];
    return NULL;
}

extern "C" const int** get_all_guards() 
{
    return (const int**)&guards_per_transition;
}

int guard[][21] = 
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0}
}
;

extern "C" const int* get_guard_matrix(int g) 
{
    if (g>=0 && g < 48) return guard[g];
    return NULL;
}

int guardmaybecoenabled[48][48] = 
{
    {1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_may_be_coenabled_matrix(int g) 
{
    if (g>=0 && g < 48) return guardmaybecoenabled[g];
    return NULL;
}

int guard_nes[48][36] = 
{
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_nes_matrix(int g) 
{
    if (g>=0 && g < 48) return guard_nes[g];
    return NULL;
}

int guard_nds[48][36] = 
{
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_nds_matrix(int g) 
{
    if (g>=0 && g < 48) return guard_nds[g];
    return NULL;
}

int dna[36][36] = 
{
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1}
}
;

extern "C" const int* get_dna_matrix(int t) 
{
    if (t >= 0 && t < 36) return dna[t];
    return NULL;
}

