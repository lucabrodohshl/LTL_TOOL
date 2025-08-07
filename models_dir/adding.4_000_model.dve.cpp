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
    sshort_int_t c;
    sshort_int_t x1;
    sshort_int_t x2;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) a1;
    struct
    {
        ushort_int_t state;
    }
    __attribute__((__packed__)) a2;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

state_struct_t initial_state = { 1,0,0,0,0 };

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
        int cpy[5] = { 1,1,1,1,1,};
        (*out).a1.state.var = 1;
        cpy[((int*)&(*out).a1.state.var - (int*)&(*out))] = 0;
        ((*out).x1.var = (*out).c.var);
        cpy[((int*)&((*out).x1.var) - (int*)&(*out))] = 0;
        // actions_read: 1,0,0,0,0
        // may-write:    0,1,0,1,0
        // must-write:   0,1,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l1: {
        *out = *in;
        int cpy[5] = { 1,1,1,1,1,};
        (*out).a1.state.var = 2;
        cpy[((int*)&(*out).a1.state.var - (int*)&(*out))] = 0;
        ((*out).x1.var = (*out).x1.var + (*out).c.var);
        cpy[((int*)&((*out).x1.var) - (int*)&(*out))] = 0;
        // actions_read: 1,1,0,0,0
        // may-write:    0,1,0,1,0
        // must-write:   0,1,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l2: {
        *out = *in;
        int cpy[5] = { 1,1,1,1,1,};
        (*out).a1.state.var = 0;
        cpy[((int*)&(*out).a1.state.var - (int*)&(*out))] = 0;
        ((*out).c.var = (*out).x1.var);
        cpy[((int*)&((*out).c.var) - (int*)&(*out))] = 0;
        // actions_read: 0,1,0,0,0
        // may-write:    1,0,0,1,0
        // must-write:   1,0,0,1,0
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l3: {
        *out = *in;
        int cpy[5] = { 1,1,1,1,1,};
        (*out).a2.state.var = 1;
        cpy[((int*)&(*out).a2.state.var - (int*)&(*out))] = 0;
        ((*out).x2.var = (*out).c.var);
        cpy[((int*)&((*out).x2.var) - (int*)&(*out))] = 0;
        // actions_read: 1,0,0,0,0
        // may-write:    0,0,1,0,1
        // must-write:   0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l4: {
        *out = *in;
        int cpy[5] = { 1,1,1,1,1,};
        (*out).a2.state.var = 2;
        cpy[((int*)&(*out).a2.state.var - (int*)&(*out))] = 0;
        ((*out).x2.var = (*out).x2.var + (*out).c.var);
        cpy[((int*)&((*out).x2.var) - (int*)&(*out))] = 0;
        // actions_read: 1,0,1,0,0
        // may-write:    0,0,1,0,1
        // must-write:   0,0,1,0,1
        callback(arg, &transition_info, out, cpy);
        ++states_emitted;
    }
    return states_emitted;
    l5: {
        *out = *in;
        int cpy[5] = { 1,1,1,1,1,};
        (*out).a2.state.var = 0;
        cpy[((int*)&(*out).a2.state.var - (int*)&(*out))] = 0;
        ((*out).c.var = (*out).x2.var);
        cpy[((int*)&((*out).c.var) - (int*)&(*out))] = 0;
        // actions_read: 0,0,1,0,0
        // may-write:    1,0,0,0,1
        // must-write:   1,0,0,0,1
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
        default: printf ("Wrong group! Using greybox/long call + -l (DiVinE LTL semantics)? This combo is not implemented."); exit (-1);
    }
    return 0;
}

