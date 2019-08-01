/*
** EPITECH PROJECT, 2019
** write_parameter.c
** File description:
** write_parameter
*/

#include "op.h"
#include "asm.h"

static int management_label_parameter(asm_t *var, char const *parameter)
{
    label_t *label = var->label_list;
    int count = 0;

    for (; label; label = label->next) {
        if (my_strcmp(parameter, label->name) == 0)
            break;
        if (label->instruct != NULL && label->instruct[0].end != 1)
            count += 1;
        for (int i = 0; label->instruct && label->instruct[i].end != 1; i++) {
            count += (i != 0) ? 1 : 0;
            if (label->instruct[i].name != 1 && label->instruct[i].name != 9 &&
                label->instruct[i].name != 12 && label->instruct[i].name != 15)
                count += 1;
            for (int i_two = 0; label->instruct[i].args[i_two]; i_two++) {
                count += find_type_of_arg(label->instruct[i].args[i_two],
                label->instruct[i].name);
            }
        }
    }
    return (count - var->label);
}

static void write_char(asm_t *var, char const *parameter)
{
    char result = (char)my_getnbr(parameter);

    var->reg += 1;
    var->posi += 1;
    write(var->fd, &result, sizeof(result));
}

static void write_short(asm_t *var, char const *parameter)
{
    int label = 0;
    short result = (short)my_getnbr(parameter);

    if (parameter[0] && parameter[1] == LABEL_CHAR) {
        label = management_label_parameter(var, &parameter[2]);
        if (label > IDX_MOD || label < IDX_MOD * -1)
            exit(my_puterror("Error size of Byte.\n"));
        result = (short)label;
    }
    var->dir += T_DIR;
    var->posi += 1;
    result = change_endian_16(result);
    write(var->fd, &result, sizeof(result));
}

static void write_int(asm_t *var, char const *parameter)
{
    int result = my_getnbr(parameter);

    if ((parameter[0] && parameter[1] == LABEL_CHAR) ||
        (parameter[1] == LABEL_CHAR)) {
        if (parameter[0] && parameter[1] == LABEL_CHAR)
            result = management_label_parameter(var, &parameter[2]);
        else
            result = management_label_parameter(var, &parameter[1]);
    }
    var->ind += T_IND;
    var->posi += 1;
    result = change_endian_32(result);
    write(var->fd, &result, sizeof(result));
}

void write_parameter(asm_t *var, char const *parameter, int cas)
{
    if (parameter == NULL) {
        my_putstr("Error Parameter.\n");
        return;
    }
    switch (cas) {
        case 1 : return (write_char(var, parameter));
        case 2 : return (write_short(var, parameter));
        case 3 : return (write_int(var, parameter));
        default : return;
    }
}
