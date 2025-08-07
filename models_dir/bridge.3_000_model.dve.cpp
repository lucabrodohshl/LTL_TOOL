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
    byte_t total_time;
    byte_t where_is_torch;
    byte_t on_right;
    struct
    {
        ushort_int_t state;
        byte_t time1;
        byte_t time2;
    }
    __attribute__((__packed__)) torch;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) soldier_1;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) soldier_2;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) soldier_3;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) soldier_4;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) soldier_5;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) soldier_6;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) soldier_7;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) soldier_8;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

state_struct_t initial_state = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

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
        ((*out).torch.time1.var) = (5);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_1.state.var = 1;
        cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,1,0,0,0,0,0,0,0
        // must-write:   0,0,0,1,1,0,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l1: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (5);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_1.state.var = 3;
        cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,0,1,0,0,0,0,0,0,0
        // must-write:   0,0,1,1,1,0,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l2: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (10);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_2.state.var = 1;
        cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,1,0,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l3: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (10);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_2.state.var = 3;
        cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,0,0,1,0,0,0,0,0,0
        // must-write:   0,0,1,1,1,0,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l4: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (20);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_3.state.var = 1;
        cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,1,1,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l5: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (20);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_3.state.var = 3;
        cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,1,1,1,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l6: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (25);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_4.state.var = 1;
        cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,1,0,0,0,0
        // must-write:   0,0,0,1,1,0,0,0,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l7: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (25);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_4.state.var = 3;
        cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,0,0,0,0,1,0,0,0,0
        // must-write:   0,0,1,1,1,0,0,0,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l8: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (30);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_5.state.var = 1;
        cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,1,1,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l9: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (30);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_5.state.var = 3;
        cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,1,1,1,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l10: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (30);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_6.state.var = 1;
        cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,1,1,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l11: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (30);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_6.state.var = 3;
        cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,1,1,1,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l12: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (40);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_7.state.var = 1;
        cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,1,0
        // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l13: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (40);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_7.state.var = 3;
        cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,0,0,0,0,0,0,0,1,0
        // must-write:   0,0,1,1,1,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l14: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (45);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_8.state.var = 1;
        cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,0,1
        // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l15: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time1.var) = (45);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 1;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_8.state.var = 3;
        cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,0,0,0,0,0,0,0,0,1
        // must-write:   0,0,1,1,1,0,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l16: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (5);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_1.state.var = 1;
        cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,1,0,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,1,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l17: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (5);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_1.state.var = 3;
        cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,1,1,0,0,0,0,0,0,0
        // must-write:   0,0,1,1,0,1,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l18: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (10);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_2.state.var = 1;
        cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l19: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (10);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_2.state.var = 3;
        cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,1,1,0,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l20: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (20);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_3.state.var = 1;
        cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,1,0,1,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l21: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (20);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_3.state.var = 3;
        cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,1,0,0,1,0,0,0,0,0
        // must-write:   0,0,1,1,0,1,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l22: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (25);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_4.state.var = 1;
        cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,0,0,1,0,0,0,0
        // must-write:   0,0,0,1,0,1,0,0,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l23: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (25);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_4.state.var = 3;
        cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,1,0,0,0,1,0,0,0,0
        // must-write:   0,0,1,1,0,1,0,0,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l24: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (30);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_5.state.var = 1;
        cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,1,0,1,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l25: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (30);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_5.state.var = 3;
        cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,1,0,0,0,0,1,0,0,0
        // must-write:   0,0,1,1,0,1,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l26: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (30);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_6.state.var = 1;
        cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,1,0,1,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l27: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (30);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_6.state.var = 3;
        cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,1,0,0,0,0,0,1,0,0
        // must-write:   0,0,1,1,0,1,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l28: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (40);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_7.state.var = 1;
        cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,1,0
        // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l29: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (40);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_7.state.var = 3;
        cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,1,0,0,0,0,0,0,1,0
        // must-write:   0,0,1,1,0,1,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l30: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (45);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_8.state.var = 1;
        cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,0,1
        // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l31: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        ((*out).torch.time2.var) = (45);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 2;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        (*out).soldier_8.state.var = 3;
        cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var - 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,1,0,0,0,0,0,0,0,1
        // must-write:   0,0,1,1,0,1,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l32: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l33: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_1.state.var = 2;
        cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,0,1,0,0,0,0,0,0,0
        // must-write:   0,0,1,1,0,0,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l34: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_1.state.var = 2;
        cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,1,1,0,0,0,0,0,0,0
        // must-write:   0,0,1,1,1,1,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l35: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_1.state.var = 2;
        cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,1,1,1,0,1,0,0,0,0,0,0,0
        // must-write:   1,1,1,1,1,0,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l36: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_1.state.var = 0;
        cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,1,0,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l37: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_1.state.var = 0;
        cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,1,1,0,0,0,0,0,0,0
        // must-write:   0,0,0,1,1,1,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l38: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_1.state.var = 0;
        cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,1,1,0,1,0,0,0,0,0,0,0
        // must-write:   1,1,0,1,1,0,1,0,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l39: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_2.state.var = 2;
        cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,0,0,1,0,0,0,0,0,0
        // must-write:   0,0,1,1,0,0,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l40: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_2.state.var = 2;
        cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,1,1,1,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l41: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_2.state.var = 2;
        cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,1,1,1,0,0,1,0,0,0,0,0,0
        // must-write:   1,1,1,1,1,0,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l42: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_2.state.var = 0;
        cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l43: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_2.state.var = 0;
        cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,1,0,1,0,0,0,0,0,0
        // must-write:   0,0,0,1,1,1,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l44: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_2.state.var = 0;
        cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,1,1,0,0,1,0,0,0,0,0,0
        // must-write:   1,1,0,1,1,0,0,1,0,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l45: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_3.state.var = 2;
        cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,1,1,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l46: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_3.state.var = 2;
        cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,1,0,0,1,0,0,0,0,0
        // must-write:   0,0,1,1,1,1,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l47: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_3.state.var = 2;
        cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,1,1,1,0,0,0,1,0,0,0,0,0
        // must-write:   1,1,1,1,1,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l48: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_3.state.var = 0;
        cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l49: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_3.state.var = 0;
        cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,1,0,0,1,0,0,0,0,0
        // must-write:   0,0,0,1,1,1,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l50: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_3.state.var = 0;
        cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,1,1,0,0,0,1,0,0,0,0,0
        // must-write:   1,1,0,1,1,0,0,0,1,0,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l51: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_4.state.var = 2;
        cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,0,0,0,0,1,0,0,0,0
        // must-write:   0,0,1,1,0,0,0,0,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l52: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_4.state.var = 2;
        cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,1,0,0,0,1,0,0,0,0
        // must-write:   0,0,1,1,1,1,0,0,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l53: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_4.state.var = 2;
        cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,1,1,1,0,0,0,0,1,0,0,0,0
        // must-write:   1,1,1,1,1,0,0,0,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l54: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_4.state.var = 0;
        cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,1,0,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l55: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_4.state.var = 0;
        cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,1,0,0,0,1,0,0,0,0
        // must-write:   0,0,0,1,1,1,0,0,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l56: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_4.state.var = 0;
        cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,1,1,0,0,0,0,1,0,0,0,0
        // must-write:   1,1,0,1,1,0,0,0,0,1,0,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l57: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_5.state.var = 2;
        cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,1,1,0,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l58: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_5.state.var = 2;
        cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,1,0,0,0,0,1,0,0,0
        // must-write:   0,0,1,1,1,1,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l59: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_5.state.var = 2;
        cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,1,1,1,0,0,0,0,0,1,0,0,0
        // must-write:   1,1,1,1,1,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l60: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_5.state.var = 0;
        cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l61: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_5.state.var = 0;
        cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,1,0,0,0,0,1,0,0,0
        // must-write:   0,0,0,1,1,1,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l62: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_5.state.var = 0;
        cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,1,1,0,0,0,0,0,1,0,0,0
        // must-write:   1,1,0,1,1,0,0,0,0,0,1,0,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l63: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_6.state.var = 2;
        cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,1,1,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l64: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_6.state.var = 2;
        cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,1,0,0,0,0,0,1,0,0
        // must-write:   0,0,1,1,1,1,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l65: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_6.state.var = 2;
        cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,1,1,1,0,0,0,0,0,0,1,0,0
        // must-write:   1,1,1,1,1,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l66: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_6.state.var = 0;
        cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l67: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_6.state.var = 0;
        cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,1,0,0,0,0,0,1,0,0
        // must-write:   0,0,0,1,1,1,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l68: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_6.state.var = 0;
        cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,1,1,0,0,0,0,0,0,1,0,0
        // must-write:   1,1,0,1,1,0,0,0,0,0,0,1,0,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l69: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_7.state.var = 2;
        cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,0,0,0,0,0,0,0,1,0
        // must-write:   0,0,1,1,0,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l70: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_7.state.var = 2;
        cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,1,0,0,0,0,0,0,1,0
        // must-write:   0,0,1,1,1,1,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l71: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_7.state.var = 2;
        cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,1,1,1,0,0,0,0,0,0,0,1,0
        // must-write:   1,1,1,1,1,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l72: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_7.state.var = 0;
        cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l73: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_7.state.var = 0;
        cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,1,0,0,0,0,0,0,1,0
        // must-write:   0,0,0,1,1,1,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l74: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_7.state.var = 0;
        cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,1,1,0,0,0,0,0,0,0,1,0
        // must-write:   1,1,0,1,1,0,0,0,0,0,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l75: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_8.state.var = 2;
        cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,0,0,0,0,0,0,0,0,0,1
        // must-write:   0,0,1,1,0,0,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l76: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_8.state.var = 2;
        cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,1,1,1,1,0,0,0,0,0,0,0,1
        // must-write:   0,0,1,1,1,1,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l77: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_8.state.var = 2;
        cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
        ((*out).on_right.var = (*out).on_right.var + 1);
        cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,1,1,1,0,0,0,0,0,0,0,0,1
        // must-write:   1,1,1,1,1,0,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l78: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_8.state.var = 0;
        cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,1
        // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l79: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_8.state.var = 0;
        cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 3;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = (*out).torch.time2.var);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).torch.time2.var = 0);
        cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        // may-write:    0,0,0,1,1,1,0,0,0,0,0,0,0,1
        // must-write:   0,0,0,1,1,1,0,0,0,0,0,0,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l80: {
        *out = *in;
        int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
        (*out).soldier_8.state.var = 0;
        cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
        (*out).torch.state.var = 0;
        cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
        ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
        cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
        ((*out).torch.time1.var = 0);
        cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
        ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
        cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        // may-write:    1,1,0,1,1,0,0,0,0,0,0,0,0,1
        // must-write:   1,1,0,1,1,0,0,0,0,0,0,0,0,1
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
        default: printf ("Wrong group! Using greybox/long call + -l (DiVinE LTL semantics)? This combo is not implemented."); exit (-1);
    }
    return 0;
}