extern "C" int get_successor( void* model, int t, const state_struct_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_struct_t *out, int *cpy), void *arg ) 
{
    int states_emitted = 0;
    goto switch_state;
    l0: {
        
        // read:         1,0,0,1,0
        // actions_read: 1,0,0,0,0
        if (  ( ((*in).a1.state.var == 0) )  &&  ( ((*in).c.var < 400) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l1: {
        
        // read:         1,1,0,1,0
        // actions_read: 1,1,0,0,0
        if (  ( ((*in).a1.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l2: {
        
        // read:         0,1,0,1,0
        // actions_read: 0,1,0,0,0
        if (  ( ((*in).a1.state.var == 2) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l3: {
        
        // read:         1,0,0,0,1
        // actions_read: 1,0,0,0,0
        if (  ( ((*in).a2.state.var == 0) )  &&  ( ((*in).c.var < 400) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l4: {
        
        // read:         1,0,1,0,1
        // actions_read: 1,0,1,0,0
        if (  ( ((*in).a2.state.var == 1) ) )
        states_emitted = get_action(model, t, in, callback, arg);
    }
    return states_emitted;
    l5: {
        
        // read:         0,0,1,0,1
        // actions_read: 0,0,1,0,0
        if (  ( ((*in).a2.state.var == 2) ) )
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
    int cpy[5] = { 1, 1, 1, 1, 1, };
    if ( false )
    {
        ;
    }
    else
    {
        if (  ( ((*in).a1.state.var == 0) ) )
        {
            
            // read:         1,0,0,1,0
            // actions_read: 1,0,0,0,0
            if (  ( ((*in).c.var < 400) ) )
            {
                *out = *in;
                int cpy[5] = { 1,1,1,1,1,};
                (*out).a1.state.var = 1;
                cpy[((int*)&(*out).a1.state.var - (int*)&(*out))] = 0;
                ((*out).x1.var = (*out).c.var);
                cpy[((int*)&((*out).x1.var) - (int*)&(*out))] = 0;
                // actions_read: 1,0,0,0,0
                // may-write:    0,1,0,1,0
                // must-write:   0,1,0,1,0
                system_in_deadlock = false;
                transition_info.group = 0;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).a1.state.var == 1) ) )
        {
            
            // read:         1,1,0,1,0
            // actions_read: 1,1,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[5] = { 1,1,1,1,1,};
                (*out).a1.state.var = 2;
                cpy[((int*)&(*out).a1.state.var - (int*)&(*out))] = 0;
                ((*out).x1.var = (*out).x1.var + (*out).c.var);
                cpy[((int*)&((*out).x1.var) - (int*)&(*out))] = 0;
                // actions_read: 1,1,0,0,0
                // may-write:    0,1,0,1,0
                // must-write:   0,1,0,1,0
                system_in_deadlock = false;
                transition_info.group = 1;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).a1.state.var == 2) ) )
        {
            
            // read:         0,1,0,1,0
            // actions_read: 0,1,0,0,0
            if ( true )
            {
                *out = *in;
                int cpy[5] = { 1,1,1,1,1,};
                (*out).a1.state.var = 0;
                cpy[((int*)&(*out).a1.state.var - (int*)&(*out))] = 0;
                ((*out).c.var = (*out).x1.var);
                cpy[((int*)&((*out).c.var) - (int*)&(*out))] = 0;
                // actions_read: 0,1,0,0,0
                // may-write:    1,0,0,1,0
                // must-write:   1,0,0,1,0
                system_in_deadlock = false;
                transition_info.group = 2;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).a2.state.var == 0) ) )
        {
            
            // read:         1,0,0,0,1
            // actions_read: 1,0,0,0,0
            if (  ( ((*in).c.var < 400) ) )
            {
                *out = *in;
                int cpy[5] = { 1,1,1,1,1,};
                (*out).a2.state.var = 1;
                cpy[((int*)&(*out).a2.state.var - (int*)&(*out))] = 0;
                ((*out).x2.var = (*out).c.var);
                cpy[((int*)&((*out).x2.var) - (int*)&(*out))] = 0;
                // actions_read: 1,0,0,0,0
                // may-write:    0,0,1,0,1
                // must-write:   0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 3;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).a2.state.var == 1) ) )
        {
            
            // read:         1,0,1,0,1
            // actions_read: 1,0,1,0,0
            if ( true )
            {
                *out = *in;
                int cpy[5] = { 1,1,1,1,1,};
                (*out).a2.state.var = 2;
                cpy[((int*)&(*out).a2.state.var - (int*)&(*out))] = 0;
                ((*out).x2.var = (*out).x2.var + (*out).c.var);
                cpy[((int*)&((*out).x2.var) - (int*)&(*out))] = 0;
                // actions_read: 1,0,1,0,0
                // may-write:    0,0,1,0,1
                // must-write:   0,0,1,0,1
                system_in_deadlock = false;
                transition_info.group = 4;
                callback(arg, &transition_info, out, cpy);
                ++states_emitted;
            }
        }
        if (  ( ((*in).a2.state.var == 2) ) )
        {
            
            // read:         0,0,1,0,1
            // actions_read: 0,0,1,0,0
            if ( true )
            {
                *out = *in;
                int cpy[5] = { 1,1,1,1,1,};
                (*out).a2.state.var = 0;
                cpy[((int*)&(*out).a2.state.var - (int*)&(*out))] = 0;
                ((*out).c.var = (*out).x2.var);
                cpy[((int*)&((*out).c.var) - (int*)&(*out))] = 0;
                // actions_read: 0,0,1,0,0
                // may-write:    1,0,0,0,1
                // must-write:   1,0,0,0,1
                system_in_deadlock = false;
                transition_info.group = 5;
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
    return 5;
}

extern "C" const char* get_state_variable_name(int var)
{
    switch (var)
    {
        case 0:
            return "c";
        case 1:
            return "x1";
        case 2:
            return "x2";
        case 3:
            return "a1";
        case 4:
            return "a2";
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
            return 2;
        default:
            return -1;
    }
}

extern "C" int get_state_variable_type_count() 
{
    return 3;
}

extern "C" const char* get_state_variable_type_name(int type) 
{
    switch (type)
    {
        case 1:
            return "a1";
        case 2:
            return "a2";
        case 0:
            return "int";
        default:
            return NULL;
    }
}

extern "C" int get_state_variable_type_value_count(int type)
{
    switch (type)
    {
        case 1: // a1
            return 3;
        case 2: // a2
            return 3;
        case 0: // int
            return 0;
        default:
            return -1;
    }
}

extern "C" const char* get_state_variable_type_value(int type, int value) 
{
    switch (type)
    {
        case 1:
        {
            switch (value)
            {
                case 0:
                    return "Q";
                case 1:
                    return "K";
                case 2:
                    return "S";
            }
        }
        case 2:
        {
            switch (value)
            {
                case 0:
                    return "Q";
                case 1:
                    return "K";
                case 2:
                    return "S";
            }
        }
    }
    return NULL;
}

int transition_dependency[][3][5] = 
{
    // { ... read ...}, { ... may-write ...}, { ... must-write ...}
    {{1,0,0,1,0},{0,1,0,1,0},{0,1,0,1,0}},
    {{1,1,0,1,0},{0,1,0,1,0},{0,1,0,1,0}},
    {{0,1,0,1,0},{1,0,0,1,0},{1,0,0,1,0}},
    {{1,0,0,0,1},{0,0,1,0,1},{0,0,1,0,1}},
    {{1,0,1,0,1},{0,0,1,0,1},{0,0,1,0,1}},
    {{0,0,1,0,1},{1,0,0,0,1},{1,0,0,0,1}}
}
;

int actions_read[][5] = 
{
    {1,0,0,0,0},
    {1,1,0,0,0},
    {0,1,0,0,0},
    {1,0,0,0,0},
    {1,0,1,0,0},
    {0,0,1,0,0}
}
;

extern "C" int get_transition_count() 
{
    return 6;
}

extern "C" const int* get_transition_read_dependencies(int t) 
{
    if (t>=0 && t < 6) return transition_dependency[t][0];
    return NULL;
}

extern "C" const int* get_transition_actions_read_dependencies(int t) 
{
    if (t>=0 && t < 6) return actions_read[t];
    return NULL;
}

extern "C" const int* get_transition_may_write_dependencies(int t) 
{
    if (t>=0 && t < 6) return transition_dependency[t][1];
    return NULL;
}

extern "C" const int* get_transition_write_dependencies(int t) 
{
    return get_transition_may_write_dependencies(t);
}

extern "C" const int* get_transition_must_write_dependencies(int t) 
{
    if (t>=0 && t < 6) return transition_dependency[t][2];
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
            case 0: return (((*src).a1.state.var == 0));
            case 1: return (((*src).c.var < 400));
            case 2: return (((*src).a1.state.var == 1));
            case 3: return (((*src).a1.state.var == 2));
            case 4: return (((*src).a2.state.var == 0));
            case 5: return (((*src).a2.state.var == 1));
            case 6: return (((*src).a2.state.var == 2));
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
}

extern "C" const int get_guard_count() 
{
    return 7;
}

#pragma clang diagnostic push
int* guards_per_transition[6] = 
{
    ((int[]){2, 0, 1}), // 0
    ((int[]){1, 2}), // 1
    ((int[]){1, 3}), // 2
    ((int[]){2, 4, 1}), // 3
    ((int[]){1, 5}), // 4
    ((int[]){1, 6}), // 5
}
;
#pragma clang diagnostic pop

extern "C" const int* get_guards(int t) 
{
    if (t>=0 && t < 6) return guards_per_transition[t];
    return NULL;
}

extern "C" const int** get_all_guards() 
{
    return (const int**)&guards_per_transition;
}

int guard[][5] = 
{
    {0,0,0,1,0},
    {1,0,0,0,0},
    {0,0,0,1,0},
    {0,0,0,1,0},
    {0,0,0,0,1},
    {0,0,0,0,1},
    {0,0,0,0,1}
}
;

extern "C" const int* get_guard_matrix(int g) 
{
    if (g>=0 && g < 7) return guard[g];
    return NULL;
}

int guardmaybecoenabled[7][7] = 
{
    {1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 0, 1, 1, 1},
    {0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 0, 1, 0},
    {1, 1, 1, 1, 0, 0, 1}
}
;

extern "C" const int* get_guard_may_be_coenabled_matrix(int g) 
{
    if (g>=0 && g < 7) return guardmaybecoenabled[g];
    return NULL;
}

int guard_nes[7][6] = 
{
    {0, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0}
}
;

extern "C" const int* get_guard_nes_matrix(int g) 
{
    if (g>=0 && g < 7) return guard_nes[g];
    return NULL;
}

int guard_nds[7][6] = 
{
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1}
}
;

extern "C" const int* get_guard_nds_matrix(int g) 
{
    if (g>=0 && g < 7) return guard_nds[g];
    return NULL;
}

int dna[6][6] = 
{
    {1, 0, 0, 1, 1, 1},
    {0, 1, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0},
    {1, 1, 1, 0, 0, 1}
}
;

extern "C" const int* get_dna_matrix(int t) 
{
    if (t >= 0 && t < 6) return dna[t];
    return NULL;
}

