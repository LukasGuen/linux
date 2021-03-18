/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2020 Patrick Franz <patfra71@gmail.com>
 */

#ifndef CF_UTILS_H
#define CF_UTILS_H

/* parse Kconfig-file and read .config */
void init_config (const char *Kconfig_file);

/* initialize satmap and cnf_clauses */
void init_data(void);


/* assign SAT-variables to all fexpr and create the sat_map */
void assign_sat_variables(void);

/* create True/False constants */
void create_constants(void);

/* create a temporary SAT-variable */
struct fexpr * create_tmpsatvar(void);

/* return a temporary SAT variable as string */
char * get_tmp_var_as_char(int i);

/* return a tristate value as a char * */
char * tristate_get_char(tristate val);


/* check if a k_expr can evaluate to mod */
bool can_evaluate_to_mod(struct k_expr *e);

/* return the constant FALSE as a k_expr */
struct k_expr * get_const_false_as_kexpr(void);

/* return the constant TRUE as a k_expr */
struct k_expr * get_const_true_as_kexpr(void);

/* parse an expr as a k_expr */
struct k_expr * parse_expr(struct expr *e, struct k_expr *parent);

/* print an expr */
void print_expr(char *tag, struct expr *e, int prevtoken);

/* print some debug info about the tree structure of k_expr */
void debug_print_kexpr(struct k_expr *e);

/* print a kexpr */
void print_kexpr(char *tag, struct k_expr *e);

/* write a kexpr into a string */
void kexpr_as_char(struct k_expr *e, struct gstr *s);


/* check, if the symbol is a tristate-constant */
bool is_tristate_constant(struct symbol *sym);

/* check, if a symbol is of type boolean or tristate */
bool sym_is_boolean(struct symbol *sym);

/* check, if a symbol is a boolean/tristate or a tristate constant */
bool sym_is_bool_or_triconst(struct symbol *sym);

/* check, if a symbol is of type int, hex, or string */
bool sym_is_nonboolean(struct symbol *sym);

/* check, if a symbol has a prompt */
bool sym_has_prompt(struct symbol *sym);

/* return the prompt of the symbol, if there is one */
struct property * sym_get_prompt(struct symbol *sym);

/* return the condition for the property, True if there is none */
struct pexpr * prop_get_condition(struct property *prop);

/* return the name of the symbol */
char * sym_get_name(struct symbol *sym);

/* check whether symbol is to be changed */
bool sym_is_sdv(struct sdv_list *list, struct symbol *sym);

/* print a symbol's name */
void print_sym_name(struct symbol *sym);

/* print all constraints for a symbol */
void print_sym_constraint(struct symbol *sym);

/* print a default map */
void print_default_map(struct defm_list *map);

/* print all symbols */
void print_all_symbols(void);

#endif