extern "C" int get_successor( void* model, int t, const state_struct_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    int states_emitted = 0;
    goto switch_state;
    l0: {
        
        // read:         0,1,0,1,0,0,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_1.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l1: {
        
        // read:         0,1,1,1,0,0,1,0,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_1.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l2: {
        
        // read:         0,1,0,1,0,0,0,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_2.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l3: {
        
        // read:         0,1,1,1,0,0,0,1,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_2.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l4: {
        
        // read:         0,1,0,1,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_3.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l5: {
        
        // read:         0,1,1,1,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_3.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l6: {
        
        // read:         0,1,0,1,0,0,0,0,0,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_4.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l7: {
        
        // read:         0,1,1,1,0,0,0,0,0,1,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_4.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l8: {
        
        // read:         0,1,0,1,0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_5.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l9: {
        
        // read:         0,1,1,1,0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_5.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l10: {
        
        // read:         0,1,0,1,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_6.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l11: {
        
        // read:         0,1,1,1,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_6.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l12: {
        
        // read:         0,1,0,1,0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_7.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l13: {
        
        // read:         0,1,1,1,0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_7.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l14: {
        
        // read:         0,1,0,1,0,0,0,0,0,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_8.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l15: {
        
        // read:         0,1,1,1,0,0,0,0,0,0,0,0,0,1
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 0) )  &&  ( ((*in).soldier_8.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l16: {
        
        // read:         0,1,0,1,0,0,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_1.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l17: {
        
        // read:         0,1,1,1,0,0,1,0,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_1.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l18: {
        
        // read:         0,1,0,1,0,0,0,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_2.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l19: {
        
        // read:         0,1,1,1,0,0,0,1,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_2.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l20: {
        
        // read:         0,1,0,1,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_3.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l21: {
        
        // read:         0,1,1,1,0,0,0,0,1,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_3.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l22: {
        
        // read:         0,1,0,1,0,0,0,0,0,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_4.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l23: {
        
        // read:         0,1,1,1,0,0,0,0,0,1,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_4.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l24: {
        
        // read:         0,1,0,1,0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_5.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l25: {
        
        // read:         0,1,1,1,0,0,0,0,0,0,1,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_5.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l26: {
        
        // read:         0,1,0,1,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_6.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l27: {
        
        // read:         0,1,1,1,0,0,0,0,0,0,0,1,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_6.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l28: {
        
        // read:         0,1,0,1,0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_7.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l29: {
        
        // read:         0,1,1,1,0,0,0,0,0,0,0,0,1,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_7.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l30: {
        
        // read:         0,1,0,1,0,0,0,0,0,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_8.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l31: {
        
        // read:         0,1,1,1,0,0,0,0,0,0,0,0,0,1
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) )  &&  ( ((*in).soldier_8.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l32: {
        
        // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).torch.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l33: {
        
        // read:         0,0,1,1,1,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_1.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l34: {
        
        // read:         0,0,1,1,1,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_1.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l35: {
        
        // read:         1,1,1,1,1,0,1,0,0,0,0,0,0,0
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_1.state.var == 1) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l36: {
        
        // read:         0,0,0,1,1,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_1.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l37: {
        
        // read:         0,0,0,1,1,1,1,0,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_1.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l38: {
        
        // read:         1,1,0,1,1,0,1,0,0,0,0,0,0,0
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_1.state.var == 3) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l39: {
        
        // read:         0,0,1,1,1,1,0,1,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_2.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l40: {
        
        // read:         0,0,1,1,1,1,0,1,0,0,0,0,0,0
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_2.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l41: {
        
        // read:         1,1,1,1,1,0,0,1,0,0,0,0,0,0
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_2.state.var == 1) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l42: {
        
        // read:         0,0,0,1,1,1,0,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_2.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l43: {
        
        // read:         0,0,0,1,1,1,0,1,0,0,0,0,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_2.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l44: {
        
        // read:         1,1,0,1,1,0,0,1,0,0,0,0,0,0
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_2.state.var == 3) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l45: {
        
        // read:         0,0,1,1,1,1,0,0,1,0,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_3.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l46: {
        
        // read:         0,0,1,1,1,1,0,0,1,0,0,0,0,0
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_3.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l47: {
        
        // read:         1,1,1,1,1,0,0,0,1,0,0,0,0,0
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_3.state.var == 1) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l48: {
        
        // read:         0,0,0,1,1,1,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_3.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l49: {
        
        // read:         0,0,0,1,1,1,0,0,1,0,0,0,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_3.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l50: {
        
        // read:         1,1,0,1,1,0,0,0,1,0,0,0,0,0
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_3.state.var == 3) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l51: {
        
        // read:         0,0,1,1,1,1,0,0,0,1,0,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_4.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l52: {
        
        // read:         0,0,1,1,1,1,0,0,0,1,0,0,0,0
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_4.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l53: {
        
        // read:         1,1,1,1,1,0,0,0,0,1,0,0,0,0
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_4.state.var == 1) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l54: {
        
        // read:         0,0,0,1,1,1,0,0,0,1,0,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_4.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l55: {
        
        // read:         0,0,0,1,1,1,0,0,0,1,0,0,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_4.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l56: {
        
        // read:         1,1,0,1,1,0,0,0,0,1,0,0,0,0
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_4.state.var == 3) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l57: {
        
        // read:         0,0,1,1,1,1,0,0,0,0,1,0,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_5.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l58: {
        
        // read:         0,0,1,1,1,1,0,0,0,0,1,0,0,0
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_5.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l59: {
        
        // read:         1,1,1,1,1,0,0,0,0,0,1,0,0,0
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_5.state.var == 1) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l60: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_5.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l61: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,1,0,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_5.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l62: {
        
        // read:         1,1,0,1,1,0,0,0,0,0,1,0,0,0
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_5.state.var == 3) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l63: {
        
        // read:         0,0,1,1,1,1,0,0,0,0,0,1,0,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_6.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l64: {
        
        // read:         0,0,1,1,1,1,0,0,0,0,0,1,0,0
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_6.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l65: {
        
        // read:         1,1,1,1,1,0,0,0,0,0,0,1,0,0
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_6.state.var == 1) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l66: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_6.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l67: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,0,1,0,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_6.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l68: {
        
        // read:         1,1,0,1,1,0,0,0,0,0,0,1,0,0
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_6.state.var == 3) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l69: {
        
        // read:         0,0,1,1,1,1,0,0,0,0,0,0,1,0
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_7.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l70: {
        
        // read:         0,0,1,1,1,1,0,0,0,0,0,0,1,0
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_7.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l71: {
        
        // read:         1,1,1,1,1,0,0,0,0,0,0,0,1,0
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_7.state.var == 1) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l72: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_7.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l73: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,0,0,1,0
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_7.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l74: {
        
        // read:         1,1,0,1,1,0,0,0,0,0,0,0,1,0
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_7.state.var == 3) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l75: {
        
        // read:         0,0,1,1,1,1,0,0,0,0,0,0,0,1
        // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_8.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l76: {
        
        // read:         0,0,1,1,1,1,0,0,0,0,0,0,0,1
        // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_8.state.var == 1) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l77: {
        
        // read:         1,1,1,1,1,0,0,0,0,0,0,0,0,1
        // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_8.state.var == 1) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l78: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,1
        // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_8.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l79: {
        
        // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,1
        // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_8.state.var == 3) )  &&  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l80: {
        
        // read:         1,1,0,1,1,0,0,0,0,0,0,0,0,1
        // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
        if (  ( ((*in).soldier_8.state.var == 3) )  &&  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
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
        if (  ( ((*in).torch.state.var == 0) ) )
        {
            
            // read:         0,1,0,1,0,0,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_1.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (5);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_1.state.var = 1;
                cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,1,0,0,0,0,0,0,0
                // must-write:   0,0,0,1,1,0,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 0;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,1,0,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_1.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (5);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_1.state.var = 3;
                cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,0,1,0,0,0,0,0,0,0
                // must-write:   0,0,1,1,1,0,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 1;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_2.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (10);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_2.state.var = 1;
                cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,1,0,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 2;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,1,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_2.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (10);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_2.state.var = 3;
                cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,0,0,1,0,0,0,0,0,0
                // must-write:   0,0,1,1,1,0,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 3;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_3.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (20);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_3.state.var = 1;
                cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,1,1,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 4;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_3.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (20);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_3.state.var = 3;
                cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,1,1,1,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 5;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,0,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_4.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (25);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_4.state.var = 1;
                cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,1,0,0,0,0
                // must-write:   0,0,0,1,1,0,0,0,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 6;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,0,1,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_4.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (25);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_4.state.var = 3;
                cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,0,0,0,0,1,0,0,0,0
                // must-write:   0,0,1,1,1,0,0,0,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 7;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_5.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (30);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_5.state.var = 1;
                cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,1,1,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 8;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_5.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (30);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_5.state.var = 3;
                cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,1,1,1,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 9;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_6.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (30);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_6.state.var = 1;
                cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,1,1,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 10;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_6.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (30);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_6.state.var = 3;
                cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,1,1,1,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 11;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_7.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (40);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_7.state.var = 1;
                cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,1,0
                // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 12;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_7.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (40);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_7.state.var = 3;
                cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,0,0,0,0,0,0,0,1,0
                // must-write:   0,0,1,1,1,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 13;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,0,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_8.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (45);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_8.state.var = 1;
                cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,0,0,0,0,0,0,0,0,1
                // must-write:   0,0,0,1,1,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 14;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,0,0,0,0,0,1
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_8.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time1.var) = (45);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 1;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_8.state.var = 3;
                cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,0,0,0,0,0,0,0,0,1
                // must-write:   0,0,1,1,1,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 15;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).torch.state.var == 1) ) )
        {
            
            // read:         0,1,0,1,0,0,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_1.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (5);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_1.state.var = 1;
                cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,1,0,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,1,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 16;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,1,0,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_1.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (5);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_1.state.var = 3;
                cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,1,1,0,0,0,0,0,0,0
                // must-write:   0,0,1,1,0,1,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 17;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_2.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (10);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_2.state.var = 1;
                cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 18;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,1,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_2.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (10);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_2.state.var = 3;
                cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,1,1,0,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 19;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_3.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (20);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_3.state.var = 1;
                cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,1,0,1,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 20;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,1,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_3.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (20);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_3.state.var = 3;
                cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,1,0,0,1,0,0,0,0,0
                // must-write:   0,0,1,1,0,1,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 21;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,0,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_4.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (25);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_4.state.var = 1;
                cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,0,0,1,0,0,0,0
                // must-write:   0,0,0,1,0,1,0,0,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 22;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,0,1,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_4.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (25);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_4.state.var = 3;
                cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,1,0,0,0,1,0,0,0,0
                // must-write:   0,0,1,1,0,1,0,0,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 23;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_5.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (30);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_5.state.var = 1;
                cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,1,0,1,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 24;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,0,0,1,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_5.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (30);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_5.state.var = 3;
                cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,1,0,0,0,0,1,0,0,0
                // must-write:   0,0,1,1,0,1,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 25;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_6.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (30);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_6.state.var = 1;
                cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,1,0,1,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 26;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,0,0,0,1,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_6.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (30);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_6.state.var = 3;
                cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,1,0,0,0,0,0,1,0,0
                // must-write:   0,0,1,1,0,1,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 27;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_7.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (40);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_7.state.var = 1;
                cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,1,0
                // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 28;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,0,0,0,0,1,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_7.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (40);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_7.state.var = 3;
                cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,1,0,0,0,0,0,0,1,0
                // must-write:   0,0,1,1,0,1,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 29;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,0,1,0,0,0,0,0,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_8.state.var == 0) )  &&  ( ((*in).where_is_torch.var == 0) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (45);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_8.state.var = 1;
                cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,1,0,0,0,0,0,0,0,1
                // must-write:   0,0,0,1,0,1,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 30;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,1,1,1,0,0,0,0,0,0,0,0,0,1
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).soldier_8.state.var == 2) )  &&  ( ((*in).where_is_torch.var == 1) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                ((*out).torch.time2.var) = (45);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 2;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                (*out).soldier_8.state.var = 3;
                cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var - 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,1,0,0,0,0,0,0,0,1
                // must-write:   0,0,1,1,0,1,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 31;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,0,0,0,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 32;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_1.state.var == 1) ) )
        {
            
            // read:         0,0,1,1,1,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_1.state.var = 2;
                cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,0,1,0,0,0,0,0,0,0
                // must-write:   0,0,1,1,0,0,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 33;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,1,1,1,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_1.state.var = 2;
                cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,1,1,0,0,0,0,0,0,0
                // must-write:   0,0,1,1,1,1,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 34;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,1,1,0,1,0,0,0,0,0,0,0
            // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_1.state.var = 2;
                cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,1,1,1,0,1,0,0,0,0,0,0,0
                // must-write:   1,1,1,1,1,0,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 35;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_1.state.var == 3) ) )
        {
            
            // read:         0,0,0,1,1,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_1.state.var = 0;
                cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,1,0,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 36;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,1,0,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_1.state.var = 0;
                cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,1,1,0,0,0,0,0,0,0
                // must-write:   0,0,0,1,1,1,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 37;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,1,1,0,1,0,0,0,0,0,0,0
            // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_1.state.var = 0;
                cpy[((int*)&(*out).soldier_1.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,1,1,0,1,0,0,0,0,0,0,0
                // must-write:   1,1,0,1,1,0,1,0,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 38;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_2.state.var == 1) ) )
        {
            
            // read:         0,0,1,1,1,1,0,1,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_2.state.var = 2;
                cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,0,0,1,0,0,0,0,0,0
                // must-write:   0,0,1,1,0,0,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 39;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,1,1,1,1,0,1,0,0,0,0,0,0
            // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_2.state.var = 2;
                cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,1,1,1,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 40;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,1,1,0,0,1,0,0,0,0,0,0
            // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_2.state.var = 2;
                cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,1,1,1,0,0,1,0,0,0,0,0,0
                // must-write:   1,1,1,1,1,0,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 41;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_2.state.var == 3) ) )
        {
            
            // read:         0,0,0,1,1,1,0,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_2.state.var = 0;
                cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 42;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,1,0,0,0,0,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_2.state.var = 0;
                cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,1,0,1,0,0,0,0,0,0
                // must-write:   0,0,0,1,1,1,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 43;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,1,1,0,0,1,0,0,0,0,0,0
            // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_2.state.var = 0;
                cpy[((int*)&(*out).soldier_2.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,1,1,0,0,1,0,0,0,0,0,0
                // must-write:   1,1,0,1,1,0,0,1,0,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 44;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_3.state.var == 1) ) )
        {
            
            // read:         0,0,1,1,1,1,0,0,1,0,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_3.state.var = 2;
                cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,1,1,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 45;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,1,1,1,1,0,0,1,0,0,0,0,0
            // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_3.state.var = 2;
                cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,1,0,0,1,0,0,0,0,0
                // must-write:   0,0,1,1,1,1,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 46;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,1,1,0,0,0,1,0,0,0,0,0
            // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_3.state.var = 2;
                cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,1,1,1,0,0,0,1,0,0,0,0,0
                // must-write:   1,1,1,1,1,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 47;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_3.state.var == 3) ) )
        {
            
            // read:         0,0,0,1,1,1,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_3.state.var = 0;
                cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 48;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,0,1,0,0,0,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_3.state.var = 0;
                cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,1,0,0,1,0,0,0,0,0
                // must-write:   0,0,0,1,1,1,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 49;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,1,1,0,0,0,1,0,0,0,0,0
            // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_3.state.var = 0;
                cpy[((int*)&(*out).soldier_3.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,1,1,0,0,0,1,0,0,0,0,0
                // must-write:   1,1,0,1,1,0,0,0,1,0,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 50;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_4.state.var == 1) ) )
        {
            
            // read:         0,0,1,1,1,1,0,0,0,1,0,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_4.state.var = 2;
                cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,0,0,0,0,1,0,0,0,0
                // must-write:   0,0,1,1,0,0,0,0,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 51;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,1,1,1,1,0,0,0,1,0,0,0,0
            // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_4.state.var = 2;
                cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,1,0,0,0,1,0,0,0,0
                // must-write:   0,0,1,1,1,1,0,0,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 52;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,1,1,0,0,0,0,1,0,0,0,0
            // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_4.state.var = 2;
                cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,1,1,1,0,0,0,0,1,0,0,0,0
                // must-write:   1,1,1,1,1,0,0,0,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 53;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_4.state.var == 3) ) )
        {
            
            // read:         0,0,0,1,1,1,0,0,0,1,0,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_4.state.var = 0;
                cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,1,0,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 54;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,0,0,1,0,0,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_4.state.var = 0;
                cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,1,0,0,0,1,0,0,0,0
                // must-write:   0,0,0,1,1,1,0,0,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 55;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,1,1,0,0,0,0,1,0,0,0,0
            // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_4.state.var = 0;
                cpy[((int*)&(*out).soldier_4.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,1,1,0,0,0,0,1,0,0,0,0
                // must-write:   1,1,0,1,1,0,0,0,0,1,0,0,0,0
                system_in_deadlock = false;
                transition_info.group = 56;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_5.state.var == 1) ) )
        {
            
            // read:         0,0,1,1,1,1,0,0,0,0,1,0,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_5.state.var = 2;
                cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,1,1,0,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 57;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,1,1,1,1,0,0,0,0,1,0,0,0
            // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_5.state.var = 2;
                cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,1,0,0,0,0,1,0,0,0
                // must-write:   0,0,1,1,1,1,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 58;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,1,1,0,0,0,0,0,1,0,0,0
            // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_5.state.var = 2;
                cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,1,1,1,0,0,0,0,0,1,0,0,0
                // must-write:   1,1,1,1,1,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 59;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_5.state.var == 3) ) )
        {
            
            // read:         0,0,0,1,1,1,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_5.state.var = 0;
                cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 60;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,0,0,0,1,0,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_5.state.var = 0;
                cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,1,0,0,0,0,1,0,0,0
                // must-write:   0,0,0,1,1,1,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 61;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,1,1,0,0,0,0,0,1,0,0,0
            // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_5.state.var = 0;
                cpy[((int*)&(*out).soldier_5.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,1,1,0,0,0,0,0,1,0,0,0
                // must-write:   1,1,0,1,1,0,0,0,0,0,1,0,0,0
                system_in_deadlock = false;
                transition_info.group = 62;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_6.state.var == 1) ) )
        {
            
            // read:         0,0,1,1,1,1,0,0,0,0,0,1,0,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_6.state.var = 2;
                cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,1,1,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 63;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,1,1,1,1,0,0,0,0,0,1,0,0
            // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_6.state.var = 2;
                cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,1,0,0,0,0,0,1,0,0
                // must-write:   0,0,1,1,1,1,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 64;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,1,1,0,0,0,0,0,0,1,0,0
            // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_6.state.var = 2;
                cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,1,1,1,0,0,0,0,0,0,1,0,0
                // must-write:   1,1,1,1,1,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 65;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_6.state.var == 3) ) )
        {
            
            // read:         0,0,0,1,1,1,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_6.state.var = 0;
                cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 66;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,0,0,0,0,1,0,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_6.state.var = 0;
                cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,1,0,0,0,0,0,1,0,0
                // must-write:   0,0,0,1,1,1,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 67;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,1,1,0,0,0,0,0,0,1,0,0
            // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_6.state.var = 0;
                cpy[((int*)&(*out).soldier_6.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,1,1,0,0,0,0,0,0,1,0,0
                // must-write:   1,1,0,1,1,0,0,0,0,0,0,1,0,0
                system_in_deadlock = false;
                transition_info.group = 68;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_7.state.var == 1) ) )
        {
            
            // read:         0,0,1,1,1,1,0,0,0,0,0,0,1,0
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_7.state.var = 2;
                cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,0,0,0,0,0,0,0,1,0
                // must-write:   0,0,1,1,0,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 69;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,1,1,1,1,0,0,0,0,0,0,1,0
            // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_7.state.var = 2;
                cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,1,0,0,0,0,0,0,1,0
                // must-write:   0,0,1,1,1,1,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 70;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,1,1,0,0,0,0,0,0,0,1,0
            // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_7.state.var = 2;
                cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,1,1,1,0,0,0,0,0,0,0,1,0
                // must-write:   1,1,1,1,1,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 71;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_7.state.var == 3) ) )
        {
            
            // read:         0,0,0,1,1,1,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_7.state.var = 0;
                cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,1,0
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 72;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,0,0,0,0,0,1,0
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_7.state.var = 0;
                cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,1,0,0,0,0,0,0,1,0
                // must-write:   0,0,0,1,1,1,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 73;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,1,1,0,0,0,0,0,0,0,1,0
            // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_7.state.var = 0;
                cpy[((int*)&(*out).soldier_7.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,1,1,0,0,0,0,0,0,0,1,0
                // must-write:   1,1,0,1,1,0,0,0,0,0,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 74;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_8.state.var == 1) ) )
        {
            
            // read:         0,0,1,1,1,1,0,0,0,0,0,0,0,1
            // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_8.state.var = 2;
                cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,0,0,0,0,0,0,0,0,0,1
                // must-write:   0,0,1,1,0,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 75;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,1,1,1,1,0,0,0,0,0,0,0,1
            // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_8.state.var = 2;
                cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,1,1,1,1,0,0,0,0,0,0,0,1
                // must-write:   0,0,1,1,1,1,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 76;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,1,1,1,0,0,0,0,0,0,0,0,1
            // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_8.state.var = 2;
                cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
                ((*out).on_right.var = (*out).on_right.var + 1);
                cpy[((int*)&((*out).on_right.var) - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,1,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,1,1,1,0,0,0,0,0,0,0,0,1
                // must-write:   1,1,1,1,1,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 77;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).soldier_8.state.var == 3) ) )
        {
            
            // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,1
            // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var >= (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_8.state.var = 0;
                cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,0,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,0,0,0,0,0,0,0,0,0,1
                // must-write:   0,0,0,1,0,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 78;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         0,0,0,1,1,1,0,0,0,0,0,0,0,1
            // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 2) )  &&  ( ((*in).torch.time1.var < (*in).torch.time2.var) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_8.state.var = 0;
                cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 3;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = (*out).torch.time2.var);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).torch.time2.var = 0);
                cpy[((int*)&((*out).torch.time2.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,0,0,0,1,0,0,0,0,0,0,0,0
                // may-write:    0,0,0,1,1,1,0,0,0,0,0,0,0,1
                // must-write:   0,0,0,1,1,1,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 79;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
            
            // read:         1,1,0,1,1,0,0,0,0,0,0,0,0,1
            // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
            if (  ( ((*in).torch.state.var == 3) )  &&  ( ((*in).total_time.var + (*in).torch.time1.var <= 200) ) )
            {
                *out = *in;
                int cpy[14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
                (*out).soldier_8.state.var = 0;
                cpy[((int*)&(*out).soldier_8.state.var - (int*)&(*out))] = 0;
                (*out).torch.state.var = 0;
                cpy[((int*)&(*out).torch.state.var - (int*)&(*out))] = 0;
                ((*out).total_time.var = (*out).total_time.var + (*out).torch.time1.var);
                cpy[((int*)&((*out).total_time.var) - (int*)&(*out))] = 0;
                ((*out).torch.time1.var = 0);
                cpy[((int*)&((*out).torch.time1.var) - (int*)&(*out))] = 0;
                ((*out).where_is_torch.var = 1 - (*out).where_is_torch.var);
                cpy[((int*)&((*out).where_is_torch.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,0,0,1,0,0,0,0,0,0,0,0,0
                // may-write:    1,1,0,1,1,0,0,0,0,0,0,0,0,1
                // must-write:   1,1,0,1,1,0,0,0,0,0,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 80;
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
            return "total_time";
        case 1:
            return "where_is_torch";
        case 2:
            return "on_right";
        case 3:
            return "torch";
        case 4:
            return "torch.time1";
        case 5:
            return "torch.time2";
        case 6:
            return "soldier_1";
        case 7:
            return "soldier_2";
        case 8:
            return "soldier_3";
        case 9:
            return "soldier_4";
        case 10:
            return "soldier_5";
        case 11:
            return "soldier_6";
        case 12:
            return "soldier_7";
        case 13:
            return "soldier_8";
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
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 7;
        case 12:
            return 8;
        case 13:
            return 9;
        default:
            return -1;
    }
}

extern "C" int get_state_variable_type_count() 
{
    return 10;
}

extern "C" const char* get_state_variable_type_name(int type) 
{
    switch (type)
    {
        case 0:
            return "byte";
        case 2:
            return "soldier_1";
        case 3:
            return "soldier_2";
        case 4:
            return "soldier_3";
        case 5:
            return "soldier_4";
        case 6:
            return "soldier_5";
        case 7:
            return "soldier_6";
        case 8:
            return "soldier_7";
        case 9:
            return "soldier_8";
        case 1:
            return "torch";
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
        case 2: // soldier_1
            return 4;
        case 3: // soldier_2
            return 4;
        case 4: // soldier_3
            return 4;
        case 5: // soldier_4
            return 4;
        case 6: // soldier_5
            return 4;
        case 7: // soldier_6
            return 4;
        case 8: // soldier_7
            return 4;
        case 9: // soldier_8
            return 4;
        case 1: // torch
            return 4;
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
                    return "left";
                case 1:
                    return "go_right";
                case 2:
                    return "right";
                case 3:
                    return "go_left";
            }
        }
        case 3:
        {
            switch (value)
            {
                case 0:
                    return "left";
                case 1:
                    return "go_right";
                case 2:
                    return "right";
                case 3:
                    return "go_left";
            }
        }
        case 4:
        {
            switch (value)
            {
                case 0:
                    return "left";
                case 1:
                    return "go_right";
                case 2:
                    return "right";
                case 3:
                    return "go_left";
            }
        }
        case 5:
        {
            switch (value)
            {
                case 0:
                    return "left";
                case 1:
                    return "go_right";
                case 2:
                    return "right";
                case 3:
                    return "go_left";
            }
        }
        case 6:
        {
            switch (value)
            {
                case 0:
                    return "left";
                case 1:
                    return "go_right";
                case 2:
                    return "right";
                case 3:
                    return "go_left";
            }
        }
        case 7:
        {
            switch (value)
            {
                case 0:
                    return "left";
                case 1:
                    return "go_right";
                case 2:
                    return "right";
                case 3:
                    return "go_left";
            }
        }
        case 8:
        {
            switch (value)
            {
                case 0:
                    return "left";
                case 1:
                    return "go_right";
                case 2:
                    return "right";
                case 3:
                    return "go_left";
            }
        }
        case 9:
        {
            switch (value)
            {
                case 0:
                    return "left";
                case 1:
                    return "go_right";
                case 2:
                    return "right";
                case 3:
                    return "go_left";
            }
        }
        case 1:
        {
            switch (value)
            {
                case 0:
                    return "free";
                case 1:
                    return "one";
                case 2:
                    return "two";
                case 3:
                    return "going";
            }
        }
    }
    return NULL;
}

int transition_dependency[][3][14] = 
{
    // { ... read ...}, { ... may-write ...}, { ... must-write ...}
    {{0,1,0,1,0,0,1,0,0,0,0,0,0,0},{0,0,0,1,1,0,1,0,0,0,0,0,0,0},{0,0,0,1,1,0,1,0,0,0,0,0,0,0}},
    {{0,1,1,1,0,0,1,0,0,0,0,0,0,0},{0,0,1,1,1,0,1,0,0,0,0,0,0,0},{0,0,1,1,1,0,1,0,0,0,0,0,0,0}},
    {{0,1,0,1,0,0,0,1,0,0,0,0,0,0},{0,0,0,1,1,0,0,1,0,0,0,0,0,0},{0,0,0,1,1,0,0,1,0,0,0,0,0,0}},
    {{0,1,1,1,0,0,0,1,0,0,0,0,0,0},{0,0,1,1,1,0,0,1,0,0,0,0,0,0},{0,0,1,1,1,0,0,1,0,0,0,0,0,0}},
    {{0,1,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,1,0,0,0,0,0}},
    {{0,1,1,1,0,0,0,0,1,0,0,0,0,0},{0,0,1,1,1,0,0,0,1,0,0,0,0,0},{0,0,1,1,1,0,0,0,1,0,0,0,0,0}},
    {{0,1,0,1,0,0,0,0,0,1,0,0,0,0},{0,0,0,1,1,0,0,0,0,1,0,0,0,0},{0,0,0,1,1,0,0,0,0,1,0,0,0,0}},
    {{0,1,1,1,0,0,0,0,0,1,0,0,0,0},{0,0,1,1,1,0,0,0,0,1,0,0,0,0},{0,0,1,1,1,0,0,0,0,1,0,0,0,0}},
    {{0,1,0,1,0,0,0,0,0,0,1,0,0,0},{0,0,0,1,1,0,0,0,0,0,1,0,0,0},{0,0,0,1,1,0,0,0,0,0,1,0,0,0}},
    {{0,1,1,1,0,0,0,0,0,0,1,0,0,0},{0,0,1,1,1,0,0,0,0,0,1,0,0,0},{0,0,1,1,1,0,0,0,0,0,1,0,0,0}},
    {{0,1,0,1,0,0,0,0,0,0,0,1,0,0},{0,0,0,1,1,0,0,0,0,0,0,1,0,0},{0,0,0,1,1,0,0,0,0,0,0,1,0,0}},
    {{0,1,1,1,0,0,0,0,0,0,0,1,0,0},{0,0,1,1,1,0,0,0,0,0,0,1,0,0},{0,0,1,1,1,0,0,0,0,0,0,1,0,0}},
    {{0,1,0,1,0,0,0,0,0,0,0,0,1,0},{0,0,0,1,1,0,0,0,0,0,0,0,1,0},{0,0,0,1,1,0,0,0,0,0,0,0,1,0}},
    {{0,1,1,1,0,0,0,0,0,0,0,0,1,0},{0,0,1,1,1,0,0,0,0,0,0,0,1,0},{0,0,1,1,1,0,0,0,0,0,0,0,1,0}},
    {{0,1,0,1,0,0,0,0,0,0,0,0,0,1},{0,0,0,1,1,0,0,0,0,0,0,0,0,1},{0,0,0,1,1,0,0,0,0,0,0,0,0,1}},
    {{0,1,1,1,0,0,0,0,0,0,0,0,0,1},{0,0,1,1,1,0,0,0,0,0,0,0,0,1},{0,0,1,1,1,0,0,0,0,0,0,0,0,1}},
    {{0,1,0,1,0,0,1,0,0,0,0,0,0,0},{0,0,0,1,0,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,1,1,0,0,0,0,0,0,0}},
    {{0,1,1,1,0,0,1,0,0,0,0,0,0,0},{0,0,1,1,0,1,1,0,0,0,0,0,0,0},{0,0,1,1,0,1,1,0,0,0,0,0,0,0}},
    {{0,1,0,1,0,0,0,1,0,0,0,0,0,0},{0,0,0,1,0,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,1,0,1,0,0,0,0,0,0}},
    {{0,1,1,1,0,0,0,1,0,0,0,0,0,0},{0,0,1,1,0,1,0,1,0,0,0,0,0,0},{0,0,1,1,0,1,0,1,0,0,0,0,0,0}},
    {{0,1,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,1,0,0,0,0,0}},
    {{0,1,1,1,0,0,0,0,1,0,0,0,0,0},{0,0,1,1,0,1,0,0,1,0,0,0,0,0},{0,0,1,1,0,1,0,0,1,0,0,0,0,0}},
    {{0,1,0,1,0,0,0,0,0,1,0,0,0,0},{0,0,0,1,0,1,0,0,0,1,0,0,0,0},{0,0,0,1,0,1,0,0,0,1,0,0,0,0}},
    {{0,1,1,1,0,0,0,0,0,1,0,0,0,0},{0,0,1,1,0,1,0,0,0,1,0,0,0,0},{0,0,1,1,0,1,0,0,0,1,0,0,0,0}},
    {{0,1,0,1,0,0,0,0,0,0,1,0,0,0},{0,0,0,1,0,1,0,0,0,0,1,0,0,0},{0,0,0,1,0,1,0,0,0,0,1,0,0,0}},
    {{0,1,1,1,0,0,0,0,0,0,1,0,0,0},{0,0,1,1,0,1,0,0,0,0,1,0,0,0},{0,0,1,1,0,1,0,0,0,0,1,0,0,0}},
    {{0,1,0,1,0,0,0,0,0,0,0,1,0,0},{0,0,0,1,0,1,0,0,0,0,0,1,0,0},{0,0,0,1,0,1,0,0,0,0,0,1,0,0}},
    {{0,1,1,1,0,0,0,0,0,0,0,1,0,0},{0,0,1,1,0,1,0,0,0,0,0,1,0,0},{0,0,1,1,0,1,0,0,0,0,0,1,0,0}},
    {{0,1,0,1,0,0,0,0,0,0,0,0,1,0},{0,0,0,1,0,1,0,0,0,0,0,0,1,0},{0,0,0,1,0,1,0,0,0,0,0,0,1,0}},
    {{0,1,1,1,0,0,0,0,0,0,0,0,1,0},{0,0,1,1,0,1,0,0,0,0,0,0,1,0},{0,0,1,1,0,1,0,0,0,0,0,0,1,0}},
    {{0,1,0,1,0,0,0,0,0,0,0,0,0,1},{0,0,0,1,0,1,0,0,0,0,0,0,0,1},{0,0,0,1,0,1,0,0,0,0,0,0,0,1}},
    {{0,1,1,1,0,0,0,0,0,0,0,0,0,1},{0,0,1,1,0,1,0,0,0,0,0,0,0,1},{0,0,1,1,0,1,0,0,0,0,0,0,0,1}},
    {{0,0,0,1,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0,0,0,0}},
    {{0,0,1,1,1,1,1,0,0,0,0,0,0,0},{0,0,1,1,0,0,1,0,0,0,0,0,0,0},{0,0,1,1,0,0,1,0,0,0,0,0,0,0}},
    {{0,0,1,1,1,1,1,0,0,0,0,0,0,0},{0,0,1,1,1,1,1,0,0,0,0,0,0,0},{0,0,1,1,1,1,1,0,0,0,0,0,0,0}},
    {{1,1,1,1,1,0,1,0,0,0,0,0,0,0},{1,1,1,1,1,0,1,0,0,0,0,0,0,0},{1,1,1,1,1,0,1,0,0,0,0,0,0,0}},
    {{0,0,0,1,1,1,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,1,0,0,0,0,0,0,0}},
    {{0,0,0,1,1,1,1,0,0,0,0,0,0,0},{0,0,0,1,1,1,1,0,0,0,0,0,0,0},{0,0,0,1,1,1,1,0,0,0,0,0,0,0}},
    {{1,1,0,1,1,0,1,0,0,0,0,0,0,0},{1,1,0,1,1,0,1,0,0,0,0,0,0,0},{1,1,0,1,1,0,1,0,0,0,0,0,0,0}},
    {{0,0,1,1,1,1,0,1,0,0,0,0,0,0},{0,0,1,1,0,0,0,1,0,0,0,0,0,0},{0,0,1,1,0,0,0,1,0,0,0,0,0,0}},
    {{0,0,1,1,1,1,0,1,0,0,0,0,0,0},{0,0,1,1,1,1,0,1,0,0,0,0,0,0},{0,0,1,1,1,1,0,1,0,0,0,0,0,0}},
    {{1,1,1,1,1,0,0,1,0,0,0,0,0,0},{1,1,1,1,1,0,0,1,0,0,0,0,0,0},{1,1,1,1,1,0,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,1,1,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,1,0,0,0,0,0,0}},
    {{0,0,0,1,1,1,0,1,0,0,0,0,0,0},{0,0,0,1,1,1,0,1,0,0,0,0,0,0},{0,0,0,1,1,1,0,1,0,0,0,0,0,0}},
    {{1,1,0,1,1,0,0,1,0,0,0,0,0,0},{1,1,0,1,1,0,0,1,0,0,0,0,0,0},{1,1,0,1,1,0,0,1,0,0,0,0,0,0}},
    {{0,0,1,1,1,1,0,0,1,0,0,0,0,0},{0,0,1,1,0,0,0,0,1,0,0,0,0,0},{0,0,1,1,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,1,1,1,1,0,0,1,0,0,0,0,0},{0,0,1,1,1,1,0,0,1,0,0,0,0,0},{0,0,1,1,1,1,0,0,1,0,0,0,0,0}},
    {{1,1,1,1,1,0,0,0,1,0,0,0,0,0},{1,1,1,1,1,0,0,0,1,0,0,0,0,0},{1,1,1,1,1,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,1,1,1,0,0,1,0,0,0,0,0},{0,0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,0,0,0,1,0,0,0,0,0}},
    {{0,0,0,1,1,1,0,0,1,0,0,0,0,0},{0,0,0,1,1,1,0,0,1,0,0,0,0,0},{0,0,0,1,1,1,0,0,1,0,0,0,0,0}},
    {{1,1,0,1,1,0,0,0,1,0,0,0,0,0},{1,1,0,1,1,0,0,0,1,0,0,0,0,0},{1,1,0,1,1,0,0,0,1,0,0,0,0,0}},
    {{0,0,1,1,1,1,0,0,0,1,0,0,0,0},{0,0,1,1,0,0,0,0,0,1,0,0,0,0},{0,0,1,1,0,0,0,0,0,1,0,0,0,0}},
    {{0,0,1,1,1,1,0,0,0,1,0,0,0,0},{0,0,1,1,1,1,0,0,0,1,0,0,0,0},{0,0,1,1,1,1,0,0,0,1,0,0,0,0}},
    {{1,1,1,1,1,0,0,0,0,1,0,0,0,0},{1,1,1,1,1,0,0,0,0,1,0,0,0,0},{1,1,1,1,1,0,0,0,0,1,0,0,0,0}},
    {{0,0,0,1,1,1,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,0,0,1,0,0,0,0}},
    {{0,0,0,1,1,1,0,0,0,1,0,0,0,0},{0,0,0,1,1,1,0,0,0,1,0,0,0,0},{0,0,0,1,1,1,0,0,0,1,0,0,0,0}},
    {{1,1,0,1,1,0,0,0,0,1,0,0,0,0},{1,1,0,1,1,0,0,0,0,1,0,0,0,0},{1,1,0,1,1,0,0,0,0,1,0,0,0,0}},
    {{0,0,1,1,1,1,0,0,0,0,1,0,0,0},{0,0,1,1,0,0,0,0,0,0,1,0,0,0},{0,0,1,1,0,0,0,0,0,0,1,0,0,0}},
    {{0,0,1,1,1,1,0,0,0,0,1,0,0,0},{0,0,1,1,1,1,0,0,0,0,1,0,0,0},{0,0,1,1,1,1,0,0,0,0,1,0,0,0}},
    {{1,1,1,1,1,0,0,0,0,0,1,0,0,0},{1,1,1,1,1,0,0,0,0,0,1,0,0,0},{1,1,1,1,1,0,0,0,0,0,1,0,0,0}},
    {{0,0,0,1,1,1,0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,0,0,0,1,0,0,0}},
    {{0,0,0,1,1,1,0,0,0,0,1,0,0,0},{0,0,0,1,1,1,0,0,0,0,1,0,0,0},{0,0,0,1,1,1,0,0,0,0,1,0,0,0}},
    {{1,1,0,1,1,0,0,0,0,0,1,0,0,0},{1,1,0,1,1,0,0,0,0,0,1,0,0,0},{1,1,0,1,1,0,0,0,0,0,1,0,0,0}},
    {{0,0,1,1,1,1,0,0,0,0,0,1,0,0},{0,0,1,1,0,0,0,0,0,0,0,1,0,0},{0,0,1,1,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,1,1,1,1,0,0,0,0,0,1,0,0},{0,0,1,1,1,1,0,0,0,0,0,1,0,0},{0,0,1,1,1,1,0,0,0,0,0,1,0,0}},
    {{1,1,1,1,1,0,0,0,0,0,0,1,0,0},{1,1,1,1,1,0,0,0,0,0,0,1,0,0},{1,1,1,1,1,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,1,1,1,0,0,0,0,0,1,0,0},{0,0,0,1,0,0,0,0,0,0,0,1,0,0},{0,0,0,1,0,0,0,0,0,0,0,1,0,0}},
    {{0,0,0,1,1,1,0,0,0,0,0,1,0,0},{0,0,0,1,1,1,0,0,0,0,0,1,0,0},{0,0,0,1,1,1,0,0,0,0,0,1,0,0}},
    {{1,1,0,1,1,0,0,0,0,0,0,1,0,0},{1,1,0,1,1,0,0,0,0,0,0,1,0,0},{1,1,0,1,1,0,0,0,0,0,0,1,0,0}},
    {{0,0,1,1,1,1,0,0,0,0,0,0,1,0},{0,0,1,1,0,0,0,0,0,0,0,0,1,0},{0,0,1,1,0,0,0,0,0,0,0,0,1,0}},
    {{0,0,1,1,1,1,0,0,0,0,0,0,1,0},{0,0,1,1,1,1,0,0,0,0,0,0,1,0},{0,0,1,1,1,1,0,0,0,0,0,0,1,0}},
    {{1,1,1,1,1,0,0,0,0,0,0,0,1,0},{1,1,1,1,1,0,0,0,0,0,0,0,1,0},{1,1,1,1,1,0,0,0,0,0,0,0,1,0}},
    {{0,0,0,1,1,1,0,0,0,0,0,0,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0},{0,0,0,1,0,0,0,0,0,0,0,0,1,0}},
    {{0,0,0,1,1,1,0,0,0,0,0,0,1,0},{0,0,0,1,1,1,0,0,0,0,0,0,1,0},{0,0,0,1,1,1,0,0,0,0,0,0,1,0}},
    {{1,1,0,1,1,0,0,0,0,0,0,0,1,0},{1,1,0,1,1,0,0,0,0,0,0,0,1,0},{1,1,0,1,1,0,0,0,0,0,0,0,1,0}},
    {{0,0,1,1,1,1,0,0,0,0,0,0,0,1},{0,0,1,1,0,0,0,0,0,0,0,0,0,1},{0,0,1,1,0,0,0,0,0,0,0,0,0,1}},
    {{0,0,1,1,1,1,0,0,0,0,0,0,0,1},{0,0,1,1,1,1,0,0,0,0,0,0,0,1},{0,0,1,1,1,1,0,0,0,0,0,0,0,1}},
    {{1,1,1,1,1,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,0,0,0,0,0,0,0,0,1}},
    {{0,0,0,1,1,1,0,0,0,0,0,0,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,1}},
    {{0,0,0,1,1,1,0,0,0,0,0,0,0,1},{0,0,0,1,1,1,0,0,0,0,0,0,0,1},{0,0,0,1,1,1,0,0,0,0,0,0,0,1}},
    {{1,1,0,1,1,0,0,0,0,0,0,0,0,1},{1,1,0,1,1,0,0,0,0,0,0,0,0,1},{1,1,0,1,1,0,0,0,0,0,0,0,0,1}}
}
;

int actions_read[][14] = 
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0,0,0,0,0}
}
;

extern "C" int get_transition_count() 
{
    return 81;
}

extern "C" const int* get_transition_read_dependencies(int t) 
{
    if (t>=0 && t < 81) return transition_dependency[t][0];
    return NULL;
}

extern "C" const int* get_transition_actions_read_dependencies(int t) 
{
    if (t>=0 && t < 81) return actions_read[t];
    return NULL;
}

extern "C" const int* get_transition_may_write_dependencies(int t) 
{
    if (t>=0 && t < 81) return transition_dependency[t][1];
    return NULL;
}

extern "C" const int* get_transition_write_dependencies(int t) 
{
    return get_transition_may_write_dependencies(t);
}

extern "C" const int* get_transition_must_write_dependencies(int t) 
{
    if (t>=0 && t < 81) return transition_dependency[t][2];
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
            case 0: return (((*src).torch.state.var == 0));
            case 1: return (((*src).soldier_1.state.var == 0));
            case 2: return (((*src).where_is_torch.var == 0));
            case 3: return (((*src).soldier_1.state.var == 2));
            case 4: return (((*src).where_is_torch.var == 1));
            case 5: return (((*src).soldier_2.state.var == 0));
            case 6: return (((*src).soldier_2.state.var == 2));
            case 7: return (((*src).soldier_3.state.var == 0));
            case 8: return (((*src).soldier_3.state.var == 2));
            case 9: return (((*src).soldier_4.state.var == 0));
            case 10: return (((*src).soldier_4.state.var == 2));
            case 11: return (((*src).soldier_5.state.var == 0));
            case 12: return (((*src).soldier_5.state.var == 2));
            case 13: return (((*src).soldier_6.state.var == 0));
            case 14: return (((*src).soldier_6.state.var == 2));
            case 15: return (((*src).soldier_7.state.var == 0));
            case 16: return (((*src).soldier_7.state.var == 2));
            case 17: return (((*src).soldier_8.state.var == 0));
            case 18: return (((*src).soldier_8.state.var == 2));
            case 19: return (((*src).torch.state.var == 1));
            case 20: return (((*src).soldier_1.state.var == 1));
            case 21: return (((*src).torch.state.var == 2));
            case 22: return (((*src).torch.time1.var >= (*src).torch.time2.var));
            case 23: return (((*src).torch.time1.var < (*src).torch.time2.var));
            case 24: return (((*src).torch.state.var == 3));
            case 25: return (((*src).total_time.var + (*src).torch.time1.var <= 200));
            case 26: return (((*src).soldier_1.state.var == 3));
            case 27: return (((*src).soldier_2.state.var == 1));
            case 28: return (((*src).soldier_2.state.var == 3));
            case 29: return (((*src).soldier_3.state.var == 1));
            case 30: return (((*src).soldier_3.state.var == 3));
            case 31: return (((*src).soldier_4.state.var == 1));
            case 32: return (((*src).soldier_4.state.var == 3));
            case 33: return (((*src).soldier_5.state.var == 1));
            case 34: return (((*src).soldier_5.state.var == 3));
            case 35: return (((*src).soldier_6.state.var == 1));
            case 36: return (((*src).soldier_6.state.var == 3));
            case 37: return (((*src).soldier_7.state.var == 1));
            case 38: return (((*src).soldier_7.state.var == 3));
            case 39: return (((*src).soldier_8.state.var == 1));
            case 40: return (((*src).soldier_8.state.var == 3));
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
}

extern "C" const int get_guard_count() 
{
    return 41;
}

#pragma clang diagnostic push
int* guards_per_transition[81] = 
{
    ((int[]){3, 0, 1, 2}), // 0
    ((int[]){3, 0, 3, 4}), // 1
    ((int[]){3, 0, 5, 2}), // 2
    ((int[]){3, 0, 6, 4}), // 3
    ((int[]){3, 0, 7, 2}), // 4
    ((int[]){3, 0, 8, 4}), // 5
    ((int[]){3, 0, 9, 2}), // 6
    ((int[]){3, 0, 10, 4}), // 7
    ((int[]){3, 0, 11, 2}), // 8
    ((int[]){3, 0, 12, 4}), // 9
    ((int[]){3, 0, 13, 2}), // 10
    ((int[]){3, 0, 14, 4}), // 11
    ((int[]){3, 0, 15, 2}), // 12
    ((int[]){3, 0, 16, 4}), // 13
    ((int[]){3, 0, 17, 2}), // 14
    ((int[]){3, 0, 18, 4}), // 15
    ((int[]){3, 19, 1, 2}), // 16
    ((int[]){3, 19, 3, 4}), // 17
    ((int[]){3, 19, 5, 2}), // 18
    ((int[]){3, 19, 6, 4}), // 19
    ((int[]){3, 19, 7, 2}), // 20
    ((int[]){3, 19, 8, 4}), // 21
    ((int[]){3, 19, 9, 2}), // 22
    ((int[]){3, 19, 10, 4}), // 23
    ((int[]){3, 19, 11, 2}), // 24
    ((int[]){3, 19, 12, 4}), // 25
    ((int[]){3, 19, 13, 2}), // 26
    ((int[]){3, 19, 14, 4}), // 27
    ((int[]){3, 19, 15, 2}), // 28
    ((int[]){3, 19, 16, 4}), // 29
    ((int[]){3, 19, 17, 2}), // 30
    ((int[]){3, 19, 18, 4}), // 31
    ((int[]){1, 19}), // 32
    ((int[]){3, 20, 21, 22}), // 33
    ((int[]){3, 20, 21, 23}), // 34
    ((int[]){3, 20, 24, 25}), // 35
    ((int[]){3, 26, 21, 22}), // 36
    ((int[]){3, 26, 21, 23}), // 37
    ((int[]){3, 26, 24, 25}), // 38
    ((int[]){3, 27, 21, 22}), // 39
    ((int[]){3, 27, 21, 23}), // 40
    ((int[]){3, 27, 24, 25}), // 41
    ((int[]){3, 28, 21, 22}), // 42
    ((int[]){3, 28, 21, 23}), // 43
    ((int[]){3, 28, 24, 25}), // 44
    ((int[]){3, 29, 21, 22}), // 45
    ((int[]){3, 29, 21, 23}), // 46
    ((int[]){3, 29, 24, 25}), // 47
    ((int[]){3, 30, 21, 22}), // 48
    ((int[]){3, 30, 21, 23}), // 49
    ((int[]){3, 30, 24, 25}), // 50
    ((int[]){3, 31, 21, 22}), // 51
    ((int[]){3, 31, 21, 23}), // 52
    ((int[]){3, 31, 24, 25}), // 53
    ((int[]){3, 32, 21, 22}), // 54
    ((int[]){3, 32, 21, 23}), // 55
    ((int[]){3, 32, 24, 25}), // 56
    ((int[]){3, 33, 21, 22}), // 57
    ((int[]){3, 33, 21, 23}), // 58
    ((int[]){3, 33, 24, 25}), // 59
    ((int[]){3, 34, 21, 22}), // 60
    ((int[]){3, 34, 21, 23}), // 61
    ((int[]){3, 34, 24, 25}), // 62
    ((int[]){3, 35, 21, 22}), // 63
    ((int[]){3, 35, 21, 23}), // 64
    ((int[]){3, 35, 24, 25}), // 65
    ((int[]){3, 36, 21, 22}), // 66
    ((int[]){3, 36, 21, 23}), // 67
    ((int[]){3, 36, 24, 25}), // 68
    ((int[]){3, 37, 21, 22}), // 69
    ((int[]){3, 37, 21, 23}), // 70
    ((int[]){3, 37, 24, 25}), // 71
    ((int[]){3, 38, 21, 22}), // 72
    ((int[]){3, 38, 21, 23}), // 73
    ((int[]){3, 38, 24, 25}), // 74
    ((int[]){3, 39, 21, 22}), // 75
    ((int[]){3, 39, 21, 23}), // 76
    ((int[]){3, 39, 24, 25}), // 77
    ((int[]){3, 40, 21, 22}), // 78
    ((int[]){3, 40, 21, 23}), // 79
    ((int[]){3, 40, 24, 25}), // 80
}
;
#pragma clang diagnostic pop

extern "C" const int* get_guards(int t) 
{
    if (t>=0 && t < 81) return guards_per_transition[t];
    return NULL;
}

extern "C" const int** get_all_guards() 
{
    return (const int**)&guards_per_transition;
}

int guard[][14] = 
{
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1}
}
;

extern "C" const int* get_guard_matrix(int g) 
{
    if (g>=0 && g < 41) return guard[g];
    return NULL;
}

int guardmaybecoenabled[41][41] = 
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
}
;

extern "C" const int* get_guard_may_be_coenabled_matrix(int g) 
{
    if (g>=0 && g < 41) return guardmaybecoenabled[g];
    return NULL;
}

int guard_nes[41][81] = 
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
}
;

extern "C" const int* get_guard_nes_matrix(int g) 
{
    if (g>=0 && g < 41) return guard_nes[g];
    return NULL;
}

int guard_nds[41][81] = 
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1}
}
;

extern "C" const int* get_guard_nds_matrix(int g) 
{
    if (g>=0 && g < 41) return guard_nds[g];
    return NULL;
}

int dna[81][81] = 
{
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_dna_matrix(int t) 
{
    if (t >= 0 && t < 81) return dna[t];
    return NULL;
}

