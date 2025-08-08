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
    byte_t id;
    byte_t t[4];
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) Timer;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) P_0;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) P_1;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) P_2;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) P_3;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

state_struct_t initial_state = { 0,255,255,255,255,0,0,0,0,0 };

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
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).Timer.state.var = 0;
        cpy[((int*)&(*out).Timer.state.var - (int*)&(*out))] = 0;
        ((*out).t[0].var = ((*out).t[0].var - 1) | (((*out).t[0].var == 255) * 255));
        cpy[((int*)&((*out).t[0].var) - (int*)&(*out))] = 0;
        ((*out).t[1].var = ((*out).t[1].var - 1) | (((*out).t[1].var == 255) * 255));
        cpy[((int*)&((*out).t[1].var) - (int*)&(*out))] = 0;
        ((*out).t[2].var = ((*out).t[2].var - 1) | (((*out).t[2].var == 255) * 255));
        cpy[((int*)&((*out).t[2].var) - (int*)&(*out))] = 0;
        ((*out).t[3].var = ((*out).t[3].var - 1) | (((*out).t[3].var == 255) * 255));
        cpy[((int*)&((*out).t[3].var) - (int*)&(*out))] = 0;
        // actions_read: 0,1,1,1,1,0,0,0,0,0
        // may-write:    0,1,1,1,1,1,0,0,0,0
        // must-write:   0,1,1,1,1,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l1: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 1;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).t[0].var = 3);
        cpy[((int*)&((*out).t[0].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,1,0,0,0,0,1,0,0,0
        // must-write:   0,1,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l2: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 2;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).t[0].var = 3);
        cpy[((int*)&((*out).t[0].var) - (int*)&(*out))] = 0;
        ((*out).id.var = 0 + 1);
        cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,1,0,0,0
        // must-write:   1,1,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l3: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 2;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).t[0].var = 255);
        cpy[((int*)&((*out).t[0].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,1,0,0,0,0,1,0,0,0
        // must-write:   0,1,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l4: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 3;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l5: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 0;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l6: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_0.state.var = 0;
        cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
        ((*out).id.var = 0);
        cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,1,0,0,0
        // must-write:   1,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l7: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 1;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).t[1].var = 3);
        cpy[((int*)&((*out).t[1].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,0,0,0,0,1,0,0
        // must-write:   0,0,1,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l8: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 2;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).t[1].var = 3);
        cpy[((int*)&((*out).t[1].var) - (int*)&(*out))] = 0;
        ((*out).id.var = 1 + 1);
        cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,1,0,0,0,0,1,0,0
        // must-write:   1,0,1,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l9: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 2;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).t[1].var = 255);
        cpy[((int*)&((*out).t[1].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,0,0,0,0,1,0,0
        // must-write:   0,0,1,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l10: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 3;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l11: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 0;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l12: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_1.state.var = 0;
        cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
        ((*out).id.var = 0);
        cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,1,0,0
        // must-write:   1,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l13: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 1;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).t[2].var = 3);
        cpy[((int*)&((*out).t[2].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,1,0
        // must-write:   0,0,0,1,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l14: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 2;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).t[2].var = 3);
        cpy[((int*)&((*out).t[2].var) - (int*)&(*out))] = 0;
        ((*out).id.var = 2 + 1);
        cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,1,0,0,0,0,1,0
        // must-write:   1,0,0,1,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l15: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 2;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).t[2].var = 255);
        cpy[((int*)&((*out).t[2].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,1,0
        // must-write:   0,0,0,1,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l16: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 3;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l17: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 0;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,1,0
        // must-write:   0,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l18: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_2.state.var = 0;
        cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
        ((*out).id.var = 0);
        cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,1,0
        // must-write:   1,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l19: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_3.state.var = 1;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        ((*out).t[3].var = 3);
        cpy[((int*)&((*out).t[3].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,0,0,0,1
        // must-write:   0,0,0,0,1,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l20: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_3.state.var = 2;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        ((*out).t[3].var = 3);
        cpy[((int*)&((*out).t[3].var) - (int*)&(*out))] = 0;
        ((*out).id.var = 3 + 1);
        cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,1,0,0,0,0,1
        // must-write:   1,0,0,0,1,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l21: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_3.state.var = 2;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        ((*out).t[3].var = 255);
        cpy[((int*)&((*out).t[3].var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,0,0,0,1
        // must-write:   0,0,0,0,1,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l22: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_3.state.var = 3;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1
        // must-write:   0,0,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l23: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_3.state.var = 0;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,0,0,1
        // must-write:   0,0,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l24: {
        *out = *in;
        int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
        (*out).P_3.state.var = 0;
        cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
        ((*out).id.var = 0);
        cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,1
        // must-write:   1,0,0,0,0,0,0,0,0,1
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
        default: printf ("Wrong group! Using greybox/long call + -l (DiVinE LTL semantics)? This combo is not implemented."); exit (-1);
    }
    return 0;
}

extern "C" int get_successor( void* model, int t, const state_struct_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    int states_emitted = 0;
    goto switch_state;
    l0: {
        
        // read:         0,1,1,1,1,1,0,0,0,0
        // actions_read: 0,1,1,1,1,0,0,0,0,0
        if (  ( ((*in).Timer.state.var == 0) )  &&  ( ((*in).t[0].var != 0 && (*in).t[1].var != 0 && (*in).t[2].var != 0 && (*in).t[3].var != 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l1: {
        
        // read:         1,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 0) )  &&  ( ((*in).id.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l2: {
        
        // read:         0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l3: {
        
        // read:         0,1,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).t[0].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l4: {
        
        // read:         1,1,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).t[0].var == 255 && (*in).id.var == 0 + 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l5: {
        
        // read:         1,1,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 2) )  &&  ( ((*in).id.var != 0 + 1 && (*in).t[0].var == 255) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l6: {
        
        // read:         0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_0.state.var == 3) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l7: {
        
        // read:         1,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 0) )  &&  ( ((*in).id.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l8: {
        
        // read:         0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l9: {
        
        // read:         0,0,1,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).t[1].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l10: {
        
        // read:         1,0,1,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).t[1].var == 255 && (*in).id.var == 1 + 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l11: {
        
        // read:         1,0,1,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 2) )  &&  ( ((*in).id.var != 1 + 1 && (*in).t[1].var == 255) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l12: {
        
        // read:         0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_1.state.var == 3) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l13: {
        
        // read:         1,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 0) )  &&  ( ((*in).id.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l14: {
        
        // read:         0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l15: {
        
        // read:         0,0,0,1,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).t[2].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l16: {
        
        // read:         1,0,0,1,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).t[2].var == 255 && (*in).id.var == 2 + 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l17: {
        
        // read:         1,0,0,1,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 2) )  &&  ( ((*in).id.var != 2 + 1 && (*in).t[2].var == 255) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l18: {
        
        // read:         0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_2.state.var == 3) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l19: {
        
        // read:         1,0,0,0,0,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_3.state.var == 0) )  &&  ( ((*in).id.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l20: {
        
        // read:         0,0,0,0,0,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_3.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l21: {
        
        // read:         0,0,0,0,1,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).t[3].var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l22: {
        
        // read:         1,0,0,0,1,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).t[3].var == 255 && (*in).id.var == 3 + 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l23: {
        
        // read:         1,0,0,0,1,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_3.state.var == 2) )  &&  ( ((*in).id.var != 3 + 1 && (*in).t[3].var == 255) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l24: {
        
        // read:         0,0,0,0,0,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).P_3.state.var == 3) ) )
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
    int cpy[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    if ( false )
    {
        ;
    }
    else
    {
        if (  ( ((*in).Timer.state.var == 0) ) )
        {
            
            // read:         0,1,1,1,1,1,0,0,0,0
            // actions_read: 0,1,1,1,1,0,0,0,0,0
            if (  ( ((*in).t[0].var != 0 && (*in).t[1].var != 0 && (*in).t[2].var != 0 && (*in).t[3].var != 0) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).Timer.state.var = 0;
                cpy[((int*)&(*out).Timer.state.var - (int*)&(*out))] = 0;
                ((*out).t[0].var = ((*out).t[0].var - 1) | (((*out).t[0].var == 255) * 255));
                cpy[((int*)&((*out).t[0].var) - (int*)&(*out))] = 0;
                ((*out).t[1].var = ((*out).t[1].var - 1) | (((*out).t[1].var == 255) * 255));
                cpy[((int*)&((*out).t[1].var) - (int*)&(*out))] = 0;
                ((*out).t[2].var = ((*out).t[2].var - 1) | (((*out).t[2].var == 255) * 255));
                cpy[((int*)&((*out).t[2].var) - (int*)&(*out))] = 0;
                ((*out).t[3].var = ((*out).t[3].var - 1) | (((*out).t[3].var == 255) * 255));
                cpy[((int*)&((*out).t[3].var) - (int*)&(*out))] = 0;
                // actions_read: 0,1,1,1,1,0,0,0,0,0
                // may-write:    0,1,1,1,1,1,0,0,0,0
                // must-write:   0,1,1,1,1,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 0;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 0) ) )
        {
            
            // read:         1,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).id.var == 0) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 1;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).t[0].var = 3);
                cpy[((int*)&((*out).t[0].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,1,0,0,0,0,1,0,0,0
                // must-write:   0,1,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 1;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 2;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).t[0].var = 3);
                cpy[((int*)&((*out).t[0].var) - (int*)&(*out))] = 0;
                ((*out).id.var = 0 + 1);
                cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,1,0,0,0
                // must-write:   1,1,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 2;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 2) ) )
        {
            
            // read:         0,1,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).t[0].var == 0) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 2;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).t[0].var = 255);
                cpy[((int*)&((*out).t[0].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,1,0,0,0,0,1,0,0,0
                // must-write:   0,1,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 3;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).t[0].var == 255 && (*in).id.var == 0 + 1) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 3;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 4;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).id.var != 0 + 1 && (*in).t[0].var == 255) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 0;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 5;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_0.state.var == 3) ) )
        {
            
            // read:         0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_0.state.var = 0;
                cpy[((int*)&(*out).P_0.state.var - (int*)&(*out))] = 0;
                ((*out).id.var = 0);
                cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,1,0,0,0
                // must-write:   1,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 6;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 0) ) )
        {
            
            // read:         1,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).id.var == 0) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 1;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).t[1].var = 3);
                cpy[((int*)&((*out).t[1].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,0,0,0,0,1,0,0
                // must-write:   0,0,1,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 7;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 2;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).t[1].var = 3);
                cpy[((int*)&((*out).t[1].var) - (int*)&(*out))] = 0;
                ((*out).id.var = 1 + 1);
                cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,1,0,0,0,0,1,0,0
                // must-write:   1,0,1,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 8;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 2) ) )
        {
            
            // read:         0,0,1,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).t[1].var == 0) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 2;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).t[1].var = 255);
                cpy[((int*)&((*out).t[1].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,0,0,0,0,1,0,0
                // must-write:   0,0,1,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 9;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,1,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).t[1].var == 255 && (*in).id.var == 1 + 1) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 3;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 10;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,1,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).id.var != 1 + 1 && (*in).t[1].var == 255) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 0;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 11;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_1.state.var == 3) ) )
        {
            
            // read:         0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_1.state.var = 0;
                cpy[((int*)&(*out).P_1.state.var - (int*)&(*out))] = 0;
                ((*out).id.var = 0);
                cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,1,0,0
                // must-write:   1,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 12;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 0) ) )
        {
            
            // read:         1,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).id.var == 0) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 1;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).t[2].var = 3);
                cpy[((int*)&((*out).t[2].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,1,0
                // must-write:   0,0,0,1,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 13;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 2;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).t[2].var = 3);
                cpy[((int*)&((*out).t[2].var) - (int*)&(*out))] = 0;
                ((*out).id.var = 2 + 1);
                cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,1,0,0,0,0,1,0
                // must-write:   1,0,0,1,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 14;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 2) ) )
        {
            
            // read:         0,0,0,1,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).t[2].var == 0) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 2;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).t[2].var = 255);
                cpy[((int*)&((*out).t[2].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,1,0
                // must-write:   0,0,0,1,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 15;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,1,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).t[2].var == 255 && (*in).id.var == 2 + 1) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 3;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 16;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,1,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).id.var != 2 + 1 && (*in).t[2].var == 255) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 0;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,1,0
                // must-write:   0,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 17;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_2.state.var == 3) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_2.state.var = 0;
                cpy[((int*)&(*out).P_2.state.var - (int*)&(*out))] = 0;
                ((*out).id.var = 0);
                cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,1,0
                // must-write:   1,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 18;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_3.state.var == 0) ) )
        {
            
            // read:         1,0,0,0,0,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).id.var == 0) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_3.state.var = 1;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                ((*out).t[3].var = 3);
                cpy[((int*)&((*out).t[3].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,0,0,0,1
                // must-write:   0,0,0,0,1,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 19;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_3.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_3.state.var = 2;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                ((*out).t[3].var = 3);
                cpy[((int*)&((*out).t[3].var) - (int*)&(*out))] = 0;
                ((*out).id.var = 3 + 1);
                cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,1,0,0,0,0,1
                // must-write:   1,0,0,0,1,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 20;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_3.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,1,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).t[3].var == 0) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_3.state.var = 2;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                ((*out).t[3].var = 255);
                cpy[((int*)&((*out).t[3].var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,0,0,0,1
                // must-write:   0,0,0,0,1,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 21;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,1,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).t[3].var == 255 && (*in).id.var == 3 + 1) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_3.state.var = 3;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1
                // must-write:   0,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 22;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,0,0,0,1,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).id.var != 3 + 1 && (*in).t[3].var == 255) ) )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_3.state.var = 0;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,0,0,1
                // must-write:   0,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 23;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).P_3.state.var == 3) ) )
        {
            
            // read:         0,0,0,0,0,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[10] = { 1,1,1,1,1,1,1,1,1,1,};
                (*out).P_3.state.var = 0;
                cpy[((int*)&(*out).P_3.state.var - (int*)&(*out))] = 0;
                ((*out).id.var = 0);
                cpy[((int*)&((*out).id.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,1
                // must-write:   1,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 24;
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
    return 10;
}

extern "C" const char* get_state_variable_name(int var)
{
    switch (var)
    {
        case 0:
            return "id";
        case 1:
            return "t[0]";
        case 2:
            return "t[1]";
        case 3:
            return "t[2]";
        case 4:
            return "t[3]";
        case 5:
            return "Timer";
        case 6:
            return "P_0";
        case 7:
            return "P_1";
        case 8:
            return "P_2";
        case 9:
            return "P_3";
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
            return 1;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 5;
        default:
            return -1;
    }
}

extern "C" int get_state_variable_type_count() 
{
    return 6;
}

extern "C" const char* get_state_variable_type_name(int type) 
{
    switch (type)
    {
        case 2:
            return "P_0";
        case 3:
            return "P_1";
        case 4:
            return "P_2";
        case 5:
            return "P_3";
        case 1:
            return "Timer";
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
        case 2: // P_0
            return 4;
        case 3: // P_1
            return 4;
        case 4: // P_2
            return 4;
        case 5: // P_3
            return 4;
        case 1: // Timer
            return 1;
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
                    return "NCS";
                case 1:
                    return "try";
                case 2:
                    return "wait";
                case 3:
                    return "CS";
            }
        }
        case 3:
        {
            switch (value)
            {
                case 0:
                    return "NCS";
                case 1:
                    return "try";
                case 2:
                    return "wait";
                case 3:
                    return "CS";
            }
        }
        case 4:
        {
            switch (value)
            {
                case 0:
                    return "NCS";
                case 1:
                    return "try";
                case 2:
                    return "wait";
                case 3:
                    return "CS";
            }
        }
        case 5:
        {
            switch (value)
            {
                case 0:
                    return "NCS";
                case 1:
                    return "try";
                case 2:
                    return "wait";
                case 3:
                    return "CS";
            }
        }
        case 1:
        {
            switch (value)
            {
                case 0:
                    return "q";
            }
        }
    }
    return NULL;
}

int transition_dependency[][3][10] = 
{
    // { ... read ...}, { ... may-write ...}, { ... must-write ...}
    {{0,1,1,1,1,1,0,0,0,0},{0,1,1,1,1,1,0,0,0,0},{0,1,1,1,1,1,0,0,0,0}},
    {{1,0,0,0,0,0,1,0,0,0},{0,1,0,0,0,0,1,0,0,0},{0,1,0,0,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0},{1,1,0,0,0,0,1,0,0,0},{1,1,0,0,0,0,1,0,0,0}},
    {{0,1,0,0,0,0,1,0,0,0},{0,1,0,0,0,0,1,0,0,0},{0,1,0,0,0,0,1,0,0,0}},
    {{1,1,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0}},
    {{1,1,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,1,0,0,0},{1,0,0,0,0,0,1,0,0,0},{1,0,0,0,0,0,1,0,0,0}},
    {{1,0,0,0,0,0,0,1,0,0},{0,0,1,0,0,0,0,1,0,0},{0,0,1,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,1,0,0},{1,0,1,0,0,0,0,1,0,0},{1,0,1,0,0,0,0,1,0,0}},
    {{0,0,1,0,0,0,0,1,0,0},{0,0,1,0,0,0,0,1,0,0},{0,0,1,0,0,0,0,1,0,0}},
    {{1,0,1,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0}},
    {{1,0,1,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,0,0,0,0,1,0,0},{1,0,0,0,0,0,0,1,0,0},{1,0,0,0,0,0,0,1,0,0}},
    {{1,0,0,0,0,0,0,0,1,0},{0,0,0,1,0,0,0,0,1,0},{0,0,0,1,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,0,0,1,0},{1,0,0,1,0,0,0,0,1,0},{1,0,0,1,0,0,0,0,1,0}},
    {{0,0,0,1,0,0,0,0,1,0},{0,0,0,1,0,0,0,0,1,0},{0,0,0,1,0,0,0,0,1,0}},
    {{1,0,0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1,0}},
    {{1,0,0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1,0}},
    {{0,0,0,0,0,0,0,0,1,0},{1,0,0,0,0,0,0,0,1,0},{1,0,0,0,0,0,0,0,1,0}},
    {{1,0,0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,0,0,1},{0,0,0,0,1,0,0,0,0,1}},
    {{0,0,0,0,0,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1}},
    {{0,0,0,0,1,0,0,0,0,1},{0,0,0,0,1,0,0,0,0,1},{0,0,0,0,1,0,0,0,0,1}},
    {{1,0,0,0,1,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,1}},
    {{1,0,0,0,1,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,1}},
    {{0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1}}
}
;

int actions_read[][10] = 
{
    {0,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
}
;

extern "C" int get_transition_count() 
{
    return 25;
}

extern "C" const int* get_transition_read_dependencies(int t) 
{
    if (t>=0 && t < 25) return transition_dependency[t][0];
    return NULL;
}

extern "C" const int* get_transition_actions_read_dependencies(int t) 
{
    if (t>=0 && t < 25) return actions_read[t];
    return NULL;
}

extern "C" const int* get_transition_may_write_dependencies(int t) 
{
    if (t>=0 && t < 25) return transition_dependency[t][1];
    return NULL;
}

extern "C" const int* get_transition_write_dependencies(int t) 
{
    return get_transition_may_write_dependencies(t);
}

extern "C" const int* get_transition_must_write_dependencies(int t) 
{
    if (t>=0 && t < 25) return transition_dependency[t][2];
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
            case 0: return (((*src).Timer.state.var == 0));
            case 1: return (((*src).t[wrapped_index(0, 4, &jbuf)].var != 0));
            case 2: return (((*src).t[wrapped_index(1, 4, &jbuf)].var != 0));
            case 3: return (((*src).t[wrapped_index(2, 4, &jbuf)].var != 0));
            case 4: return (((*src).t[wrapped_index(3, 4, &jbuf)].var != 0));
            case 5: return (((*src).P_0.state.var == 0));
            case 6: return (((*src).id.var == 0));
            case 7: return (((*src).P_0.state.var == 1));
            case 8: return (((*src).P_0.state.var == 2));
            case 9: return (((*src).t[wrapped_index(0, 4, &jbuf)].var == 0));
            case 10: return (((*src).t[wrapped_index(0, 4, &jbuf)].var == 255));
            case 11: return (((*src).id.var == 0 + 1));
            case 12: return (((*src).id.var != 0 + 1));
            case 13: return (((*src).P_0.state.var == 3));
            case 14: return (((*src).P_1.state.var == 0));
            case 15: return (((*src).P_1.state.var == 1));
            case 16: return (((*src).P_1.state.var == 2));
            case 17: return (((*src).t[wrapped_index(1, 4, &jbuf)].var == 0));
            case 18: return (((*src).t[wrapped_index(1, 4, &jbuf)].var == 255));
            case 19: return (((*src).id.var == 1 + 1));
            case 20: return (((*src).id.var != 1 + 1));
            case 21: return (((*src).P_1.state.var == 3));
            case 22: return (((*src).P_2.state.var == 0));
            case 23: return (((*src).P_2.state.var == 1));
            case 24: return (((*src).P_2.state.var == 2));
            case 25: return (((*src).t[wrapped_index(2, 4, &jbuf)].var == 0));
            case 26: return (((*src).t[wrapped_index(2, 4, &jbuf)].var == 255));
            case 27: return (((*src).id.var == 2 + 1));
            case 28: return (((*src).id.var != 2 + 1));
            case 29: return (((*src).P_2.state.var == 3));
            case 30: return (((*src).P_3.state.var == 0));
            case 31: return (((*src).P_3.state.var == 1));
            case 32: return (((*src).P_3.state.var == 2));
            case 33: return (((*src).t[wrapped_index(3, 4, &jbuf)].var == 0));
            case 34: return (((*src).t[wrapped_index(3, 4, &jbuf)].var == 255));
            case 35: return (((*src).id.var == 3 + 1));
            case 36: return (((*src).id.var != 3 + 1));
            case 37: return (((*src).P_3.state.var == 3));
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
}

extern "C" const int get_guard_count() 
{
    return 38;
}

#pragma clang diagnostic push
int* guards_per_transition[25] = 
{
    ((int[]){5, 0, 1, 2, 3, 4}), // 0
    ((int[]){2, 5, 6}), // 1
    ((int[]){1, 7}), // 2
    ((int[]){2, 8, 9}), // 3
    ((int[]){3, 8, 10, 11}), // 4
    ((int[]){3, 8, 12, 10}), // 5
    ((int[]){1, 13}), // 6
    ((int[]){2, 14, 6}), // 7
    ((int[]){1, 15}), // 8
    ((int[]){2, 16, 17}), // 9
    ((int[]){3, 16, 18, 19}), // 10
    ((int[]){3, 16, 20, 18}), // 11
    ((int[]){1, 21}), // 12
    ((int[]){2, 22, 6}), // 13
    ((int[]){1, 23}), // 14
    ((int[]){2, 24, 25}), // 15
    ((int[]){3, 24, 26, 27}), // 16
    ((int[]){3, 24, 28, 26}), // 17
    ((int[]){1, 29}), // 18
    ((int[]){2, 30, 6}), // 19
    ((int[]){1, 31}), // 20
    ((int[]){2, 32, 33}), // 21
    ((int[]){3, 32, 34, 35}), // 22
    ((int[]){3, 32, 36, 34}), // 23
    ((int[]){1, 37}), // 24
}
;
#pragma clang diagnostic pop

extern "C" const int* get_guards(int t) 
{
    if (t>=0 && t < 25) return guards_per_transition[t];
    return NULL;
}

extern "C" const int** get_all_guards() 
{
    return (const int**)&guards_per_transition;
}

int guard[][10] = 
{
    {0,0,0,0,0,1,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1,0},
    {0,0,0,1,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1}
}
;

extern "C" const int* get_guard_matrix(int g) 
{
    if (g>=0 && g < 38) return guard[g];
    return NULL;
}

int guardmaybecoenabled[38][38] = 
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_may_be_coenabled_matrix(int g) 
{
    if (g>=0 && g < 38) return guardmaybecoenabled[g];
    return NULL;
}

int guard_nes[38][25] = 
{
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}
}
;

extern "C" const int* get_guard_nes_matrix(int g) 
{
    if (g>=0 && g < 38) return guard_nes[g];
    return NULL;
}

int guard_nds[38][25] = 
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_guard_nds_matrix(int g) 
{
    if (g>=0 && g < 38) return guard_nds[g];
    return NULL;
}

int dna[25][25] = 
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_dna_matrix(int t) 
{
    if (t >= 0 && t < 25) return dna[t];
    return NULL;
}

