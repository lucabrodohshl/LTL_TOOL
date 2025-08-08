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
        byte_t v;
    }
    __attribute__((__packed__)) channel_K;
    struct
    {
        ushort_int_t state;
        byte_t v;
    }
    __attribute__((__packed__)) channel_L;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) Producer;
    struct
    {
        ushort_int_t state;
        byte_t value;
    }
    __attribute__((__packed__)) Consumer;
    struct
    {
        ushort_int_t state;
        byte_t value;
        byte_t sab;
        byte_t ack;
    }
    __attribute__((__packed__)) Sender;
    struct
    {
        ushort_int_t state;
        byte_t value;
        byte_t rab;
    }
    __attribute__((__packed__)) Receiver;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

state_struct_t initial_state = { 0,0,0,0,0,0,0,0,0,0,0,0,0,1 };

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
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_K.v.var) = ((*in).Sender.value.var);
        cpy[((int*)&((*out).channel_K.v.var) - (int*)&(*out))] = 0;
        (*out).channel_K.state.var = 1;
        cpy[((int*)&(*out).channel_K.state.var - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 1;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0
        // may-write:    1,1,0,0,0,0,0,1,0,0,0,0,0,0
        // must-write:   1,1,0,0,0,0,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l1: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).channel_K.state.var = 0;
        cpy[((int*)&(*out).channel_K.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l2: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).channel_L.v.var) = ((*in).Receiver.rab.var);
        cpy[((int*)&((*out).channel_L.v.var) - (int*)&(*out))] = 0;
        (*out).channel_L.state.var = 1;
        cpy[((int*)&(*out).channel_L.state.var - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 0;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1
        // may-write:    0,0,1,1,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,1,1,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l3: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).channel_L.state.var = 0;
        cpy[((int*)&(*out).channel_L.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,1,0,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l4: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 1;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l5: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Producer.state.var = 2;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l6: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Consumer.value.var) = ((*in).Receiver.value.var);
        cpy[((int*)&((*out).Consumer.value.var) - (int*)&(*out))] = 0;
        (*out).Consumer.state.var = 1;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 0;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        ((*out).Receiver.rab.var = 1 - (*out).Receiver.rab.var);
        cpy[((int*)&((*out).Receiver.rab.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,1
        // may-write:    0,0,0,0,0,1,1,0,0,0,0,1,0,1
        // must-write:   0,0,0,0,0,1,1,0,0,0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l7: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Consumer.state.var = 2;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l8: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Consumer.state.var = 3;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l9: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Consumer.state.var = 0;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l10: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Consumer.state.var = 0;
        cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,1,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l11: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Sender.value.var) = (0);
        cpy[((int*)&((*out).Sender.value.var) - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 1;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        (*out).Producer.state.var = 0;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,0,1,1,0,0,0,0,0
        // must-write:   0,0,0,0,1,0,0,1,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l12: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Sender.value.var) = (1);
        cpy[((int*)&((*out).Sender.value.var) - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 1;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        (*out).Producer.state.var = 0;
        cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,1,0,0,1,1,0,0,0,0,0
        // must-write:   0,0,0,0,1,0,0,1,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l13: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Sender.ack.var) = ((*in).channel_L.v.var);
        cpy[((int*)&((*out).Sender.ack.var) - (int*)&(*out))] = 0;
        (*out).Sender.state.var = 2;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        (*out).channel_L.state.var = 0;
        cpy[((int*)&(*out).channel_L.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,0,0,0,0,1,0,0,1,0,0,0
        // must-write:   0,0,1,0,0,0,0,1,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l14: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Sender.state.var = 1;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l15: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).Sender.state.var = 0;
        cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
        ((*out).Sender.sab.var = 1 - (*out).Sender.sab.var);
        cpy[((int*)&((*out).Sender.sab.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,1,0,0,0,0
        // may-write:    0,0,0,0,0,0,0,1,0,1,0,0,0,0
        // must-write:   0,0,0,0,0,0,0,1,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l16: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).Receiver.value.var) = ((*in).channel_K.v.var);
        cpy[((int*)&((*out).Receiver.value.var) - (int*)&(*out))] = 0;
        (*out).Receiver.state.var = 1;
        cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
        (*out).channel_K.state.var = 0;
        cpy[((int*)&(*out).channel_K.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    1,0,0,0,0,0,0,0,0,0,0,1,1,0
        // must-write:   1,0,0,0,0,0,0,0,0,0,0,1,1,0
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
        default: printf ("Wrong group! Using greybox/long call + -l (DiVinE LTL semantics)? This combo is not implemented."); exit (-1);
    }
    return 0;
}

extern "C" int get_successor( void* model, int t, const state_struct_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    int states_emitted = 0;
    goto switch_state;
    l0: {
        
        // read:         1,0,0,0,0,0,0,1,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0
        if (  ( ((*in).channel_K.state.var == 0) )  &&  ( ((*in).Sender.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l1: {
        
        // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_K.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l2: {
        
        // read:         0,0,1,0,0,0,0,0,0,0,0,1,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1
        if (  ( ((*in).channel_L.state.var == 0) )  &&  ( ((*in).Receiver.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l3: {
        
        // read:         0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).channel_L.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l4: {
        
        // read:         0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l5: {
        
        // read:         0,0,0,0,1,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Producer.state.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l6: {
        
        // read:         0,0,0,0,0,1,0,0,0,0,0,1,1,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,1
        if (  ( ((*in).Consumer.state.var == 0) )  &&  ( ((*in).Receiver.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l7: {
        
        // read:         0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 1) )  &&  ( ((*in).Consumer.value.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l8: {
        
        // read:         0,0,0,0,0,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 1) )  &&  ( ((*in).Consumer.value.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l9: {
        
        // read:         0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l10: {
        
        // read:         0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Consumer.state.var == 3) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l11: {
        
        // read:         0,0,0,0,1,0,0,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 0) )  &&  ( ((*in).Producer.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l12: {
        
        // read:         0,0,0,0,1,0,0,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 0) )  &&  ( ((*in).Producer.state.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l13: {
        
        // read:         0,0,1,1,0,0,0,1,0,0,0,0,0,0
        // actions_read: 0,0,0,1,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 1) )  &&  ( ((*in).channel_L.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l14: {
        
        // read:         0,0,0,0,0,0,0,1,0,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Sender.state.var == 2) )  &&  ( ((*in).Sender.ack.var != (*in).Sender.sab.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l15: {
        
        // read:         0,0,0,0,0,0,0,1,0,1,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,1,0,0,0,0
        if (  ( ((*in).Sender.state.var == 2) )  &&  ( ((*in).Sender.ack.var == (*in).Sender.sab.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l16: {
        
        // read:         1,1,0,0,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).Receiver.state.var == 0) )  &&  ( ((*in).channel_K.state.var == 1) ) )
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
    int cpy[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    if ( false )
    {
        ;
    }
    else
    {
        if (  ( ((*in).channel_K.state.var == 0) ) )
        {
            
            // read:         1,0,0,0,0,0,0,1,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0
            if (  ( ((*in).Sender.state.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_K.v.var) = ((*in).Sender.value.var);
                cpy[((int*)&((*out).channel_K.v.var) - (int*)&(*out))] = 0;
                (*out).channel_K.state.var = 1;
                cpy[((int*)&(*out).channel_K.state.var - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 1;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,1,0,0,0,0,0
                // may-write:    1,1,0,0,0,0,0,1,0,0,0,0,0,0
                // must-write:   1,1,0,0,0,0,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 0;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_K.state.var == 1) ) )
        {
            
            // read:         1,0,0,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).channel_K.state.var = 0;
                cpy[((int*)&(*out).channel_K.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 1;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_L.state.var == 0) ) )
        {
            
            // read:         0,0,1,0,0,0,0,0,0,0,0,1,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1
            if (  ( ((*in).Receiver.state.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).channel_L.v.var) = ((*in).Receiver.rab.var);
                cpy[((int*)&((*out).channel_L.v.var) - (int*)&(*out))] = 0;
                (*out).channel_L.state.var = 1;
                cpy[((int*)&(*out).channel_L.state.var - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 0;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,1
                // may-write:    0,0,1,1,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,1,1,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 2;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).channel_L.state.var == 1) ) )
        {
            
            // read:         0,0,1,0,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).channel_L.state.var = 0;
                cpy[((int*)&(*out).channel_L.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,1,0,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 3;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Producer.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,1,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 1;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 4;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,1,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Producer.state.var = 2;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,1,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 5;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Consumer.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,0,1,0,0,0,0,0,1,1,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,1
            if (  ( ((*in).Receiver.state.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Consumer.value.var) = ((*in).Receiver.value.var);
                cpy[((int*)&((*out).Consumer.value.var) - (int*)&(*out))] = 0;
                (*out).Consumer.state.var = 1;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 0;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                ((*out).Receiver.rab.var = 1 - (*out).Receiver.rab.var);
                cpy[((int*)&((*out).Receiver.rab.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,1,1
                // may-write:    0,0,0,0,0,1,1,0,0,0,0,1,0,1
                // must-write:   0,0,0,0,0,1,1,0,0,0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 6;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Consumer.state.var == 1) ) )
        {
            
            // read:         0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Consumer.value.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Consumer.state.var = 2;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 7;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Consumer.value.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Consumer.state.var = 3;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 8;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Consumer.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,1,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Consumer.state.var = 0;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 9;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Consumer.state.var == 3) ) )
        {
            
            // read:         0,0,0,0,0,1,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Consumer.state.var = 0;
                cpy[((int*)&(*out).Consumer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,1,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 10;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Sender.state.var == 0) ) )
        {
            
            // read:         0,0,0,0,1,0,0,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Producer.state.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Sender.value.var) = (0);
                cpy[((int*)&((*out).Sender.value.var) - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 1;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                (*out).Producer.state.var = 0;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,0,1,1,0,0,0,0,0
                // must-write:   0,0,0,0,1,0,0,1,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 11;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,1,0,0,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Producer.state.var == 2) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Sender.value.var) = (1);
                cpy[((int*)&((*out).Sender.value.var) - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 1;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                (*out).Producer.state.var = 0;
                cpy[((int*)&(*out).Producer.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,1,0,0,1,1,0,0,0,0,0
                // must-write:   0,0,0,0,1,0,0,1,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 12;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Sender.state.var == 1) ) )
        {
            
            // read:         0,0,1,1,0,0,0,1,0,0,0,0,0,0
            // actions_read: 0,0,0,1,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).channel_L.state.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Sender.ack.var) = ((*in).channel_L.v.var);
                cpy[((int*)&((*out).Sender.ack.var) - (int*)&(*out))] = 0;
                (*out).Sender.state.var = 2;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                (*out).channel_L.state.var = 0;
                cpy[((int*)&(*out).channel_L.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,0,0,0,0,1,0,0,1,0,0,0
                // must-write:   0,0,1,0,0,0,0,1,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 13;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Sender.state.var == 2) ) )
        {
            
            // read:         0,0,0,0,0,0,0,1,0,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).Sender.ack.var != (*in).Sender.sab.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Sender.state.var = 1;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 14;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,0,0,0,0,1,0,1,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,1,0,0,0,0
            if (  ( ((*in).Sender.ack.var == (*in).Sender.sab.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).Sender.state.var = 0;
                cpy[((int*)&(*out).Sender.state.var - (int*)&(*out))] = 0;
                ((*out).Sender.sab.var = 1 - (*out).Sender.sab.var);
                cpy[((int*)&((*out).Sender.sab.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,1,0,0,0,0
                // may-write:    0,0,0,0,0,0,0,1,0,1,0,0,0,0
                // must-write:   0,0,0,0,0,0,0,1,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 15;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).Receiver.state.var == 0) ) )
        {
            
            // read:         1,1,0,0,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).channel_K.state.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).Receiver.value.var) = ((*in).channel_K.v.var);
                cpy[((int*)&((*out).Receiver.value.var) - (int*)&(*out))] = 0;
                (*out).Receiver.state.var = 1;
                cpy[((int*)&(*out).Receiver.state.var - (int*)&(*out))] = 0;
                (*out).channel_K.state.var = 0;
                cpy[((int*)&(*out).channel_K.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    1,0,0,0,0,0,0,0,0,0,0,1,1,0
                // must-write:   1,0,0,0,0,0,0,0,0,0,0,1,1,0
                system_in_deadlock = false;
                transition_info.group = 16;
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
    return 14;
}

extern "C" const char* get_state_variable_name(int var)
{
    switch (var)
    {
        case 0:
            return "channel_K";
        case 1:
            return "channel_K.v";
        case 2:
            return "channel_L";
        case 3:
            return "channel_L.v";
        case 4:
            return "Producer";
        case 5:
            return "Consumer";
        case 6:
            return "Consumer.value";
        case 7:
            return "Sender";
        case 8:
            return "Sender.value";
        case 9:
            return "Sender.sab";
        case 10:
            return "Sender.ack";
        case 11:
            return "Receiver";
        case 12:
            return "Receiver.value";
        case 13:
            return "Receiver.rab";
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
            return 2;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 1;
        case 7:
            return 5;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 6;
        case 12:
            return 1;
        case 13:
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
        case 4:
            return "Consumer";
        case 3:
            return "Producer";
        case 6:
            return "Receiver";
        case 5:
            return "Sender";
        case 1:
            return "byte";
        case 0:
            return "channel_K";
        case 2:
            return "channel_L";
        default:
            return NULL;
    }
}

extern "C" int get_state_variable_type_value_count(int type)
{
    switch (type)
    {
        case 4: // Consumer
            return 4;
        case 3: // Producer
            return 3;
        case 6: // Receiver
            return 2;
        case 5: // Sender
            return 3;
        case 1: // byte
            return 0;
        case 0: // channel_K
            return 3;
        case 2: // channel_L
            return 3;
        default:
            return -1;
    }
}

extern "C" const char* get_state_variable_type_value(int type, int value) 
{
    switch (type)
    {
        case 4:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "got_msg";
                case 2:
                    return "consume0";
                case 3:
                    return "consume1";
            }
        }
        case 3:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "produce0";
                case 2:
                    return "produce1";
            }
        }
        case 6:
        {
            switch (value)
            {
                case 0:
                    return "wait_msg";
                case 1:
                    return "got_msg";
            }
        }
        case 5:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "sending";
                case 2:
                    return "wait_ack";
            }
        }
        case 0:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "tr";
                case 2:
                    return "data_lost";
            }
        }
        case 2:
        {
            switch (value)
            {
                case 0:
                    return "ready";
                case 1:
                    return "tr";
                case 2:
                    return "dataOK";
            }
        }
    }
    return NULL;
}

int transition_dependency[][3][14] = 
{
    // { ... read ...}, { ... may-write ...}, { ... must-write ...}
    {{1,0,0,0,0,0,0,1,1,0,0,0,0,0},{1,1,0,0,0,0,0,1,0,0,0,0,0,0},{1,1,0,0,0,0,0,1,0,0,0,0,0,0}},
    {{1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,1,0,0,0,0,0,0,0,0,1,0,1},{0,0,1,1,0,0,0,0,0,0,0,1,0,0},{0,0,1,1,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,1,0,0,0,0,0,1,1,1},{0,0,0,0,0,1,1,0,0,0,0,1,0,1},{0,0,0,0,0,1,1,0,0,0,0,1,0,1}},
    {{0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,1,1,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,0,0}},
    {{0,0,0,0,1,0,0,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,1,0,0,1,1,0,0,0,0,0}},
    {{0,0,0,0,1,0,0,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,1,0,0,1,1,0,0,0,0,0}},
    {{0,0,1,1,0,0,0,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,1,0,0,1,0,0,0},{0,0,1,0,0,0,0,1,0,0,1,0,0,0}},
    {{0,0,0,0,0,0,0,1,0,1,1,0,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,0}},
    {{0,0,0,0,0,0,0,1,0,1,1,0,0,0},{0,0,0,0,0,0,0,1,0,1,0,0,0,0},{0,0,0,0,0,0,0,1,0,1,0,0,0,0}},
    {{1,1,0,0,0,0,0,0,0,0,0,1,0,0},{1,0,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,0,0,0,0,0,0,0,0,0,1,1,0}}
}
;

int actions_read[][14] = 
{
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0}
}
;

extern "C" int get_transition_count() 
{
    return 17;
}

extern "C" const int* get_transition_read_dependencies(int t) 
{
    if (t>=0 && t < 17) return transition_dependency[t][0];
    return NULL;
}

extern "C" const int* get_transition_actions_read_dependencies(int t) 
{
    if (t>=0 && t < 17) return actions_read[t];
    return NULL;
}

extern "C" const int* get_transition_may_write_dependencies(int t) 
{
    if (t>=0 && t < 17) return transition_dependency[t][1];
    return NULL;
}

extern "C" const int* get_transition_write_dependencies(int t) 
{
    return get_transition_may_write_dependencies(t);
}

extern "C" const int* get_transition_must_write_dependencies(int t) 
{
    if (t>=0 && t < 17) return transition_dependency[t][2];
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
            case 0: return (((*src).channel_K.state.var == 0));
            case 1: return (((*src).Sender.state.var == 1));
            case 2: return (((*src).channel_K.state.var == 1));
            case 3: return (((*src).channel_L.state.var == 0));
            case 4: return (((*src).Receiver.state.var == 0));
            case 5: return (((*src).channel_L.state.var == 1));
            case 6: return (((*src).Producer.state.var == 0));
            case 7: return (((*src).Consumer.state.var == 0));
            case 8: return (((*src).Receiver.state.var == 1));
            case 9: return (((*src).Consumer.state.var == 1));
            case 10: return (((*src).Consumer.value.var == 0));
            case 11: return (((*src).Consumer.value.var == 1));
            case 12: return (((*src).Consumer.state.var == 2));
            case 13: return (((*src).Consumer.state.var == 3));
            case 14: return (((*src).Sender.state.var == 0));
            case 15: return (((*src).Producer.state.var == 1));
            case 16: return (((*src).Producer.state.var == 2));
            case 17: return (((*src).Sender.state.var == 2));
            case 18: return (((*src).Sender.ack.var != (*src).Sender.sab.var));
            case 19: return (((*src).Sender.ack.var == (*src).Sender.sab.var));
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
}

extern "C" const int get_guard_count() 
{
    return 20;
}

#pragma clang diagnostic push
int* guards_per_transition[17] = 
{
    ((int[]){2, 0, 1}), // 0
    ((int[]){1, 2}), // 1
    ((int[]){2, 3, 4}), // 2
    ((int[]){1, 5}), // 3
    ((int[]){1, 6}), // 4
    ((int[]){1, 6}), // 5
    ((int[]){2, 7, 8}), // 6
    ((int[]){2, 9, 10}), // 7
    ((int[]){2, 9, 11}), // 8
    ((int[]){1, 12}), // 9
    ((int[]){1, 13}), // 10
    ((int[]){2, 14, 15}), // 11
    ((int[]){2, 14, 16}), // 12
    ((int[]){2, 1, 5}), // 13
    ((int[]){2, 17, 18}), // 14
    ((int[]){2, 17, 19}), // 15
    ((int[]){2, 4, 2}), // 16
}
;
#pragma clang diagnostic pop

extern "C" const int* get_guards(int t) 
{
    if (t>=0 && t < 17) return guards_per_transition[t];
    return NULL;
}

extern "C" const int** get_all_guards() 
{
    return (const int**)&guards_per_transition;
}

int guard[][14] = 
{
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0}
}
;

extern "C" const int* get_guard_matrix(int g) 
{
    if (g>=0 && g < 20) return guard[g];
    return NULL;
}

int guardmaybecoenabled[20][20] = 
{
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_may_be_coenabled_matrix(int g) 
{
    if (g>=0 && g < 20) return guardmaybecoenabled[g];
    return NULL;
}

int guard_nes[20][17] = 
{
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_nes_matrix(int g) 
{
    if (g>=0 && g < 20) return guard_nes[g];
    return NULL;
}

int guard_nds[20][17] = 
{
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_guard_nds_matrix(int g) 
{
    if (g>=0 && g < 20) return guard_nds[g];
    return NULL;
}

int dna[17][17] = 
{
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}
;

extern "C" const int* get_dna_matrix(int t) 
{
    if (t >= 0 && t < 17) return dna[t];
    return NULL;
}

